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


private:
    Speedometer *speedometer_;
    ReverseInd  *reverseInd_;
    TextPaint   *txtPaint1_;
    TextPaint   *txtPaint2_;


};

#endif // MIDDLEBLOCK_H
