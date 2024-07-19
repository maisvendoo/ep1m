#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepSoundSignals(double t, double dt)
{
    (void) t;
    (void) dt;

    analogSignal[SOUND_SVISTOK] = horn->getSoundSignal(TrainHorn::SVISTOK_SOUND);
    analogSignal[SOUND_TIFON] = horn->getSoundSignal(TrainHorn::TIFON_SOUND);
}
