#ifndef SPEEDOMETER_H
#define SPEEDOMETER_H

#include <QLabel>



class Speedometer : public QLabel
{

public:
    Speedometer(QSize size, QString cfg_path, QWidget *parent = Q_NULLPTR);

    void setSpeed(int speed);
    void setSpeedLimit(int speedLimit);
    void setSpeedNextLimit(int speedNextLimit);


private:
    std::vector<QPoint> speed_coordsOutScale;
    std::vector<QPoint> speed_coordsInsideScale;

    int num_speed_ = 0;
    int num_speedLimit_ = 0;
    int num_speedNextLimit_ = 0;

    int old_num_speed_ = -1;
    int old_num_speedLimit_ = -1;
    int old_num_speedNextLimit_ = -1;


    void drawArc_(int num_speed, int num_speedLimit, int num_speedNextLimit);

    void loadScalePontsCoolrds_(QString txt_path, std::vector<QPoint> &vec);


};

#endif // SPEEDOMETER_H
