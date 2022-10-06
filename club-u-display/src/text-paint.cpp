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
    , txtWeight_(50)
    , txt_("")
    , countCell_(1)
    , deltaX_(10)
    , flagSetPoint_(false)
    , pointX_(-1)
    , pointY_(-1)
{
    this->resize(_size);

    //this->setStyleSheet("border: 1px solid red;");

    int id = QFontDatabase::addApplicationFont(":/rcc/club-u-ttf"); //путь к шрифту
    familyFont_ = QFontDatabase::applicationFontFamilies(id).at(0); //имя шрифта


    img_ = QImage(this->size(), QImage::Format_ARGB32_Premultiplied);


}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TextPaint::setFonts(int fontSize, Qt::GlobalColor color, int txtWeight)
{
    fontSize_ = fontSize;
    color_ = color;
    txtWeight_ = txtWeight;

    font_ = QFont(familyFont_, fontSize_, txtWeight_);
}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TextPaint::setParams(int countCell, int deltaX)
{
    countCell_ = countCell;
    deltaX_ = deltaX;
}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TextPaint::setPointForDigit(int x, int y)
{
    flagSetPoint_ = true;
    pointX_ = x;
    pointY_ = y;
}



////------------------------------------------------------------------------------
////
////------------------------------------------------------------------------------
//void TextPaint::setText(QString txt)
//{
//    drawText_(txt);
//}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TextPaint::setText2(QString txt, bool isNull)
{
    drawText2_(txt, isNull);
}



////------------------------------------------------------------------------------
////
////------------------------------------------------------------------------------
//void TextPaint::drawText_(QString txt)
//{
//    img_.fill(Qt::transparent);
//    QPixmap pix = QPixmap::fromImage(img_);
//    QPainter paint(&pix);
//    paint.setRenderHint(QPainter::Antialiasing, true);

//    int id = QFontDatabase::addApplicationFont(":/rcc/club-u-ttf"); //путь к шрифту
//    QString family = QFontDatabase::applicationFontFamilies(id).at(0); //имя шрифта
//    QFont f(family, fontSize_);
//    paint.setFont(f);

//    paint.setPen(QPen(QColor(color_)));

//    paint.drawText(0,this->height(), txt);

//    paint.end();
//    this->setPixmap(pix);
//}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TextPaint::drawText2_(QString txt, bool isNull)
{
    img_.fill(Qt::transparent);
    QPixmap pix = QPixmap::fromImage(img_);
    QPainter paint(&pix);
    //paint.setRenderHint(QPainter::Antialiasing, true);
    paint.setFont(font_);
    paint.setPen(color_);


    for (int i = 0; i < countCell_; ++i)
    {
        int posX = this->width() - (i + 1)*deltaX_;
        int k = txt.length() - 1 - i;

        if (i < txt.length())
            paint.drawText(posX, this->height(), QString(txt[k]));
        else
        {
            if (!isNull)
                paint.drawText(posX, this->height(), "0");
        }

    }

    if (flagSetPoint_)
    {
        paint.setPen(QPen(QColor(color_), 5));
        paint.drawPoint(pointX_, pointY_);
    }


//    for (int i = txt.size(); i > 0; --i)
//    {
//        paint.drawText(i*20,this->height(), QString(txt[i]));
//    }


    paint.end();
    this->setPixmap(pix);
}
