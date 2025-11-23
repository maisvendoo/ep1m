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
    , indicationZapretOtpuska_(Q_NULLPTR)
{
    this->resize(size);
    //this->setStyleSheet("border: 1px solid red");


    //
    txtPaintPressureTM1_ = new TextPaint(QSize(28, 30), this);
    txtPaintPressureTM1_->move(0, 63);
    txtPaintPressureTM1_->setFonts(20, Qt::green, TextPaint::LED_6X8_DOTS, 87);
    txtPaintPressureTM1_->setParams(1, 25);
    txtPaintPressureTM1_->setText(QString("0"));

    txtPaintPressureTM2_ = new TextPaint(QSize(70, 30), this);
    txtPaintPressureTM2_->move(29, 63);
    txtPaintPressureTM2_->setFonts(20, Qt::green, TextPaint::LED_6X8_DOTS, 87);
    txtPaintPressureTM2_->setParams(2, 26);
    txtPaintPressureTM2_->setPointForDigit(5, 25);
    txtPaintPressureTM2_->setText(QString(".00"));

    //
    txtPaintPressureUR1_ = new TextPaint(QSize(28, 30), this);
    txtPaintPressureUR1_->move(0, 162);
    txtPaintPressureUR1_->setFonts(20, Qt::green, TextPaint::LED_6X8_DOTS, 87);
    txtPaintPressureUR1_->setParams(1, 25);
    txtPaintPressureUR1_->setText(QString("0"));

    txtPaintPressureUR2_ = new TextPaint(QSize(70, 30), this);
    txtPaintPressureUR2_->move(29, 162);
    txtPaintPressureUR2_->setFonts(20, Qt::green, TextPaint::LED_6X8_DOTS, 87);
    txtPaintPressureUR2_->setParams(2, 26);
    txtPaintPressureUR2_->setPointForDigit(5, 25);
    txtPaintPressureUR2_->setText(QString(".00"));

    //
    TextPaint *txtPaintALS = new TextPaint(QSize(60, 30), this);
    txtPaintALS->move(135, 162);
    txtPaintALS->setFonts(20, Qt::green, TextPaint::LED_6X8_DOTS, 87);
    txtPaintALS->setParams(2, 26);
    txtPaintALS->setText("25");

    //
    txtPaintNumTrack_ = new TextPaint(QSize(75, 30), this);
    txtPaintNumTrack_->move(0, 261);
    txtPaintNumTrack_->setFonts(20, Qt::green, TextPaint::LED_6X8_DOTS, 87);
    txtPaintNumTrack_->setParams(4, 25, true);
    txtPaintNumTrack_->setText(QString("1ПР"));

    //
    txtPaintAcceleration1_ = new TextPaint(QSize(28, 30), this);
    txtPaintAcceleration1_->move(124, 261);
    txtPaintAcceleration1_->setFonts(20, Qt::green, TextPaint::LED_6X8_DOTS, 87);
    txtPaintAcceleration1_->setParams(1, 25);
    txtPaintAcceleration1_->setText(QString("0"));

    txtPaintAcceleration2_ = new TextPaint(QSize(40, 30), this);
    txtPaintAcceleration2_->move(154, 261);
    txtPaintAcceleration2_->setFonts(20, Qt::green, TextPaint::LED_6X8_DOTS, 87);
    txtPaintAcceleration2_->setParams(1, 25);
    txtPaintAcceleration2_->setPointForDigit(4, 25);
    txtPaintAcceleration2_->setText(QString("0"));


    // Индикация "Запрет отпуска"
    indicationZapretOtpuska_ = new ImageWidget("rcc", "ind_zapret_otpuska", QSize(94,48), this);
    indicationZapretOtpuska_->move(53, 432);
    indicationZapretOtpuska_->setVisible(false);

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



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void RightBlock::setIndZapretOtpuska(bool flag)
{
    indicationZapretOtpuska_->setVisible(flag);
}
