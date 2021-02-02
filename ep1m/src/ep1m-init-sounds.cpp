#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::initSounds()
{
    connect(tumblers_panel, &EP1MTumblersPanel::soundPlay, this, &EP1m::soundPlay);
}
