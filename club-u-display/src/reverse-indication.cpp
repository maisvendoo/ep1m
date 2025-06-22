#include "reverse-indication.h"

#include <QPainter>



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
ReverseInd::ReverseInd(QSize _size, QWidget *parent)
    : QLabel(parent)
    , oldVal_(0)
{
    this->resize(_size);
    //this->setStyleSheet("border: 1px solid red;");

    QPixmap pix = QPixmap(this->size());
    pix.fill(Qt::transparent);
    QPainter paint(&pix);
    paint.setRenderHint(QPainter::Antialiasing, true);
    paint.setPen(QPen( QColor(Qt::green),
                      9,
                      Qt::SolidLine,
                      Qt::RoundCap ));

    paint.drawPoint(15,16);
    paint.drawPoint(15,38);
    paint.end();
    this->setPixmap(pix);
}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void ReverseInd::setRevese(int val)
{
    if (val == oldVal_)
        return;

    oldVal_ = val;

    if (val == 0)
    {
        this->setPixmap(QPixmap());
        return;
    }

    drawReverse_(val);
}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void ReverseInd::drawReverse_(int val)
{
    QPixmap pix = QPixmap(this->size());
    pix.fill(Qt::transparent);
    QPainter paint(&pix);
    paint.setRenderHint(QPainter::Antialiasing, true);
    paint.setPen(QPen( QColor(Qt::green),
                       9,
                       Qt::SolidLine,
                       Qt::RoundCap ));


    if (val == 1)
        paint.drawPoint(15,16);

    if (val == -1)
        paint.drawPoint(15,38);


    paint.end();
    this->setPixmap(pix);
}
