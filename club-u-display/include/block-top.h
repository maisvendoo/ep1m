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

#include "image-widget.h"




/*!
 * \class TopBlock
 * \brief Класс, описывающий верхний блок БЛОКа
 */
class TopBlock : public QLabel
{
    Q_OBJECT

public:

    /*!
     * \brief Конструктор
     * \param size - размер блока
     */
    TopBlock(QSize size, QWidget* parent = Q_NULLPTR);
    /// Деструктор
    ~TopBlock();


private:
    ImageWidget* indicationBditelnosti_;



};

#endif // TOPBLOCK_H
