#include    "pneumo-reducer-panel.h"

#include    <QDir>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
PneumoReducerPanel::PneumoReducerPanel(QObject *parent) : Device(parent)
  , pPL(0.0)
  , p_kp1(0.15)
  , p_kp5(0.7)
  , kp1(new PneumoReducer())
  , kp5(new PneumoReducer())
  , Q1(0.0)
  , Q5(0.0)
  , p_out1(0.0)
  , p_out5(0.0)
{
    std::fill(K.begin(), K.end(), 0.0);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
PneumoReducerPanel::~PneumoReducerPanel()
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void PneumoReducerPanel::step(double t, double dt)
{
    kp1->setInputPressure(pPL);
    Q1 = K[1] * (kp1->getOutPressure() - p_out1);
    kp1->setQ_out(-Q1);
    kp1->step(t, dt);

    kp5->setInputPressure(pPL);
    Q5 = K[5] * (kp5->getOutPressure() - p_out5);
    kp5->setQ_out(-Q5);
    kp5->step(t, dt);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void PneumoReducerPanel::preStep(state_vector_t &Y, double t)
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void PneumoReducerPanel::ode_system(const state_vector_t &Y,
                                    state_vector_t &dYdt,
                                    double t)
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void PneumoReducerPanel::load_config(CfgReader &cfg)
{
    kp1->read_custom_config(custom_config_dir +
                            QDir::separator() +
                            "pneumo-reducer");

    kp5->read_custom_config(custom_config_dir +
                            QDir::separator() +
                            "pneumo-reducer");

    QString secName = "Device";

    cfg.getDouble(secName, "p_kp1", p_kp1);
    cfg.getDouble(secName, "p_kp5", p_kp5);

    kp1->setRefPressure(p_kp1);
    kp5->setRefPressure(p_kp5);

    for (size_t i = 1; i < K.size(); ++i)
    {
        QString coeff = QString("K%1").arg(i);
        cfg.getDouble(secName, coeff, K[i]);
    }
}
