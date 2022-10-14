#ifndef MANOMETERARROW_H
#define MANOMETERARROW_H


#include <QLabel>


class ManometerArrow : public QLabel
{
public:
    ManometerArrow(QSize _size, QWidget* parent = Q_NULLPTR);

    void setVal(double val);


private:
    double w_2_;
    double h_2_;

    QImage img_;

    void drawArrow_(double manometerVal);


};

#endif // MANOMETERARROW_H
