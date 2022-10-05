#ifndef SPEEDOMETER_H
#define SPEEDOMETER_H


#include <QLabel>
#include "SGlobalParams.h"


class Speedometer : public QLabel, SGlobalParams
{

public:
    Speedometer(QSize size, QWidget *parent = Q_NULLPTR);

    void setSpeed(int speed);
    void setSpeedLimit(int speedLimit);


private:
    QImage img_;

    QVector<QPoint> speed_coords1;
    QVector<QPoint> speed_coords2;

    int speed_;
    int speedLimit_;


    void drawArc_(int speed, int speedLimit);

    void loadTxtSpeedCoolrds1_(QString txt_path, QVector<QPoint> &vec);


};

#endif // SPEEDOMETER_H
