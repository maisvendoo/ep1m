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

    // верхний ряд слева направо
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

    // нижний ряд справа налево
    analogSignal[SOUND_TUMBLER_AUX_MACHINES_ON] = tumblers_panel->getTumblerSoundSignal(TUMBLER_AUX_MACHINES, Trigger::ON_SOUND);
    analogSignal[SOUND_TUMBLER_AUX_MACHINES_OFF] = tumblers_panel->getTumblerSoundSignal(TUMBLER_AUX_MACHINES, Trigger::OFF_SOUND);
    analogSignal[SOUND_TUMBLER_COMPRESSOR_ON] = tumblers_panel->getTumblerSoundSignal(TUMBLER_COMPRESSOR, Trigger::ON_SOUND);
    analogSignal[SOUND_TUMBLER_COMPRESSOR_OFF] = tumblers_panel->getTumblerSoundSignal(TUMBLER_COMPRESSOR, Trigger::OFF_SOUND);
    analogSignal[SOUND_TUMBLER_MOTOR_FAN1_ON] = tumblers_panel->getTumblerSoundSignal(TUMBLER_MOTOR_FAN1, Trigger::ON_SOUND);
    analogSignal[SOUND_TUMBLER_MOTOR_FAN1_OFF] = tumblers_panel->getTumblerSoundSignal(TUMBLER_MOTOR_FAN1, Trigger::OFF_SOUND);
    analogSignal[SOUND_TUMBLER_MOTOR_FAN2_ON] = tumblers_panel->getTumblerSoundSignal(TUMBLER_MOTOR_FAN2, Trigger::ON_SOUND);
    analogSignal[SOUND_TUMBLER_MOTOR_FAN2_OFF] = tumblers_panel->getTumblerSoundSignal(TUMBLER_MOTOR_FAN2, Trigger::OFF_SOUND);
    analogSignal[SOUND_TUMBLER_MOTOR_FAN3_ON] = tumblers_panel->getTumblerSoundSignal(TUMBLER_MOTOR_FAN3, Trigger::ON_SOUND);
    analogSignal[SOUND_TUMBLER_MOTOR_FAN3_OFF] = tumblers_panel->getTumblerSoundSignal(TUMBLER_MOTOR_FAN3, Trigger::OFF_SOUND);
    analogSignal[SOUND_TUMBLER_EPT_ON] = tumblers_panel->getTumblerSoundSignal(TUMBLER_EPT, Trigger::ON_SOUND);
    analogSignal[SOUND_TUMBLER_EPT_OFF] = tumblers_panel->getTumblerSoundSignal(TUMBLER_EPT, Trigger::OFF_SOUND);

    // Тяговый трансформатор
    analogSignal[SOUND_TRANSFORMER] = trac_trans->getSoundSignal();

    // Мотор-вентиляторы
    analogSignal[SOUND_FAN1_LOW] = motor_fan[MV1]->getSoundSignal(MotorFan::LOW_FREQ);
    analogSignal[SOUND_FAN1_HIGH] = motor_fan[MV1]->getSoundSignal(MotorFan::HIGH_FREQ);
    analogSignal[SOUND_FAN2_LOW] = motor_fan[MV2]->getSoundSignal(MotorFan::LOW_FREQ);
    analogSignal[SOUND_FAN2_HIGH] = motor_fan[MV2]->getSoundSignal(MotorFan::HIGH_FREQ);
    analogSignal[SOUND_FAN3_LOW] = motor_fan[MV3]->getSoundSignal(MotorFan::LOW_FREQ);
    analogSignal[SOUND_FAN3_HIGH] = motor_fan[MV3]->getSoundSignal(MotorFan::HIGH_FREQ);
    analogSignal[SOUND_FAN4] = motor_fan[MV4]->getSoundSignal(MotorFan::HIGH_FREQ);

    // Контроллер машиниста
    analogSignal[SOUND_CONTROLLER] = km->getSoundSignal(TracController::MAIN_HANDLE);
    analogSignal[SOUND_REVERSOR] = km->getSoundSignal(TracController::REVERS_HANDLE);

    // Маленькие тумблерки разного назначения
    analogSignal[SOUND_TUMBLER_PCHF_ON] = tumblers[TUMBLER_PCHF].getSoundSignal(Trigger::ON_SOUND);
    analogSignal[SOUND_TUMBLER_PCHF_OFF] = tumblers[TUMBLER_PCHF].getSoundSignal(Trigger::OFF_SOUND);
    analogSignal[SOUND_TUMBLER_SIGNALING_ON] = tumblers[TUMBLER_BS_002].getSoundSignal(Trigger::ON_SOUND);
    analogSignal[SOUND_TUMBLER_SIGNALING_OFF] = tumblers[TUMBLER_BS_002].getSoundSignal(Trigger::OFF_SOUND);
    analogSignal[SOUND_TUMBLER_AUTOREG_ON] = tumblers[TUMBLER_AUTO_MODE].getSoundSignal(Trigger::ON_SOUND);
    analogSignal[SOUND_TUMBLER_AUTOREG_OFF] = tumblers[TUMBLER_AUTO_MODE].getSoundSignal(Trigger::OFF_SOUND);
    analogSignal[SOUND_TUMBLER_MPK_ON] = tumblers[TUMBLER_MPK].getSoundSignal(Trigger::ON_SOUND);
    analogSignal[SOUND_TUMBLER_MPK_OFF] = tumblers[TUMBLER_MPK].getSoundSignal(Trigger::OFF_SOUND);
}
