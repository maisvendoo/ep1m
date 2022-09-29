#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepDebugPrint(double t, double dt)
{
    Q_UNUSED(t)
    Q_UNUSED(dt)

    DebugMsg = QString("Блок.: %1")
            .arg(static_cast<int>(tumblers_panel->getUnlockKeyState()));
}
