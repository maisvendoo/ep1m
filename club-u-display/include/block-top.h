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
#include <QTime>

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


private:
    ImageWidget *indicationBditelnosti_;
    ImageWidget *indicationCassette_;
    ImageWidget *indicationM_;
    ImageWidget *indicationP_;

    TextPaint   *txtPaintCoordinate1_;
    TextPaint   *txtPaintCoordinate2_;
    TextPaint   *txtPaintStation_;
    TextPaint   *txtPaintCurTimeH_;
    TextPaint   *txtPaintCurTimeM_;
    TextPaint   *txtPaintCurTimeS_;

    double oldCoordinate_;
    QString oldStation_;



    QTimer* timeTimer_;
    QTime curTime_;



};

#endif // TOPBLOCK_H
