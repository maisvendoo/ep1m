#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::initPanel()
{
    tumblers_panel = new EP1MTumblersPanel();

    km = new TracController();

    signals_module = new SignalizationModule();
}
