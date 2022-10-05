//-----------------------------------------------------------------------------
//
//      Глобальные параметры спидометра
//      (c) РГУПС, ВЖД ../10/2017
//      Разработал: Даглдиян Б.Д.
//
//-----------------------------------------------------------------------------
/*!
 * \file
 * \brief Глобальные параметры спидометра
 * \copyright РГУПС, ВЖД
 * \author Даглдиян Б.Д.
 * \date ../10/2017
 */

#ifndef SGLOBALPARAMS_H
#define SGLOBALPARAMS_H

class QString;

/*!
 * \class SGlobalParams
 * \brief Глобальные параметры спидометра
 */
class SGlobalParams
{
public:
    /// Конструктор
    SGlobalParams();

    // --- cfg параметры --- //
    int  sgp_arcSplitCenterAngle;   ///< угол середины разрыва дуги
    int  sgp_arcSplitLength;        ///< длина разрыва дуги
    int  sgp_maxSpeedScale;         ///< max скорость на шкале
    int  sgp_stepSpeed;             ///< шаг скорости
    // --------------------- //
    int  sgp_angleArcEnd;           ///< угол конца дуги

private:
    /// Чтение конфигураций
    bool loadCfg_(QString cfg_path);

};

#endif // SGLOBALPARAMS_H
