#ifndef     MSUD_H
#define     MSUD_H

#include    "device.h"

#include    "msud-data.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class MSUD : public Device
{
public:

    MSUD(QObject *parent = Q_NULLPTR);

    ~MSUD() override;

    /// Общая инициализация МСУД
    void init();

    void setPowerVoltage(double Uc);

    void setInputData(const msud_input_t &msud_input)
    {
        this->msud_input = msud_input;
    }

    msud_output_t getOutputData() const
    {
        return this->msud_output;
    }

private:

    // Напряжение питания
    double  Uc;    

    // Минимально допустимое напряжение питания МСУД
    double  Uc_min;

    // Условное время загрузки МСУД после включения питания
    double  load_time;

    // Таймер загрузки МСУД
    Timer   *load_timer;

    bool is_fans_low_freq;

    Timer *normalFreqTimer;

    Timer *lowFreqTimer;

    Timer *fansBustTimer;

    Timer *runOutTimer;

    size_t fans_count;

    double fan_switch_timeout;

    double fan_bust_interval;

    double fan_runout_time;

    double I_fan_sw_min;

    double I_fan_sw_max;

    msud_input_t msud_input;

    msud_output_t msud_output;




     void ode_system(const state_vector_t &Y,
                     state_vector_t &dYdt,
                     double t) override;

     void stepDiscrete(double t, double dt) override;

     void load_config(CfgReader &cfg) override;

     // Обработка переходов мсуд из состояния в состояние
     void stateProcess(double t, double dt);

     // Общий сброс МСУД
     void reset();

     // Основной цикл работы МСУД
     void main_loop(double t, double dt);

     // Управление частотой вращения мотор-вентиляторов
     void motor_fans_control(double t, double dt);

private slots:

     void slotLoadTimer();

     void slotNormalFreqTimer();

     void slotLowFreqTimer();

     void slotFansBustTimer();

     void slotRunOutTimer();
};

#endif // MSUD_H
