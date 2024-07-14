#include    "ep1m.h"

#include    "filesystem.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
EP1m::EP1m(QObject *parent) : Vehicle (parent)
  , coupling_module_name("sa3")
  , coupling_config_name("sa3")
  , coupling_fwd(nullptr)
  , coupling_bwd(nullptr)
  , oper_rod_fwd(nullptr)
  , oper_rod_bwd(nullptr)
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
  , is_Registrator_on(false)
  , is_N45_on(false)
  , is_N53_on(false)
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
    QString modules_dir = QString(fs.getModulesDir().c_str());
    QString custom_cfg_dir(fs.getVehiclesDir().c_str());
    custom_cfg_dir += fs.separator() + config_dir;

    // Инициализация сцепных устройств
    initCouplings(modules_dir, custom_cfg_dir);

    // Инициализация питания цепей управления
    initControlPower(modules_dir, custom_cfg_dir);

    // Инициализация цепей управления
    initControlCircuit(modules_dir, custom_cfg_dir);

    // Инициализация АЗВ
    initAZV(modules_dir, custom_cfg_dir);

    // Инициализация пульта управления в кабине
    initPanel(modules_dir, custom_cfg_dir);

    // Инициализация микропроцессорной системы управления и диагностики (МСУД)
    initMSUD(modules_dir, custom_cfg_dir);

    // Инициализация силовой схемы
    initPowerCircuit(modules_dir, custom_cfg_dir);

    // Инициализация системы подготовки сжатого воздуха
    initPneumoSupply(modules_dir, custom_cfg_dir);

    // Инициализация приборов управления тормозами
    initBrakesControl(modules_dir, custom_cfg_dir);

    // Инициализация приборов торможения
    initBrakesEquipment(modules_dir, custom_cfg_dir);

    // Инициализация ЭПТ
    initEPB(modules_dir, custom_cfg_dir);

    // Инициализация вспомогательных машин
    initAuxMachines(modules_dir, custom_cfg_dir);

    // Инициализация приборов безопасности
    initSafetyDevices(modules_dir, custom_cfg_dir);

    // Инициализация прочих устройств
    initOtherEquipment(modules_dir, custom_cfg_dir);

    // Инициализация озвучки
    initSounds();

    // Инициализация звуков перестука
    initTapSounds();

    // Инициализация регистратора
    if (is_Registrator_on)
        initRegistartor(modules_dir, custom_cfg_dir);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::preStep(double t)
{
    preStepCouplings(t);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::step(double t, double dt)
{
    // Моделирование сцепных устройств
    stepCouplings(t, dt);

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

    // Вывод сигналов для звуков
    stepSoundSignals(t, dt);

    // Отладочный вывод
    stepDebugPrint(t, dt);

    // Регистрация параметров движения
    if (is_Registrator_on)
        stepRegistration(t, dt);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
GET_VEHICLE(EP1m)
