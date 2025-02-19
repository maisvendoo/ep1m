#include    "ep1m.h"

void EP1m::stepBlockKON(double t, double dt)
{
    block_KON->setKeyEPK(epk->isKeyOn());
    block_KON->setVelocityKmh(KLUB_BEL->getVelocityKmh());
    block_KON->setBrakeCylinderPressure(brake_mech[TROLLEY_FWD]->getBCpressure());

    block_KON->step(t, dt);
}
