#include    "ep1m-tumblers-panel.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
EP1MTumblersPanel::EP1MTumblersPanel(QObject *parent) : Device(parent)
{
    for (size_t i = 0; i < tumblers.size(); ++i)
    {
        connect(&tumblers[i], &Trigger::soundPlay, this, &EP1MTumblersPanel::soundPlay);
        tumblers[i].setOnSoundName("Tumbler_On");
        tumblers[i].setOffSoundName("Tumbler_Off");
    }

    unlock_panel_key.setOnSoundName("Key_Unlock");
    unlock_panel_key.setOffSoundName("Key_Lock");
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
EP1MTumblersPanel::~EP1MTumblersPanel()
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
bool EP1MTumblersPanel::getTumblerState(size_t tumbler_index) const
{
    return tumblers[tumbler_index].getState();
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1MTumblersPanel::ode_system(const state_vector_t &Y,
                                   state_vector_t &dYdt,
                                   double t)
{
    Q_UNUSED(Y)
    Q_UNUSED(dYdt)
    Q_UNUSED(t)
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1MTumblersPanel::stepKeysControl(double t, double dt)
{
    // Поворот ключа блокировки, при условии нахождения всех тумблеров
    // в положении "выключено"
    if (getKeyState(KEY_U))
    {
        if (isShift())
            unlock_panel_key.set();
        else
        {
            if (isTumblersNotActive())
                unlock_panel_key.reset();
        }
    }

    // Обрабатываем тумблеры при условии разблокировки пульта ключем
    if (unlock_panel_key.getState())
    {
        // Включение МСУД
        if (getKeyState(KEY_J))
        {
            if (isShift())
                tumblers[TUMBLER_MSUD].set();
            else
                tumblers[TUMBLER_MSUD].reset();
        }

        // Поднятие токоприемника 1
        if (getKeyState(KEY_I))
        {
            if (isShift())
                tumblers[TUMBLER_PANT1].set();
            else
                tumblers[TUMBLER_PANT1].reset();
        }

        // Поднятие токоприемника 2
        if (getKeyState(KEY_O))
        {
            if (isShift())
                tumblers[TUMBLER_PANT2].set();
            else
                tumblers[TUMBLER_PANT2].reset();
        }

        // Блокирование ВВК
        if (getKeyState(KEY_Y))
        {
            if (isShift())
                tumblers[TUMBLER_LOCK_VVK].set();
            else
                tumblers[TUMBLER_LOCK_VVK].reset();
        }

        // Возврат защиты ГВ
        if (getKeyState(KEY_K))
            tumblers[TUMBLER_RETURN_PROTECTION].set();
        else
            tumblers[TUMBLER_RETURN_PROTECTION].reset();

        // Включение ГВ
        if (getKeyState(KEY_P))
        {
            if (isShift())
                tumblers[TUMBLER_MAIN_SWITCH].set();
            else
                tumblers[TUMBLER_MAIN_SWITCH].reset();
        }

        // Вспомогательные машины
        if (getKeyState(KEY_T))
        {
            if (isShift())
                tumblers[TUMBLER_AUX_MACHINES].set();
            else
                tumblers[TUMBLER_AUX_MACHINES].reset();
        }

        // Вентилятор 1
        if (getKeyState(KEY_5))
        {
            if (isShift())
                tumblers[TUMBLER_MOTOR_FAN1].set();
            else
                tumblers[TUMBLER_MOTOR_FAN1].reset();
        }

        // Вентилятор 2
        if (getKeyState(KEY_6))
        {
            if (isShift())
                tumblers[TUMBLER_MOTOR_FAN2].set();
            else
                tumblers[TUMBLER_MOTOR_FAN2].reset();
        }

        // Вентилятор 3
        if (getKeyState(KEY_7))
        {
            if (isShift())
                tumblers[TUMBLER_MOTOR_FAN3].set();
            else
                tumblers[TUMBLER_MOTOR_FAN3].reset();
        }

        // Включение ЭПТ
        if (getKeyState(KEY_V))
        {
            if (isShift())
                tumblers[TUMBLER_EPT].set();
            else
                tumblers[TUMBLER_EPT].reset();
        }
    }
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
bool EP1MTumblersPanel::isTumblersNotActive() const
{
    bool is_not_active = true;

    for (size_t i = 0; i < tumblers.size(); ++i)
    {
        is_not_active = is_not_active & (!tumblers[i].getState());
    }

    return is_not_active;
}
