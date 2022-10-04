#ifndef ALSN_H
#define ALSN_H

#include <QLabel>

#include "image-widget.h"


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
enum ALSN_COLORS
{
    WHITE = 0,
    RED = 1,
    RED_YELLOW = 2,
    YELLOW = 3,
    GREEN = 4
};



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
class ALSN : public QLabel
{
public:
    ALSN(QSize _size, QWidget* parent = Q_NULLPTR);

    void setSignal(int color, int freeBlocs = 1);


private:

    QLabel *ledGreen_;

    QVector<ImageWidget*> ledWidgets_;

    void loadLedImages_();

};

#endif // ALSN_H
