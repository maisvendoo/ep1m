#include "status-bar.h"

#include <QPainter>

#include <QDebug>



StatusBar::StatusBar(QSize _size, QWidget *parent)
    : QLabel(parent)
{
    this->resize(_size);
    //this->setStyleSheet("border: 1px solid green;");

    img_ = QImage(this->size(), QImage::Format_ARGB32_Premultiplied);

}



void StatusBar::setVal(double val)
{

    drawBar_(val);
}



void StatusBar::drawBar_(double val)
{
    img_.fill(Qt::transparent);
    QPixmap pix = QPixmap::fromImage(img_);
    QPainter paint(&pix);


    //paint.setPen(QColor("yellow"));
    paint.setPen(Qt::transparent);
    paint.setBrush(QColor("yellow"));


    int w = this->width() * val/100.0;

    QPolygon p;
    p << QPoint(0,0)
      << QPoint(w, 0)
      << QPoint(w, this->height()-10)
      << QPoint(0, this->height()-10);

    paint.drawPolygon(p);


    double linesDeltaX = this->width() / 10.0;

    for (int i = 1; i < 10 ; ++i)
    {
        paint.setPen(QColor(70,70,70));

        int fooX = i*linesDeltaX;
        paint.drawLine(fooX, 0,
                       fooX, this->height()-12);

    }


    paint.end();
    this->setPixmap(pix);

}
