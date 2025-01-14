#ifndef     EP1M_H
#define     EP1M_H

#include    <ep1m-headers.h>

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
    QString coupling_module_name = "sa3";
    /// Имя конфига сцепного устройства
    QString coupling_config_name = "sa3";

    /// Сцепка спереди
    Coupling *coupling_fwd = Q_NULLPTR;
    /// Сцепка сзади
    Coupling *coupling_bwd = Q_NULLPTR;

    /// Расцепной рычаг спереди
    OperatingRod *oper_rod_fwd = Q_NULLPTR;
    /// Расцепной рычаг сзади
    OperatingRod *oper_rod_bwd = Q_NULLPTR;

    /// Панель тумблеров
    EP1MTumblersPanel   *tumblers_panel = Q_NULLPTR;

    /// МСУД
    MSUD    *msud = Q_NULLPTR;

    /// Напряжение питания цепей управления
    double  Ucc = 0.0;

    /// Аккумуляторная батарея 21KL-125P
    Battery *battery = Q_NULLPTR;

    /// Шкаф питания ШП-21
    PowerSupply *power_supply = Q_NULLPTR;

    /// Ток, потребляемый цепями управления
    double Icc = 0.0;

    /// Тяговый трансформатор
    TractionTransformer *trac_trans = Q_NULLPTR;

    /// Главный выключатель
    ProtectiveDevice *main_switch = Q_NULLPTR;

    /// Напряжение на крышевой шине
    double Ukr = 0.0;

    /// Контактор КМ5 включения ШП-21
    Relay   *km5 = Q_NULLPTR;

    /// Вентиль защиты ВЗ-6
    ElectroValve    *safety_valve = Q_NULLPTR;

    /// Промежуточное реле KV44
    Relay           *kv44 = Q_NULLPTR;

    /// Промежуточное реле KV39
    Relay           *kv39 = Q_NULLPTR;

    Relay   *kv21 = Q_NULLPTR;

    Relay   *kv22 = Q_NULLPTR;

    Relay   *kv23 = Q_NULLPTR;

    Relay   *kv41 = Q_NULLPTR;

    Relay   *km7 = Q_NULLPTR;

    Relay   *km8 = Q_NULLPTR;

    Relay   *km9 = Q_NULLPTR;

    Relay   *km11 = Q_NULLPTR;

    Relay   *km12 = Q_NULLPTR;

    Relay   *km13 = Q_NULLPTR;

    /// Контроллер машиниста
    TracController  *km = Q_NULLPTR;

    /// Блок сигнализации БС-002
    SignalizationModule *signals_module = Q_NULLPTR;

    bool return_GV = false;

    /// Преобразователь частоты и числа фаз (ПЧФ)
    FreqPhaseConverter *freq_phase_conv  = Q_NULLPTR;

    /// Передаточное число тягового редуктора
    double ip = 1.0;

    /// Сигнал на проводе Н36
    bool is_H36 = false;

    /// Сигнал на проводе Н211
    bool is_N211_on = false;

    /// Сигнал на проводе Н212
    bool is_N212_on = false;

    /// Регистрировать параметры движения
    bool is_Registrator_on = false;

    /// Сигнал на проводе Н45
    bool is_N45_on = false;

    /// Сигнал на проводе Н53
    bool is_N53_on = false;

    /// Реверсор
    Reversor *reversor = Q_NULLPTR;

    /// Темп утечки из главного резервуара
    double main_res_leak = 1e-6;

    /// Мотор-компрессор
    ACMotorCompressor   *motor_compressor  = Q_NULLPTR;

    /// Регулятор давления в ГР
    PressureRegulator   *press_reg = Q_NULLPTR;

    /// Главный резервуар
    Reservoir           *main_reservoir = Q_NULLPTR;

    /// Концевой кран питательной магистрали спереди
    PneumoAngleCock     *anglecock_fl_fwd = Q_NULLPTR;

    /// Концевой кран питательной магистрали сзади
    PneumoAngleCock     *anglecock_fl_bwd = Q_NULLPTR;

    /// Рукав питательной  магистрали спереди
    PneumoHose          *hose_fl_fwd = Q_NULLPTR;

    /// Рукав питательной  магистрали сзади
    PneumoHose          *hose_fl_bwd = Q_NULLPTR;

    double  charge_press = 0.5;

    /// Сигнализатор давления в ТМ
    HysteresisRelay *sp4 = Q_NULLPTR;

    /// Блокировочное устройство УБТ усл.№367м
    BrakeLock           *brake_lock = Q_NULLPTR;

    /// Поездной кран машиниста усл.№395
    BrakeCrane          *brake_crane = Q_NULLPTR;

    /// Кран впомогательного тормоза усл.№254
    LocoCrane           *loco_crane = Q_NULLPTR;

    /// ЭПК автостопа
    AutoTrainStop       *epk = Q_NULLPTR;

    /// Тормозная магистраль
    Reservoir           *brakepipe = Q_NULLPTR;

    /// Воздухораспределитель
    AirDistributor      *air_dist = Q_NULLPTR;

    /// Электровоздухораспределитель
    ElectroAirDistributor  *electro_air_dist = Q_NULLPTR;

    /// Запасный резервуар
    Reservoir           *supply_reservoir = Q_NULLPTR;

    /// Концевой кран тормозной магистрали спереди
    PneumoAngleCock     *anglecock_bp_fwd = Q_NULLPTR;

    /// Концевой кран тормозной магистрали сзади
    PneumoAngleCock     *anglecock_bp_bwd = Q_NULLPTR;

    /// Рукав тормозной магистрали спереди
    PneumoHoseEPB       *hose_bp_fwd = Q_NULLPTR;

    /// Рукав тормозной магистрали сзади
    PneumoHoseEPB       *hose_bp_bwd = Q_NULLPTR;

    /// Повторительное пневмореле для давления от воздухораспределителя РД4
    PneumoRelay         *rd4 = Q_NULLPTR;

    /// Переключательный клапан КП1
    SwitchingValve      *kp1 = Q_NULLPTR;

    /// Переключательный клапан КП2
    SwitchingValve      *kp2 = Q_NULLPTR;

    /// Переключательный клапан КП5
    SwitchingValve      *kp5 = Q_NULLPTR;

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
    EPBConverter        *epb_converter = Q_NULLPTR;

    /// Блок управления двухпроводного ЭПТ
    EPBControl          *epb_control = Q_NULLPTR;

    /// Блок электронный локомотивный (БЭЛ)
    SafetyDevice *KLUB_BEL;

    /// Реле подачи питания на МСУД
    Relay   *km43 = Q_NULLPTR;

    /// Промежуточное реле KV11
    Relay   *kv11 = Q_NULLPTR;

    /// Промежуточное реле KV12
    Relay   *kv12 = Q_NULLPTR;

    /// Промежуточное реле KV13
    Relay   *kv13 = Q_NULLPTR;

    /// Промежуточное реле KV14
    Relay   *kv14 = Q_NULLPTR;

    /// Промежуточное реле KV15
    Relay   *kv15 = Q_NULLPTR;

    /// Реле КЛУБ
    Relay   *kv84 = Q_NULLPTR;

    /// Реле выдержки времени КТ10
    TimeRelay   *kt10 = Q_NULLPTR;

    /// Реле выдержки времени КТ1
    TimeRelay   *kt1 = Q_NULLPTR;

    /// Тормозной переключатель
    BrakeSwitcher *qt1 = Q_NULLPTR;

    /// Контактор KM41
    Relay       *km41 = Q_NULLPTR;

    /// Контактор KM42
    Relay       *km42 = Q_NULLPTR;

    /// Реле выдержки времени КТ4
    TimeRelay   *kt4 = Q_NULLPTR;

    /// Реле выдержки времени КТ5
    TimeRelay   *kt5 = Q_NULLPTR;

    /// Контактор мотор-вентилятора ББР
    Relay       *km14 = Q_NULLPTR;

    /// Контактор К1
    Relay       *k1 = Q_NULLPTR;

    /// Вентиль отпуска У3
    ElectroPneumoValve *Y3 = Q_NULLPTR;

    /// Вентиль замещения ЭДТ У4
    ElectroPneumoValve *Y4 = Q_NULLPTR;

    /// Вентиль усиления торможения У5
    ElectroPneumoValve *Y5 = Q_NULLPTR;

    /// Панель пневматических редукторов
    PneumoReducerPanel *pneumo_red_panel = Q_NULLPTR;

    /// Датчик давления магистрали передней тележки (ТЦ1 и ТЦ2)
    PressureSensor *sp3 = Q_NULLPTR;

    /// Датчик аварийного давления в ТМ SP6
    PressureSensor  *sp6 = Q_NULLPTR;

    /// Регистратор параметров движения (для отладки и испытаний)
    Registrator *registrator = Q_NULLPTR;

    /// Свисток и тифон
    TrainHorn *horn = Q_NULLPTR;

    /// Система подачи песка
    SandingSystem *sand_system = Q_NULLPTR;

    /// Шунты ослабления возбуждения ТЭД
    ShuntsModule *shunts = Q_NULLPTR;

    /// Выпрямительна установка возбуждения ВУВ-118
    FieldRect *field_rect = Q_NULLPTR;

    enum
    {
        PANT_NUMBER = 2,
        PANT1 = 0,
        PANT2 = 1
    };

    /// Данные, передаваемые в МСУД-Н
    msud_input_t msud_input = msud_input_t();

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

    /// Ограничения скорости на путевой инфраструктуре для кабины А
    SpeedMap    *speedmap_fwd = Q_NULLPTR;
    /// Ограничения скорости на путевой инфраструктуре для кабины Б
    SpeedMap    *speedmap_bwd = Q_NULLPTR;

    /// Приёмная катушка АЛСН для кабины А
    CoilALSN    *coil_ALSN_fwd = Q_NULLPTR;
    /// Приёмная катушка АЛСН для кабины Б
    CoilALSN    *coil_ALSN_bwd = Q_NULLPTR;

    /// Дешифратор сигнала АЛСН
    DecoderALSN *alsn_decoder = Q_NULLPTR;

    double      v_max = 140.0;

    QString     plugin_safety_device = "";

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

    void signalsOutput();

    void stepSoundSignals(double t, double dt);

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
