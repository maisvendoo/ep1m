#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepSoundSignals(double t, double dt)
{
    (void) t;
    (void) dt;

    // Свистулька и тифулька :-)
    analogSignal[SOUND_SVISTOK] = horn->getSoundSignal(TrainHorn::SVISTOK_SOUND);
    analogSignal[SOUND_TIFON] = horn->getSoundSignal(TrainHorn::TIFON_SOUND);

    // Устройство блокировки тормозов
    analogSignal[SOUND_BRAKE_LOCK_CHANGE_LOCK_POS] = brake_lock->getSoundSignal(BrakeLock::CHANGE_LOCK_POS_SOUND);
    analogSignal[SOUND_BRAKE_LOCK_CHANGE_COMB_POS] = brake_lock->getSoundSignal(BrakeLock::CHANGE_COMB_POS_SOUND);
    analogSignal[SOUND_BRAKE_LOCK_BP_DRAIN_FLOW] = brake_lock->getSoundSignal(BrakeLock::BP_DRAIN_FLOW_SOUND);
    // Кран поездного тормоза
    analogSignal[SOUND_BRAKE_CRANE_CHANGE_POS] = brake_crane->getSoundSignal(BrakeCrane::CHANGE_POS_SOUND);
    analogSignal[SOUND_BRAKE_CRANE_ER_STAB_FLOW] = brake_crane->getSoundSignal(BrakeCrane::ER_STAB_SOUND);
    analogSignal[SOUND_BRAKE_CRANE_ER_FILL_FLOW] = brake_crane->getSoundSignal(BrakeCrane::ER_FILL_FLOW_SOUND);
    analogSignal[SOUND_BRAKE_CRANE_ER_DRAIN_FLOW] = brake_crane->getSoundSignal(BrakeCrane::ER_DRAIN_FLOW_SOUND);
    analogSignal[SOUND_BRAKE_CRANE_BP_FILL_FLOW] = brake_crane->getSoundSignal(BrakeCrane::BP_FILL_FLOW_SOUND);
    analogSignal[SOUND_BRAKE_CRANE_BP_DRAIN_FLOW] = brake_crane->getSoundSignal(BrakeCrane::BP_DRAIN_FLOW_SOUND);
    // Кран локомотивного тормоза
    analogSignal[SOUND_LOCO_CRANE_CHANGE_POS] = loco_crane->getSoundSignal(LocoCrane::CHANGE_POS_SOUND);
    analogSignal[SOUND_LOCO_CRANE_BC_FILL_FLOW] = loco_crane->getSoundSignal(LocoCrane::BC_FILL_FLOW_SOUND);
    analogSignal[SOUND_LOCO_CRANE_BC_DRAIN_FLOW] = loco_crane->getSoundSignal(LocoCrane::BC_DRAIN_FLOW_SOUND);

    // Тумблеры центральной панели
    analogSignal[SOUND_TUMBLER_MSUD_ON] = tumblers_panel->getTumblerSoundSignal(TUMBLER_MSUD, Trigger::ON_SOUND);
    analogSignal[SOUND_TUMBLER_MSUD_OFF] = tumblers_panel->getTumblerSoundSignal(TUMBLER_MSUD, Trigger::OFF_SOUND);
    analogSignal[SOUND_TUMBLER_LOCK_VVK_ON] = tumblers_panel->getTumblerSoundSignal(TUMBLER_LOCK_VVK, Trigger::ON_SOUND);
    analogSignal[SOUND_TUMBLER_LOCK_VVK_OFF] = tumblers_panel->getTumblerSoundSignal(TUMBLER_LOCK_VVK, Trigger::OFF_SOUND);
    analogSignal[SOUND_TUMBLER_PANT1_ON] = tumblers_panel->getTumblerSoundSignal(TUMBLER_PANT1, Trigger::ON_SOUND);
    analogSignal[SOUND_TUMBLER_PANT1_OFF] = tumblers_panel->getTumblerSoundSignal(TUMBLER_PANT1, Trigger::OFF_SOUND);
    analogSignal[SOUND_TUMBLER_PANT2_ON] = tumblers_panel->getTumblerSoundSignal(TUMBLER_PANT2, Trigger::ON_SOUND);
    analogSignal[SOUND_TUMBLER_PANT2_OFF] = tumblers_panel->getTumblerSoundSignal(TUMBLER_PANT2, Trigger::OFF_SOUND);
    analogSignal[SOUND_TUMBLER_RETURN_PROTECTION_ON] = tumblers_panel->getTumblerSoundSignal(TUMBLER_RETURN_PROTECTION, Trigger::ON_SOUND);
    analogSignal[SOUND_TUMBLER_RETURN_PROTECTION_OFF] = tumblers_panel->getTumblerSoundSignal(TUMBLER_RETURN_PROTECTION, Trigger::OFF_SOUND);
    analogSignal[SOUND_TUMBLER_MAIN_SWITCH_ON] = tumblers_panel->getTumblerSoundSignal(TUMBLER_MAIN_SWITCH, Trigger::ON_SOUND);
    analogSignal[SOUND_TUMBLER_MAIN_SWITCH_OFF] = tumblers_panel->getTumblerSoundSignal(TUMBLER_MAIN_SWITCH, Trigger::OFF_SOUND);
}
