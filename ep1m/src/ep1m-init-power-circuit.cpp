#include    "ep1m.h"

#include    <QDir>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::initPowerCircuit()
{
    for (size_t i = 0; i < pant.size(); ++i)
    {
        pant[i] = new Pantograph();
    }

    main_switch = new ProtectiveDevice();

    trac_trans = new TractionTransformer();

    safety_valve = new ElectroValve();
    safety_valve->read_custom_config(config_dir + QDir::separator() + "vz-6");
}
