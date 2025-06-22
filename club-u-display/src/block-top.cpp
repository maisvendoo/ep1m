#include "block-top.h"

#include "cmath"
/*
#include <QTime>
*/


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
TopBlock::TopBlock(QSize size, QWidget *parent)
    : QLabel(parent)
{
    this->resize(size);
    //this->setStyleSheet("border: 1px solid red");


    // Индикация бдительности (красный треугольник)
    indicationBditelnosti_ = new ImageWidget("rcc", "ind_bdit", QSize(81,82), this);
    indicationBditelnosti_->move(580, 25);
    indicationBditelnosti_->setVisible(false);

    // Индикация кассеты
    indicationCassette_ = new ImageWidget("rcc", "ind_cassette", QSize(26,23), this);
    indicationCassette_->move(353, 29);
    indicationCassette_->setVisible(true);

    // Индикация М
    indicationM_ = new ImageWidget("rcc", "ind_M", QSize(16,18), this);
    indicationM_->move(270, 31);
    indicationM_->setVisible(true);

    // Индикация П
    indicationP_ = new ImageWidget("rcc", "ind_P", QSize(12,18), this);
    indicationP_->move(316, 31);
    indicationP_->setVisible(true);

    // Индикация из АЛС-ЕН "прямо"
    indicationStraight_ = new ImageWidget("rcc", "ind_straight", QSize(45,17), this);
    indicationStraight_->move(10, 77);
    indicationStraight_->setVisible(true);

    // Индикация из АЛС-ЕН "отклонение"
    indicationSide_ = new ImageWidget("rcc", "ind_side", QSize(45,17), this);
    indicationSide_->move(10, 112);
    indicationSide_->setVisible(true);

    //
    txtPaintCoordinate1_ = new TextPaint(QSize(76, 20), this);
    txtPaintCoordinate1_->move(78, 100);
    txtPaintCoordinate1_->setFonts(13, Qt::green, 87);
    txtPaintCoordinate1_->setParams(4, 19);
    txtPaintCoordinate1_->setText(QString::number(0));

    txtPaintCoordinate2_ = new TextPaint(QSize(77, 20), this);
    txtPaintCoordinate2_->move(153, 100);
    txtPaintCoordinate2_->setFonts(13, Qt::green, 87);
    txtPaintCoordinate2_->setParams(3, 19);
    txtPaintCoordinate2_->setPointForDigit(6, 16);
    txtPaintCoordinate2_->setText(QString::number(0.0, 'f', 3));

    //
    txtPaintStation_ = new TextPaint(QSize(155, 20), this);
    txtPaintStation_->move(242, 100);
    txtPaintStation_->setFonts(13, Qt::yellow);
    txtPaintStation_->setParams(8, 19, true);
    txtPaintStation_->setText("STATION1");

    //
    txtPaintCurTimeH_ = new TextPaint(QSize(38, 20), this);
    txtPaintCurTimeH_->move(411, 100);
    txtPaintCurTimeH_->setFonts(13, Qt::green, 87);
    txtPaintCurTimeH_->setParams(2, 19);
    txtPaintCurTimeH_->setText(QString::number(0));

    txtPaintCurTimeM_ = new TextPaint(QSize(58, 20), this);
    txtPaintCurTimeM_->move(447, 100);
    txtPaintCurTimeM_->setFonts(13, Qt::green, 87);
    txtPaintCurTimeM_->setParams(2, 19);
    txtPaintCurTimeM_->setPointForDigit(6, 16);
    txtPaintCurTimeM_->setText(QString::number(0));

    txtPaintCurTimeS_ = new TextPaint(QSize(58, 20), this);
    txtPaintCurTimeS_->move(504, 100);
    txtPaintCurTimeS_->setFonts(13, Qt::green, 87);
    txtPaintCurTimeS_->setParams(2, 19);
    txtPaintCurTimeS_->setPointForDigit(6, 16);
    txtPaintCurTimeS_->setText(QString::number(0));

    txtPaintSheduleTimeH_ = new TextPaint(QSize(38, 20), this);
    txtPaintSheduleTimeH_->move(411, 30);
    txtPaintSheduleTimeH_->setFonts(13, Qt::green, 87);
    txtPaintSheduleTimeH_->setParams(2, 19);
    txtPaintSheduleTimeH_->setText(QString::number(0));

    txtPaintSheduleTimeM_ = new TextPaint(QSize(58, 20), this);
    txtPaintSheduleTimeM_->move(447, 30);
    txtPaintSheduleTimeM_->setFonts(13, Qt::green, 87);
    txtPaintSheduleTimeM_->setParams(2, 19);
    txtPaintSheduleTimeM_->setPointForDigit(6, 16);
    txtPaintSheduleTimeM_->setText(QString::number(0));

    txtPaintSheduleTimeS_ = new TextPaint(QSize(58, 20), this);
    txtPaintSheduleTimeS_->move(504, 30);
    txtPaintSheduleTimeS_->setFonts(13, Qt::green, 87);
    txtPaintSheduleTimeS_->setParams(2, 19);
    txtPaintSheduleTimeS_->setPointForDigit(6, 16);
    txtPaintSheduleTimeS_->setText(QString::number(0));
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
TopBlock::~TopBlock()
{

}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void TopBlock::setBditelnost(bool flag)
{
    if (indicationBditelnosti_->isVisible() == flag)
        return;

    indicationBditelnosti_->setVisible(flag);
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void TopBlock::setIndM(bool flag)
{
    if (indicationM_->isVisible() == flag)
        return;

    indicationM_->setVisible(flag);
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void TopBlock::setIndP(bool flag)
{
    if (indicationP_->isVisible() == flag)
        return;

    indicationP_->setVisible(flag);
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void TopBlock::setCassete(bool flag)
{
    if (indicationCassette_->isVisible() == flag)
        return;

    indicationCassette_->setVisible(flag);
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void TopBlock::setIndStraight(bool flag)
{
    if (indicationStraight_->isVisible() == flag)
        return;

    indicationStraight_->setVisible(flag);
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void TopBlock::setIndSide(bool flag)
{
    if (indicationSide_->isVisible() == flag)
        return;

    indicationSide_->setVisible(flag);
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void TopBlock::setCoordinate(double coordinate)
{
    if ((coordinate < 0.0) || (coordinate > 9999.999))
        return;

    if (std::abs(coordinate - oldCoordinate_) < 0.001)
        return;

    txtPaintCoordinate1_->setText(QString::number(floor(coordinate)));
    txtPaintCoordinate2_->setText(QString::number(coordinate, 'f', 3));

    oldCoordinate_ = coordinate;
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void TopBlock::setStationName(QString stationName)
{
    if (stationName.compare(oldStation_, Qt::CaseSensitivity::CaseInsensitive) == 0)
        return;

    txtPaintStation_->setText(stationName.toUpper());

    oldStation_ = stationName;
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void TopBlock::setCurTime(int h, int m, int s)
{
    if (oldCurH_ != h)
    {
        txtPaintCurTimeH_->setText(QString::number(h));
        oldCurH_ = h;
    }

    if (oldCurM_ != m)
    {
        txtPaintCurTimeM_->setText(QString::number(m));
        oldCurM_ = m;
    }

    if (oldCurS_ != s)
    {
        txtPaintCurTimeS_->setText(QString::number(s));
        oldCurS_ = s;
    }
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void TopBlock::setSheduleTime(int h, int m, int s)
{
    if (oldSheduleH_ != h)
    {
        txtPaintSheduleTimeH_->setText(QString::number(h));
        oldSheduleH_ = h;
    }

    if (oldSheduleM_ != m)
    {
        txtPaintSheduleTimeM_->setText(QString::number(m));
        oldSheduleM_ = m;
    }

    if (oldSheduleS_ != s)
    {
        txtPaintSheduleTimeS_->setText(QString::number(s));
        oldSheduleS_ = s;
    }
}



