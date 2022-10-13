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

    Q_r[1] = brake_mech[FWD_TROLLEY]->getBrakeTorque();
    Q_r[2] = brake_mech[FWD_TROLLEY]->getBrakeTorque();

    Q_r[3] = brake_mech[MID_TROLLEY]->getBrakeTorque();
    Q_r[4] = brake_mech[MID_TROLLEY]->getBrakeTorque();

    Q_r[5] = brake_mech[BWD_TROLLEY]->getBrakeTorque();
    Q_r[6] = brake_mech[BWD_TROLLEY]->getBrakeTorque();

    for (size_t i = 0; i < brake_mech.size(); ++i)
    {
        brake_mech[i]->step(t, dt);
    }
}
