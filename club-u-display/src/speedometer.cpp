#include "speedometer.h"

#include <QPainter>
#include <QtCore/qmath.h>

#include <qdebug.h>

#include <QVector>
#include <QFile>

#include "CfgReader.h"



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
Speedometer::Speedometer(QSize size, QWidget *parent)
    : QLabel(parent)
    , speed_(0)
    , speedLimit_(0)
    , speedNextLimit_(0)
{
    this->resize(size);
   // this->setStyleSheet("border: 1px solid red;");


    img_ = QImage(this->size(), QImage::Format_ARGB32_Premultiplied);


    loadTxtSpeedCoolrds1_("G:/WORK/Projects/ep1m/soft/ep1m/cfg/vehicles/ep1m-384/CLUB-U/speed-coordinates1.txt", speed_coords1);
    loadTxtSpeedCoolrds1_("G:/WORK/Projects/ep1m/soft/ep1m/cfg/vehicles/ep1m-384/CLUB-U/speed-coordinates2.txt", speed_coords2);

}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void Speedometer::setSpeed(int speed)
{
    speed_ = speed;

    drawArc_(speed, speedLimit_, speedNextLimit_);
}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void Speedometer::setSpeedLimit(int speedLimit)
{
    speedLimit_ = speedLimit;

    drawArc_(speed_, speedLimit, speedNextLimit_);
}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void Speedometer::setSpeedNextLimit(int speedNextLimit)
{
    speedNextLimit_ = speedNextLimit;

    drawArc_(speed_, speedLimit_, speedNextLimit);
}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void Speedometer::drawArc_(int speed, int speedLimit, int speedNextLimit)
{
    img_.fill(Qt::transparent);
    QPixmap pix = QPixmap::fromImage(img_);
    QPainter paint(&pix);
    paint.setRenderHint(QPainter::Antialiasing, true);

    //
    paint.setPen(QPen( QColor(Qt::red),
                       9,
                       Qt::SolidLine,
                       Qt::RoundCap ));


    // ограничение скорости
    paint.drawPoint(speed_coords1[speedLimit/5]);


    //
    paint.setPen(QPen( QColor(Qt::yellow),
                       9,
                       Qt::SolidLine,
                       Qt::RoundCap ));
    // следующее ограничение скорости
    paint.drawPoint(speed_coords1[speedNextLimit/5]);


    //
    paint.setPen(QPen( QColor(Qt::green),
                       9,
                       Qt::SolidLine,
                       Qt::RoundCap ));

    // скорость
    for (int i = 0, n = speed/5 + 1; i < n; ++i)
    {
        paint.drawPoint(speed_coords2[i]);
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

