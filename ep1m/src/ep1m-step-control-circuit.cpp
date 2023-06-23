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
    bool is_kv23_on = is_kv22_on;
    kv23->setVoltage(Ucc * is_kv23_on);
    kv23->step(t, dt);

    // Цепь на проводе Н211
    is_N211_on =
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

    stepRecuperationControl(t, dt);
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
    bool is_N3_on = km->isContacts13_14() &&
            km->isContscts1_2() &&
            reversor->isForward();

    bool is_N4_on = km->isContacts13_14() &&
            km->isContscts3_4() &&
            reversor->isBackward();

    kt10->setControlVoltage(Ucc * static_cast<double>(is_N3_on || is_N4_on));
    kt10->step(t, dt);

    // Включение реле KV14
    kv14->setVoltage(Ucc * static_cast<double>(msud->getOutputData().kv14_On));
    kv14->step(t, dt);

    // Включение реле KV15
    bool is_N40_on = is_H36 &&
            qt1->getContactState(2) &&
            qt1->getContactState(3) &&
            kt10->getContactState(0);

    bool is_KV15_on = is_N40_on &&
            ( (kt1->getContactState(1) && kv15->getContactState(1)) ||
               kv22->getContactState(1) );

    kv15->setVoltage(Ucc * static_cast<double>(is_KV15_on));
    kv15->step(t, dt);

    // Включение контактора KM41
    bool is_H153 = kv23->getContactState(0) || km41->getContactState(0);

    bool is_KM41_on = is_H153 &&
            kv15->getContactState(2) &&
            qt1->getContactState(7);

    km41->setVoltage(Ucc * static_cast<double>(is_KM41_on));
    km41->step(t, dt);

    // Включение контактора KM42
    bool is_H163 = kv23->getContactState(1) || km42->getContactState(0);

    bool is_KM42_on = is_H163 &&
            kv15->getContactState(3) &&
            qt1->getContactState(8);

    km42->setVoltage(Ucc * static_cast<double>(is_KM42_on));
    km42->step(t, dt);

    // Запуск реле времени КТ1
    bool is_KT1_on = km41->getContactState(1) && km42->getContactState(1);

    kt1->setControlVoltage(Ucc * static_cast<double>(is_KT1_on));
    kt1->step(t, dt);

    // Включение БВ от ВИП1 на ТЭД1, ТЭД2, ТЭД3
    bool is_Hold_1_3 = is_H153 && (!main_switch->getState());


    fast_switch[TRAC_MOTOR1]->setHold(is_Hold_1_3);
    fast_switch[TRAC_MOTOR2]->setHold(is_Hold_1_3);
    fast_switch[TRAC_MOTOR3]->setHold(is_Hold_1_3);

    bool is_Power_On_1_3 = is_N211_on && kv21->getContactState(1);

    fast_switch[TRAC_MOTOR1]->setPowerOn(is_Power_On_1_3);
    fast_switch[TRAC_MOTOR2]->setPowerOn(is_Power_On_1_3);
    fast_switch[TRAC_MOTOR3]->setPowerOn(is_Power_On_1_3);

    // Включение БВ от ВИП2 на ТЭД4, ТЭД5, ТЭД6
    bool is_Hold_4_6 = is_H163 && (!main_switch->getState());

    fast_switch[TRAC_MOTOR4]->setHold(is_Hold_4_6);
    fast_switch[TRAC_MOTOR5]->setHold(is_Hold_4_6);
    fast_switch[TRAC_MOTOR6]->setHold(is_Hold_4_6);

    bool is_Power_On_4_6 = is_N211_on && kv21->getContactState(1);

    fast_switch[TRAC_MOTOR4]->setPowerOn(is_Power_On_4_6);
    fast_switch[TRAC_MOTOR5]->setPowerOn(is_Power_On_4_6);
    fast_switch[TRAC_MOTOR6]->setPowerOn(is_Power_On_4_6);

    bool circuit_state = true;
    for (size_t i = 0; i < fast_switch.size(); ++i)
    {
        circuit_state = circuit_state && (!fast_switch[i]->getContactState(2));
    }

    circuit_state = circuit_state &&
            km41->getContactState(0) &&
            km42->getContactState(0);

    msud_input.is_traction = circuit_state;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepRecuperationControl(double t, double dt)
{
    is_N45_on = km->isContacts11_12();

    // Цепь подготовки реле КТ4
    bool is_KT4_on = is_N45_on &&
            km41->getContactState(4) &&
            km42->getContactState(4);

    kt4->setControlVoltage(Ucc * static_cast<double>(is_KT4_on));

    kt4->step(t, dt);
}
