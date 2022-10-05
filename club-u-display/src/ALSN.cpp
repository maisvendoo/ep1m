#include "ALSN.h"



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
ALSN::ALSN(QSize _size, QWidget *parent)
    : QLabel(parent)
{
    this->resize(_size);
    //this->setStyleSheet("border: 1px solid red;");

    loadLedImages_();

}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void ALSN::setSignal(int color, int freeBlocs)
{
    for (int i = 0; i < 8; ++i)
    {
        ledWidgets_[i]->setVisible(false);
    }

    if (color == ALSN_COLORS::GREEN)
    {
        if (freeBlocs > 4)
            return;

        for (int i = 3; i > 3 - freeBlocs; --i)
        {
            ledWidgets_[i]->setVisible(true);
        }
    }
    else
    {
        ledWidgets_[7-color]->setVisible(true);
    }
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void ALSN::loadLedImages_()
{
//    ledGreen_ = new QLabel(this);
//    ledGreen_->setFrameShape(QLabel::NoFrame);
//    QPixmap pic;
//    if (!pic.load(":/rcc/alsn_green")) { return; }
//    ledGreen_->setFixedSize(pic.size());
//    ledGreen_->setPixmap(pic);
//    ledGreen_->move(5, 4);

    //ledGreen_->setStyleSheet("background-color: rgba(255, 255, 255, 50);");

    ledWidgets_.reserve(8);

    int ledW = 82;
    int ledH = 35;
    int ledX = 3;
    int ledY = 3;
    int dY = ledH + 8;


    ImageWidget* imgWidget;

    for (int i = 0; i < 4; ++i)
    {
        imgWidget = new ImageWidget("rcc", "alsn_green", QSize(ledW, ledH), this);
        imgWidget->move(ledX, ledY);
        ledWidgets_.append(imgWidget);
        ledY += dY;
    }

    imgWidget = new ImageWidget("rcc", "alsn_yellow", QSize(ledW, ledH), this);
    imgWidget->move(ledX, ledY);
    ledWidgets_.append(imgWidget);
    ledY += dY;

    imgWidget = new ImageWidget("rcc", "alsn_yellow_red", QSize(ledW, ledH + 9), this);
    imgWidget->move(ledX, ledY);
    ledWidgets_.append(imgWidget);

    ledY += dY + 8;

    imgWidget = new ImageWidget("rcc", "alsn_red", QSize(ledW, ledH), this);
    imgWidget->move(ledX, ledY);
    ledWidgets_.append(imgWidget);

    ledY += dY;

    imgWidget = new ImageWidget("rcc", "alsn_white", QSize(ledW, ledH), this);
    imgWidget->move(ledX, ledY);
    ledWidgets_.append(imgWidget);

}

