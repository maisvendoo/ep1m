#ifndef     EP1M_TUMBLERS_PANEL_H
#define     EP1M_TUMBLERS_PANEL_H

#include    "device.h"

enum
{
    TUMBLERS_NUMBER = 12
};

enum
{
    TUMBLER_MSUD = 0,
    TUMBLER_LOCK_VVK = 1,
    TUMBLER_PANT1 = 2,
    TUMBLER_PANT2 = 3,
    TUMBLER_RETURN_PROTECTION = 4,
    TUMBLER_MAIN_SWITCH = 5,

    TUMBLER_AUX_MACHINES = 6,
    TUMBLER_COMPRESSOR = 7,
    TUMBLER_MOTOR_FAN1 = 8,
    TUMBLER_MOTOR_FAN2 = 9,
    TUMBLER_MOTOR_FAN3 = 10,
    TUMBLER_EPT = 11
};

class EP1MTumblersPanel : public Device
{
public:

    EP1MTumblersPanel(QObject *parent = Q_NULLPTR);

    ~EP1MTumblersPanel();

private:

    void ode_system(const state_vector_t &Y, state_vector_t &dYdt, double t) override;

    void stepKeysControl(double t, double dt) override;
};

#endif // EP1M_TUMBLERS_PANEL_H
