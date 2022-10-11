#include "block-middle.h"



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
MiddleBlock::MiddleBlock(QSize _size, QString cfg_path, QWidget *parent)
    : QLabel(parent)
    , speedometer_(Q_NULLPTR)
    , reverseInd_(Q_NULLPTR)
    , txtCurSpeed_(Q_NULLPTR)
    , txtCurSpeedLimit_(Q_NULLPTR)
    , oldSpeed_(0)
    , oldSpeedLimit_(0)
    , oldNextSpeedLimit_(0)
    , forceBlinking_(false)
{
    this->resize(_size);

    // Спидометр
    speedometer_ = new Speedometer(_size, cfg_path, this);

    // Индикация реверсора
    reverseInd_ = new ReverseInd(QSize(30,50), this);
    reverseInd_->move(150, 260);

    // Числовая индикация скорости
    txtCurSpeed_ = new TextPaint(QSize(100,50), this);
    txtCurSpeed_->setFonts(33, Qt::green);
    txtCurSpeed_->move(135, 84);
    txtCurSpeed_->setParams(3, 33);

    // Числовая индикация ограничения скорости
    txtCurSpeedLimit_ = new TextPaint(QSize(100,50), this);
    txtCurSpeedLimit_->setFonts(33, Qt::red);
    txtCurSpeedLimit_->move(135, 159);
    txtCurSpeedLimit_->setParams(3, 33);


    // Моргание скорости, если подходим к ограничению скорости
    connect(&timerForBlink, &QTimer::timeout, [&]()
    {
        if ((oldSpeedLimit_ - oldSpeed_ <= 3) || forceBlinking_)
            txtCurSpeed_->setVisible(!txtCurSpeed_->isVisible());
        else
            txtCurSpeed_->setVisible(true);
    });
    timerForBlink.start(500);
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void MiddleBlock::setCurSpeed(int curSpeed)
{
    if (oldSpeed_ == curSpeed)
        return;

    speedometer_->setSpeed(curSpeed);
    txtCurSpeed_->setText(QString::number(curSpeed));

    oldSpeed_ = curSpeed;
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void MiddleBlock::setCurSpeedLimit(int curSpeedLimit)
{
    if (oldSpeedLimit_ == curSpeedLimit)
        return;

    speedometer_->setSpeedLimit(curSpeedLimit);

    txtCurSpeedLimit_->setText(QString::number(curSpeedLimit));

    oldSpeedLimit_ = curSpeedLimit;
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void MiddleBlock::setNextSpeedLimit(int nextSpeedLimit)
{
    if (oldNextSpeedLimit_ == nextSpeedLimit)
        return;

    speedometer_->setSpeedNextLimit(nextSpeedLimit);

    oldNextSpeedLimit_ = nextSpeedLimit;
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void MiddleBlock::setReverse(int reverse)
{
    reverseInd_->setRevese(reverse);
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void MiddleBlock::setSpeedLimitVisible(bool flag)
{
    txtCurSpeedLimit_->setVisible(flag);
}



void MiddleBlock::blinkingSpeed(bool flag)
{
    //txtCurSpeed_->setVisible(!txtCurSpeed_->isVisible());
    forceBlinking_ = flag;
}


