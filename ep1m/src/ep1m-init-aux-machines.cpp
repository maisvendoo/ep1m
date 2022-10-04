#include    "ep1m.h"

#include    <QDir>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::initAuxMachines()
{
    freq_phase_conv = new FreqPhaseConverter();

    km7 = new Relay(2);
    km7->read_custom_config(config_dir + QDir::separator() + "mk-69");
    km7->setInitContactState(0, false);
    km7->setInitContactState(1, false);

    km8 = new Relay(2);
    km8->read_custom_config(config_dir + QDir::separator() + "mk-69");
    km8->setInitContactState(0, false);
    km8->setInitContactState(1, false);

    km9 = new Relay(2);
    km9->read_custom_config(config_dir + QDir::separator() + "mk-69");
    km9->setInitContactState(0, false);
    km9->setInitContactState(1, false);
}
