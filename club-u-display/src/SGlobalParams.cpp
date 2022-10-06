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

#include "SGlobalParams.h"

#include "CfgReader.h"

const	QString		SGLOBALPARAMS_CFG = "../cfg/CLUB/SGlobalParams.xml";

//-----------------------------------------------------------------------------
//  Конструктор
//-----------------------------------------------------------------------------
SGlobalParams::SGlobalParams()
    : sgp_arcSplitCenterAngle(270)
    , sgp_arcSplitLength(90)
    , sgp_maxSpeedScale(300)
    , sgp_stepSpeed(20)
    , sgp_angleArcEnd(sgp_arcSplitCenterAngle + sgp_arcSplitLength/2)
{
    loadCfg_(SGLOBALPARAMS_CFG);
}

//-----------------------------------------------------------------------------
//  Чтение конфигураций
//-----------------------------------------------------------------------------
bool SGlobalParams::loadCfg_(QString cfg_path)
{
    CfgReader cfg;

    if (cfg.load(cfg_path))
    {
        QString sectionName = "SGlobalParams";

        // угол середины разрыва дуги
        if (!cfg.getInt(sectionName, "arc_splitPoint", sgp_arcSplitCenterAngle))
            sgp_arcSplitCenterAngle = 270;
        // длина разрыва дуги
        if (!cfg.getInt(sectionName, "arc_splitAngle", sgp_arcSplitLength))
            sgp_arcSplitLength = 90;
        // max скорость на шкале
        if (!cfg.getInt(sectionName, "maxSpeedScale", sgp_maxSpeedScale))
            sgp_maxSpeedScale = 300;
        // шаг скорости
        if (!cfg.getInt(sectionName, "stepSpeedScale", sgp_stepSpeed))
            sgp_stepSpeed = 20;

    }
    else
    {
        // Параметры по умолчанию.
        sgp_arcSplitCenterAngle = 270;  // угол середины разрыва дуги
        sgp_arcSplitLength = 56;        // длина разрыва дуги
        sgp_maxSpeedScale = 160;        // max скорость на шкале
        sgp_stepSpeed = 5;             // шаг скорости
    }

    sgp_angleArcEnd = sgp_arcSplitCenterAngle + sgp_arcSplitLength/2;

    // округляем значение макс. скорости на велечину шага
    if ( sgp_maxSpeedScale % sgp_stepSpeed != 0 )
        sgp_maxSpeedScale += sgp_stepSpeed - (sgp_maxSpeedScale % sgp_stepSpeed);

    return true;
}
