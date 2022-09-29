#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepDebugPrint(double t, double dt)
{
    Q_UNUSED(t)
    Q_UNUSED(dt)

    DebugMsg = QString("Пульт: %1 Ucc: %2 ВВК: %3")
            .arg(static_cast<int>(tumblers_panel->getUnlockKeyState()), 1)
            .arg(static_cast<float>(Ucc), 5, 'f', 2)
            .arg(static_cast<int>(safety_valve->getState()), 1);
}
