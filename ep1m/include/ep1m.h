#ifndef EP1M_H
#define EP1M_H

#include    "vehicle-api.h"
#include    "ep1m-signals.h"
#include    "tumblers-panel.h"
#include    "azv.h"
#include    "msud.h"
#include    "battery.h"
#include    "power-supply.h"

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

    /// Автоматические защитные выключатели
    std::array<Trigger, AZV_NUMBER> azv;

    void initialization() override;

    /// Инициализация подсистемы питания цепей управления
    void initControlPower();

    /// Инициализация АЗВ
    void initAZV();

    /// Инициализация пульта управления в кабине
    void initPanel();

    /// Инициализация МСУД
    void initMSUD();

    /// Инициализация озвучки
    void initSounds();

    void stepControlPower(double t, double dt);

    void stepPanel(double t, double dt);

    void stepMSUD(double t, double dt);

    void step(double t, double dt) override;

    void keyProcess() override;
};

#endif // EP1M_H
