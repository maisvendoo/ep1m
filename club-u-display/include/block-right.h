#ifndef RIGHTBLOCK_H
#define RIGHTBLOCK_H



#include <QLabel>


#include    "text-paint.h"



class RightBlock : public QLabel
{

public:
    RightBlock(QSize size, QWidget* parent = Q_NULLPTR);

    void setPressureTM(double pressure);
    void setPressureUR(double pressure);
    void setNumTrack(QString trackNum);
    void setAcceleration(double a);


private:
    TextPaint   *txtPaintPressureTM1_;
    TextPaint   *txtPaintPressureTM2_;
    TextPaint   *txtPaintPressureUR1_;
    TextPaint   *txtPaintPressureUR2_;
    TextPaint   *txtPaintNumTrack_;
    TextPaint   *txtPaintAcceleration1_;
    TextPaint   *txtPaintAcceleration2_;


};

#endif // RIGHTBLOCK_H
