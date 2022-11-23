#ifndef     PKD15_H
#define     PKD15_H

#include    "device.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class BrakeSwitcher : Device
{
public:

    BrakeSwitcher(QObject *parent = Q_NULLPTR);

    ~BrakeSwitcher();

private:

    void preStep(state_vector_t &Y, double t);

    void ode_system(const state_vector_t &Y, state_vector_t &dYdt, double t);

    void load_config(CfgReader &cfg);
};

#endif // PKD15_H
