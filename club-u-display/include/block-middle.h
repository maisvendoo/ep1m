#ifndef MIDDLEBLOCK_H
#define MIDDLEBLOCK_H

#include <QLabel>
#include <QTimer>


#include    "speedometer.h"
#include    "reverse-indication.h"
#include    "text-paint.h"



class MiddleBlock : public QLabel
{
public:
    MiddleBlock(QSize _size, QString cfg_path, QWidget* parent = Q_NULLPTR);

    void setCurSpeed(int curSpeed);
    void setCurSpeedLimit(int curSpeedLimit);
    void setNextSpeedLimit(int nextSpeedLimit);
    void setReverse(int reverse);

    void setSpeedLimitVisible(bool flag);

    void blinkingSpeed(bool flag);


private:
    Speedometer *speedometer_;
    ReverseInd  *reverseInd_;
    TextPaint   *txtCurSpeed_;
    TextPaint   *txtCurSpeedLimit_;

    int oldSpeed_;
    int oldSpeedLimit_;
    int oldNextSpeedLimit_;

    QTimer timerForBlink;
    bool forceBlinking_;


};

#endif // MIDDLEBLOCK_H
