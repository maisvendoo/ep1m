#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepPowerCircuit(double t, double dt)
{
    pant[PANT1]->setState(safety_valve->getState() && tumblers_panel->getTumblerState(TUMBLER_PANT1));
    pant[PANT2]->setState(safety_valve->getState() && tumblers_panel->getTumblerState(TUMBLER_PANT2));

    for (size_t i = 0; i < pant.size(); ++i)
    {
        pant[i]->setUks(Uks);
        pant[i]->step(t, dt);
    }

    Ukr = max(pant[PANT1]->getUout(), pant[PANT2]->getUout());

    main_switch->setU_in(Ukr);
    main_switch->setHoldingCoilState(getHoldingCoilState());
    main_switch->step(t, dt);

    trac_trans->setInputVoltage(main_switch->getU_out());
    trac_trans->step(t, dt);

    safety_valve->setVoltage(Ucc * static_cast<double>(tumblers_panel->getTumblerState(TUMBLER_LOCK_VVK)));
    safety_valve->step(t, dt);
}
