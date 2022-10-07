#ifndef MIDDLEBLOCK_H
#define MIDDLEBLOCK_H

#include <QLabel>

#include    "speedometer.h"
#include    "reverse-indication.h"
#include    "text-paint.h"



class MiddleBlock : public QLabel
{
public:
    MiddleBlock(QSize _size, QWidget* parent = Q_NULLPTR);

    void setCurSpeed(int curSpeed);
    void setCurSpeedLimit(int curSpeedLimit);
    void setNextSpeedLimit(int nextSpeedLimit);
    void setReverse(int reverse);


private:
    Speedometer *speedometer_;
    ReverseInd  *reverseInd_;
    TextPaint   *txtCurSpeed_;
    TextPaint   *txtCurSpeedLimit_;

    int oldSpeed_;
    int oldSpeedLimit_;
    int oldNextSpeedLimit_;


};

#endif // MIDDLEBLOCK_H
