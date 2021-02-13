#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepControlPower(double t, double dt)
{
    battery->setChargeVoltage(power_supply->getChargeVoltage());
    battery->setLoadCurrent(Icc);
    battery->step(t, dt);

    power_supply->setBatVoltage(battery->getVoltage());
    power_supply->setBatChargeCurrent(battery->getCargeCurrent());
    power_supply->setInputVoltage(trac_trans->getControlPowerVoltage());
    power_supply->step(t, dt);

    Ucc = power_supply->getPowerControlVoltage();
}
