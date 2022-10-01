#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepMSUD(double t, double dt)
{
    msud->setPowerVoltage(Ucc * static_cast<double>(tumblers_panel->getTumblerState(TUMBLER_MSUD)));
    msud->setInputData(msud_input);
    msud->step(t, dt);
}
