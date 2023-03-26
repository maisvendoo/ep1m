#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
double EP1m::calcTracForce()
{
    double trac_force = 0;

    for (size_t i = 1; i < Q_a.size(); ++i)
    {
        trac_force += 2 * Q_a[i] / wheel_diameter[i - 1];
    }

    return trac_force;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepRegistration(double t, double dt)
{
    if (!is_Registarator_on)
        return;

    QString line = QString("%1 %2 %3 %4")
            .arg(t, 10, 'f', 1)
            .arg(velocity * Physics::kmh, 6, '2', 1)
            .arg(trac_motor[0]->getAncorCurrent(), 7, 'f', 2)
            .arg(calcTracForce() / 1000.0, 6, '2', 1);

    registrator->print(line, t, dt);
}
