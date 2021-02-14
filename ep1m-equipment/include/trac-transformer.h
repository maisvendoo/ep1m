#ifndef     TRAC_TRANSFORMER_H
#define     TRAC_TRANSFORMER_H

#include    "device.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class TractionTransformer : public Device
{
public:

    TractionTransformer(QObject *parent = Q_NULLPTR);

    ~TractionTransformer() override;

    void setInputVoltage(double U1) { this->U1 = U1; }

    double getControlPowerVoltage() const { return U2cc; }

private:

    /// Напряжение на первичной обмотке
    double U1;

    /// Коэффициент передачи на обмотку питания цепей управления
    double Kcc;

    /// Напряжение обмотки питания собственных нужд
    double U2cc;

    void ode_system(const state_vector_t &Y,
                    state_vector_t &dYdt,
                    double t) override;

    void stepDiscrete(double t, double dt) override;
};


#endif // TRAC_TRANSFORMER_H
