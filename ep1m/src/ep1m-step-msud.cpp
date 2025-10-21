#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepMSUD(const double& t, const double& dt)
{
    if (tumblers_panel[CAB1]->getTumblerState(EP1MTumblersPanel::TUMBLER_MSUD))
    {
        // Состояние из кабины 1
        msud_input.tumbler_MPK = tumblers[TUMBLER_MPK][CAB1].getState();
        msud_input.is_automatic_mode = tumblers[TUMBLER_AUTO_MODE][CAB1].getState();
        msud_input.is_PCHF_On = tumblers[TUMBLER_PCHF][CAB1].getState();

        msud_input.is_auto_reg = tumblers[TUMBLER_AUTO_MODE][CAB1].getState();
        msud_input.km_trac_level = km[CAB1]->getTracLevel();
        msud_input.km_brake_level = km[CAB1]->getBrakeLevel();
        msud_input.km_ref_velocity_level = km[CAB1]->getRefSpeedLevel();

        msud_input.is_emergency_brake = (brake_crane[CAB1]->getPositionName() == "VI") ||
                                        epk[CAB1]->getEmergencyBrakeContact();
    }

    if (tumblers_panel[CAB2]->getTumblerState(EP1MTumblersPanel::TUMBLER_MSUD))
    {
        // Состояние из кабины 2
        msud_input.tumbler_MPK = tumblers[TUMBLER_MPK][CAB2].getState();
        msud_input.is_automatic_mode = tumblers[TUMBLER_AUTO_MODE][CAB2].getState();
        msud_input.is_PCHF_On = tumblers[TUMBLER_PCHF][CAB2].getState();

        msud_input.is_auto_reg = tumblers[TUMBLER_AUTO_MODE][CAB2].getState();
        msud_input.km_trac_level = km[CAB2]->getTracLevel();
        msud_input.km_brake_level = km[CAB2]->getBrakeLevel();
        msud_input.km_ref_velocity_level = km[CAB2]->getRefSpeedLevel();

        msud_input.is_emergency_brake = (brake_crane[CAB2]->getPositionName() == "VI") ||
                                        epk[CAB2]->getEmergencyBrakeContact();
    }

    for (size_t i = 0; i < motor_fan.size(); ++i)
        msud_input.mv_state[i] = !motor_fan[i]->isNoReady();

    // Мерям токи тяговых двигателей
    for (size_t i = 0; i < msud_input.Ia.size(); ++i)
    {
        msud_input.Ia[i] = trac_motor[i]->getAncorCurrent();
        msud_input.If[i] = trac_motor[i]->getFieldCurrent();
    }

    for (size_t i = 0; i < brake_mech.size(); ++i)
    {
        msud_input.TC_press[i] = brake_mech[i]->getBCpressure();
    }

    msud_input.V_cur = qAbs(wheel_omega[0] * wheel_diameter[0] * Physics::kmh / 2.0);

    bool is_MSUD_on = km43->getContactState(1);

    msud->setPowerVoltage(Ucc * static_cast<double>(is_MSUD_on));
    msud->setInputData(msud_input);
    msud->step(t, dt);
}
