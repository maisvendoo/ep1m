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
{

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

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MSUD::main_loop(double t, double dt)
{
    Q_UNUSED(t)
    Q_UNUSED(dt)
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MSUD::slotLoadTimer()
{
    load_timer->stop();
    state = MSUD_READY;
}
