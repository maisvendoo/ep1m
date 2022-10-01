#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepPanel(double t, double dt)
{
    tumblers_panel->setControl(keys);
    tumblers_panel->step(t, dt);

    km->setControl(keys);
    km->setFwdKeyState(tumblers[SWITCH_REVERS_FWD].getState());
    km->setBwdKeyState(tumblers[SWITCH_REVERS_BWD].getState());
    km->step(t, dt);
}
