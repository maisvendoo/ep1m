#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepOtherEquipment(double t, double dt)
{
    horn->setControl(keys);
    horn->step(t, dt);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepTapSounds()
{
    double speed = abs(this->velocity) * 3.6;

    for (int i = 0; i < tap_sounds.count(); ++i)
    {
        emit volumeCurveStep(tap_sounds[i], static_cast<float>(speed));
    }
}
