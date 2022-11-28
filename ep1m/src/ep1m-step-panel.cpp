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

    signals_module->setVoltage(
                Ucc * static_cast<double>(tumblers[TUMBLER_BS_002].getState()));

    setSignalsModuleInputs();
    signals_module->step(t, dt);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::setSignalsModuleInputs()
{
    signals_module->setLampInputSignal(SM_GV, main_switch->getState());
    signals_module->setLampInputSignal(SM_MK1, !main_compressor->isStarted());
    signals_module->setLampInputSignal(SM_MK2, !main_compressor->isStarted());

    signals_module->setLampInputSignal(SM_V1, motor_fan[MV1]->isNoReady());
    signals_module->setLampInputSignal(SM_V2, motor_fan[MV2]->isNoReady());
    signals_module->setLampInputSignal(SM_V3, motor_fan[MV3]->isNoReady());

    signals_module->setLampInputSignal(SM_LOW_FREQ, msud->getOutputData().is_MV_low_freq);

    for (size_t i = 0; i < brake_mech.size(); ++i)
    {
        signals_module->setLampInputSignal(SM_LAMP_TC3 + i,
                                           brake_mech[i]->getBrakeCylinderPressure() >
                                           msud->getOutputData().TC_min_press);
    }

    signals_module->setLampInputSignal(SM_TD1, fast_switch[TRAC_MOTOR1]->getContactState(2));
    signals_module->setLampInputSignal(SM_TD2, fast_switch[TRAC_MOTOR2]->getContactState(2));
    signals_module->setLampInputSignal(SM_TD3, fast_switch[TRAC_MOTOR3]->getContactState(2));
    signals_module->setLampInputSignal(SM_TD4, fast_switch[TRAC_MOTOR4]->getContactState(2));
    signals_module->setLampInputSignal(SM_TD5, fast_switch[TRAC_MOTOR5]->getContactState(2));
    signals_module->setLampInputSignal(SM_TD6, fast_switch[TRAC_MOTOR6]->getContactState(2));
}
