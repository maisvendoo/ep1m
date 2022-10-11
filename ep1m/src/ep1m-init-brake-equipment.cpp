#include    "ep1m.h"

#include    <QDir>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::initBrakeEquipment()
{
    for (size_t i = 0; i < brake_mech.size(); ++i)
    {
        brake_mech[i] = new TrolleyBrakeMech();
    }
}
