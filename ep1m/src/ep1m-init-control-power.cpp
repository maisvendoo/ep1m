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

    tumblers[BUTTON_MAIN_SWITCH_OFF].set();

    km5 = new Relay(1);
    km5->read_custom_config(config_dir + QDir::separator() + "mk-69");
    km5->setSoundName("KM5_On");
    km5->setInitContactState(0, false);
}
