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
    if (isTumblersNotActive() && getKeyState(KEY_U))
    {
        if (isShift())
            unlock_panel_key.set();
        else
            unlock_panel_key.reset();
    }

    // Обрабатываем тумблеры при условии разблокировки пульта ключем
    if (unlock_panel_key.getState())
    {
        if (getKeyState(KEY_J))
        {
            if (isShift())
                tumblers[TUMBLER_MSUD].set();
            else
                tumblers[TUMBLER_MSUD].reset();
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
