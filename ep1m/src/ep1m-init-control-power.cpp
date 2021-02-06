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
}
