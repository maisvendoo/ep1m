#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepOtherEquipment(double t, double dt)
{
    horn->setFLpressure(main_reservoir->getPressure());
    horn->setControl(keys);
    horn->step(t, dt);

    // Система подачи песка
    sand_system->setFLpressure(main_reservoir->getPressure());
    //sand_system->setSandDeliveryOn(button_sandbox.getState());
    sand_system->setControl(keys);
    sand_system->step(t, dt);
    for (size_t i = 0; i < num_axis; ++i)
    {
        // Пересчёт трения колесо-рельс
        psi[i] = sand_system->getWheelRailFrictionCoeff(psi[i]);
    }
    // Пересчёт массы локомотива
    payload_coeff = sand_system->getSandLevel();
    setPayloadCoeff(payload_coeff);
}
