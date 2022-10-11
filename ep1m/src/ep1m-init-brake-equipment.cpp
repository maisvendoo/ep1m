#include    "ep1m.h"

#include    <QDir>

#include    "filesystem.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::initBrakeEquipment()
{
    FileSystem &fs = FileSystem::getInstance();

    QString epk_path = QString(fs.combinePath(fs.getModulesDir(), "epk150").c_str());
    epk = loadAutoTrainStop(epk_path);
    epk->read_config("epk150");

    for (size_t i = 0; i < brake_mech.size(); ++i)
    {
        brake_mech[i] = new TrolleyBrakeMech();
    }

    brake_mech[FWD_TROLLEY]->read_custom_config(config_dir +
                                                QDir::separator() +
                                                "fwd-trolley-brake");

    brake_mech[MID_TROLLEY]->read_custom_config(config_dir +
                                                QDir::separator() +
                                                "mid-trolley-brake");

    brake_mech[BWD_TROLLEY]->read_custom_config(config_dir +
                                                QDir::separator() +
                                                "bwd-trolley-brake");
}
