#ifndef     MSUD_H
#define     MSUD_H

#include    "device.h"

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

private:

    // Напряжение питания
    double  Uc;

    // Доступные состояния МСУД
    enum msud_state_t
    {
        MSUD_OFF = 0,
        MSUD_RESET = 1,
        MSUD_READY = 2
    };

    // Текущее состояние МСУД
    msud_state_t     state;

    // Минимально допустимое напряжение питания МСУД
    double  Uc_min;

    // Условное время загрузки МСУД после включения питания
    double  load_time;

    // Таймер загрузки МСУД
    Timer   *load_timer;

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


private slots:

     void slotLoadTimer();
};

#endif // MSUD_H
