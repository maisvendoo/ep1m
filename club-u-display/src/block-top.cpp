#include "block-top.h"

#include "CfgReader.h"
#include "cmath"
#include <QTimer>



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
TopBlock::TopBlock(QSize size, QWidget *parent)
    : QLabel(parent)
    , txtPaintCoordinate1_(Q_NULLPTR)
    , txtPaintCoordinate2_(Q_NULLPTR)
    , txtPaintStation_(Q_NULLPTR)
    , txtPaintCurTimeH_(Q_NULLPTR)
    , txtPaintCurTimeM_(Q_NULLPTR)
    , txtPaintCurTimeS_(Q_NULLPTR)
{
    this->resize(size);
    //this->setStyleSheet("border: 1px solid red");


    // Индикация бдительности (красный треугольник)
    indicationBditelnosti_ = new ImageWidget("rcc", "ind_bdit", QSize(81,82), this);
    indicationBditelnosti_->move(580, 25);
    indicationBditelnosti_->setVisible(false);

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
    txtPaintStation_->setParams(8, 19);

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



    txtPaintCurTimeH_->setText2("");
    txtPaintCurTimeM_->setText2("");
    txtPaintCurTimeS_->setText2("");


//    timeTimer_ = new QTimer();
//    timeTimer_->setInterval(1000);
//    timeTimer_->start(0);

//    //curTime_ = new QTime();

//    connect(timeTimer_, &QTimer::timeout, this, [this]()
//    {
//        txtPaintCurTimeH_->setText2(QString::number(curTime_.currentTime().hour()));
//        txtPaintCurTimeM_->setText2(QString::number(curTime_.currentTime().minute()));
//        txtPaintCurTimeS_->setText2(QString::number(curTime_.currentTime().second()));
//    });


}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
TopBlock::~TopBlock()
{

}



void TopBlock::setBditelnost(bool flag)
{
    indicationBditelnosti_->setVisible(flag);
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void TopBlock::setCoordinate(double coordinate)
{
    if ((coordinate < 0.0) || (coordinate > 9999.999))
        return;

    txtPaintCoordinate1_->setText2(QString::number(round(coordinate)));
    txtPaintCoordinate2_->setText2(QString::number(coordinate, 'f', 3));
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void TopBlock::setStationName(QString stationName)
{
    txtPaintStation_->setText2(stationName.toUpper(), true);
}





