#include    "msud.h"

#include    "defines.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
MSUD::MSUD(QObject *parent) : Device(parent)
  , Uc(0.0)
  , state(MSUD_OFF)
  , Uc_min(40.0)
  , load_time(2.0)
  , load_timer(Q_NULLPTR)
  , is_fans_low_freq(true)
  , normalFreqTimer(new Timer(80.0, false))
  , lowFreqTimer(new Timer(80.0, false))
  , fansBustTimer(new Timer(2.5, true))
  , runOutTimer(new Timer(10.0, false))
  , fans_count(0)
{
    normalFreqTimer->setTimeout(80.0);
    connect(normalFreqTimer, &Timer::process, this, &MSUD::slotNormalFreqTimer);

    lowFreqTimer->setTimeout(80.0);
    connect(lowFreqTimer, &Timer::process, this, &MSUD::slotLowFreqTimer);

    fansBustTimer->setTimeout(2.5);
    connect(fansBustTimer, &Timer::process, this, &MSUD::slotFansBustTimer);

    runOutTimer->setTimeout(10.0);
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

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MSUD::stateProcess(double t, double dt)
{
    switch (state)
    {
    case MSUD_OFF:
        {
            // Переход в режим общего сброса при включении питания
            if ( Uc >= Uc_min )
            {
                state = MSUD_RESET;
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
        state = MSUD_OFF;
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
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MSUD::motor_fans_control(double t, double dt)
{
    Q_UNUSED(t)
    Q_UNUSED(dt)

    if (msud_input.Ia[TRAC_MOTOR1] <= 480)
    {
        if (!lowFreqTimer->isStarted())
            lowFreqTimer->start();
    }

    if (msud_input.Ia[TRAC_MOTOR1] >= 510)
    {
        if (!normalFreqTimer->isStarted())
            normalFreqTimer->start();
    }


    normalFreqTimer->step(t, dt);
    lowFreqTimer->step(t, dt);
    fansBustTimer->step(t, dt);
    runOutTimer->step(t, dt);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MSUD::slotLoadTimer()
{
    load_timer->stop();
    state = MSUD_READY;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MSUD::slotNormalFreqTimer()
{
    if (!fansBustTimer->isStarted())
        fansBustTimer->start();

    fans_count = MV1;
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
    }

    runOutTimer->stop();
}
