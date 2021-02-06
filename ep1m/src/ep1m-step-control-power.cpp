#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepControlPower(double t, double dt)
{
    battery->step(t, dt);

    Ucc = max(0.0, battery->getVoltage());
}
