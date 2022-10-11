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
}
