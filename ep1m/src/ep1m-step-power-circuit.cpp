#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepPowerCircuit(double t, double dt)
{
    trac_trans->setInputVoltage(0.0);
    trac_trans->step(t, dt);
}
