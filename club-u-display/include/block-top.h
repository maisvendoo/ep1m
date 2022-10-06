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

//#include <QMap>
//#include <QTimer>
#include <QWidget>
#include <QLabel>
#include <QTime>

#include "image-widget.h"
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
    void setCoordinate(double coordinate);
    void setStationName(QString stationName);


private:
    ImageWidget* indicationBditelnosti_;
    TextPaint   *txtPaintCoordinate1_;
    TextPaint   *txtPaintCoordinate2_;
    TextPaint   *txtPaintStation_;
    TextPaint   *txtPaintCurTimeH_;
    TextPaint   *txtPaintCurTimeM_;
    TextPaint   *txtPaintCurTimeS_;

    QTimer* timeTimer_;
    QTime curTime_;



};

#endif // TOPBLOCK_H
