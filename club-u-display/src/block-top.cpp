#include "block-top.h"

#include "CfgReader.h"
#include <QTime>



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
TopBlock::TopBlock(QSize size, QWidget *parent)
    : QLabel(parent)
    , txtPaintCoordinate1_(Q_NULLPTR)
    , txtPaintCoordinate2_(Q_NULLPTR)
{
    this->resize(size);
    //this->setStyleSheet("border: 1px solid red");


    // Индикация бдительности (красный треугольник)
    indicationBditelnosti_ = new ImageWidget("rcc", "ind_bdit", QSize(81,82), this);
    indicationBditelnosti_->move(580, 25);

    //
    txtPaintCoordinate1_ = new TextPaint(QSize(76, 20), this);
    txtPaintCoordinate1_->setFonts(13, Qt::green);
    txtPaintCoordinate1_->move(78, 100);
    txtPaintCoordinate1_->setParams(4, 19);

    txtPaintCoordinate2_ = new TextPaint(QSize(57, 20), this);
    txtPaintCoordinate2_->setFonts(13, Qt::green);
    txtPaintCoordinate2_->move(173, 100);
    txtPaintCoordinate2_->setParams(3, 19);



    txtPaintCoordinate1_->setText2("123");
    txtPaintCoordinate2_->setText2("10");
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
TopBlock::~TopBlock()
{

}


