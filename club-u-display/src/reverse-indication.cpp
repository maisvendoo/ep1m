#include "reverse-indication.h"

#include <QPainter>



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
ReverseInd::ReverseInd(QSize _size, QWidget *parent)
    : QLabel(parent)
{
    this->resize(_size);
    //this->setStyleSheet("border: 1px solid red;");

    QPixmap pix = QPixmap(this->size());
    pix.fill(Qt::transparent);
    QPainter paint(&pix);
    paint.setRenderHint(QPainter::Antialiasing, true);
    paint.setPen(QPen( QColor(Qt::green),
                      13,
                      Qt::SolidLine,
                      Qt::RoundCap ));

    paint.drawPoint(7,8);
    paint.drawPoint(7,37);
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
                       13,
                       Qt::SolidLine,
                       Qt::RoundCap ));


    if (val == 1)
        paint.drawPoint(7,8);

    if (val == -1)
        paint.drawPoint(7,37);


    paint.end();
    this->setPixmap(pix);
}
