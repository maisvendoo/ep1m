#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepPanel(double t, double dt)
{
    tumblers_panel->setControl(keys);
    tumblers_panel->step(t, dt);
}
