#include "block-bottom.h"



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
BottomBlock::BottomBlock(QSize size, QWidget *parent)
    : QLabel(parent)
    , txtPaintDistToTarget_(Q_NULLPTR)
    , txtPaintTargetType_(Q_NULLPTR)
    , txtPaintTargetName_(Q_NULLPTR)
    , oldDistToTarget_(-1)
    , oldTargetName_("")
{
    this->resize(size);
    //this->setStyleSheet("border: 1px solid red");


    //
    txtPaintDistToTarget_ = new TextPaint(QSize(90, 20), this);
    txtPaintDistToTarget_->move(16, 2);
    txtPaintDistToTarget_->setFonts(13, Qt::green, 87);
    txtPaintDistToTarget_->setParams(4, 22);

    //
    txtPaintTargetType_ = new TextPaint(QSize(200, 20), this);
    txtPaintTargetType_->move(123, 2);
    txtPaintTargetType_->setFonts(13, Qt::green, 87);
    txtPaintTargetType_->setParams(10, 19, false, false);
    txtPaintTargetType_->setText("СВЕТОФОР");

    //
    txtPaintTargetName_ = new TextPaint(QSize(77, 20), this);
    txtPaintTargetName_->move(this->width()-90, 2);
    txtPaintTargetName_->setFonts(13, Qt::green, 87);
    txtPaintTargetName_->setParams(4, 18, true);

}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BottomBlock::setDistToTarget(int dist)
{
    if (dist == oldDistToTarget_)
        return;

    txtPaintDistToTarget_->setText(QString::number(dist));

    oldDistToTarget_ = dist;
}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BottomBlock::setTargetName(QString txt)
{
    if (txt.compare(oldTargetName_, Qt::CaseSensitivity::CaseInsensitive) == 0)
        return;

    txtPaintTargetName_->setText(txt.toUpper());

    oldTargetName_ = txt;
}
