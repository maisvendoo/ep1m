#include    "ep1m.h"

#include    <QDir>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::initRegistartor()
{
    if (!is_Registarator_on)
        return;

    registrator = new Registrator();
    registrator->read_custom_config(config_dir +
                                    QDir::separator() +
                                    "registrator");


}
