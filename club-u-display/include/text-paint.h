#ifndef TEXTPAINT_H
#define TEXTPAINT_H


#include <QLabel>


class TextPaint : public QLabel
{

public:
    TextPaint(QSize _size, QWidget *parent = Q_NULLPTR);

    void setFonts(int fontSize, Qt::GlobalColor color);
    void setParams(int countCell, int deltaX, int txtWeight = 50);

    //void setText(QString txt);
    void setText2(QString txt, bool isNull = false);



private:
    QString familyFont_;

    QImage img_;

    int fontSize_;
    Qt::GlobalColor color_;
    QString txt_;
    int countCell_; // количество ячеек под текст
    int deltaX_;    // дельта X для символов в ячейках
    int txtWeight_; // жирность текста


    //void drawText_(QString txt);
    void drawText2_(QString txt, bool isNull = false);

};

#endif // TEXTPAINT_H
