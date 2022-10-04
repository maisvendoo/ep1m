#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::signalsOutput()
{
    analogSignal[SIGNAL_UNLOCK_KEY] = TO_FLOAT(tumblers_panel->getUnlockKeyState());

    analogSignal[SIGNAL_TUMBLER_MSUD] = TO_FLOAT(tumblers_panel->getTumblerState(TUMBLER_MSUD));
    analogSignal[SIGNAL_TUMBLER_LOCK_VVK] = TO_FLOAT(tumblers_panel->getTumblerState(TUMBLER_LOCK_VVK));
    analogSignal[SIGNAL_TUMBLER_PANT1] = TO_FLOAT(tumblers_panel->getTumblerState(TUMBLER_PANT1));
    analogSignal[SIGNAL_TUMBLER_PANT2] = TO_FLOAT(tumblers_panel->getTumblerState(TUMBLER_PANT2));
    analogSignal[SIGNAL_TUMBLER_RETURN_PROTECTION] = TO_FLOAT(tumblers_panel->getTumblerState(TUMBLER_RETURN_PROTECTION));
    analogSignal[SIGNAL_TUMBLER_MAIN_SWITCH] = TO_FLOAT(tumblers_panel->getTumblerState(TUMBLER_MAIN_SWITCH));
    analogSignal[SIGNAL_TUMBLER_AUX_MACHINES] = TO_FLOAT(tumblers_panel->getTumblerState(TUMBLER_AUX_MACHINES));
    analogSignal[SIGNAL_TUMBLER_COMPRESSOR] = TO_FLOAT(tumblers_panel->getTumblerState(TUMBLER_COMPRESSOR));
    analogSignal[SIGNAL_TUMBLER_MOTOR_FAN1] = TO_FLOAT(tumblers_panel->getTumblerState(TUMBLER_MOTOR_FAN1));
    analogSignal[SIGNAL_TUMBLER_MOTOR_FAN2] = TO_FLOAT(tumblers_panel->getTumblerState(TUMBLER_MOTOR_FAN2));
    analogSignal[SIGNAL_TUMBLER_MOTOR_FAN3] = TO_FLOAT(tumblers_panel->getTumblerState(TUMBLER_MOTOR_FAN3));
    analogSignal[SIGNAL_TUMBLER_EPT] = TO_FLOAT(tumblers_panel->getTumblerState(TUMBLER_EPT));

    analogSignal[SIGNAL_PANT1] = TO_FLOAT(pant[PANT1]->getHeight());
    analogSignal[SIGNAL_PANT2] = TO_FLOAT(pant[PANT2]->getHeight());

    analogSignal[SIGNAL_REVERS] = km->getReversHandlePos();
    analogSignal[SIGNAL_KONTROLLER] = km->getHandlePosition();

    analogSignal[STRELKA_U_KS] = TO_FLOAT(main_switch->getU_out() / 30000.0);

    analogSignal[LAMP_GV] = TO_FLOAT(signals_module->getLampState(SM_GV));
    analogSignal[LAMP_MK1] = TO_FLOAT(signals_module->getLampState(SM_MK1));
    analogSignal[LAMP_MK2] = TO_FLOAT(signals_module->getLampState(SM_MK2));

    analogSignal[LAMP_MV1] = TO_FLOAT(signals_module->getLampState(SM_V1));
    analogSignal[LAMP_MV2] = TO_FLOAT(signals_module->getLampState(SM_V2));
    analogSignal[LAMP_MV3] = TO_FLOAT(signals_module->getLampState(SM_V3));

    analogSignal[STRELKA_GR] = TO_FLOAT(main_res->getPressure() / 1.6);

    analogSignal[SIGNAL_WHEEL1] = TO_FLOAT(dir * wheel_rotation_angle[0] / 2.0 / Physics::PI);
    analogSignal[SIGNAL_WHEEL2] = TO_FLOAT(dir * wheel_rotation_angle[1] / 2.0 / Physics::PI);
    analogSignal[SIGNAL_WHEEL3] = TO_FLOAT(dir * wheel_rotation_angle[2] / 2.0 / Physics::PI);
    analogSignal[SIGNAL_WHEEL4] = TO_FLOAT(dir * wheel_rotation_angle[3] / 2.0 / Physics::PI);
    analogSignal[SIGNAL_WHEEL5] = TO_FLOAT(dir * wheel_rotation_angle[4] / 2.0 / Physics::PI);
    analogSignal[SIGNAL_WHEEL6] = TO_FLOAT(dir * wheel_rotation_angle[5] / 2.0 / Physics::PI);
}
