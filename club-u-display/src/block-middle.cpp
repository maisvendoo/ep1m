#include "block-middle.h"

MiddleBlock::MiddleBlock(QSize _size, QWidget *parent)
    : QLabel(parent)
    , speedometer_(Q_NULLPTR)
    , reverseInd_(Q_NULLPTR)
{
    this->resize(_size);

    // Спидометр
    speedometer_ = new Speedometer(_size, this);
    //speedometer_->move(225, 240);

    reverseInd_ = new ReverseInd(QSize(30,50), this);
    reverseInd_->move(150, 260);
}
