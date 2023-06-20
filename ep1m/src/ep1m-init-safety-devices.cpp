#include    "ep1m.h"

#include    <QDir>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::initSafetyDevices()
{
    klub_BEL = new KLUB();
    klub_BEL->setMaxVelocity(140.0);

    // Загрузка электронной карты в КЛУБ
    QString speeds_name = "speeds";

    if (dir > 0)
        speeds_name += "1";
    else
        speeds_name += "2";

    QString path = QDir::toNativeSeparators(route_dir) +
            QDir::separator() + speeds_name + ".conf";

    klub_BEL->loadSpeedsMap(path);
    klub_BEL->setDirection(dir * orient);
    klub_BEL->setTrainLength(length);

    // Загрузка станций в КЛУБ
    path = QDir::toNativeSeparators(route_dir) +
            QDir::separator() + "stations.conf";

    klub_BEL->loadStationsMap(path);
}
