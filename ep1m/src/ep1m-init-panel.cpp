#include    "ep1m.h"

#include    <QDir>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::initPanel(const QString& modules_dir, const QString& custom_cfg_dir)
{
    (void) modules_dir;

    tumblers_panel = new EP1MTumblersPanel();

    km = new TracController();
    km->read_config("km-35-01", custom_cfg_dir);

    signals_module = new SignalizationModule();

    tumblers[BUTTON_EMERGENCY_BRAKE].set();
    //tumblers[TUMBLER_AUTO_MODE].set();
}
