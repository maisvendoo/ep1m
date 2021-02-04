#ifndef EP1M_H
#define EP1M_H

#include    "vehicle-api.h"
#include    "ep1m-signals.h"
#include    "ep1m-tumblers-panel.h"
#include    "ep1m-azv.h"
#include    "msud.h"

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

    /// Автоматические защитные выключатели
    std::array<Trigger, AZV_NUMBER> azv;

    void initialization() override;

    void initAZV();

    void initPanel();

    void initMSUD();

    void initSounds();

    void stepPanel(double t, double dt);

    void stepMSUD(double t, double dt);

    void step(double t, double dt) override;

    void keyProcess() override;
};

#endif // EP1M_H
