#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepSafetyDevices(double t, double dt)
{
    // Приёмные катушки АЛСН
    coil_ALSN_fwd->step(t, dt);
    coil_ALSN_bwd->step(t, dt);

    // Дешифратор АЛСН
    alsn_decoder->setCoilSignal(coil_ALSN_fwd->getCode());
    alsn_decoder->step(t, dt);

    klub_BEL->setVoltage(Ucc);
    klub_BEL->setAlsnCode(alsn_decoder->getCode());
    klub_BEL->setKeyEPK(epk->isKeyOn());
    klub_BEL->setCoord(profile_point_data.position);
    klub_BEL->setRailCoord(profile_point_data.railway_coord);
    klub_BEL->setVelocity(wheel_omega[0] * wheel_diameter[0] / 2.0);
    klub_BEL->setTrainLength(length);
    klub_BEL->setRBstate(tumblers[BUTTON_RB].getState());
    klub_BEL->setRBSstate(tumblers[BUTTON_RBS].getState());
    klub_BEL->step(t, dt);
}
