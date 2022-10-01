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
            kv39->getContactState(0);

    return is_holding_coil_on;
}
