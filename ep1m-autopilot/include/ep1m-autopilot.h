#ifndef     EP1M_AUTOPILOT
#define     EP1M_AUTOPILOT

#include    <autopilot.h>
#include    <ep1m-autopilot-types.h>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class EP1mAutopilot : public Autopilot
{
public:

    EP1mAutopilot();

    ~EP1mAutopilot();

    auto_control_t *getControl() override;

    void step(double t, double dt) override;

    void initAutoBrakeControl(const QString& config_name,
                              const QString& custom_cfg_dir) override;

private:

    /// структура управляющих воздействий
    ep1m_control_t *auto_control = new ep1m_control_t();

    /// структура обратных связей
    ep1m_feedback_t *auto_feedback = nullptr;

    /// Максимальный ток якоря
    double Imax = 0.0;

    /// Тормозной контроллер
    AutopilotBrakeController *brake_control = new AutopilotBrakeController;

    void press_RB() override;

    void release_RB() override;

    void load_config(CfgReader &cfg) override;

    void preStep(state_vector_t &Y, double t) override;
};

#endif
