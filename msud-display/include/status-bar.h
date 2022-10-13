#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QLabel>



class StatusBar : public QLabel
{
public:
    StatusBar(QSize _size, QWidget *parent = Q_NULLPTR);


private:
    QImage img_;

    QFont font_;

    void drawBar_();

};

#endif // STATUSBAR_H
