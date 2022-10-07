#ifndef BOTTOMBLOCK_H
#define BOTTOMBLOCK_H

#include <QLabel>

#include    "text-paint.h"



class BottomBlock : public QLabel
{

public:
    BottomBlock(QSize size, QWidget* parent = Q_NULLPTR);

    void setDistToTarget(int dist);
    void setTargetName(QString txt);


private:
    TextPaint   *txtPaintDistToTarget_;
    TextPaint   *txtPaintTargetType_;
    TextPaint   *txtPaintTargetName_;

    int oldDistToTarget_;
    QString oldTargetName_;

};

#endif // BOTTOMBLOCK_H
