#include    "ep1m.h"

#include    <QDir>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::initMSUD()
{
    msud = new MSUD();
    msud->read_custom_config(config_dir + QDir::separator() +  "msud");
    msud->init();
}
