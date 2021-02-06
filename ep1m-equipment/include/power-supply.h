#ifndef     POWER_SUPPLY_H
#define     POWER_SUPPLY_H

#include    "device.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class PowerSupply : public Device
{
public:

    PowerSupply(QObject *parent = Q_NULLPTR);

    ~PowerSupply() override;

private:

    void ode_system(const state_vector_t &Y,
                    state_vector_t &dYdt,
                    double t) override;
};

#endif // POWERSUPPLY_H
