#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::keyProcess()
{
    // Включение/выключение шкафа питания ШП-21
    if (getKeyState(KEY_Y))
    {
        if (isShift())
            tumbler_power_supply.set();
        else
            tumbler_power_supply.reset();
    }
}
