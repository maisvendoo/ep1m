#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepMSUD(double t, double dt)
{
    for (size_t i = 0; i < motor_fan.size(); ++i)
        msud_input.mv_state[i] = !motor_fan[i]->isNoReady();

    // Мерям токи тяговых двигателей
    for (size_t i = 0; i < msud_input.Ia.size(); ++i)
    {
        msud_input.Ia[i] = trac_motor[i]->getAncorCurrent();
        msud_input.If[i] = trac_motor[i]->getFieldCurrent();
    }

    msud_input.tumbler_MPK = tumblers[TUMBLER_MPK].getState();
    msud_input.is_automatic_mode = tumblers[TUMBLER_AUTO_MODE].getState();
    msud_input.is_PCHF_On = tumblers[TUMBLER_PCHF].getState();

    for (size_t i = 0; i < brake_mech.size(); ++i)
    {
        msud_input.TC_press[i] = brake_mech[i]->getBrakeCylinderPressure();
    }

    msud->setPowerVoltage(Ucc * static_cast<double>(tumblers_panel->getTumblerState(TUMBLER_MSUD)));
    msud->setInputData(msud_input);
    msud->step(t, dt);
}
