#ifndef     MOTOR_FAN_H
#define     MOTOR_FAN_H

#include    "device.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class MotorFan : public Device
{
public:

    MotorFan(size_t idx = 1, QObject *parent = Q_NULLPTR);

    ~MotorFan();

    void setU_power(double value);

    void setFreq(double freq) { f = freq; }

    bool isNoReady() const;

private:

    /// Индекс (по сути номер мотор-вентилятора в схеме)
    size_t  idx;

    double  Mmax;

    double  s_kr_nom;

    double  Un;

    double  U_power;

    double  omega0;

    double  omega_nom;

    double  kr;

    double  J;

    double  is_no_ready;

    /// Текущая частота питающего напряжения
    double f;

    bool is_low_freq;

    QString sndName;

    /// Номинальная частота питающего напряжения
    const double fn = 50.0;

    void preStep(state_vector_t &Y, double t);

    void ode_system(const state_vector_t &Y, state_vector_t &dYdt, double t);

    void load_config(CfgReader &cfg);
};

#endif // MOTOR_FAN_H
