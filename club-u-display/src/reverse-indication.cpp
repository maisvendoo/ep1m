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

    img_ = QImage(this->size(), QImage::Format_ARGB32_Premultiplied);
}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void ReverseInd::setRevese(int val)
{
    if (val == oldVal_)
        return;

    if (val == 0)
    {
        this->setPixmap(QPixmap());
        return;
    }

    drawReverse_(val);

    oldVal_ = val;
}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void ReverseInd::drawReverse_(int val)
{
    img_.fill(Qt::transparent);
    QPixmap pix = QPixmap::fromImage(img_);
    QPainter paint(&pix);
    paint.setRenderHint(QPainter::Antialiasing, true);

    //
    paint.setPen(QPen( QColor(Qt::yellow),
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
