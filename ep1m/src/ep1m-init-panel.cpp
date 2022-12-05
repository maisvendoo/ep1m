#include    "ep1m.h"

#include    <QDir>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::initPanel()
{
    tumblers_panel = new EP1MTumblersPanel();

    km = new TracController();
    km->read_custom_config(config_dir + QDir::separator() + "km-35-01");

    signals_module = new SignalizationModule();

    tumblers[BUTTON_EMERGENCY_BRAKE].set();
    //tumblers[TUMBLER_AUTO_MODE].set();
}
