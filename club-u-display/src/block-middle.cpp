#include "block-middle.h"

MiddleBlock::MiddleBlock(QSize _size, QWidget *parent)
    : QLabel(parent)
    , speedometer_(Q_NULLPTR)
    , reverseInd_(Q_NULLPTR)
{
    this->resize(_size);

    // Спидометр
    speedometer_ = new Speedometer(_size, this);

    // Индикация реверсора
    reverseInd_ = new ReverseInd(QSize(30,50), this);
    reverseInd_->move(150, 260);

    // Индикация скорости
    txtPaint1_ = new TextPaint(QSize(130,50), this);
    txtPaint1_->setFonts(33, Qt::green);
    txtPaint1_->move(135, 84);

    txtPaint2_ = new TextPaint(QSize(130,50), this);
    txtPaint2_->setFonts(33, Qt::red);
    txtPaint2_->move(135, 159);



    txtPaint1_->setText("060");
    txtPaint2_->setText("080");
}
