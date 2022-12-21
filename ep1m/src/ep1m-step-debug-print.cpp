#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepDebugPrint(double t, double dt)
{
    Q_UNUSED(t)
    Q_UNUSED(dt)
/*
    DebugMsg = QString("Пульт: %1 Ucc: %2 ВВК: %3 Uсн: %4 Реверс: %5 ГВ: %6 УК: %7 KT10: %8 KT1: %9 KV22: %10 KV15: %11 KM41: %12 KM42: %13")
            .arg(static_cast<int>(tumblers_panel->getUnlockKeyState()), 1)
            .arg(static_cast<float>(Ucc), 5, 'f', 2)
            .arg(static_cast<int>(safety_valve->getState()), 1)
            .arg(static_cast<float>(trac_trans->getControlPowerVoltage()), 5, 'f', 2)
            .arg(static_cast<int>(km->getReversHandlePos()), 2)
            .arg(static_cast<int>(main_switch->getState()), 1)
            .arg(static_cast<int>(getHoldingCoilState()), 1)
            .arg(static_cast<int>(kt10->getContactState(0)), 1)
            .arg(static_cast<int>(kt1->getContactState(1)), 1)
            .arg(static_cast<int>(kv22->getContactState(0)), 1)
            .arg(static_cast<int>(kv15->getContactState(0)), 1)
            .arg(static_cast<int>(km41->getContactState(0)))
            .arg(static_cast<int>(km41->getContactState(0)));
*/
    DebugMsg = QString("%1")
            .arg(trac_motor[0]->getDebugMsg(), 1);

}
