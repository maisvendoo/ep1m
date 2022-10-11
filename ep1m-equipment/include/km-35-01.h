#ifndef     KM_35_01_H
#define     KM_35_01_H

#include    "device.h"

//------------------------------------------------------------------------------
//  Контроллер машиниста электровоза ЭП1м(п)
//------------------------------------------------------------------------------
class TracController : public Device
{
public:

    TracController(QObject *parent = Q_NULLPTR);

    ~TracController();

    bool isZero() const
    {
        return mode_pos == 0;
    }

    bool isTraction() const
    {
        return mode_pos == 1;
    }

    bool isBrake()
    {
        return mode_pos == -1;
    }

    bool isContacts15_16 () const
    {
        return (trac_level == 0) && (brake_level == 0);
    }

    void setFwdKeyState(bool key_state) { fwd_key_state = key_state; }

    void setBwdKeyState(bool key_state) { bwd_key_state = key_state; }

    float getReversHandlePos() const { return static_cast<float>(revers_pos); }

    float getHandlePosition() const;

    double getTracLevel() const { return static_cast<double>(trac_level) / 100.0; }

    double getBrakeLevel() const { return static_cast<double>(brake_level) / 100.0; }

private:

    /// Позиция, определяющая состояние схемы
    /// (0 - схема разобрана, 1 - подготовка тяги, 2 - подготовка рекуперации)
    int mode_pos;
    int mode_pos_old;

    bool fwd_key_state;
    bool old_fwd_key_state;

    bool bwd_key_state;
    bool old_bwd_key_state;

    int revers_pos;

    QString reversSoundName;

    QString mainHandleSoundName;

    bool old_traction_key;

    bool old_brake_key;

    int trac_level;

    int brake_level;

    int dir;

    Timer tracTimer;

    Timer brakeTimer;

    Trigger traction;

    Trigger brake;

    void preStep(state_vector_t &Y, double t) override;

    void ode_system(const state_vector_t &Y,
                    state_vector_t &dYdt,
                    double t) override;

    void load_config(CfgReader &cfg) override;

    void stepKeysControl(double t, double dt) override;

    void processDiscretePositions(bool key_state, bool old_key_state, int dir);

private slots:

    void slotTracLevelProcess();

    void slotBrakeLevelProcess();
};

#endif // KM_35_01_H
