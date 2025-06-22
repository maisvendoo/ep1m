#include "speedometer.h"

#include <QPainter>
#include <QVector>
#include <QFile>



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------

Speedometer::Speedometer(QSize size, QString cfg_path, QWidget *parent)
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

    loadScalePontsCoolrds_(cfg_path + "speed-coordinatesOutScale.txt", speed_coordsOutScale);
    loadScalePontsCoolrds_(cfg_path + "speed-coordinatesInsideScale.txt", speed_coordsInsideScale);

    QPixmap pix = QPixmap(this->size());
    pix.fill(Qt::transparent);
    QPainter paint(&pix);
    paint.setRenderHint(QPainter::Antialiasing, true);


    // ограничение скорости
    paint.setPen(QPen( QColor(Qt::red), 9, Qt::SolidLine, Qt::RoundCap ));
    for (int i = 0; i < speed_coordsOutScale.size(); ++i)
    {
        paint.drawPoint(speed_coordsOutScale[i]);
    }

    // скорость
    paint.setPen(QPen( QColor(Qt::green), 9, Qt::SolidLine, Qt::RoundCap ));
    for (int i = 0; i < speed_coordsInsideScale.size(); ++i)
    {
        paint.drawPoint(speed_coordsInsideScale[i]);
    }


    paint.end();
    this->setPixmap(pix);
}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void Speedometer::setSpeed(int speed)
{
    num_speed_ = std::min(static_cast<size_t>(speed / 5), speed_coordsInsideScale.size() - 1);

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
    num_speedLimit_ = std::min(static_cast<size_t>(speedLimit / 5), speed_coordsOutScale.size() - 1);

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
    num_speedNextLimit_ = std::min(static_cast<size_t>(speedNextLimit / 5), speed_coordsOutScale.size() - 1);

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
    QPixmap pix = QPixmap(this->size());
    pix.fill(Qt::transparent);
    QPainter paint(&pix);
    paint.setRenderHint(QPainter::Antialiasing, true);


    if ((num_speedLimit_ >= 0) && (num_speedNextLimit >= 0))
    {
        // ограничение скорости
        paint.setPen(QPen( QColor(Qt::red), 9, Qt::SolidLine, Qt::RoundCap ));
        paint.drawPoint(speed_coordsOutScale[num_speedLimit]);

        // следующее ограничение скорости
        paint.setPen(QPen( QColor(Qt::yellow), 9, Qt::SolidLine, Qt::RoundCap ));
        paint.drawPoint(speed_coordsOutScale[num_speedNextLimit]);
    }

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
void Speedometer::loadScalePontsCoolrds_(QString txt_path, std::vector<QPoint> &vec)
{
    QFile fileTxt(txt_path);

    if (!QFile::exists(fileTxt.fileName()))
        return;

    if (fileTxt.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!fileTxt.atEnd())
        {
            QString str = fileTxt.readLine();
            QStringList strList = str.split(" ");
            int x = strList[0].toInt();
            int y = strList[1].toInt();
            vec.push_back(QPoint(x, y));
        }
        fileTxt.close();
    }

}

