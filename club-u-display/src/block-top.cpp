#include "block-top.h"

#include "cmath"

#include <QTime>



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
TopBlock::TopBlock(QSize size, QWidget *parent)
    : QLabel(parent)
    , indicationBditelnosti_(Q_NULLPTR)
    , indicationCassette_(Q_NULLPTR)
    , indicationM_(Q_NULLPTR)
    , indicationP_(Q_NULLPTR)
    , txtPaintCoordinate1_(Q_NULLPTR)
    , txtPaintCoordinate2_(Q_NULLPTR)
    , txtPaintStation_(Q_NULLPTR)
    , txtPaintCurTimeH_(Q_NULLPTR)
    , txtPaintCurTimeM_(Q_NULLPTR)
    , txtPaintCurTimeS_(Q_NULLPTR)
    , oldCoordinate_(0.0)
    , oldStation_("")
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
    indicationCassette_->setVisible(false);

    // Индикация М
    indicationM_ = new ImageWidget("rcc", "ind_M", QSize(16,18), this);
    indicationM_->move(270, 31);
    indicationM_->setVisible(false);

    // Индикация П
    indicationP_ = new ImageWidget("rcc", "ind_P", QSize(12,18), this);
    indicationP_->move(316, 31);
    indicationP_->setVisible(false);

    //
    txtPaintCoordinate1_ = new TextPaint(QSize(76, 20), this);
    txtPaintCoordinate1_->move(78, 100);
    txtPaintCoordinate1_->setFonts(13, Qt::green, 87);
    txtPaintCoordinate1_->setParams(4, 19);

    txtPaintCoordinate2_ = new TextPaint(QSize(77, 20), this);
    txtPaintCoordinate2_->move(153, 100);
    txtPaintCoordinate2_->setFonts(13, Qt::green, 87);
    txtPaintCoordinate2_->setParams(3, 19);
    txtPaintCoordinate2_->setPointForDigit(6, 16);

    //
    txtPaintStation_ = new TextPaint(QSize(155, 20), this);
    txtPaintStation_->move(242, 100);
    txtPaintStation_->setFonts(13, Qt::yellow);
    txtPaintStation_->setParams(8, 19, true);

    //
    txtPaintCurTimeH_ = new TextPaint(QSize(38, 20), this);
    txtPaintCurTimeH_->move(411, 100);
    txtPaintCurTimeH_->setFonts(13, Qt::green, 87);
    txtPaintCurTimeH_->setParams(2, 19);

    txtPaintCurTimeM_ = new TextPaint(QSize(58, 20), this);
    txtPaintCurTimeM_->move(447, 100);
    txtPaintCurTimeM_->setFonts(13, Qt::green, 87);
    txtPaintCurTimeM_->setParams(2, 19);
    txtPaintCurTimeM_->setPointForDigit(6, 16);

    txtPaintCurTimeS_ = new TextPaint(QSize(58, 20), this);
    txtPaintCurTimeS_->move(504, 100);
    txtPaintCurTimeS_->setFonts(13, Qt::green, 87);
    txtPaintCurTimeS_->setParams(2, 19);
    txtPaintCurTimeS_->setPointForDigit(6, 16);

    connect(&timeTimer_, &QTimer::timeout, [&]()
    {
        txtPaintCurTimeH_->setText(QString::number(QTime::currentTime().hour()));
        txtPaintCurTimeM_->setText(QString::number(QTime::currentTime().minute()));
        txtPaintCurTimeS_->setText(QString::number(QTime::currentTime().second()));
    });
    timeTimer_.start(1000);

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





