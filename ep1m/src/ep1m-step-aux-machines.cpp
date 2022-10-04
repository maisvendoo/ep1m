#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepAuxMachines(double t, double dt)
{
    bool is_freq_conv_On = tumblers_panel->getTumblerState(TUMBLER_AUX_MACHINES);

    freq_phase_conv->setInputVoltage(trac_trans->getControlPowerVoltage() *
                                     static_cast<double>(is_freq_conv_On));

    freq_phase_conv->step(t, dt);
}
