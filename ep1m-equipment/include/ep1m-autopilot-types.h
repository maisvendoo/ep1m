#ifndef     EP1M_AUTOPILOT_TYPES_H
#define     EP1M_AUTOPILOT_TYPES_H

#include    <autopilot-types.h>
#include    <cstdint>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class ep1m_control_t : public auto_control_t
{
public:

    int8_t mode_pos = 0;

    ep1m_control_t()
    {

    }
};

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class ep1m_feedback_t : public auto_feedback_t
{
public:

    /// Ток якоря ТЭД
    double I_motor = 0.0;

    /// Признак активности ЭПТ
    bool is_EPB_on = false;

    /// Признак замыкания линейных контакторов ТЭД
    bool is_LC_ON = false;

    ep1m_feedback_t()
    {

    }
};

#endif
