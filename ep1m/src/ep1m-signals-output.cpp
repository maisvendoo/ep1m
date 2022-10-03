#include    "ep1m.h"

void EP1m::signalsOutput()
{
    analogSignal[SIGNAL_UNLOCK_KEY] = static_cast<float>(tumblers_panel->getUnlockKeyState());

    analogSignal[SIGNAL_TUMBLER_MSUD] = static_cast<float>(tumblers_panel->getTumblerState(TUMBLER_MSUD));
    analogSignal[SIGNAL_TUMBLER_LOCK_VVK] = static_cast<float>(tumblers_panel->getTumblerState(TUMBLER_LOCK_VVK));
    analogSignal[SIGNAL_TUMBLER_PANT1] = static_cast<float>(tumblers_panel->getTumblerState(TUMBLER_PANT1));
    analogSignal[SIGNAL_TUMBLER_PANT2] = static_cast<float>(tumblers_panel->getTumblerState(TUMBLER_PANT2));
    analogSignal[SIGNAL_TUMBLER_RETURN_PROTECTION] = static_cast<float>(tumblers_panel->getTumblerState(TUMBLER_RETURN_PROTECTION));
    analogSignal[SIGNAL_TUMBLER_MAIN_SWITCH] = static_cast<float>(tumblers_panel->getTumblerState(TUMBLER_MAIN_SWITCH));
    analogSignal[SIGNAL_TUMBLER_AUX_MACHINES] = static_cast<float>(tumblers_panel->getTumblerState(TUMBLER_AUX_MACHINES));
    analogSignal[SIGNAL_TUMBLER_COMPRESSOR] = static_cast<float>(tumblers_panel->getTumblerState(TUMBLER_COMPRESSOR));
    analogSignal[SIGNAL_TUMBLER_MOTOR_FAN1] = static_cast<float>(tumblers_panel->getTumblerState(TUMBLER_MOTOR_FAN1));
    analogSignal[SIGNAL_TUMBLER_MOTOR_FAN2] = static_cast<float>(tumblers_panel->getTumblerState(TUMBLER_MOTOR_FAN2));
    analogSignal[SIGNAL_TUMBLER_MOTOR_FAN3] = static_cast<float>(tumblers_panel->getTumblerState(TUMBLER_MOTOR_FAN3));
    analogSignal[SIGNAL_TUMBLER_EPT] = static_cast<float>(tumblers_panel->getTumblerState(TUMBLER_EPT));

    analogSignal[SIGNAL_PANT1] = static_cast<float>(pant[PANT1]->getHeight());
    analogSignal[SIGNAL_PANT2] = static_cast<float>(pant[PANT2]->getHeight());

    analogSignal[SIGNAL_REVERS] = km->getReversHandlePos();
    analogSignal[SIGNAL_KONTROLLER] = km->getHandlePosition();

    analogSignal[STRELKA_U_KS] = static_cast<float>(main_switch->getU_out() / 30000.0);

    analogSignal[LAMP_GV] = static_cast<float>(main_switch->getState());

    analogSignal[SIGNAL_WHEEL1] = static_cast<float>(dir * wheel_rotation_angle[0] / 2.0 / Physics::PI);
    analogSignal[SIGNAL_WHEEL2] = static_cast<float>(dir * wheel_rotation_angle[1] / 2.0 / Physics::PI);
    analogSignal[SIGNAL_WHEEL3] = static_cast<float>(dir * wheel_rotation_angle[2] / 2.0 / Physics::PI);
    analogSignal[SIGNAL_WHEEL4] = static_cast<float>(dir * wheel_rotation_angle[3] / 2.0 / Physics::PI);
    analogSignal[SIGNAL_WHEEL5] = static_cast<float>(dir * wheel_rotation_angle[4] / 2.0 / Physics::PI);
    analogSignal[SIGNAL_WHEEL6] = static_cast<float>(dir * wheel_rotation_angle[5] / 2.0 / Physics::PI);
}
