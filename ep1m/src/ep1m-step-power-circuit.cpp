#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepPowerCircuit(double t, double dt)
{
    for (size_t i = 0; i < pant.size(); ++i)
    {
        pant[i]->setUks(Uks);
        pant[i]->step(t, dt);
    }

    Ukr = max(pant[PANT1]->getUout(), pant[PANT2]->getUout());

    main_switch->setU_in(Ukr);
    main_switch->step(t, dt);

    trac_trans->setInputVoltage(main_switch->getU_out());
    trac_trans->step(t, dt);
}
