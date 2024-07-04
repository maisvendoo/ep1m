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

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepTapSounds()
{
    double speed = abs(this->velocity) * 3.6;

    for (int i = 0; i < tap_sounds.count(); ++i)
    {
        emit volumeCurveStep(tap_sounds[i], static_cast<float>(speed));
    }
}
