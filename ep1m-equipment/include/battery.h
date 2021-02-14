#ifndef     BATTERY_H
#define     BATTERY_H

#include    "device.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class Battery : public Device
{
public:

    Battery(QObject *parent = Q_NULLPTR);

    ~Battery();

    double getVoltage() const;

    double getCargeCurrent() const;

    void setLoadCurrent(double In) { this->In = In; }

    void setChargeVoltage(double U_gen);

private:

    /// Внутреннее сопротивление батареи
    double  r;

    /// Добавочное сопротивление в цепи заряда
    double  Rd;

    /// Ток, потребляемый нагрузкой
    double  In;

    /// Ток заряда/разряда
    double  Ib;

    /// Максимальная ЭДС
    double  Emax;

    /// Минимальная ЭДС
    double  Emin;

    /// Емкость, А*ч
    double  C;

    /// Напряжение заряда
    double  U_gen;

    void preStep(state_vector_t &Y, double t);

    void ode_system(const state_vector_t &Y, state_vector_t &dYdt, double t);

    void load_config(CfgReader &cfg);
};

#endif // BATTERY_H
