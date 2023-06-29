#include    "epv.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
ElectroPneumoValve::ElectroPneumoValve(QObject *parent) : Relay(1, parent)
  , Vk(0.002)
  , Q_in(0.0)
  , Q_out(0.0)
  , p_out(0.0)
{
    this->setInitContactState(0, false);
    std::fill(K.begin(), K.end(), 0);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
ElectroPneumoValve::~ElectroPneumoValve()
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void ElectroPneumoValve::preStep(state_vector_t &Y, double t)
{
    Relay::preStep(Y, t);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void ElectroPneumoValve::ode_system(const state_vector_t &Y,
                                    state_vector_t &dYdt,
                                    double t)
{
    Relay::ode_system(Y, dYdt, t);

    double Q1 = K[1] * (Y[1] - p_out);

    double Q2 = K[2] * p_out;

    double u1 = static_cast<double>(!getContactState(0));

    double u2 = static_cast<double>(getContactState(0));

    Q_out = Q1 * u1 - Q2 * u2;

    dYdt[1] = (Q_in - Q1 * u1) / Vk;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void ElectroPneumoValve::load_config(CfgReader &cfg)
{
    Relay::load_config(cfg);

    QString secName = "Device";

    cfg.getDouble(secName, "Vk", Vk);

    for (size_t i = 0; i < K.size(); ++i)
    {
        QString coeff = QString("K%1").arg(i);
        cfg.getDouble(secName, coeff, K[i]);
    }
}
