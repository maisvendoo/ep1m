#ifndef     MSUD_H
#define     MSUD_H

#include    "device.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class MSUD : public Device
{
public:

    MSUD(QObject *parent = Q_NULLPTR);

    ~MSUD() override;

private:

     void ode_system(const state_vector_t &Y,
                     state_vector_t &dYdt,
                     double t) override;
};

#endif // MSUD_H
