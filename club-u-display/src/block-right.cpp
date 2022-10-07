#include "block-right.h"

#include "cmath"



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
RightBlock::RightBlock(QSize size, QWidget *parent)
    : QLabel(parent)
    , txtPaintPressureTM1_(Q_NULLPTR)
    , txtPaintPressureTM2_(Q_NULLPTR)
    , txtPaintPressureUR1_(Q_NULLPTR)
    , txtPaintPressureUR2_(Q_NULLPTR)
    , txtPaintNumTrack_(Q_NULLPTR)
    , txtPaintAcceleration1_(Q_NULLPTR)
    , txtPaintAcceleration2_(Q_NULLPTR)
    , oldPressureTM_(0.0)
    , oldPressureUR_(0.0)
    , oldTrackNum_("")
    , oldAcceleration_(0.0)
{
    this->resize(size);
    //this->setStyleSheet("border: 1px solid red");


    //
    txtPaintPressureTM1_ = new TextPaint(QSize(15, 20), this);
    txtPaintPressureTM1_->move(3, 50);
    txtPaintPressureTM1_->setFonts(13, Qt::green, 87);
    txtPaintPressureTM1_->setParams(1, 15);

    txtPaintPressureTM2_ = new TextPaint(QSize(50, 20), this);
    txtPaintPressureTM2_->move(22, 50);
    txtPaintPressureTM2_->setFonts(13, Qt::green, 87);
    txtPaintPressureTM2_->setParams(2, 17);
    txtPaintPressureTM2_->setPointForDigit(4, 17);

    //
    txtPaintPressureUR1_ = new TextPaint(QSize(15, 20), this);
    txtPaintPressureUR1_->move(3, 122);
    txtPaintPressureUR1_->setFonts(13, Qt::green, 87);
    txtPaintPressureUR1_->setParams(1, 15);

    txtPaintPressureUR2_ = new TextPaint(QSize(50, 20), this);
    txtPaintPressureUR2_->move(22, 122);
    txtPaintPressureUR2_->setFonts(13, Qt::green, 87);
    txtPaintPressureUR2_->setParams(2, 17);
    txtPaintPressureUR2_->setPointForDigit(4, 17);

    //
    TextPaint *txtPaintALS = new TextPaint(QSize(35, 20), this);
    txtPaintALS->move(94, 122);
    txtPaintALS->setFonts(13, Qt::green, 87);
    txtPaintALS->setParams(2, 17);
    txtPaintALS->setText("25");

    //
    txtPaintNumTrack_ = new TextPaint(QSize(72, 20), this);
    txtPaintNumTrack_->move(3, 198);
    txtPaintNumTrack_->setFonts(13, Qt::green, 87);
    txtPaintNumTrack_->setParams(4, 18, true);

    //
    txtPaintAcceleration1_ = new TextPaint(QSize(15, 20), this);
    txtPaintAcceleration1_->move(95, 198);
    txtPaintAcceleration1_->setFonts(13, Qt::green, 87);
    txtPaintAcceleration1_->setParams(1, 15);

    txtPaintAcceleration2_ = new TextPaint(QSize(32, 20), this);
    txtPaintAcceleration2_->move(111, 198);
    txtPaintAcceleration2_->setFonts(13, Qt::green, 87);
    txtPaintAcceleration2_->setParams(1, 15);
    txtPaintAcceleration2_->setPointForDigit(5, 15);

}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void RightBlock::setPressureTM(double pressure)
{
    if ((pressure < 0.0) || (pressure > 9.99))
        return;

    if (std::abs(pressure - oldPressureTM_) < 0.01)
        return;

    txtPaintPressureTM1_->setText(QString::number(floor(pressure)));
    txtPaintPressureTM2_->setText(QString::number(pressure, 'f', 2));

    oldPressureTM_ = pressure;
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void RightBlock::setPressureUR(double pressure)
{
    if ((pressure < 0.0) || (pressure > 9.99))
        return;

    if (std::abs(pressure - oldPressureUR_) < 0.01)
        return;

    txtPaintPressureUR1_->setText(QString::number(floor(pressure)));
    txtPaintPressureUR2_->setText(QString::number(pressure, 'f', 2));

    oldPressureUR_ = pressure;
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void RightBlock::setNumTrack(QString trackNum)
{
    if (trackNum.compare(oldTrackNum_, Qt::CaseSensitivity::CaseInsensitive) == 0)
        return;

    txtPaintNumTrack_->setText(trackNum.toUpper());

    oldTrackNum_ = trackNum;
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void RightBlock::setAcceleration(double a)
{
    if ((a < 0.0) || (a > 9.9))
        return;

    if (std::abs(a - oldAcceleration_) < 0.1)
        return;

    txtPaintAcceleration1_->setText(QString::number(floor(a)));
    txtPaintAcceleration2_->setText(QString::number(a, 'f', 1));

    oldAcceleration_ = a;
}
