#include "text-paint.h"


#include <QPainter>

#include <QFontDatabase>



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
TextPaint::TextPaint(QSize _size, QWidget *parent)
    : QLabel(parent)
{
    this->resize(_size);

    //this->setStyleSheet("border: 1px solid red;");

    img_ = QImage(this->size(), QImage::Format_ARGB32_Premultiplied);

}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TextPaint::setFonts(int fontSize, Qt::GlobalColor color)
{
    fontSize_ = fontSize;
    color_ = color;
}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TextPaint::setText(QString txt)
{
    drawText_(txt);
}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TextPaint::drawText_(QString txt)
{
    img_.fill(Qt::transparent);
    QPixmap pix = QPixmap::fromImage(img_);
    QPainter paint(&pix);
    paint.setRenderHint(QPainter::Antialiasing, true);

    int id = QFontDatabase::addApplicationFont(":/rcc/club-u-ttf"); //путь к шрифту
    QString family = QFontDatabase::applicationFontFamilies(id).at(0); //имя шрифта
    QFont f(family, fontSize_);
    paint.setFont(f);

    paint.setPen(QPen(QColor(color_)));

    paint.drawText(0,this->height(), txt);

    paint.end();
    this->setPixmap(pix);
}
