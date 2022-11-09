#include    "msud.h"

#include    "defines.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
MSUD::MSUD(QObject *parent) : Device(parent)
  , Uc(0.0)
  , Uc_min(40.0)
  , load_time(2.0)
  , load_timer(Q_NULLPTR)
  , is_fans_low_freq(true)
  , normalFreqTimer(new Timer(1.0, false))
  , lowFreqTimer(new Timer(1.0, false))
  , fansBustTimer(new Timer(2.5, true))
  , runOutTimer(new Timer(10.0, false))
  , fans_count(0)
  , fan_switch_timeout(80.0)
  , fan_bust_interval(2.5)
  , fan_runout_time(10.0)
  , I_fan_sw_min(480)
  , I_fan_sw_max(510)
  , is_pchf_ignored(false)  
{
    connect(normalFreqTimer, &Timer::process, this, &MSUD::slotNormalFreqTimer);

    connect(lowFreqTimer, &Timer::process, this, &MSUD::slotLowFreqTimer);

    connect(fansBustTimer, &Timer::process, this, &MSUD::slotFansBustTimer);

    connect(runOutTimer, &Timer::process, this, &MSUD::slotRunOutTimer);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
MSUD::~MSUD()
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MSUD::init()
{
    load_timer = new Timer(load_time, false);
    connect(load_timer, &Timer::process, this, &MSUD::slotLoadTimer);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MSUD::setPowerVoltage(double Uc)
{
    this->Uc = Uc;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MSUD::ode_system(const state_vector_t &Y,
                      state_vector_t &dYdt,
                      double t)
{
    Q_UNUSED(Y)
    Q_UNUSED(dYdt)
    Q_UNUSED(t)
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MSUD::stepDiscrete(double t, double dt)
{
    stateProcess(t, dt);

    load_timer->step(t, dt);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MSUD::load_config(CfgReader &cfg)
{
    QString secName = "Device";

    cfg.getDouble(secName, "FanSwitchTimeout", fan_switch_timeout);

    lowFreqTimer->setTimeout(fan_switch_timeout);
    normalFreqTimer->setTimeout(fan_switch_timeout);

    cfg.getDouble(secName, "FanBustInterval", fan_bust_interval);
    fansBustTimer->setTimeout(fan_bust_interval);

    cfg.getDouble(secName, "FanRunoutTime", fan_runout_time);
    runOutTimer->setTimeout(fan_runout_time);

    cfg.getDouble(secName, "FanSwitchCurrentMin", I_fan_sw_min);

    cfg.getDouble(secName, "FanSwitchCurrentMax", I_fan_sw_max);

    cfg.getBool(secName, "Ignore_Off_PCHF", is_pchf_ignored);

    cfg.getDouble(secName, "TC_min_press", msud_output.TC_min_press);

    QDomNode secNode = cfg.getFirstSection("Zone");

    while (!secNode.isNull())
    {


        secNode = cfg.getNextSection();
    }
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MSUD::stateProcess(double t, double dt)
{
    switch (msud_output.state)
    {
    case MSUD_OFF:
        {
            // Переход в режим общего сброса при включении питания
            if ( Uc >= Uc_min )
            {
                msud_output.state = MSUD_RESET;
            }

            break;
        }

    case MSUD_RESET:
        {
            // Общий сброс
            reset();
            // Ожидание загрузки
            load_timer->start();

            break;
        }

    case MSUD_READY:
        {
            // Основной цикл работы МСУД
            main_loop(t, dt);
            break;
        }
    }

    // Если напряжение питания упало ниже минимально допустимого
    // МСУД переходит в выключенное состояние
    if (Uc < Uc_min)
        msud_output.state = MSUD_OFF;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MSUD::reset()
{
    // Снимаем все управляющие сигналы
    msud_output = msud_output_t();
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MSUD::main_loop(double t, double dt)
{
    Q_UNUSED(t)
    Q_UNUSED(dt)

    // Подаем питание на реле KV23 (временно, потом будем считать отключения ГВ)
    msud_output.kv23_on = true;

    motor_fans_control(t, dt);

    brake_cylinders_pressure_control(t, dt);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MSUD::motor_fans_control(double t, double dt)
{
    Q_UNUSED(t)
    Q_UNUSED(dt)

    // Тики таймеров
    normalFreqTimer->step(t, dt);
    lowFreqTimer->step(t, dt);
    fansBustTimer->step(t, dt);
    runOutTimer->step(t, dt);

    // Признак работы без ПЧФ, только на нормальной частоте
    bool is_Norm_Freq_Only = (!msud_input.is_PCHF_On) || (is_pchf_ignored);

    // Проверяем, запущены ли венты
    bool fans_run = true;

    for (size_t i = 0; i < msud_input.mv_state.size(); ++i)
        fans_run = fans_run && msud_input.mv_state[i];


    if (!is_Norm_Freq_Only)
    {
        // Работаем при включенном ПЧФ
        bool is_low_freq = msud_output.mv_freq_low[MV1] ||
                msud_output.mv_freq_low[MV2] ||
                msud_output.mv_freq_low[MV3];

        bool is_norm_freq = msud_output.mv_freq_norm[MV1] ||
                msud_output.mv_freq_norm[MV2] ||
                msud_output.mv_freq_norm[MV3];

        msud_output.is_MV_low_freq = fans_run && is_low_freq;

        if (fans_run)
        {
            if (msud_input.Ia[TRAC_MOTOR1] <= I_fan_sw_min)
            {
                if (!lowFreqTimer->isStarted() && !is_low_freq)
                    lowFreqTimer->start();
            }

            if (msud_input.Ia[TRAC_MOTOR1] >= I_fan_sw_max)
            {
                if (!normalFreqTimer->isStarted() && !is_norm_freq)
                    normalFreqTimer->start();
            }
        }
        else
        {
            for (size_t i = 0; i < msud_output.mv_freq_low.size(); ++i)
            {
                msud_output.mv_freq_low[i] = true;
                msud_output.mv_freq_norm[i] = false;
            }
        }
    }
    else
    {
        msud_output.is_MV_low_freq = false;
        lowFreqTimer->stop();
        normalFreqTimer->stop();
        runOutTimer->stop();

        if (!fansBustTimer->isStarted())
            fansBustTimer->start();
    }
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MSUD::brake_cylinders_pressure_control(double t, double dt)
{
    Q_UNUSED(t)
    Q_UNUSED(dt)

    bool is_TC_full = false;

    for (size_t i = 0; i < msud_output.TC_full.size(); ++i)
    {
        msud_output.TC_full[i] = msud_input.TC_press[i] > msud_output.TC_min_press;
        is_TC_full |= msud_output.TC_full[i];
    }

    if (is_TC_full)
    {
        msud_output.TC_status = MSUD_STATUS_BLINK;
    }
    else
    {
        msud_output.TC_status = MSUD_STATUS_OFF;
    }
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MSUD::slotLoadTimer()
{
    load_timer->stop();
    msud_output.state = MSUD_READY;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MSUD::slotNormalFreqTimer()
{
    if (!fansBustTimer->isStarted())
    {
        fansBustTimer->start();
        fans_count = MV1;
        normalFreqTimer->stop();
    }
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MSUD::slotLowFreqTimer()
{
    for (size_t i = 0; i < msud_output.mv_freq_norm.size(); ++i)
    {
        msud_output.mv_freq_norm[i] = false;        
    }

    if (!runOutTimer->isStarted())
        runOutTimer->start();

    lowFreqTimer->stop();
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MSUD::slotFansBustTimer()
{
    msud_output.mv_freq_low[fans_count] = false;
    msud_output.mv_freq_norm[fans_count] = true;
    fans_count++;

    if (fans_count == msud_output.mv_freq_norm.size())
    {
        fans_count = MV1;
        fansBustTimer->stop();
    }
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MSUD::slotRunOutTimer()
{
    for (size_t i = 0; i < msud_output.mv_freq_low.size(); ++i)
    {
        msud_output.mv_freq_low[i] = true;
        msud_output.mv_freq_norm[i] = false;
    }

    runOutTimer->stop();
}
