#include    "ep1m.h"

//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
void EP1m::stepBrakesControl(double t, double dt)
{
    // Блокировочное устройство
    brake_lock->setFLpressure(main_reservoir->getPressure());
    brake_lock->setBPpressure(brakepipe->getPressure());
    brake_lock->setBCpressure(bc_switch_valve->getPressure1());
    brake_lock->setCraneFLflow(brake_crane->getFLflow() + loco_crane->getFLflow());
    brake_lock->setCraneBPflow(brake_crane->getBPflow());
    brake_lock->setCraneBCflow(loco_crane->getBCflow());
    brake_lock->setControl(keys);
    brake_lock->step(t, dt);

    // Поездной кран машиниста
    brake_crane->setFLpressure(brake_lock->getCraneFLpressure());
    brake_crane->setBPpressure(brake_lock->getCraneBPpressure());
    brake_crane->setControl(keys);
    brake_crane->step(t, dt);

    // Кран вспомогательного тормоза
    loco_crane->setFLpressure(brake_lock->getCraneFLpressure());
    loco_crane->setBCpressure(brake_lock->getCraneBCpressure());
    loco_crane->setILpressure(0.0);
    loco_crane->setControl(keys);
    loco_crane->step(t, dt);

    // ЭПК
    epk->setFLpressure(main_reservoir->getPressure());
    epk->setBPpressure(brakepipe->getPressure());
    epk->powerOn(klub_BEL->getEPKstate());
//    epk->setControl(keys);
    epk->keyOn(tumblers[EPK_KEY].getState());
    epk->step(t, dt);

    // Повторительное пневмореле для давления от воздухораспределителя РД4
    // Управляющая камера моделирует импульсный резервуар (ложный ТЦ)
    air_dist_pressure_relay->setFLpressure(main_reservoir->getPressure());
    air_dist_pressure_relay->setControlFlow(electro_air_dist->getBCflow());
    air_dist_pressure_relay->setPipePressure(bc_switch_valve->getPressure2());
    air_dist_pressure_relay->step(t, dt);

    // Переключательный клапан КП5
    // Выход клапана подключен через тройники к повторителям давления тележек
    bc_switch_valve->setInputFlow1(brake_lock->getBCflow());
    bc_switch_valve->setInputFlow2(air_dist_pressure_relay->getPipeFlow());
    bc_switch_valve->setOutputPressure(bc_splitter[0]->getInputPressure());
    bc_switch_valve->step(t, dt);

    // Тройники
    bc_splitter[0]->setInputFlow(bc_switch_valve->getOutputFlow());
    bc_splitter[0]->setPipePressure1(bc_pressure_relay[TROLLEY_MID]->getControlPressure());
    bc_splitter[0]->setPipePressure2(bc_splitter[1]->getInputPressure());
    bc_splitter[0]->step(t, dt);

    bc_splitter[1]->setInputFlow(bc_splitter[0]->getPipeFlow2());
    bc_splitter[1]->setPipePressure1(bc_pressure_relay[TROLLEY_FWD]->getControlPressure());
    bc_splitter[1]->setPipePressure2(bc_pressure_relay[TROLLEY_BWD]->getControlPressure());
    bc_splitter[1]->step(t, dt);

    // Повторительное реле давления №304 передней тележки
    bc_pressure_relay[TROLLEY_FWD]->setFLpressure(main_reservoir->getPressure());
    bc_pressure_relay[TROLLEY_FWD]->setControlFlow(bc_splitter[1]->getPipeFlow1());
    bc_pressure_relay[TROLLEY_FWD]->setPipePressure(brake_mech[TROLLEY_FWD]->getBCpressure());
    bc_pressure_relay[TROLLEY_FWD]->step(t, dt);

    // Повторительное реле давления №304 средней тележки
    bc_pressure_relay[TROLLEY_MID]->setFLpressure(main_reservoir->getPressure());
    bc_pressure_relay[TROLLEY_MID]->setControlFlow(bc_splitter[0]->getPipeFlow1());
    bc_pressure_relay[TROLLEY_MID]->setPipePressure(brake_mech[TROLLEY_MID]->getBCpressure());
    bc_pressure_relay[TROLLEY_MID]->step(t, dt);

    // Повторительное реле давления №304 задней тележки
    bc_pressure_relay[TROLLEY_BWD]->setFLpressure(main_reservoir->getPressure());
    bc_pressure_relay[TROLLEY_BWD]->setControlFlow(bc_splitter[1]->getPipeFlow2());
    bc_pressure_relay[TROLLEY_BWD]->setPipePressure(brake_mech[TROLLEY_BWD]->getBCpressure());
    bc_pressure_relay[TROLLEY_BWD]->step(t, dt);
}
