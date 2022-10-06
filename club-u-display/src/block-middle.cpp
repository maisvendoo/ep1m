#include "block-middle.h"

MiddleBlock::MiddleBlock(QSize _size, QWidget *parent)
    : QLabel(parent)
    , speedometer_(Q_NULLPTR)
    , reverseInd_(Q_NULLPTR)
    , txtCurSpeed_(Q_NULLPTR)
    , txtCurSpeedLimit_(Q_NULLPTR)
{
    this->resize(_size);

    // Спидометр
    speedometer_ = new Speedometer(_size, this);

    // Индикация реверсора
    reverseInd_ = new ReverseInd(QSize(30,50), this);
    reverseInd_->move(150, 260);

    // Индикация скорости
    txtCurSpeed_ = new TextPaint(QSize(100,50), this);
    txtCurSpeed_->setFonts(33, Qt::green);
    txtCurSpeed_->move(135, 84);
    txtCurSpeed_->setParams(3, 33);

    txtCurSpeedLimit_ = new TextPaint(QSize(100,50), this);
    txtCurSpeedLimit_->setFonts(33, Qt::red);
    txtCurSpeedLimit_->move(135, 159);
    txtCurSpeedLimit_->setParams(3, 33);
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void MiddleBlock::setCurSpeed(int curSpeed)
{
    speedometer_->setSpeed(curSpeed);
    txtCurSpeed_->setText2(QString::number(curSpeed));
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void MiddleBlock::setCurSpeedLimit(int curSpeedLimit)
{
    speedometer_->setSpeedLimit(curSpeedLimit);
    txtCurSpeedLimit_->setText2(QString::number(curSpeedLimit));
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void MiddleBlock::setNextSpeedLimit(int nextSpeedLimit)
{
    speedometer_->setSpeedNextLimit(nextSpeedLimit);
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void MiddleBlock::setReverse(int reverse)
{
    reverseInd_->setRevese(reverse);
}
