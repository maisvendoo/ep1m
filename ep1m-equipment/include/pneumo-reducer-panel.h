#ifndef     PNEUMO_REDUCER_PANEL_H
#define     PNEUMO_REDUCER_PANEL_H

#include    "device.h"
#include    "pneumo-reducer.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class PneumoReducerPanel : public Device
{
public:

    PneumoReducerPanel(QObject *parent = Q_NULLPTR);

    ~PneumoReducerPanel();

    void step(double t, double dt) override;

    void setPipeLinePressure(double pPL)
    {
        this->pPL = pPL;
    }

    double getOutputFlow1() const
    {
        return Q1;
    }

    double getOutputFlow5() const
    {
        return Q5;
    }

    void setPressure1(double p_out1)
    {
        this->p_out1 = p_out1;
    }

    void setPressure5(double p_out5)
    {
        this->p_out5 = p_out5;
    }

private:

    /// Давление в питательной магистрали
    double pPL;

    /// Уставка редуктора KP1
    double p_kp1;

    /// Уставка редуктора KP5
    double p_kp5;

    /// Редуктор питания клапана замещения Y4
    PneumoReducer *kp1;

    /// Редуктор питания кклапана ЭТ Y5
    PneumoReducer *kp5;

    /// Расход из редуктора KP1
    double Q1;

    /// Расход из редуктора KP5
    double Q5;

    /// Давление на выходе KP1
    double p_out1;

    /// Давление на выходе KP5
    double p_out5;

    enum
    {
        NUM_COEFFS = 10
    };

    std::array<double, NUM_COEFFS> K;

    void preStep(state_vector_t &Y, double t);

    void ode_system(const state_vector_t &Y, state_vector_t &dYdt, double t);

    void load_config(CfgReader &cfg) override;
};

#endif // PNEUMO_REDUCER_PANEL_H
