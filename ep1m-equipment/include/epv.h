#ifndef     EPV_H
#define     EPV_H

#include    "relay.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class ElectroPneumoValve : public Relay
{
public:

    ElectroPneumoValve(QObject *parent = Q_NULLPTR);

    ~ElectroPneumoValve();

    void setInputFlow(double Q_in)
    {
        this->Q_in = Q_in;
    }

    double getInputPressure() const
    {
        return getY(1);
    }

    double getOutputFlow() const
    {
        return Q_out;
    }

    void setOutputPressure(double p_out)
    {
        this->p_out = p_out;
    }

private:

    /// Эквивалентный объем полостей ЭПВ
    double Vk;

    /// Расход на входе ЭПВ
    double Q_in;

    /// Расход на выходе ЭПВ
    double Q_out;

    /// Давление на выходе ЭПВ
    double p_out;

    enum
    {
        NUM_COEFFS = 10
    };

    std::array<double, NUM_COEFFS> K;

    void preStep(state_vector_t &Y, double t) override;

    void ode_system(const state_vector_t &Y,
                    state_vector_t &dYdt,
                    double t) override;

    void load_config(CfgReader &cfg) override;
};

#endif // EPV_H
