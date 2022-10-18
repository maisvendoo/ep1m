#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepSafetyDevices(double t, double dt)
{
    klub_BEL->setVoltage(Ucc);
    klub_BEL->setKeyEPK(epk->getStateKey());
    klub_BEL->setDirection(dir);
    klub_BEL->setRailCoord(railway_coord);
    klub_BEL->setVelocity(velocity);
    klub_BEL->setAlsnCode(alsn_info.code_alsn);
    klub_BEL->setRBstate(tumblers[BUTTON_RB].getState());
    klub_BEL->setRBSstate(tumblers[BUTTON_RBS].getState());
    klub_BEL->step(t, dt);
}
