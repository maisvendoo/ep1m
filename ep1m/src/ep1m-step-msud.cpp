#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepMSUD(double t, double dt)
{
    for (size_t i = 0; i < motor_fan.size(); ++i)
        msud_input.mv_state[i] = !motor_fan[i]->isNoReady();

    //msud_input.Ia[TRAC_MOTOR1] = 1300.0 * km->getTracLevel();

    msud_input.tumbler_MPK = tumblers[TUMBLER_MPK].getState();
    msud_input.is_automatic_mode = tumblers[TUMBLER_AUTO_MODE].getState();
    msud_input.is_PCHF_On = tumblers[TUMBLER_PCHF].getState();

    msud->setPowerVoltage(Ucc * static_cast<double>(tumblers_panel->getTumblerState(TUMBLER_MSUD)));
    msud->setInputData(msud_input);
    msud->step(t, dt);
}
