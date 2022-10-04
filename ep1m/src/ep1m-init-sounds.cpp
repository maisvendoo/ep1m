#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::initSounds()
{
    connect(tumblers_panel, &EP1MTumblersPanel::soundPlay, this, &EP1m::soundPlay);

    connect(trac_trans, &TractionTransformer::soundPlay, this, &EP1m::soundPlay);
    connect(trac_trans, &TractionTransformer::soundStop, this, &EP1m::soundStop);

    for (size_t i = 0; i < tumblers.size(); ++i)
    {
        tumblers[i].setOnSoundName("Tumbler_On");
        tumblers[i].setOffSoundName("Tumbler_Off");
        connect(&tumblers[i], &Trigger::soundPlay, this, &EP1m::soundPlay);
    }

    tumblers[SWITCH_REVERS_FWD].setOnSoundName("");
    tumblers[SWITCH_REVERS_FWD].setOffSoundName("");
    tumblers[SWITCH_REVERS_BWD].setOnSoundName("");
    tumblers[SWITCH_REVERS_BWD].setOffSoundName("");

    connect(km5, &Relay::soundPlay, this, &EP1m::soundPlay);

    connect(safety_valve, &ElectroValve::soundPlay, this, &EP1m::soundPlay);

    connect(pant[PANT1], &Pantograph::soundPlay, this, &EP1m::soundPlay);
    connect(pant[PANT2], &Pantograph::soundPlay, this, &EP1m::soundPlay);

    connect(kv44, &Relay::soundPlay, this, &EP1m::soundPlay);
    connect(kv39, &Relay::soundPlay, this, &EP1m::soundPlay);

    connect(km, &TracController::soundPlay, this, &EP1m::soundPlay);

    connect(main_switch, &ProtectiveDevice::soundPlay,
            this, &EP1m::soundPlay);

    connect(main_compressor, &MotorCompressor::soundPlay,
            this, &EP1m::soundPlay);

    connect(main_compressor, &MotorCompressor::soundStop,
            this, &EP1m::soundStop);

    connect(main_compressor, &MotorCompressor::soundSetPitch,
            this, &EP1m::soundSetPitch);
}
