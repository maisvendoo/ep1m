#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::keyProcess()
{
    // Включение/выключение шкафа питания ШП-21
    if (getKeyState(KEY_H))
    {
        if (isShift())
            tumblers[TUMBLER_POWER_SUPPLY_ON].set();
        else
            tumblers[TUMBLER_POWER_SUPPLY_ON].reset();
    }

    // Перевод реверсивной рукоятки
    if (getKeyState(KEY_W))
    {
        tumblers[SWITCH_REVERS_FWD].set();
    }
    else
    {
        tumblers[SWITCH_REVERS_FWD].reset();
    }

    if (getKeyState(KEY_S))
    {
        tumblers[SWITCH_REVERS_BWD].set();
    }
    else
    {
        tumblers[SWITCH_REVERS_BWD].reset();
    }
}
