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

    // Включение блока сигнализации
    if (getKeyState(KEY_8))
    {
        if (isShift())
            tumblers[TUMBLER_BS_002].set();
        else
            tumblers[TUMBLER_BS_002].reset();
    }

    // РБ
    if (getKeyState(KEY_M))
        tumblers[BUTTON_RB].set();
    else
        tumblers[BUTTON_RB].reset();

    // РБС
    if (getKeyState(KEY_Z))
        tumblers[BUTTON_RBS].set();
    else
        tumblers[BUTTON_RBS].reset();

    // ЭПК
    if (getKeyState(KEY_N))
    {
        if (isShift())
            tumblers[EPK_KEY].set();
        else
            tumblers[EPK_KEY].reset();
    }

    // Выбор МПК
    if (getKeyState(KEY_1))
    {
        if (isShift())
            tumblers[TUMBLER_MPK].set();
        else
            tumblers[TUMBLER_MPK].reset();
    }

    // Вкл/Выкл "АВТОРЕГУЛИРОВАНИЕ"
    if (getKeyState(KEY_F))
    {
        if (isShift())
            tumblers[TUMBLER_AUTO_MODE].set();
        else
            tumblers[TUMBLER_AUTO_MODE].reset();
    }

    // Отключение ПЧФ
    if (getKeyState(KEY_2))
    {
        if (isShift())
            tumblers[TUMBLER_PCHF].set();
        else
            tumblers[TUMBLER_PCHF].reset();
    }
}
