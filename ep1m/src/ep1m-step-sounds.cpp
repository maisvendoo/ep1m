#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepSoundSignals(double t, double dt)
{
    (void) t;
    (void) dt;

    analogSignal[SOUND_SVISTOK] = horn->getSvistokSound().createSoundSignal();
    analogSignal[SOUND_TIFON] = horn->getTifonSound().createSoundSignal();
}
