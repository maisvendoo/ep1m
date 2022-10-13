#include "text-paint.h"



//    this->setStyleSheet("color: "+ QString("green") +";"
//                         "font-weight: 100;");



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
TextPaint::TextPaint(QSize _size, QWidget *parent, Qt::Alignment align)
    : QLabel(parent)
{
    this->resize(_size);

    this->setFont(QFont("Arial", 19, 87));
    this->setStyleSheet("border: 1px solid green;"
                        "color: white;");

    this->setAlignment(align);


    //drawText_("sdf");
}



void TextPaint::setText(QString str)
{
    drawText_(str);
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void TextPaint::drawText_(QString txt)
{


    this->setText(txt.toUpper());
}
