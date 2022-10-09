#ifndef MIDDLEBLOCK_H
#define MIDDLEBLOCK_H

#include <QLabel>


#include    "speedometer.h"
#include    "reverse-indication.h"
#include    "text-paint.h"



class MiddleBlock : public QLabel
{
public:
    MiddleBlock(QString config_dir, QSize _size, QWidget* parent = Q_NULLPTR);


    void setCurSpeed(int curSpeed);
    void setCurSpeedLimit(int curSpeedLimit);
    void setNextSpeedLimit(int nextSpeedLimit);
    void setReverse(int reverse);

    void setConfigDir(QString config_dir) { this->config_dir = config_dir; }

private:
    Speedometer *speedometer_;
    ReverseInd  *reverseInd_;
    TextPaint   *txtCurSpeed_;
    TextPaint   *txtCurSpeedLimit_;

    QString config_dir;
};

#endif // MIDDLEBLOCK_H
