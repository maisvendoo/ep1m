#include    "ep1m.h"

#include    "filesystem.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
EP1m::EP1m(QObject *parent) : Vehicle (parent)
  , tumblers_panel(Q_NULLPTR)
  , msud(Q_NULLPTR)
  , Ucc(0.0)
  , battery(Q_NULLPTR)
  , power_supply(Q_NULLPTR)
  , Icc(0.0)
  , trac_trans(Q_NULLPTR)
  , main_switch(Q_NULLPTR)
  , Ukr(0.0)
  , km5(Q_NULLPTR)
  , safety_valve(Q_NULLPTR)
  , kv44(Q_NULLPTR)
  , kv39(Q_NULLPTR)
  , km(Q_NULLPTR)
  , signals_module(Q_NULLPTR)
  , return_GV(false)
  , freq_phase_conv(Q_NULLPTR)
  , ip(1.0)
  , is_H36(false)
  , is_N211_on(false)
  , is_Registarator_on(false)
  , main_res_leak(1e-6)
  , charge_press(0.5)
{
    Uks = 25000.0;
    alsn_info.code_alsn = KLUB_ALSN_GREEN;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
EP1m::~EP1m()
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::initialization()
{
    FileSystem &fs = FileSystem::getInstance();
    QString modules_dir(fs.getModulesDir().c_str());

    // Инициализация питания цепей управления
    initControlPower();

    // Инициализация цепей управления
    initControlCircuit();

    // Инициализация АЗВ
    initAZV();

    // Инициализация пульта управления в кабине
    initPanel();

    // Инициализация микропроцессорной системы управления и диагностики (МСУД)
    initMSUD();

    // Инициализация силовой схемы
    initPowerCircuit();

    // Инициализация системы подготовки сжатого воздуха
    initPneumoSupply(modules_dir);

    // Инициализация приборов управления тормозами
    initBrakesControl(modules_dir);

    // Инициализация приборов торможения
    initBrakesEquipment(modules_dir);

    // Инициализация ЭПТ
    initEPB(modules_dir);

    // Инициализация вспомогательных машин
    initAuxMachines();

    // Инициализация приборов безопасности
    initSafetyDevices();

    // Инициализация прочих устройств
    initOtherEquipment();

    // Инициализация озвучки
    initSounds();

    // Инициализация звуков перестука
    initTapSounds();

    if (!is_Registarator_on)
        return;

    // Инициализация регистратора
    initRegistartor();
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::step(double t, double dt)
{
    // Работа подсистемы питания цепей управления
    stepControlPower(t, dt);

    // Работа цепей управления
    stepControlCircuit(t, dt);

    // Работа приборов управления в кабине
    stepPanel(t, dt);

    // Работа микропроцессорной системы управления и диагностики
    stepMSUD(t, dt);

    // Работа силовой схемы
    stepPowerCircuit(t, dt);

    // Работа системы подготовки сжатого воздуха
    stepPneumoSupply(t, dt);

    // Работа приборов управления тормозами
    stepBrakesControl(t, dt);

    // Работа приборов торможения
    stepBrakesEquipment(t, dt);

    // Работа ЭПТ
    stepEPB(t, dt);

    // Работа вспомогательных машин
    stepAuxMachines(t, dt);

    // Работа приборов безопасности
    stepSafetyDevices(t, dt);

    // Работа прочих устройств
    stepOtherEquipment(t, dt);

    // Перестуки
    stepTapSounds();

    // Вывод сигналов к внешней модели
    signalsOutput();

    // Отладочный вывод
    stepDebugPrint(t, dt);

    if (!is_Registarator_on)
        return;

    // Регистрация параметров движения
    stepRegistration(t, dt);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
GET_VEHICLE(EP1m)
