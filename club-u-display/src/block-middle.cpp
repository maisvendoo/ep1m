#include "block-middle.h"

MiddleBlock::MiddleBlock(QSize _size, QWidget *parent)
    : QLabel(parent)
    , speedometer_(Q_NULLPTR)
    , reverseInd_(Q_NULLPTR)
    , txtPaint1_(Q_NULLPTR)
    , txtPaint2_(Q_NULLPTR)
{
    this->resize(_size);

    // Спидометр
    speedometer_ = new Speedometer(_size, this);

    // Индикация реверсора
    reverseInd_ = new ReverseInd(QSize(30,50), this);
    reverseInd_->move(150, 260);

    // Индикация скорости
    txtPaint1_ = new TextPaint(QSize(100,50), this);
    txtPaint1_->setFonts(33, Qt::green);
    txtPaint1_->move(135, 84);
    txtPaint1_->setParams(3, 33);

    txtPaint2_ = new TextPaint(QSize(100,50), this);
    txtPaint2_->setFonts(33, Qt::red);
    txtPaint2_->move(135, 159);
    txtPaint2_->setParams(3, 33);



}




void MiddleBlock::setCurSpeed(int curSpeed)
{
    speedometer_->setSpeed(curSpeed);
    txtPaint1_->setText2(QString::number(curSpeed));
}

void MiddleBlock::setCurSpeedLimit(int curSpeedLimit)
{
    speedometer_->setSpeedLimit(curSpeedLimit);
    txtPaint2_->setText2(QString::number(curSpeedLimit));
}

void MiddleBlock::setNextSpeedLimit(int nextSpeedLimit)
{
    speedometer_->setSpeedNextLimit(nextSpeedLimit);
}

void MiddleBlock::setReverse(int reverse)
{
    reverseInd_->setRevese(reverse);
}
