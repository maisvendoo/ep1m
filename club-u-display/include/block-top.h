//-----------------------------------------------------------------------------
//
//      Верхний блок БЛОКа
//      (c) РГУПС, ВЖД 30/03/2017
//      Разработал: Даглдиян Б.Д.
//
//-----------------------------------------------------------------------------
/*!
 * \file
 * \brief Класс "Верхний блок" БЛОКа
 * \copyright РГУПС, ВЖД
 * \author Даглдиян Б.Д.
 * \date 30/03/2017
 */

#ifndef TOPBLOCK_H
#define TOPBLOCK_H


#include <QLabel>
#include <QTimer>

#include    "image-widget.h"
#include    "text-paint.h"



/*!
 * \class TopBlock
 * \brief Класс, описывающий верхний блок БЛОКа
 */
class TopBlock : public QLabel
{

public:

    /*!
     * \brief Конструктор
     * \param size - размер блока
     */
    TopBlock(QSize size, QWidget* parent = Q_NULLPTR);
    /// Деструктор
    ~TopBlock();

    void setBditelnost(bool flag);
    void setIndM(bool flag);
    void setIndP(bool flag);
    void setCassete(bool flag);
    void setCoordinate(double coordinate);
    void setStationName(QString stationName);
    void setCurTime(int h, int m, int s);
    void setSheduleTime(int h, int m, int s);
    void setIndStraight(bool flag);
    void setIndSide(bool flag);


private:
    ImageWidget *indicationBditelnosti_ = nullptr;
    ImageWidget *indicationCassette_ = nullptr;
    ImageWidget *indicationM_ = nullptr;
    ImageWidget *indicationP_ = nullptr;
    ImageWidget *indicationStraight_ = nullptr;
    ImageWidget *indicationSide_ = nullptr;

    TextPaint   *txtPaintCoordinate1_ = nullptr;
    TextPaint   *txtPaintCoordinate2_ = nullptr;
    TextPaint   *txtPaintStation_ = nullptr;
    TextPaint   *txtPaintCurTimeH_ = nullptr;
    TextPaint   *txtPaintCurTimeM_ = nullptr;
    TextPaint   *txtPaintCurTimeS_ = nullptr;
    TextPaint   *txtPaintSheduleTimeH_ = nullptr;
    TextPaint   *txtPaintSheduleTimeM_ = nullptr;
    TextPaint   *txtPaintSheduleTimeS_ = nullptr;

    double oldCoordinate_ = 0.0;
    QString oldStation_ = "";
    int oldCurH_ = 0;
    int oldCurM_ = 0;
    int oldCurS_ = 0;
    int oldSheduleH_ = 0;
    int oldSheduleM_ = 0;
    int oldSheduleS_ = 0;
/*
    QTimer timeTimer_;
*/

};

#endif // TOPBLOCK_H
