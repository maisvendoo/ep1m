#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepDebugPrint(double t, double dt)
{
    Q_UNUSED(t)
    Q_UNUSED(dt)

    DebugMsg = QString("Пульт: %1 Ucc: %2 ВВК: %3 Uсн: %4 Реверс: %5 ГВ: %6 УК: %7 Возвр.: %8 Ток: %9")
            .arg(static_cast<int>(tumblers_panel->getUnlockKeyState()), 1)
            .arg(static_cast<float>(Ucc), 5, 'f', 2)
            .arg(static_cast<int>(safety_valve->getState()), 1)
            .arg(static_cast<float>(trac_trans->getControlPowerVoltage()), 5, 'f', 2)
            .arg(static_cast<int>(km->getReversHandlePos()), 2)
            .arg(static_cast<int>(main_switch->getState()), 1)
            .arg(static_cast<int>(getHoldingCoilState()), 1)
            .arg(static_cast<int>(return_GV), 1)
            .arg(static_cast<double>(msud_input.Ia[TRAC_MOTOR1]), 6, 'f', 1);
}
