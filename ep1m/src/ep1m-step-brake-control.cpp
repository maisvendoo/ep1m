#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepBrakeControl(double t, double dt)
{
    ubt->setLocoFLpressure(main_res->getPressure());
    ubt->setCraneTMpressure(brake_crane->getBrakePipeInitPressure());
    ubt->setControl(keys);
    p0 = ubt->getLocoTMpressure();
    ubt->step(t, dt);

    brake_crane->setFeedLinePressure(ubt->getCraneFLpressure());
    brake_crane->setChargePressure(0.5);
    brake_crane->setBrakePipePressure(pTM);
    brake_crane->setControl(keys);
    brake_crane->step(t, dt);

    loco_crane->setFeedlinePressure(ubt->getCraneFLpressure());
    loco_crane->setBrakeCylinderPressure(0.0);
    loco_crane->setAirDistributorFlow(0.0);
    loco_crane->setControl(keys);
    loco_crane->step(t, dt);
}
