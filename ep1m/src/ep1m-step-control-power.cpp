#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepControlPower(double t, double dt)
{
    Icc = km5->getCurrent() +
          safety_valve->getCurrent();

    battery->setChargeVoltage(power_supply->getChargeVoltage());
    battery->setLoadCurrent(Icc);
    battery->step(t, dt);

    km5->setVoltage(battery->getVoltage() *
                    static_cast<double>(tumblers[TUMBLER_POWER_SUPPLY_ON].getState()));
    km5->step(t, dt);

    power_supply->setBatVoltage(battery->getVoltage());
    power_supply->setBatChargeCurrent(battery->getCargeCurrent());
    power_supply->setInputVoltage(trac_trans->getControlPowerVoltage() * static_cast<double>(km5->getContactState(0)));
    power_supply->step(t, dt);

    Ucc = power_supply->getPowerControlVoltage();
}
