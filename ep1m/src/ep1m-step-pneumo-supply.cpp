#include    "ep1m.h"

//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
void EP1m::stepPneumoSupply(double t, double dt)
{
    // Регулятор давления
    press_reg->setFLpressure(main_reservoir->getPressure());
    press_reg->step(t, dt);

    // Цепь включения главного компрессора
    double is_mk_On = static_cast<double>( press_reg->getState()
                    && tumblers_panel->getTumblerState(TUMBLER_COMPRESSOR) );
    double U_power = is_mk_On * freq_phase_conv->getOutputVoltage();

    // Мотор-компрессор
    motor_compressor->setFLpressure(main_reservoir->getPressure());
    motor_compressor->setPowerVoltage(U_power);
    motor_compressor->step(t, dt);

    // Главный резервуар
    double FL_flow = 0.0;
    FL_flow += motor_compressor->getFLflow();
    FL_flow += brake_lock->getFLflow();
    FL_flow += epk->getFLflow();
    FL_flow += bc_pressure_relay[TROLLEY_FWD]->getFLflow();
    FL_flow += bc_pressure_relay[TROLLEY_MID]->getFLflow();
    FL_flow += bc_pressure_relay[TROLLEY_BWD]->getFLflow();
    FL_flow += anglecock_fl_fwd->getFlowToPipe();
    FL_flow += anglecock_fl_bwd->getFlowToPipe();
    main_reservoir->setFlow(FL_flow);
    main_reservoir->step(t, dt);

    // Концевые краны питательной магистрали
    anglecock_fl_fwd->setPipePressure(main_reservoir->getPressure());
    anglecock_fl_fwd->setHoseFlow(hose_fl_fwd->getFlow());
    anglecock_fl_fwd->step(t, dt);
    anglecock_fl_bwd->setPipePressure(main_reservoir->getPressure());
    anglecock_fl_bwd->setHoseFlow(hose_fl_bwd->getFlow());
    anglecock_fl_bwd->step(t, dt);

    // Рукава тормозной питательной магистрали
    hose_fl_fwd->setPressure(anglecock_fl_fwd->getPressureToHose());
    hose_fl_fwd->setFlowCoeff(anglecock_fl_fwd->getFlowCoeff());
    hose_fl_fwd->step(t, dt);
    hose_fl_bwd->setPressure(anglecock_fl_bwd->getPressureToHose());
    hose_fl_bwd->setFlowCoeff(anglecock_fl_bwd->getFlowCoeff());
    hose_fl_bwd->step(t, dt);
}
