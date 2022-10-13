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
        brake_mech[i]->setEffFricRadius(wheel_diameter / 2.0);
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

    ps1 = new PneumoSplitter();
    ps1->read_config("pneumo-splitter");

    ps2 = new PneumoSplitter();
    ps2->read_config("pneumo-splitter");

    rd1 = new PneumoReley();
    rd1->read_config("rd304");

    rd2 = new PneumoReley();
    rd2->read_config("rd304");

    rd3 = new PneumoReley();
    rd3->read_config("rd304");

    rd4 = new PneumoReley();
    rd4->read_config("rd304");

    kp1 = new SwitchingValve();
    kp1->read_config("zpk");

    kp2 = new SwitchingValve();
    kp2->read_config("zpk");

    kp5 = new SwitchingValve();
    kp5->read_config("zpk");

    aux_res = new Reservoir(0.055);

    QString air_dist_path = QString(fs.combinePath(fs.getModulesDir(), "vr242").c_str());
    air_dist = loadAirDistributor(air_dist_path);
    air_dist->read_config("vr242");

    QString electro_air_dist_path = QString(fs.combinePath(fs.getModulesDir(), "evr305").c_str());
    electro_air_dist = loadElectroAirDistributor(electro_air_dist_path);
    electro_air_dist->read_config("evr305");
}
