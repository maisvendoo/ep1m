#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepBrakeEquipment(double t, double dt)
{
    epk->setBrakepipePressure(pTM);
    epk->setFeedlinePressure(main_res->getPressure());
    epk->setControl(keys);
    epk->step(t, dt);
}
