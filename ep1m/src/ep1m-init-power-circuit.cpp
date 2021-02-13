#include    "ep1m.h"

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
}
