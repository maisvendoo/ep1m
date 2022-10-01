#include    "ep1m.h"

#include    <QDir>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::initControlPower()
{
    battery = new Battery();
    battery->read_custom_config(config_dir + QDir::separator() + "battery");

    power_supply = new PowerSupply();

    tumbler_power_supply.setOnSoundName("Tumbler_On");
    tumbler_power_supply.setOffSoundName("Tumbler_Off");

    button_main_swith_off.set();

    km5 = new Relay(1);
    km5->read_custom_config(config_dir + QDir::separator() + "mk-69");
    km5->setSoundName("KM5_On");
    km5->setInitContactState(0, false);
}
