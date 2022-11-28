#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepControlCircuit(double t, double dt)
{
    // Цепь питания промежуточного реле KV44
    bool is_kv44_on = tumblers_panel->getTumblerState(TUMBLER_MSUD);

    kv44->setVoltage(Ucc * static_cast<double>(is_kv44_on));
    kv44->step(t, dt);

    // Цепь питания промежуточного реле KV39
    bool is_kv39_on = tumblers_panel->getTumblerState(TUMBLER_PANT1) |
                      tumblers_panel->getTumblerState(TUMBLER_PANT2);

    kv39->setVoltage(Ucc * static_cast<double>(is_kv39_on));
    kv39->step(t, dt);

    // Цепь питания промежуточных реле КV21 и KV22
    bool is_kv21_on = km->isContacts15_16();

    bool is_kv22_on = km->isContacts15_16();

    kv21->setVoltage(Ucc * static_cast<double>(is_kv21_on));
    kv21->step(t, dt);

    // Цепь питания контактора КМ43
    bool is_km43_on = tumblers_panel->getTumblerState(TUMBLER_MSUD) &&
            (kv21->getContactState(1) || km43->getContactState(0));

    km43->setVoltage(Ucc * static_cast<double>(is_km43_on));
    km43->step(t, dt);

    kv22->setVoltage(Ucc * static_cast<double>(is_kv22_on));
    kv22->step(t, dt);

    // Цепь питания реле KV23
    bool is_kv23_on = static_cast<double>(msud->getOutputData().kv23_On);
    kv23->setVoltage(Ucc * is_kv23_on);
    kv23->step(t, dt);

    // Цепь на проводе Н211
    bool is_N211_on =
            tumblers_panel->getTumblerState(TUMBLER_MAIN_SWITCH) &&
            tumblers[BUTTON_MAIN_SWITCH_OFF].getState() &&
            tumblers_panel->getTumblerState(TUMBLER_RETURN_PROTECTION);

    bool is_kv41_on =
            is_N211_on && ((!main_switch->getState()) ||
            (kv21->getContactState(0) && kv41->getContactState(0)));

    kv41->setVoltage(Ucc * static_cast<double>(is_kv41_on));
    kv41->step(t, dt);

    // Состояние цепи "Возврат защиты ГВ"
    return_GV =
            is_N211_on &&
            kv41->getContactState(1) &&
            kv39->getContactState(1) &&
            kv44->getContactState(2) &&
            kv23->getContactState(0);

    main_switch->setReturn(return_GV);        

    stepTractionControl(t, dt);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
bool EP1m::getHoldingCoilState()
{
    bool is_holding_coil_on =
            tumblers_panel->getTumblerState(TUMBLER_MAIN_SWITCH) &&
            tumblers[BUTTON_MAIN_SWITCH_OFF].getState() &&
            kv44->getContactState(0) &&
            kv39->getContactState(0) &&
            safety_valve->getState();

    return is_holding_coil_on;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepTractionControl(double t, double dt)
{
    bool is_KV11_KV12_on = km->isContacts5_6() &&
            epk->getEmeggencyBrakeContact();

    kv11->setVoltage(Ucc * static_cast<double>(is_KV11_KV12_on));
    kv11->step(t, dt);

    kv12->setVoltage(Ucc * static_cast<double>(is_KV11_KV12_on));
    kv12->step(t, dt);

    // Контроль давления в тормозной магистрали
    sp4->setInput(pTM);
    sp4->step(t, dt);

    // Контакт экстренного торможения на кране машиниста
    bool is_SQ3 =  brake_crane->getPositionName() == "VI";

    bool is_KV13_on = km->isContacts5_6() &&
            (!is_SQ3) &&
            (tumblers[BUTTON_EMERGENCY_BRAKE].getState());

    kv13->setVoltage(Ucc * static_cast<double>(is_KV13_on));
    kv13->step(t, dt);

    // Разрешение тяги от КЛУБ
    kv84->setVoltage(Ucc * static_cast<double>(klub_BEL->isTractionAllowed()));
    kv84->step(t, dt);

    // Включение реле времени KT10
    kt10->setControlVoltage(Ucc * static_cast<double>(reversor->isNoZero()));
    kt10->step(t, dt);

    // Включение реле KV14
    kv14->setVoltage(Ucc * static_cast<double>(msud->getOutputData().kv14_On));
    kv14->step(t, dt);

    // Включение реле KV15
    bool is_KV15_on = is_H36 &&
            qt1->getContactState(2) &&
            qt1->getContactState(3) &&
            kt10->getContactState(0) &&
            ( (kt1->getContactState(1) && kv15->getContactState(0)) || kv22->getContactState(1) );

    kv15->setVoltage(Ucc * static_cast<double>(is_KV15_on));
    kv15->step(t, dt);

    // Включение контактора KM41
    bool is_KM41_on = kv23->getContactState(0) &&
            kv15->getContactState(1) &&
            qt1->getContactState(7);

    km41->setVoltage(Ucc * static_cast<double>(is_KM41_on));
    km41->step(t, dt);

    // Включение контактора KM42
    bool is_KM42_on = kv23->getContactState(1) &&
            kv15->getContactState(2) &&
            qt1->getContactState(8);

    km42->setVoltage(Ucc * static_cast<double>(is_KM42_on));
    km42->step(t, dt);

    // Включение БВ от ВИП1 на ТЭД1, ТЭД2, ТЭД3
    bool is_Hold_1_3 = km41->getContactState(0) &&
            main_switch->getState();
}
