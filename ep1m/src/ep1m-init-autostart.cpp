#include    <ep1m.h>
#include    <km-35-01.h>
#include    <tumblers-panel.h>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
bool EP1m::initAutostartProgram(int cab_autostart_request)
{
    if (autoStartTimer->isStarted())
    {
        return false;
    }

    // проверяем индекс кабины
    if ((cab_autostart_request != CAB1) && (cab_autostart_request != CAB2))
    {
        return false;
    }

    // проверяем наличие ключа именно в рабочей кабине
    if (tumblers_panel[(cab_autostart_request == CAB1) ? CAB2 : CAB1]->isKey())
    {
        return false;
    }

    // проверяем наличие реверсивки именно в рабочей кабине
    if (km[(cab_autostart_request == CAB1) ? CAB2 : CAB1]->isReversHandle())
    {
        return false;
    }

    // проверяем блокировку 367 в рабочей кабине
    if (!brake_lock[cab_autostart_request]->isLockHandleAllowed())
    {
        return false;
    }

    // ключ ЭПК в рабочей кабине?
    if (!epk[cab_autostart_request]->isKeyAllowed())
    {
        return false;
    }

    autostart_cab = cab_autostart_request;
    tumblers_panel[autostart_cab]->insertKey(true);
    km[autostart_cab]->insertReversHandle(true);
    brake_lock[autostart_cab]->setStateOn(true);
    epk[autostart_cab]->insertKey(true);

    km[CAB1]->setControl();
    km[CAB2]->setControl();
    brake_lock[CAB1]->setControl();
    brake_lock[CAB2]->setControl();
    epk[CAB1]->setControl();
    epk[CAB2]->setControl();

    start_count = 0;
    autostart_triggers.clear();
    autostart_triggers.push_back(tumblers_panel[autostart_cab]->getTumblerPtr(EP1MTumblersPanel::TUMBLER_LOCK_VVK));
    autostart_triggers.push_back(tumblers_panel[autostart_cab]->getTumblerPtr(EP1MTumblersPanel::TUMBLER_MSUD));
    autostart_triggers.push_back(tumblers_panel[autostart_cab]->getTumblerPtr(EP1MTumblersPanel::TUMBLER_PANT2));
    autostart_triggers.push_back(tumblers_panel[autostart_cab]->getTumblerPtr(EP1MTumblersPanel::TUMBLER_MAIN_SWITCH));
    autostart_triggers.push_back(tumblers_panel[autostart_cab]->getTumblerPtr(EP1MTumblersPanel::TUMBLER_RETURN_PROTECTION));
    autostart_triggers.push_back(tumblers_panel[autostart_cab]->getTumblerPtr(EP1MTumblersPanel::TUMBLER_AUX_MACHINES));
    autostart_triggers.push_back(tumblers_panel[autostart_cab]->getTumblerPtr(EP1MTumblersPanel::TUMBLER_COMPRESSOR));
    autostart_triggers.push_back(tumblers_panel[autostart_cab]->getTumblerPtr(EP1MTumblersPanel::TUMBLER_MOTOR_FAN1));
    autostart_triggers.push_back(tumblers_panel[autostart_cab]->getTumblerPtr(EP1MTumblersPanel::TUMBLER_MOTOR_FAN2));
    autostart_triggers.push_back(tumblers_panel[autostart_cab]->getTumblerPtr(EP1MTumblersPanel::TUMBLER_MOTOR_FAN3));

    return true;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::slotAutostart()
{
    if (start_count < autostart_triggers.size())
    {
        // Разблокируем панель тумблеров, если она не разблокирована
        if (!tumblers_panel[autostart_cab]->isKeyOn())
        {
            tumblers_panel[autostart_cab]->setKeyOn(true);
            return;
        }

        // Проверяем факт поднятия рогов, прежде чем включать ГВ
        if (autostart_triggers[start_count] == tumblers_panel[autostart_cab]->getTumblerPtr(EP1MTumblersPanel::TUMBLER_MAIN_SWITCH) &&
            !pant[PANT1]->isUp() && !pant[PANT2]->isUp())
        {
            return;
        }

        // Проверяем, включен ли ГВ, чтобы отпустить возврат защиты
        if (main_switch->getState())
        {
            tumblers_panel[autostart_cab]->getTumblerPtr(EP1MTumblersPanel::TUMBLER_RETURN_PROTECTION)->reset();
        }
        else
        {
            if (autostart_triggers[start_count] == tumblers_panel[autostart_cab]->getTumblerPtr(EP1MTumblersPanel::TUMBLER_RETURN_PROTECTION))
            {
                tumblers_panel[autostart_cab]->getTumblerPtr(EP1MTumblersPanel::TUMBLER_RETURN_PROTECTION)->set();
                return;
            }
        }

        autostart_triggers[start_count++]->set();
    }
    else
    {

    }
}
