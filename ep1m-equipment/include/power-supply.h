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

    void setInputVoltage(double U_in);

private:

    /// Входное напряжение переменного тока
    double U_in;

    /// Выходное напряжение подзаряда аккумуляторной батареи
    double U_bat;

    void ode_system(const state_vector_t &Y,
                    state_vector_t &dYdt,
                    double t) override;

    void stepDiscrete(double t, double dt) override;
};

#endif // POWER_SUPPLY_H
