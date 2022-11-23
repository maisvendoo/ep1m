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

    void setPressure(double p) { this->p = p; }

    void setTracValveState(double trac_valve_state)
    {
        this->trac_valve_state = trac_valve_state;
    }

    void setBrakeValveState(double brake_valve_state)
    {
        this->brake_valve_state = brake_valve_state;
    }

private:

    /// Время переключения с одного положения на другое
    double tau;

    /// Состояние вентиля "тяга"
    bool trac_valve_state;

    /// Состояние вентиля "торможение"
    bool brake_valve_state;

    /// Рабочее давление
    double p;

    void preStep(state_vector_t &Y, double t);

    void ode_system(const state_vector_t &Y, state_vector_t &dYdt, double t);

    void load_config(CfgReader &cfg);
};

#endif // PKD15_H
