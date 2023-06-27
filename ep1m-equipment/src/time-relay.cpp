#include    "time-relay.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
TimeRelay::TimeRelay(size_t num_contacts,
                     bool is_On_delay,
                     QObject *parent) : Relay(num_contacts, parent)
  , timer(new Timer(0.1, false))
  , Uc(0.0)
  , U_nom(110)
  , Rc(300)
  , start_level(0.7)
  , is_started(false)
  , is_On_delay(is_On_delay)
{
    timer->firstProcess(false);
    connect(timer, &Timer::process, this, &TimeRelay::slotTimeoutProcess);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
TimeRelay::~TimeRelay()
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TimeRelay::setTimeout(double timeout)
{
    timer->setTimeout(timeout);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TimeRelay::setControlVoltage(double Uc)
{
    this->Uc = Uc;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
double TimeRelay::getCurrent() const
{
    return getY(0) + Uc / Rc;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TimeRelay::step(double t, double dt)
{
    timer->step(t, dt);
    Relay::step(t, dt);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TimeRelay::setVoltage(double U)
{
    this->U = U;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TimeRelay::onDelayProcess()
{
    if ( (Uc >= U_nom * start_level) && !is_started)
    {
        timer->start();
        is_started = true;
    }

    if ( (Uc < U_nom * start_level) && is_started)
    {
        setVoltage(0.0);
        is_started = false;
    }
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TimeRelay::offDelayProcess()
{
    if ( (Uc >= U_nom * start_level) )
    {
        setVoltage(Uc);
    }

    if ( (Uc < U_nom * start_level) && !timer->isStarted())
    {
        timer->start();
    }
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TimeRelay::preStep(state_vector_t &Y, double t)
{
    if (is_On_delay)
        onDelayProcess();
    else
        offDelayProcess();


    Relay::preStep(Y, t);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TimeRelay::ode_system(const state_vector_t &Y,
                           state_vector_t &dYdt,
                           double t)
{
    Relay::ode_system(Y, dYdt, t);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TimeRelay::load_config(CfgReader &cfg)
{
    QString secName = "Device";
    cfg.getDouble(secName, "U_nom", U_nom);

    Relay::load_config(cfg);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TimeRelay::slotTimeoutProcess()
{
    setVoltage(Uc * static_cast<double>(is_On_delay));
    timer->stop();
}
