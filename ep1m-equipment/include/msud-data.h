#ifndef     MSUD_DATA_H
#define     MSUD_DATA_H

#include    <array>

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
    MOTOR_FANS_NUM = 3,
    MV1 = 0,
    MV2 = 1,
    MV3 = 2
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

    /// Токи якоря тяговых двигателей
    std::array<double, TRAC_MOTORS_NUM> Ia;

    /// Состояние мотор-вентиляторов
    std::array<bool, MOTOR_FANS_NUM> mv_state;

    /// Давление в ТЦ тележек
    std::array<double, TRAC_MOTORS_NUM / 2> TC_press;

    msud_input_t()
        : tumbler_MPK(false)
        , is_automatic_mode(false)
        , is_PCHF_On(false)
    {
        std::fill(Ia.begin(), Ia.end(), 0.0);
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
    bool kv23_on;

    /// Работа МВ на низкой частоте
    bool is_MV_low_freq;

    double TC_min_press;

    int TC_status;

    /// Включение МВ на низкой частоте
    std::array<bool, MOTOR_FANS_NUM> mv_freq_low;
    /// Включение МВ на нормальной частоте
    std::array<bool, MOTOR_FANS_NUM> mv_freq_norm;
    /// Наполнение ТЦ тележек
    std::array<bool, TRAC_MOTORS_NUM / 2> TC_full;

    msud_output_t()
        : state(MSUD_OFF)
        , kv23_on(false)
        , is_MV_low_freq(false)
        , TC_min_press(0.11)
        , TC_status(0)
    {
        std::fill(mv_freq_low.begin(), mv_freq_low.end(), true);
        std::fill(mv_freq_norm.begin(), mv_freq_norm.end(), false);
        std::fill(TC_full.begin(), TC_full.end(), false);
    }
};

#endif // MSUD_DATA_H
