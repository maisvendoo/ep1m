#include "speedometer.h"

#include <QPainter>
#include <QVector>
#include <QFile>



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
Speedometer::Speedometer(QSize size, QWidget *parent)
    : QLabel(parent)
    , num_speed_(0)
    , num_speedLimit_(0)
    , num_speedNextLimit_(0)
    , old_num_speed_(0)
    , old_num_speedLimit_(0)
    , old_num_speedNextLimit_(0)
{
    this->resize(size);
   // this->setStyleSheet("border: 1px solid red;");


    img_ = QImage(this->size(), QImage::Format_ARGB32_Premultiplied);


    loadTxtSpeedCoolrds1_("G:/WORK/Projects/ep1m/soft/ep1m/cfg/vehicles/ep1m-384/CLUB-U/speed-coordinatesOutScale.txt", speed_coordsOutScale);
    loadTxtSpeedCoolrds1_("G:/WORK/Projects/ep1m/soft/ep1m/cfg/vehicles/ep1m-384/CLUB-U/speed-coordinatesInsideScale.txt", speed_coordsInsideScale);

}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void Speedometer::setSpeed(int speed)
{
    num_speed_ = speed / 5;

    if (num_speed_ == old_num_speed_)
        return;

    drawArc_(num_speed_, num_speedLimit_, num_speedNextLimit_);

    old_num_speed_ = num_speed_;
}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void Speedometer::setSpeedLimit(int speedLimit)
{
    num_speedLimit_ = speedLimit / 5;

    if (num_speedLimit_ == old_num_speedLimit_)
        return;

    drawArc_(num_speed_, num_speedLimit_, num_speedNextLimit_);

    old_num_speedLimit_ = num_speedLimit_;
}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void Speedometer::setSpeedNextLimit(int speedNextLimit)
{
    num_speedNextLimit_ = speedNextLimit / 5;

    if (num_speedNextLimit_ == old_num_speedNextLimit_)
        return;

    drawArc_(num_speed_, num_speedLimit_, num_speedNextLimit_);

    old_num_speedNextLimit_ = num_speedNextLimit_;
}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void Speedometer::drawArc_(int num_speed, int num_speedLimit, int num_speedNextLimit)
{
    img_.fill(Qt::transparent);
    QPixmap pix = QPixmap::fromImage(img_);
    QPainter paint(&pix);
    paint.setRenderHint(QPainter::Antialiasing, true);


    // ограничение скорости
    paint.setPen(QPen( QColor(Qt::red), 9, Qt::SolidLine, Qt::RoundCap ));
    paint.drawPoint(speed_coordsOutScale[num_speedLimit]);

    // следующее ограничение скорости
    paint.setPen(QPen( QColor(Qt::yellow), 9, Qt::SolidLine, Qt::RoundCap ));
    paint.drawPoint(speed_coordsOutScale[num_speedNextLimit]);

    // скорость
    paint.setPen(QPen( QColor(Qt::green), 9, Qt::SolidLine, Qt::RoundCap ));
    for (int i = 0, n = num_speed + 1; i < n; ++i)
    {
        paint.drawPoint(speed_coordsInsideScale[i]);
    }


    paint.end();
    this->setPixmap(pix);
}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void Speedometer::loadTxtSpeedCoolrds1_(QString txt_path, QVector<QPoint> &vec)
{
    QFile fileTxt(txt_path);

    if (!QFile::exists(fileTxt.fileName()))
        return;

    if (fileTxt.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!fileTxt.atEnd())
        {
            QString str = fileTxt.readLine();
            QStringList strList = str.split(" ", QString::SkipEmptyParts);
            int x = strList[0].toInt();
            int y = strList[1].toInt();
            vec.append(QPoint(x, y));
        }
        fileTxt.close();
    }

}

