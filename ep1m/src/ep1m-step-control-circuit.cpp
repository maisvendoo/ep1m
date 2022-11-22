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
    bool is_kv23_on = static_cast<double>(msud->getOutputData().kv23_on);
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
