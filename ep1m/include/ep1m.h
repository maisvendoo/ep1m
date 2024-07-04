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

     /// Имя модуля сцепного устройства
     QString coupling_module_name;
     /// Имя конфига сцепного устройства
     QString coupling_config_name;

     /// Сцепка спереди
     Coupling *coupling_fwd;
     /// Сцепка сзади
     Coupling *coupling_bwd;

     /// Расцепной рычаг спереди
     OperatingRod *oper_rod_fwd;
     /// Расцепной рычаг сзади
     OperatingRod *oper_rod_bwd;

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

    Relay   *kv21;

    Relay   *kv22;

    Relay   *kv23;

    Relay   *kv41;

    Relay   *km7;

    Relay   *km8;

    Relay   *km9;

    Relay   *km11;

    Relay   *km12;

    Relay   *km13;

    /// Контроллер машиниста
    TracController  *km;

    /// Блок сигнализации БС-002
    SignalizationModule *signals_module;

    bool return_GV;

    /// Преобразователь частоты и числа фаз (ПЧФ)
    FreqPhaseConverter *freq_phase_conv;

    /// Передаточное число тягового редуктора
    double ip;

    /// Сигнал на проводе Н36
    bool is_H36;

    /// Сигнал на проводе Н211
    bool is_N211_on;

    /// Регистрировать параметры движения
    bool is_Registrator_on;

    /// Сигнал на проводе Н45
    bool is_N45_on;

    /// Сигнал на проводе Н53
    bool is_N53_on;

    /// Реверсор
    Reversor *reversor;

    /// Темп утечки из главного резервуара
    double main_res_leak;

    /// Мотор-компрессор
    ACMotorCompressor   *motor_compressor;

    /// Регулятор давления в ГР
    PressureRegulator   *press_reg;

    /// Главный резервуар
    Reservoir           *main_reservoir;

    /// Концевой кран питательной магистрали спереди
    PneumoAngleCock     *anglecock_fl_fwd;

    /// Концевой кран питательной магистрали сзади
    PneumoAngleCock     *anglecock_fl_bwd;

    /// Рукав питательной  магистрали спереди
    PneumoHose          *hose_fl_fwd;

    /// Рукав питательной  магистрали сзади
    PneumoHose          *hose_fl_bwd;

    double  charge_press;

    /// Сигнализатор давления в ТМ
    HysteresisRelay *sp4;

    /// Блокировочное устройство УБТ усл.№367м
    BrakeLock           *brake_lock;

    /// Поездной кран машиниста усл.№395
    BrakeCrane          *brake_crane;

    /// Кран впомогательного тормоза усл.№254
    LocoCrane           *loco_crane;

    /// ЭПК автостопа
    AutoTrainStop       *epk;

    /// Тормозная магистраль
    Reservoir           *brakepipe;

    /// Воздухораспределитель
    AirDistributor      *air_dist;

    /// Электровоздухораспределитель
    ElectroAirDistributor  *electro_air_dist;

    /// Запасный резервуар
    Reservoir           *supply_reservoir;

    /// Концевой кран тормозной магистрали спереди
    PneumoAngleCock     *anglecock_bp_fwd;

    /// Концевой кран тормозной магистрали сзади
    PneumoAngleCock     *anglecock_bp_bwd;

    /// Рукав тормозной магистрали спереди
    PneumoHoseEPB       *hose_bp_fwd;

    /// Рукав тормозной магистрали сзади
    PneumoHoseEPB       *hose_bp_bwd;

    /// Повторительное пневмореле для давления от воздухораспределителя РД4
    PneumoRelay         *rd4;

    /// Переключательный клапан КП1
    SwitchingValve      *kp1;

    /// Переключательный клапан КП2
    SwitchingValve      *kp2;

    /// Переключательный клапан КП5
    SwitchingValve      *kp5;

    /// Тройники для распределения воздуха от переключательного клапана
    /// к тележкам
    std::array<PneumoSplitter *, 2> bc_splitter;

    enum
    {
        NUM_TROLLEYS = 3,
        NUM_AXIS_PER_TROLLEY = 2,
        TROLLEY_FWD = 0,
        TROLLEY_MID = 1,
        TROLLEY_BWD = 2
    };

    /// Повторительное реле давления тележек
    std::array<PneumoRelay *, NUM_TROLLEYS> bc_pressure_relay;

    /// Тормозные механизмы тележек
    std::array<BrakeMech *, NUM_TROLLEYS> brake_mech;

    /// Источник питания ЭПТ
    EPBConverter        *epb_converter;

    /// Блок управления двухпроводного ЭПТ
    EPBControl          *epb_control;

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

    /// Контактор мотор-вентилятора ББР
    Relay       *km14;

    /// Контактор К1
    Relay       *k1;

    /// Вентиль отпуска У3
    ElectroPneumoValve *Y3;

    /// Вентиль замещения ЭДТ У4
    ElectroPneumoValve *Y4;

    /// Вентиль усиления торможения У5
    ElectroPneumoValve *Y5;

    /// Панель пневматических редукторов
    PneumoReducerPanel *pneumo_red_panel;

    /// Датчик давления магистрали передней тележки (ТЦ1 и ТЦ2)
    PressureSensor *sp3;

    /// Датчик аварийного давления в ТМ SP6
    PressureSensor  *sp6;

    /// Регистратор параметров движения (для отладки и испытаний)
    Registrator *registrator;

    /// Свисток и тифон
    TrainHorn *horn;

    /// Система подачи песка
    SandingSystem *sand_system;

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

    /// Инициализация сцепных устройств
    void initCouplings(const QString &modules_dir, const QString &custom_cfg_dir);

    /// Инициализация подсистемы питания цепей управления
    void initControlPower(const QString &modules_dir, const QString &custom_cfg_dir);

    /// Инициализация цепей управления
    void initControlCircuit(const QString &modules_dir, const QString &custom_cfg_dir);

    /// Инициализация АЗВ
    void initAZV(const QString &modules_dir, const QString &custom_cfg_dir);

    /// Инициализация пульта управления в кабине
    void initPanel(const QString &modules_dir, const QString &custom_cfg_dir);

    /// Инициализация МСУД
    void initMSUD(const QString &modules_dir, const QString &custom_cfg_dir);

    /// Инициализация силовой схемы
    void initPowerCircuit(const QString &modules_dir, const QString &custom_cfg_dir);

    /// Инициализация питательной магистрали
    void initPneumoSupply(const QString &modules_dir, const QString &custom_cfg_dir);

    /// Инициализация приборов управления тормозами
    void initBrakesControl(const QString &modules_dir, const QString &custom_cfg_dir);

    /// Инициализация тормозного оборудования
    void initBrakesEquipment(const QString &modules_dir, const QString &custom_cfg_dir);

    /// Инициализация ЭПТ
    void initEPB(const QString &modules_dir, const QString &custom_cfg_dir);

    /// Инициализация вспомогательных машин
    void initAuxMachines(const QString &modules_dir, const QString &custom_cfg_dir);

    /// Инициализация устройств безопасности
    void initSafetyDevices(const QString &modules_dir, const QString &custom_cfg_dir);

    /// Инициализация прочих устройств
    void initOtherEquipment(const QString &modules_dir, const QString &custom_cfg_dir);

    /// Инициализация озвучки
    void initSounds();

    /// Инициализация перестуков
    void initTapSounds();

    /// Инициализация регистратора параметров движения
    void initRegistartor(const QString &modules_dir, const QString &custom_cfg_dir);

    /// Предварительные расчёты перед симуляцией
    void preStep(double t) override;

    /// Предварительный расчёт координат сцепных устройств
    void preStepCouplings(double t);

    /// Шаг симуляции всех систем электровоза
    void step(double t, double dt) override;

    /// Моделирование сцепных устройств
    void stepCouplings(double t, double dt);

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

    /// Шаг моделирования питательной магистрали
    void stepPneumoSupply(double t, double dt);

    /// Шаг моделирования приборов управления тормозами
    void stepBrakesControl(double t, double dt);

    /// Шаг моделирования тормозного оборудования
    void stepBrakesEquipment(double t, double dt);

    /// Шаг моделирования ЭПТ
    void stepEPB(double t, double dt);

    void stepAuxMachines(double t, double dt);

    void stepSafetyDevices(double t, double dt);

    void stepOtherEquipment(double t, double dt);

    void stepTapSounds();

    void signalsOutput();

    /// Отладочная печать по F1
    void stepDebugPrint(double t, double dt);

    void keyProcess() override;

    void loadConfig(QString path) override;

    void initBrakeDevices(double p0, double pBP, double PFL) override;

    void load_brakes_config(QString path);

    double calcTracForce();

    void stepRegistration(double t, double dt);
};

#endif // EP1M_H
