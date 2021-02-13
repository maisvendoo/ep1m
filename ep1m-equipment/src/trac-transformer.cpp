#include    "trac-transformer.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
TractionTransformer::TractionTransformer(QObject *parent) : Device(parent)
  , U1(0.0)
  , Kcc(0.38 / 25.0)
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
TractionTransformer::~TractionTransformer()
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TractionTransformer::ode_system(const state_vector_t &Y,
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
void TractionTransformer::stepDiscrete(double t, double dt)
{
    if (qAbs(U1) >= 19000.0)
        emit soundPlay("Trac_Transformer");
    else
        emit soundStop("Trac_Transformer");

    U2cc = Kcc * U1;
}
