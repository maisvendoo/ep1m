#include    "ep1m.h"

#include    "filesystem.h"


//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::initBrakeControl()
{
    FileSystem &fs = FileSystem::getInstance();

    ubt = new BrakeLock();
    ubt->read_config("ubt367m");

    QString brake_crane_cfg = QString(fs.combinePath(fs.getModulesDir(), "krm395").c_str());
    brake_crane = loadBrakeCrane(brake_crane_cfg);
    brake_crane->read_config("krm395");

    QString loco_crane_cfg = QString(fs.combinePath(fs.getModulesDir(), "kvt254").c_str());
    loco_crane = loadLocoCrane(loco_crane_cfg);
    loco_crane->read_config("kvt254");
}
