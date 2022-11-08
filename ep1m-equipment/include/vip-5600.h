#ifndef     VIP_5600_H
#define     VIP_5600_H

#include    "device.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class RectInvertConverter : public Device
{
public:

    RectInvertConverter(QObject *parent = Q_NULLPTR);

    ~RectInvertConverter();

    void setU1(double U1) { this->U1 = U1; }

    void setU2(double U2) { this->U2 = U2; }

    void setU3(double U3) { this->U3 = U3; }

    void setAlpha(double alpha) { this->alpha = alpha; }

    void setZoneNum(size_t zone_num) { this->zoneNum = zone_num; }

    double getU_out() const { return U_out; }

    void setI_out(double I_out) { this->I_out = I_out; }

private:

    /// Эквивалентное внутреннее сопротивление ВПИ (вместе с соответствующей
    /// обмоткой тягового трансформатора)
    double r;

    /// Напряжение первой секции тяговогой обмотки (четверть)
    double U1;

    /// Напряжение второй секции тяговой обмотки (втрорая четверть)
    double U2;

    /// Напряжение третьей секции тяговой обмотки (последняя половина)
    double U3;

    /// Коэффициент передачи между действующим напряжением обмотки
    /// и средним выпрямленным напряжением
    double K_rect;

    /// Угол открытия тиристоров
    double alpha;

    /// Номер зоны
    size_t zoneNum;

    /// Выходное напряжение ВИП
    double U_out;

    /// Ток нагрузки ВИП
    double I_out;

    struct zone_t
    {
        double Umin;
        double Umax;

        zone_t()
            : Umin(0.0)
            , Umax(0.0)
        {

        }
    };

    enum
    {
        ZONES_NUM = 4,
        ZONE1 = 0,
        ZONE2 = 1,
        ZONE3 = 2,
        ZONE4 = 3
    };

    /// Данные по выходным параметров зон регулирования
    std::array<zone_t, ZONES_NUM> zone;

    void preStep(state_vector_t &Y, double t);

    void ode_system(const state_vector_t &Y, state_vector_t &dYdt, double t);

    void load_config(CfgReader &cfg);
};

#endif // VIP_5600_H
