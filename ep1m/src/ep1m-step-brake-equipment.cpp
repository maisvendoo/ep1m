#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepBrakeEquipment(double t, double dt)
{
    epk->setBrakepipePressure(pTM);
    epk->setFeedlinePressure(main_res->getPressure());
    epk->setControl(keys);
    epk->powerOn(klub_BEL->getEPKstate());
    epk->step(t, dt);

    Q_r[1] = brake_mech[FWD_TROLLEY]->getBrakeTorque();
    Q_r[2] = brake_mech[FWD_TROLLEY]->getBrakeTorque();

    Q_r[3] = brake_mech[MID_TROLLEY]->getBrakeTorque();
    Q_r[4] = brake_mech[MID_TROLLEY]->getBrakeTorque();

    Q_r[5] = brake_mech[BWD_TROLLEY]->getBrakeTorque();
    Q_r[6] = brake_mech[BWD_TROLLEY]->getBrakeTorque();


    brake_mech[FWD_TROLLEY]->setAirFlow(rd1->getBrakeCylAirFlow());
    brake_mech[MID_TROLLEY]->setAirFlow(rd2->getBrakeCylAirFlow());
    brake_mech[BWD_TROLLEY]->setAirFlow(rd3->getBrakeCylAirFlow());

    for (size_t i = 0; i < brake_mech.size(); ++i)
    {
        brake_mech[i]->step(t, dt);
    }

    aux_res->setAirFlow(electro_air_dist->getOutputSupplyReservoirFlow());
    aux_res->step(t, dt);

    air_dist->setBrakeCylinderPressure(electro_air_dist->getPbc_out());
    air_dist->setAirSupplyPressure(electro_air_dist->getSupplyReservoirPressure());
    air_dist->setBrakepipePressure(pTM);
    auxRate = air_dist->getAuxRate() + epk->getEmergencyBrakeRate();
    air_dist->step(t, dt);

    electro_air_dist->setControlLine(ept_control[0] * static_cast<double>(!tumblers[BRAKE_RELEASE_BUTTON].getState()));
    electro_air_dist->setQbc_in(air_dist->getBrakeCylinderAirFlow());
    electro_air_dist->setPbc_in(rd4->getWorkPressure());
    electro_air_dist->setInputSupplyReservoirFlow(air_dist->getAirSupplyFlow());
    electro_air_dist->setSupplyReservoirPressure(aux_res->getPressure());
    electro_air_dist->step(t, dt);

    rd4->setPipelinePressure(main_res->getPressure());
    rd4->setWorkAirFlow(electro_air_dist->getQbc_out());
    rd4->setBrakeCylPressure(kp1->getPressure2());
    rd4->step(t, dt);

    pneumo_red_panel->setPipeLinePressure(main_res->getPressure());
    pneumo_red_panel->setPressure1(Y4->getInputPressure());
    pneumo_red_panel->setPressure5(Y5->getInputPressure());
    pneumo_red_panel->step(t, dt);

    Y4->setInputFlow(pneumo_red_panel->getOutputFlow1());
    Y4->setOutputPressure(kp2->getPressure1());
    Y4->step(t, dt);

    Y5->setVoltage(Ucc * static_cast<double>(msud->getOutputData().is_not_brake_boost));
    Y5->setInputFlow(pneumo_red_panel->getOutputFlow5());
    Y5->setOutputPressure(kp1->getPressure1());
    Y5->step(t, dt);

    kp1->setInputFlow1(Y5->getOutputFlow());
    kp1->setInputFlow2(rd4->getBrakeCylAirFlow());
    kp1->setOutputPressure(Y3->getInputPressure());
    kp1->step(t, dt);

    Y3->setInputFlow(kp1->getOutputFlow());
    Y3->setOutputPressure(kp2->getPressure2());
    Y3->step(t, dt);

    kp2->setInputFlow1(Y4->getOutputFlow());
    kp2->setInputFlow2(Y3->getOutputFlow());
    kp2->setOutputPressure(kp5->getPressure1());
    kp2->step(t, dt);

    kp5->setInputFlow1(kp2->getOutputFlow());
    kp5->setInputFlow2(loco_crane->getBrakeCylinderFlow());
    kp5->setOutputPressure(ps1->getP_in());
    kp5->step(t, dt);

    ps1->setQ_in(kp5->getOutputFlow());
    ps1->setP_out1(rd1->getWorkPressure());
    ps1->setP_out2(ps2->getP_in());
    ps1->step(t, dt);

    ps2->setQ_in(ps1->getQ_out2());
    ps2->setP_out1(rd2->getWorkPressure());
    ps2->setP_out2(rd3->getWorkPressure());
    ps2->step(t, dt);

    rd1->setPipelinePressure(main_res->getPressure());
    rd1->setWorkAirFlow(ps1->getQ_out1());
    rd1->setBrakeCylPressure(brake_mech[FWD_TROLLEY]->getBrakeCylinderPressure());
    rd1->step(t, dt);

    rd2->setPipelinePressure(main_res->getPressure());
    rd2->setWorkAirFlow(ps2->getQ_out1());
    rd2->setBrakeCylPressure(brake_mech[MID_TROLLEY]->getBrakeCylinderPressure());
    rd2->step(t, dt);

    rd3->setPipelinePressure(main_res->getPressure());
    rd3->setWorkAirFlow(ps2->getQ_out2());
    rd3->setBrakeCylPressure(brake_mech[BWD_TROLLEY]->getBrakeCylinderPressure());
    rd3->step(t, dt);

    stepEPT(t, dt);
}
