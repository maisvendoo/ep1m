#ifndef     MSUD_DATA_H
#define     MSUD_DATA_H

#include    <array>

// Доступные состояния МСУД
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
    /// Токи якоря тяговых двигателей
    std::array<double, TRAC_MOTORS_NUM> Ia;

    /// Состояние мотор-вентиляторов
    std::array<bool, MOTOR_FANS_NUM> mv_state;

    msud_input_t()
    {
        std::fill(Ia.begin(), Ia.end(), 0.0);
        std::fill(mv_state.begin(), mv_state.end(), false);

    }
};


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
struct msud_output_t
{
    msud_state_t state;

    // Подача питания на реле КМ23
    bool kv23_on;

    /// Работа МВ на низкой частоте
    bool is_MV_low_freq;

    // Включение МВ на низкой частоте
    std::array<bool, MOTOR_FANS_NUM> mv_freq_low;
    // Включение МВ на нормальной частоте
    std::array<bool, MOTOR_FANS_NUM> mv_freq_norm;

    msud_output_t()
        : state(MSUD_OFF)
        , kv23_on(false)
        , is_MV_low_freq(false)
    {
        std::fill(mv_freq_low.begin(), mv_freq_low.end(), true);
        std::fill(mv_freq_norm.begin(), mv_freq_norm.end(), false);
    }
};

#endif // MSUD_DATA_H
