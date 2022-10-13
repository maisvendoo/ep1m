#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QLabel>



class StatusBar : public QLabel
{
public:
    StatusBar(QSize _size, QWidget *parent = Q_NULLPTR);

    void setVal(double val);

private:
    QImage img_;


    void drawBar_(double val);

};

#endif // STATUSBAR_H
