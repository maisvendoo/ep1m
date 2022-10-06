#ifndef TEXTPAINT_H
#define TEXTPAINT_H


#include <QLabel>



class TextPaint : public QLabel
{

public:
    TextPaint(QSize _size, QWidget *parent = Q_NULLPTR);

    void setFonts(int fontSize, Qt::GlobalColor color, int txtWeight = 50);
    void setParams(int countCell, int deltaX, bool symbolIsNull = false, bool rightleftText = true);
    // Установить точку-разделитель числа
    void setPointForDigit(int x, int y);

    void setText(QString txt);



private:
    QString familyFont_;

    QImage img_;

    int fontSize_;
    Qt::GlobalColor color_;
    int txtWeight_; // жирность текста
    QString txt_;
    int countCell_;     // количество ячеек под текст
    int deltaX_;        // дельта X для символов в ячейках
    bool symbolIsNull_; // null или 0 на дисплее
    bool rightleftText_; // текст справа налево (по умолчанию)

    QFont font_;

    // точка-разделитель числа
    bool flagSetPoint_;
    int pointX_;
    int pointY_;


    void drawText_(QString txt);


};

#endif // TEXTPAINT_H
