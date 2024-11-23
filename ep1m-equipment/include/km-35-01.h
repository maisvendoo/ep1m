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

    bool isContacts5_6() const
    {
        return (revers_pos == 1) || (revers_pos == -1);
    }

    bool isContacts7_8() const
    {
        return (revers_pos == 1) || (revers_pos == -1);
    }

    bool isContacts9_10() const
    {
        return mode_pos == 1;
    }

    bool isContacts11_12() const
    {
        return mode_pos == -1;
    }

    bool isContscts3_4() const
    {
        return revers_pos == -1;
    }

    bool isContscts1_2() const
    {
        return revers_pos == 1;
    }

    bool isContacts13_14() const
    {
        return (mode_pos == 1) || (mode_pos == -1);
    }

    void setFwdKeyState(bool key_state) { fwd_key_state = key_state; }

    void setBwdKeyState(bool key_state) { bwd_key_state = key_state; }

    float getReversHandlePos() const { return static_cast<float>(revers_pos); }

    float getHandlePosition() const;

    double getTracLevel() const { return static_cast<double>(trac_level) / 100.0; }

    double getBrakeLevel() const { return static_cast<double>(brake_level) / 100.0; }

    double getRefSpeedLevel() const { return static_cast<double>(refV_level) / 100.0; }

    enum
    {
        MAIN_HANDLE = 0,
        REVERS_HANDLE = 1
    };

    float getSoundSignal(size_t state_idx) const override
    {
        return sound_states[state_idx].createSoundSignal();
    }

private:

    /// Позиция, определяющая состояние схемы
    /// (0 - схема разобрана, 1 - подготовка тяги, 2 - подготовка рекуперации)
    int mode_pos = 0;
    int mode_pos_old = 0;

    bool fwd_key_state = false;
    bool old_fwd_key_state = false;

    bool bwd_key_state = false;
    bool old_bwd_key_state = false;

    int revers_pos = 0;

    bool old_traction_key = false;

    bool old_brake_key = false;

    int trac_level = 0;

    int brake_level = 0;

    /// Вращение контроллера по сигналу таймера
    int handle_motion_speed = 0;

    /// Коэффициент ускорения контроллера с нажатым Shift
    int handle_high_speed_coeff = 8;

    /// Положение регулятора скорости
    double refV_level = 0.0;

    /// Шаг вращения регулятора скорости
    double refV_step = 100.0 / 160.0; // 0.625;

    /// Вращение регулятора скорости по сигналу таймера
    double refV_motion_speed = 0.0;

    /// Коэффициент ускорения регулятора скорости с нажатым Shift
    double refV_high_speed_coeff = 8.0;

    Timer tracTimer;

    Timer brakeTimer;

    Timer speedTimer;

    Trigger traction;

    Trigger brake;

    std::array<sound_state_t, 2> sound_states;

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

    void slotSpeedLevelProcess();
};

#endif // KM_35_01_H
