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
    QString familyFont_;

    QLabel* fon_;

    QLabel* labMode_;
    QLabel* labKO_TC_;
    QLabel* labKO_DB_;
    QLabel* labKO_MK_;
    QLabel* labKO_DM_;
    QLabel* labKO_NC_;
    QLabel* labKO_OB_;
    QLabel* labKO_KZ_;
    QLabel* labKO_OV_;
    QLabel* labKO_MPK_;
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


    QLabel* labFieldWeak1_;
    QLabel* labFieldWeak2_;
    QLabel* labFieldWeak3_;

    StatusBar* sbCurrentEPT_;
    StatusBar* sbVoltageEPT_;
    QLabel* labCurrentEPT_;
    QLabel* labVoltageEPT_;


    ManometerArrow* manArrV_;
    ManometerArrow* manArrI_;

    QLabel* labCurTime_;

//    int val1_ = 0;
//    int val2_ = 0;


    QTimer updateTimer_;
    QTimer timeTimer_;

    QTimer timerTC_;
    QTimer timerDB_;
    QTimer timerMK_;
    QTimer timerDM_;
    QTimer timerNC_;
    QTimer timerOB_;
    QTimer timerKZ_;
    QTimer timerOV_;


    void initDisplay_();

    // Создание и расположение лейбла
    void createLab_(QLabel* &lab, QSize size,
                    QString color,
                    Qt::Alignment align = Qt::AlignHCenter);

    // Создается соединение таймера и лейбла для "моргания"
    void createConnectionTimer_(QTimer &timer, QLabel* &lab);

    // Отображение лейбла/скрытие/стар "моргания"
    void setStateLabKO_(QLabel* &lab, int signalEnum, QTimer &timer);


private slots:
    void slotUpdateTimer();


};

#endif // MSUD_DISPLAY_H
