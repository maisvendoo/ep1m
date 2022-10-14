#ifndef MANOMETERARROW_H
#define MANOMETERARROW_H


#include <QLabel>



class ManometerArrow : public QLabel
{
public:
    ManometerArrow(QSize _size, int maxValScale, QWidget* parent = Q_NULLPTR);

    void setVals(int val1_line, int val2_arrow);


private:
    double w_2_;
    double h_2_;

    QImage img_;

    int maxValScale_;

    int oldVal1_line_;
    int oldVal2_arrow_;


    void drawArrow_(int val1_line, int val2_arrow);


};

#endif // MANOMETERARROW_H
