#include "manometer-arrow.h"

#include <QPainter>
#include <qmath.h>



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
ManometerArrow::ManometerArrow(QSize _size, QWidget *parent)
    : QLabel(parent)
{
    this->resize(_size);
    this->setStyleSheet("border: 1px solid red");

    w_2_ = this->width()/2;
    h_2_ = this->height()/2;

    img_ = QImage(this->size(), QImage::Format_ARGB32_Premultiplied);


    drawArrow_(0);

}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void ManometerArrow::setVal(double val)
{
    drawArrow_(val);
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void ManometerArrow::drawArrow_(double manometerVal)
{
    img_.fill(Qt::transparent);
    QPixmap pix = QPixmap::fromImage(img_);
    QPainter paint(&pix);
    paint.setRenderHint(QPainter::Antialiasing, true);



    int maxValScale = 160;
    int angleArcEnd = 46;
    int arcSplitLength = 272;



    double fooAngle2 = (360.0 - angleArcEnd) - (maxValScale - manometerVal)*(360.0-arcSplitLength)/maxValScale;
    double angle = qDegreesToRadians(fooAngle2);
    double fooAngle = qDegreesToRadians(90.0);



    paint.setPen(QPen(Qt::green, 1, Qt::SolidLine));
    paint.setBrush(Qt::black);



    // 416 - диаметр круга
    QRectF rect(-53, 10,
                416, 416 + 10);


    paint.drawArc(rect,
                  angleArcEnd*16,
                  (360.0 - arcSplitLength)*16);


    w_2_ = rect.x() + rect.width()/2.0;
    h_2_ = rect.y() + rect.height()/2.0;
    double r_ = 205.0;





    // линия стрелки
    paint.drawLine(w_2_ + (r_ - 10)*cos(angle),
                   h_2_ + (r_ - 10)*sin(angle),
                   w_2_,
                   h_2_);



    double ht = 15.0; // высота треугольника стрелки
    double bt = 5.0; // длина основания треугольника
    QPolygonF triangle;
    triangle << QPointF( w_2_ + (r_)*cos(angle),
                         h_2_ + (r_)*sin(angle) )
             << QPointF( w_2_ + (r_ - ht)*cos(angle) + (bt)*cos(angle+fooAngle),
                         h_2_ + (r_ - ht)*sin(angle) + (bt)*sin(angle+fooAngle) )
             << QPointF( w_2_ + (r_ - ht)*cos(angle) + (bt)*cos(angle-fooAngle),
                         h_2_ + (r_ - ht)*sin(angle) + (bt)*sin(angle-fooAngle) );

    // треугольник стрелки
    paint.drawPolygon(triangle);







    paint.end();
    this->setPixmap(pix);
}
