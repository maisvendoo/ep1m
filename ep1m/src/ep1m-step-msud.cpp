#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepMSUD(double t, double dt)
{
    for (size_t i = 0; i < motor_fan.size(); ++i)
        msud_input.mv_state[i] = !motor_fan[i]->isNoReady();

    msud->setPowerVoltage(Ucc * static_cast<double>(tumblers_panel->getTumblerState(TUMBLER_MSUD)));
    msud->setInputData(msud_input);
    msud->step(t, dt);
}
