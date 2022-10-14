#ifndef     TROLLEY_BRAKE_MECH_H
#define     TROLLEY_BRAKE_MECH_H

#include    "brake-mech.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class TrolleyBrakeMech : public BrakeMech
{
public:

    TrolleyBrakeMech(QObject *parent = Q_NULLPTR);

    ~TrolleyBrakeMech();

private:

    void load_config(CfgReader &cfg) override;
};

#endif // TROLLEYBRAKEMECH_H
