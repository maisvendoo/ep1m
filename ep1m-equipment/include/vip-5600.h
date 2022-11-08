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

    struct zone_t
    {
        double Umin;
        double Umax;
        double r;

        zone_t()
            : Umin(0.0)
            , Umax(0.0)
            , r(0.0)
        {

        }
    };

    /// Данные по выходным параметров зон регулирования
    std::vector<zone_t> zone;

    void preStep(state_vector_t &Y, double t);

    void ode_system(const state_vector_t &Y, state_vector_t &dYdt, double t);

    void load_config(CfgReader &cfg);
};

#endif // VIP_5600_H
