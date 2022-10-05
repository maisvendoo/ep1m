#include "text-paint.h"


#include <QPainter>

#include <QFontDatabase>



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
TextPaint::TextPaint(QSize _size, QWidget *parent)
    : QLabel(parent)
    , fontSize_(13)
    , color_(Qt::green)
    , txt_("")
    , countCell_(1)
    , deltaX_(10)
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

void TextPaint::setParams(int countCell, int deltaX)
{
    countCell_ = countCell;
    deltaX_ = deltaX;
}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TextPaint::setText(QString txt)
{
    drawText_(txt);
}

void TextPaint::setText2(QString txt)
{
    drawText2_(txt);
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



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TextPaint::drawText2_(QString txt)
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


    for (int i = 0; i < countCell_; ++i)
    {
        int posX = this->width() - (i + 1)*deltaX_;
        int k = txt.length() - 1 - i;

        if (i < txt.length())
            paint.drawText(posX, this->height(), QString(txt[k]));
        else
            paint.drawText(posX, this->height(), "0");

    }


//    for (int i = txt.size(); i > 0; --i)
//    {
//        paint.drawText(i*20,this->height(), QString(txt[i]));
//    }


    paint.end();
    this->setPixmap(pix);
}
