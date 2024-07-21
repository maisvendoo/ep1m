#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepDebugPrint(double t, double dt)
{
    (void) t;
    (void) dt;

    /*DebugMsg = "";
    DebugMsg += QString("x%1 km|V%2 km/h|")
                    .arg(railway_coord / 1000.0, 8, 'f', 3)
                    .arg(velocity * Physics::kmh, 6, 'f', 1);
    DebugMsg += QString("pBP%1|pBC%2|pSR%3|")
                    .arg(10.0 * brakepipe->getPressure(), 6, 'f', 2)
                    .arg(10.0 * brake_mech[TROLLEY_FWD]->getBCpressure(), 6, 'f', 2)
                    .arg(10.0 * supply_reservoir->getPressure(), 6, 'f', 2);
    DebugMsg += QString("pFL%1|pER%2|395:%3|254:%4%|")
                    .arg(10.0 * main_reservoir->getPressure(), 6, 'f', 2)
                    .arg(10.0 * brake_crane->getERpressure(), 6, 'f', 2)
                    .arg(brake_crane->getPositionName(), 3)
                    .arg(loco_crane->getHandlePosition() * 100.0, 3, 'f', 0);
    DebugMsg += QString("Rev%1|T:%2%|")
                    .arg(km->getReversHandlePos(), 2)
                    .arg(100.0 * km->getHandlePosition(), 4, 'f', 0);

    QString traction_reg = "";
    if (tumblers[TUMBLER_AUTO_MODE].getState())
        traction_reg = QString("V:off|field%1%|I:%2 A")
                    .arg(km->getRefSpeedLevel() * 100.0, 3, 'f', 0)
                    .arg(trac_motor[TRAC_MOTOR1]->getAncorCurrent(), 6, 'f', 0);
    else
        traction_reg = QString("V:%1 /%2 |I:%3 A")
                    .arg(velocity * Physics::kmh, 4, 'f', 0)
                    .arg(km->getRefSpeedLevel() * 140.0, 4, 'f', 0)
                    .arg(trac_motor[TRAC_MOTOR1]->getAncorCurrent(), 6, 'f', 0);

    DebugMsg += traction_reg;

    DebugMsg += QString("BP:Anglecock F%1 B%2|Hose F%3 B%4|")
                    .arg(anglecock_bp_fwd->isOpened())
                    .arg(anglecock_bp_bwd->isOpened())
                    .arg(hose_bp_fwd->isConnected())
                    .arg(hose_bp_bwd->isConnected());*/

    DebugMsg = QString("ГВ: %1| KV41.0: %2")
                   .arg(main_switch->getState())
                   .arg(kv41->getContactState(0));
}
