#include    "filesystem.h"

#include    "ep1m.h"

//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
void EP1m::initBrakesControl(QString modules_dir)
{
    // Блокировочное устройство
    brake_lock = new BrakeLock();
    brake_lock->read_config("ubt367m");

    // Поездной кран машиниста
    brake_crane = loadBrakeCrane(modules_dir + QDir::separator() + "krm395");
    brake_crane->read_config("krm395");

    // Кран вспомогательного тормоза
    loco_crane = loadLocoCrane(modules_dir + QDir::separator() + "kvt254");
    loco_crane->read_custom_config(config_dir + QDir::separator() + "kvt215");

    // ЭПК
    epk = loadAutoTrainStop(modules_dir + QDir::separator() + "epk150");
    epk->read_config("epk150");

    // Повторительное пневмореле для давления от воздухораспределителя РД4
    air_dist_pressure_relay = new PneumoRelay();
    air_dist_pressure_relay->read_custom_config(config_dir + QDir::separator() + "rd4");

    // Переключательный клапан КП5
    bc_switch_valve = new SwitchingValve();
    bc_switch_valve->read_custom_config(config_dir + QDir::separator() + "kp5");

    // Тройники
    bc_splitter[0] = new PneumoSplitter();
    bc_splitter[0]->read_config("pneumo-splitter");
    bc_splitter[1] = new PneumoSplitter();
    bc_splitter[1]->read_config("pneumo-splitter");

    // Повторительное реле давления тележек
    bc_pressure_relay[TROLLEY_FWD] = new PneumoRelay();
    bc_pressure_relay[TROLLEY_FWD]->read_config("rd304");
    bc_pressure_relay[TROLLEY_MID] = new PneumoRelay();
    bc_pressure_relay[TROLLEY_MID]->read_config("rd304");
    bc_pressure_relay[TROLLEY_BWD] = new PneumoRelay();
    bc_pressure_relay[TROLLEY_BWD]->read_config("rd304");
}
