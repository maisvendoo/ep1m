#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepSafetyDevices(double t, double dt)
{
    klub_BEL->setVoltage(Ucc);
    klub_BEL->setAlsnCode(alsn_info.code_alsn);
    klub_BEL->setKeyEPK(epk->getStateKey());
    klub_BEL->setRailCoord(railway_coord + dir * orient * length / 2.0);
    klub_BEL->setVelocity(wheel_omega[0] * wheel_diameter[0] / 2.0);
    klub_BEL->setTrainLength(length);
    klub_BEL->setRBstate(tumblers[BUTTON_RB].getState());
    klub_BEL->setRBSstate(tumblers[BUTTON_RBS].getState());
    klub_BEL->step(t, dt);
}
