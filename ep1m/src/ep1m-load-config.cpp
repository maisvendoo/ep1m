#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::loadConfig(QString path)
{
    CfgReader cfg;

    if (cfg.load(path))
    {
        QString secName = "Vehicle";

        cfg.getDouble(secName, "MainResLeak", main_res_leak);
    }
}
