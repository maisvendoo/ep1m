#ifndef     MSUD_DATA_H
#define     MSUD_DATA_H

#include    <array>
#include    "physics.h"
#include    "shunts-module-defines.h"

// Режимы работы статуса оборудования
//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
enum
{
    MSUD_STATUS_OFF = 0,
    MSUD_STATUS_ON = 1,
    MSUD_STATUS_BLINK = 2
};

// Доступные состояния МСУД
//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
enum msud_state_t
{
    MSUD_OFF = 0,
    MSUD_RESET = 1,
    MSUD_READY = 2
};

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
enum
{
    TRAC_MOTORS_NUM = 6,
    TRAC_MOTOR1 = 0,
    TRAC_MOTOR2 = 1,
    TRAC_MOTOR3 = 2,
    TRAC_MOTOR4 = 3,
    TRAC_MOTOR5 = 4,
    TRAC_MOTOR6 = 5
};

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
enum
{
    MOTOR_FANS_NUM = 4,
    MV1 = 0,
    MV2 = 1,
    MV3 = 2,
    MV4 = 3
};

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
struct msud_input_t
{
    /// Положение тумблера (МПК1/МПК2)
    bool tumbler_MPK;

    /// Признак включения режима "АВТОРЕГУЛИРОВАНИЕ"
    bool is_automatic_mode;

    /// Признак включения ПЧФ
    bool is_PCHF_On;

    /// Режим управления (Авторегулирование/Ручной)
    bool is_auto_reg;

    /// Положение главного вала КМ в тяге
    double km_trac_level;

    /// Положение главного вала КМ в рекуперации
    double km_brake_level;

    /// Положение задатчика скорости
    double km_ref_velocity_level;

    /// Текущая скорость электровоза, км/ч
    double V_cur;

    /// Признак сбора тяги
    bool is_traction;

    /// Признак сбора рекуперации
    bool is_brake;

    /// Токи якоря тяговых двигателей
    std::array<double, TRAC_MOTORS_NUM> Ia;

    /// Токи возбуждения тяговых двигателей
    std::array<double, TRAC_MOTORS_NUM> If;

    /// Состояние мотор-вентиляторов
    std::array<bool, MOTOR_FANS_NUM> mv_state;

    /// Давление в ТЦ тележек
    std::array<double, TRAC_MOTORS_NUM / 2> TC_press;

    msud_input_t()
        : tumbler_MPK(false)
        , is_automatic_mode(false)
        , is_PCHF_On(false)
        , is_auto_reg(false)
        , km_trac_level(0.0)
        , km_brake_level(0.0)
        , km_ref_velocity_level(0.0)
        , V_cur(0.0)
        , is_traction(false)
        , is_brake(false)
    {
        std::fill(Ia.begin(), Ia.end(), 0.0);
        std::fill(If.begin(), If.end(), 0.0);
        std::fill(mv_state.begin(), mv_state.end(), false);
        std::fill(TC_press.begin(), TC_press.end(), 0.0);
    }
};


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
struct msud_output_t
{
    msud_state_t state;

    /// Подача питания на реле КМ23
    bool kv23_On;

    /// Сигнал включения реле KV14
    bool kv14_On;

    /// Работа МВ на низкой частоте
    bool is_MV_low_freq;

    double TC_min_press;

    int TC_status;

    /// Уровень напряжение на выходе ВИП (от 0.0 до 4.0) отображаемый на БИ
    double vip_voltage_level;

    /// Номер зоны ВИП
    size_t zone_num;

    /// Угол открытия тиристоров
    double alpha;

    /// Ступень ослабления возбуждения
    size_t field_weak_step;

    /// Уровень тока возбуждения от ВУВ
    double field_level;

    /// Ограничение тока ББР
    double Ib_max;

    /// Ограниение тока возбуждения
    double If_max;

    /// Ограничение тока якоря
    double Ia_max;

    /// Максимальная задаваемая скорость
    double Vmax;

    /// Сигнал отсутствия усиление торможения от вентиля Y5
    bool is_not_brake_boost;

    /// Включение МВ на низкой частоте
    std::array<bool, MOTOR_FANS_NUM> mv_freq_low;
    /// Включение МВ на нормальной частоте
    std::array<bool, MOTOR_FANS_NUM> mv_freq_norm;
    /// Наполнение ТЦ тележек
    std::array<bool, TRAC_MOTORS_NUM / 2> TC_full;

    /// Сгнализация супеней ОП
    std::array<bool, NUM_STEPS> op;

    msud_output_t()
        : state(MSUD_OFF)
        , kv23_On(false)
        , kv14_On(false)
        , is_MV_low_freq(false)
        , TC_min_press(0.11)
        , TC_status(0)
        , vip_voltage_level(0.0)
        , zone_num(1)
        , alpha(Physics::PI / 2.0)
        , field_weak_step(0)
        , field_level(0.0)
        , Ib_max(950.0)
        , If_max(845.0)
        , Ia_max(1300.0)
        , Vmax(140.0)
        , is_not_brake_boost(true)
    {
        std::fill(mv_freq_low.begin(), mv_freq_low.end(), true);
        std::fill(mv_freq_norm.begin(), mv_freq_norm.end(), false);
        std::fill(TC_full.begin(), TC_full.end(), false);
        std::fill(op.begin(), op.end(), true);
    }
};

#endif // MSUD_DATA_H
