#ifndef     EP1M_H
#define     EP1M_H

#include    "ep1m-headers.h"

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

    double  charge_press;

    /// Передаточное число тягового редуктора
    double ip;

    /// Сигнал на проводе Н36
    bool is_H36;

    /// Сигнал на проводе Н211
    bool is_N211_on;

    /// Регистрировать параметры движения
    bool is_Registarator_on;

    /// Сигнал на проводе Н45
    bool is_N45_on;

    /// Сигнал на проводе Н53
    bool is_N53_on;    

    /// Реверсор
    Reversor *reversor;

    /// Сигнализатор давления в ТМ
    HysteresisRelay *sp4;

    Relay   *km7;

    Relay   *km8;

    Relay   *km9;

    Relay   *km11;

    Relay   *km12;

    Relay   *km13;


    BrakeLock *ubt;

    LocoCrane *loco_crane;

    BrakeCrane *brake_crane;

    AutoTrainStopEPK150 *epk;

    /// Запасный резервуар
    Reservoir *aux_res;

    /// Воздухораспределитель
    AirDistributor *air_dist;

    /// Электровоздухораспределитель
    ElectroAirDistributor *electro_air_dist;

    PneumoReley *rd4;

    PneumoReley *rd1;
    PneumoReley *rd2;
    PneumoReley *rd3;

    SwitchingValve *kp1;
    SwitchingValve *kp2;
    SwitchingValve *kp5;

    PneumoSplitter *ps1;
    PneumoSplitter *ps2;

    EPTConverter *ept_converter;
    EPTPassControl *ept_pass_control;

    /// Блок электронный локомотивный (БЭЛ)
    KLUB    *klub_BEL;

    /// Реле подачи питания на МСУД
    Relay   *km43;

    /// Промежуточное реле KV11
    Relay   *kv11;

    /// Промежуточное реле KV12
    Relay   *kv12;

    /// Промежуточное реле KV13
    Relay   *kv13;

    /// Промежуточное реле KV14
    Relay   *kv14;

    /// Промежуточное реле KV15
    Relay   *kv15;

    /// Реле КЛУБ
    Relay   *kv84;

    /// Реле выдержки времени КТ10
    TimeRelay   *kt10;

    /// Реле выдержки времени КТ1
    TimeRelay   *kt1;

    /// Тормозной переключатель
    BrakeSwitcher *qt1;

    /// Контактор KM41
    Relay       *km41;

    /// Контактор KM42
    Relay       *km42;

    /// Реле выдержки времени КТ4
    TimeRelay   *kt4;

    /// Реле выдержки времени КТ5
    TimeRelay   *kt5;

    /// контактор мотор-вентилятора ББР
    Relay       *km14;

    /// контактор К1
    Relay       *k1;

    /// вентиль отпуска
    ElectroPneumoValve *Y3;

    /// датчик аварийного давления в ТМ SP6
    PressureSensor  *sp6;

    /// Регистратор параметров движения (для отладки и испытаний)
    Registrator *registrator;

    /// Свисток и тифон
    EP1mHorn *horn;

    /// Шунты ослабления возбуждения ТЭД
    ShuntsModule *shunts;

    /// Выпрямительна установка возбуждения ВУВ-118
    FieldRect *field_rect;

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

    /// Тормозные механизмы тележек
    enum
    {
        TROLLEYS_NUM = 3,
        FWD_TROLLEY = 0,
        MID_TROLLEY = 1,
        BWD_TROLLEY = 2
    };

    std::array<TrolleyBrakeMech *, TROLLEYS_NUM> brake_mech;

    std::array<TractionMotor *, TRAC_MOTORS_NUM> trac_motor;

    /// Быстродействующие выключатели ТЭД
    std::array<FastSwitch *, TRAC_MOTORS_NUM> fast_switch;

    /// Выпрямительно инверторные преобразователи
    enum
    {
        RECT_INV_CONV_NUM = 2,
        VIP1 = 0,
        VIP2 = 1
    };

    std::array<RectInvertConverter *, RECT_INV_CONV_NUM> vip;

    QList<QString> tap_sounds;

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

    /// Инициализация приборов торможения
    void initBrakeEquipment();

    /// Инициализация ЭПТ
    void initEPT();

    /// Инициализация устройств безопасности
    void initSafetyDevices();

    /// Инициализация прочих устройств
    void initOtherEquipment();

    /// Инициализация озвучки
    void initSounds();

    /// Инициализация перестуков
    void initTapSounds();

    /// Инициализация регистратора параметров движения
    void initRegistartor();

    void stepControlPower(double t, double dt);

    void stepControlCircuit(double t, double dt);

    bool getHoldingCoilState();

    /// Управление схемой тяги
    void stepTractionControl(double t, double dt);

    /// Управление схемой рекуперации
    void stepRecuperationControl(double t, double dt);


    void stepPanel(double t, double dt);

    void setSignalsModuleInputs();

    void stepMSUD(double t, double dt);

    void stepPowerCircuit(double t, double dt);

    void stepAirSupplySystem(double t, double dt);

    void stepAuxMachines(double t, double dt);

    void stepBrakeControl(double t, double dt);

    void stepBrakeEquipment(double t, double dt);

    void stepEPT(double t, double dt);

    void stepSafetyDevices(double t, double dt);

    void stepOtherEquipment(double t, double dt);

    void stepTapSounds();

    void signalsOutput();

    /// Отладочная печать по F1
    void stepDebugPrint(double t, double dt);

    void step(double t, double dt) override;

    void keyProcess() override;

    void loadConfig(QString path) override;

    void initBrakeDevices(double p0, double pTM, double PFL) override;

    void load_brakes_config(QString path);

    double calcTracForce();

    void stepRegistration(double t, double dt);
};

#endif // EP1M_H
