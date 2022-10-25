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

    km11 = new Relay(2);
    km11->read_custom_config(config_dir + QDir::separator() + "mk-69");
    km11->setInitContactState(0, false);
    km11->setInitContactState(1, false);

    km12 = new Relay(2);
    km12->read_custom_config(config_dir + QDir::separator() + "mk-69");
    km12->setInitContactState(0, false);
    km12->setInitContactState(1, false);

    km13 = new Relay(2);
    km13->read_custom_config(config_dir + QDir::separator() + "mk-69");
    km13->setInitContactState(0, false);
    km13->setInitContactState(1, false);

    for (size_t i = 0; i < motor_fan.size(); ++i)
    {
        motor_fan[i] = new MotorFan(i + 1);
    }

    // Тумблер "ПЧФ" включен по-умолчанию
    tumblers[TUMBLER_PCHF].set();
}
