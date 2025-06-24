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


    // Индикация кассеты
    indicationCassette_ = new ImageWidget("rcc", "ind_cassette", QSize(34,30), this);
    indicationCassette_->move(465, 3);
    indicationCassette_->setVisible(true);

    // Индикация М
    indicationM_ = new ImageWidget("rcc", "ind_M", QSize(21,23), this);
    indicationM_->move(352, 7);
    indicationM_->setVisible(false);

    // Индикация П
    indicationP_ = new ImageWidget("rcc", "ind_P", QSize(16,23), this);
    indicationP_->move(413, 7);
    indicationP_->setVisible(true);

    // Индикация из АЛС-ЕН "прямо"
    indicationStraight_ = new ImageWidget("rcc", "ind_straight", QSize(59,22), this);
    indicationStraight_->move(5, 68);
    indicationStraight_->setVisible(false);

    // Индикация из АЛС-ЕН "отклонение"
    indicationSide_ = new ImageWidget("rcc", "ind_side", QSize(59,22), this);
    indicationSide_->move(5, 115);
    indicationSide_->setVisible(false);

    //
    txtPaintCoordinate1_ = new TextPaint(QSize(99, 30), this);
    txtPaintCoordinate1_->move(95, 98);
    txtPaintCoordinate1_->setFonts(20, Qt::green, 87);
    txtPaintCoordinate1_->setParams(4, 25);
    txtPaintCoordinate1_->setText(QString::number(0));

    txtPaintCoordinate2_ = new TextPaint(QSize(99, 30), this);
    txtPaintCoordinate2_->move(196, 98);
    txtPaintCoordinate2_->setFonts(20, Qt::green, 87);
    txtPaintCoordinate2_->setParams(3, 25);
    txtPaintCoordinate2_->setPointForDigit(10, 25);
    txtPaintCoordinate2_->setText(QString::number(0.0, 'f', 3));

    //
    txtPaintStation_ = new TextPaint(QSize(200, 30), this);
    txtPaintStation_->move(318, 98);
    txtPaintStation_->setFonts(20, Qt::yellow);
    txtPaintStation_->setParams(8, 25, true);
    txtPaintStation_->setText("STATION1");

    //
    txtPaintCurTimeH_ = new TextPaint(QSize(54, 30), this);
    txtPaintCurTimeH_->move(538, 98);
    txtPaintCurTimeH_->setFonts(20, Qt::green, 87);
    txtPaintCurTimeH_->setParams(2, 26);
    txtPaintCurTimeH_->setText(QString::number(0));

    txtPaintCurTimeM_ = new TextPaint(QSize(72, 30), this);
    txtPaintCurTimeM_->move(592, 98);
    txtPaintCurTimeM_->setFonts(20, Qt::green, 87);
    txtPaintCurTimeM_->setParams(2, 26);
    txtPaintCurTimeM_->setPointForDigit(8, 25);
    txtPaintCurTimeM_->setText(QString::number(0));

    txtPaintCurTimeS_ = new TextPaint(QSize(72, 30), this);
    txtPaintCurTimeS_->move(665, 98);
    txtPaintCurTimeS_->setFonts(20, Qt::green, 87);
    txtPaintCurTimeS_->setParams(2, 26);
    txtPaintCurTimeS_->setPointForDigit(8, 25);
    txtPaintCurTimeS_->setText(QString::number(0));

    txtPaintSheduleTimeH_ = new TextPaint(QSize(54, 30), this);
    txtPaintSheduleTimeH_->move(538, 4);
    txtPaintSheduleTimeH_->setFonts(20, Qt::green, 87);
    txtPaintSheduleTimeH_->setParams(2, 26);
    txtPaintSheduleTimeH_->setText(QString::number(0));

    txtPaintSheduleTimeM_ = new TextPaint(QSize(72, 30), this);
    txtPaintSheduleTimeM_->move(592, 4);
    txtPaintSheduleTimeM_->setFonts(20, Qt::green, 87);
    txtPaintSheduleTimeM_->setParams(2, 26);
    txtPaintSheduleTimeM_->setPointForDigit(8, 25);
    txtPaintSheduleTimeM_->setText(QString::number(0));

    txtPaintSheduleTimeS_ = new TextPaint(QSize(72, 30), this);
    txtPaintSheduleTimeS_->move(665, 4);
    txtPaintSheduleTimeS_->setFonts(20, Qt::green, 87);
    txtPaintSheduleTimeS_->setParams(2, 26);
    txtPaintSheduleTimeS_->setPointForDigit(8, 25);
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



