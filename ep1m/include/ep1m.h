#ifndef EP1M_H
#define EP1M_H

#include    "defines.h"
#include    "vehicle-api.h"
#include    "ep1m-signals.h"
#include    "ep1m-tumblers.h"
#include    "tumblers-panel.h"
#include    "azv.h"
#include    "msud.h"
#include    "battery.h"
#include    "power-supply.h"
#include    "trac-transformer.h"
#include    "pantograph.h"
#include    "protective-device.h"
#include    "relay.h"
#include    "electro-valve.h"
#include    "km-35-01.h"
#include    "bs-002.h"
#include    "freq-phase-converter.h"
#include    "motor-compressor.h"
#include    "pressure-regulator.h"
#include    "motor-fan.h"
#include    "ubt367m.h"

//---------------------------------------------------------------------
//
//---------------------------------------------------------------------
class EP1m : public Vehicle
{
public:

     /// Конструктор класса
     EP1m(QObject *parent = Q_NULLPTR);

     /// Деструктор класс
     ~EP1m() override;

private:

    /// Панель тумблеров
    EP1MTumblersPanel   *tumblers_panel;

    /// МСУД
    MSUD    *msud;

    /// Напряжение питания цепей управления
    double  Ucc;

    /// Аккумуляторная батарея 21KL-125P
    Battery *battery;

    /// Шкаф питания ШП-21
    PowerSupply *power_supply;

    /// Ток, потребляемый цепями управления
    double Icc;

    /// Тяговый трансформатор
    TractionTransformer *trac_trans;

    /// Главный выключатель
    ProtectiveDevice *main_switch;

    /// Напряжение на крышевой шине
    double Ukr;

    /// Контактор КМ5 включения ШП-21
    Relay   *km5;

    /// Вентиль защиты ВЗ-6
    ElectroValve    *safety_valve;

    /// Промежуточное реле KV44
    Relay           *kv44;

    /// Промежуточное реле KV39
    Relay           *kv39;

    Relay           *kv21;

    Relay           *kv22;

    Relay           *kv23;

    Relay           *kv41;

    /// Контроллер машиниста
    TracController  *km;

    /// Блок сигнализации БС-002
    SignalizationModule *signals_module;

    bool return_GV;

    /// Главный (питательный) резервуар
    Reservoir   *main_res;

    /// Темп утечки из главного резервуара
    double main_res_leak;

    /// Мотор-компрессор
    MotorCompressor *main_compressor;

    /// Реле-регулятор давления
    PressureRegulator *press_reg;

    /// Преобразователь частоты и числа фаз (ПЧФ)
    FreqPhaseConverter *freq_phase_conv;

    Relay   *km7;

    Relay   *km8;

    Relay   *km9;

    Relay   *km11;

    Relay   *km12;

    Relay   *km13;

    BrakeLock *ubt;

    LocoCrane *loco_crane;

    BrakeCrane *brake_crane;

    enum
    {
        PANT_NUMBER = 2,
        PANT1 = 0,
        PANT2 = 1
    };

    /// Данные, передаваемые в МСУД-Н
    msud_input_t msud_input;

    /// Токоприемники
    std::array<Pantograph *, PANT_NUMBER> pant;

    /// Автоматические защитные выключатели
    std::array<Trigger, AZV_NUMBER> azv;

    /// Тумблеры и кнопки вне блокируемой панели
    std::array<Trigger, TUMBLERS_COUNT> tumblers;

    /// Мотор-вентиляторы М11 - М13
    std::array<MotorFan *, MOTOR_FANS_NUM> motor_fan;

    void initialization() override;

    /// Инициализация подсистемы питания цепей управления
    void initControlPower();

    /// Инициализация цепей управления
    void initControlCircuit();

    /// Инициализация АЗВ
    void initAZV();

    /// Инициализация пульта управления в кабине
    void initPanel();

    /// Инициализация МСУД
    void initMSUD();

    /// Инициализация силовой схемы
    void initPowerCircuit();

    /// Инициализация системы подготовки сжатого воздуха
    void initAirSupplySystem();

    /// Инициализация вспомогательных машин
    void initAuxMachines();

    /// Инициализация приборов управления тормозами
    void initBrakeControl();

    /// Инициализация озвучки
    void initSounds();

    void stepControlPower(double t, double dt);

    void stepControlCircuit(double t, double dt);

    bool getHoldingCoilState();

    void stepPanel(double t, double dt);

    void setSignalsModuleInputs();

    void stepMSUD(double t, double dt);

    void stepPowerCircuit(double t, double dt);

    void stepAirSupplySystem(double t, double dt);

    void stepAuxMachines(double t, double dt);

    void stepBrakeControl(double t, double dt);

    void signalsOutput();

    /// Отладочная печать по F1
    void stepDebugPrint(double t, double dt);

    void step(double t, double dt) override;

    void keyProcess() override;

    void loadConfig(QString path) override;
};

#endif // EP1M_H
