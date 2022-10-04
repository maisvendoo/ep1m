#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepAirSupplySystem(double t, double dt)
{
    main_res->setAirFlow(main_compressor->getAirFlow());
    main_res->step(t, dt);

    // Цепь включения главного компрессора
    bool is_mk_On = tumblers_panel->getTumblerState(TUMBLER_AUX_MACHINES) &&
            tumblers_panel->getTumblerState(TUMBLER_COMPRESSOR) &&
            press_reg->getState();

    main_compressor->setU_power(trac_trans->getControlPowerVoltage() *
                                static_cast<double>(is_mk_On));

    main_compressor->setExternalPressure(main_res->getPressure());
    main_compressor->step(t, dt);

    press_reg->setPressure(main_res->getPressure());
    press_reg->step(t, dt);
}
