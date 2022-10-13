#include    "ep1m.h"

#include    "filesystem.h"
#include    <QDir>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::initBrakeDevices(double p0, double pTM, double pFL)
{
    main_res->setY(0, pFL);
    charge_press = p0;

    brake_crane->setChargePressure(charge_press);
    brake_crane->init(pTM, pFL);
    loco_crane->init(pTM, pFL);

    epk->init(pTM, pFL);

    load_brakes_config(config_dir + QDir::separator() + "brakes-init.xml");
}

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
    loco_crane->read_custom_config(config_dir + QDir::separator() + "kvt215");
}
