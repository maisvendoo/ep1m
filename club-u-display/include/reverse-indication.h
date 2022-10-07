#ifndef REVERSEIND_H
#define REVERSEIND_H


#include <QLabel>



class ReverseInd : public QLabel
{

public:
    ReverseInd(QSize _size, QWidget *parent = Q_NULLPTR);
    void setRevese(int val);


private:
    QImage img_;

    int oldVal_;

    void drawReverse_(int val);

};

#endif // REVERSEIND_H
