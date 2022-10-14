#ifndef MSUD_DISPLAY_H
#define MSUD_DISPLAY_H

#include    <QTimer>

#include    "display.h"

#include    "status-bar.h"
#include    "manometer-arrow.h"


class MsudDisplay : public AbstractDisplay
{
public:
    MsudDisplay(QWidget *parent = Q_NULLPTR,
                Qt::WindowFlags f = Qt::WindowFlags());

    ~MsudDisplay() override;

    void init() override;


private:
    QLabel* fon_;

    QLabel* labMode_;
    QLabel* labControl_;
    QLabel* labPC1_;
    QLabel* labPC2_;
    QLabel* labPC3_;

    StatusBar* sbTyaga_;
    StatusBar* sbCurrent_;
    QLabel* labTyaga_;
    QLabel* labCurrent_;

    QLabel* labV1_;
    QLabel* labV2_;
    QLabel* labI1_;
    QLabel* labI2_;


    StatusBar* sbCurrentEPT_;
    StatusBar* sbVoltageEPT_;
    QLabel* labCurrentEPT_;
    QLabel* labVoltageEPT_;


    ManometerArrow* manArrV_;
    ManometerArrow* manArrI_;

    int val1_ = 0;
    int val2_ = 0;


    QTimer updateTimer_;


    void initDisplay_();

    void createLab_(QLabel* &lab, QSize size,
                    QString color,
                    Qt::Alignment align = Qt::AlignCenter);


private slots:
    void slotUpdateTimer();


};

#endif // MSUD_DISPLAY_H
