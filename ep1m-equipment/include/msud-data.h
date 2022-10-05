#ifndef     MSUD_DATA_H
#define     MSUD_DATA_H

#include    <array>

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
struct msud_input_t
{
    /// Токи якоря тяговых двигателей
    std::array<double, TRAC_MOTORS_NUM> Ia;

    msud_input_t()
    {
        std::fill(Ia.begin(), Ia.end(), 0.0);
    }
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
struct msud_output_t
{
    // Подача питания на реле КМ23
    bool kv23_on;

    // Включение МВ на низкой частоте
    std::array<bool, MOTOR_FANS_NUM> mv_freq_low;
    // Включение МВ на нормальной частоте
    std::array<bool, MOTOR_FANS_NUM> mv_freq_norm;

    msud_output_t()
        : kv23_on(false)
    {
        std::fill(mv_freq_low.begin(), mv_freq_low.end(), true);
        std::fill(mv_freq_norm.begin(), mv_freq_norm.end(), false);
    }
};

#endif // MSUD_DATA_H
