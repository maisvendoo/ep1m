#ifndef     VIP_5600_H
#define     VIP_5600_H

#include    "device.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class RectInvertConverter : public Device
{
public:

    RectInvertConverter(QObject *parent = Q_NULLPTR);

    ~RectInvertConverter();

private:

    void preStep(state_vector_t &Y, double t);

    void ode_system(const state_vector_t &Y, state_vector_t &dYdt, double t);

    void load_config(CfgReader &cfg);
};

#endif // VIP_5600_H
