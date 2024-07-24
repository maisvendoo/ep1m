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

    // Мотор-компрессор
    analogSignal[SOUND_COMPRESSOR] = motor_compressor->getSoundSignal();

    // Токоприемники
    analogSignal[SOUND_PANT1_UP] = pant[PANT1]->getSoundSignal(Pantograph::UP_SOUND);
    analogSignal[SOUND_PANT1_DOWN] = pant[PANT1]->getSoundSignal(Pantograph::DOWN_SOUND);
    analogSignal[SOUND_PANT2_UP] = pant[PANT2]->getSoundSignal(Pantograph::UP_SOUND);
    analogSignal[SOUND_PANT2_DOWN] = pant[PANT2]->getSoundSignal(Pantograph::DOWN_SOUND);

    // Главный выключатель
    analogSignal[SOUND_MAIN_SWITCH_ON] = main_switch->getSoundSignal(ProtectiveDevice::ON_SOUND);
    analogSignal[SOUND_MAIN_SWITCH_OFF] = main_switch->getSoundSignal(ProtectiveDevice::OFF_SOUND);

    // Ключ ЭПК
    analogSignal[SOUND_EPK_KEY_ON] = tumblers[EPK_KEY].getSoundSignal(Trigger::ON_SOUND);
    analogSignal[SOUND_EPK_KEY_OFF] = tumblers[EPK_KEY].getSoundSignal(Trigger::OFF_SOUND);

    // Реле и контакторы
    analogSignal[SOUND_KM5] = km5->getSoundSignal(Relay::CHANGE_SOUND);
    analogSignal[SOUND_VZ6] = safety_valve->getSoundSignal(Relay::CHANGE_SOUND);
    analogSignal[SOUND_KV44] = kv44->getSoundSignal(Relay::CHANGE_SOUND);
    analogSignal[SOUND_KV39] = kv39->getSoundSignal(Relay::CHANGE_SOUND);
    analogSignal[SOUND_KV21] = kv21->getSoundSignal(Relay::CHANGE_SOUND);
    analogSignal[SOUND_KV22] = kv22->getSoundSignal(Relay::CHANGE_SOUND);
    analogSignal[SOUND_KV23] = kv23->getSoundSignal(Relay::CHANGE_SOUND);
    analogSignal[SOUND_KV41] = kv41->getSoundSignal(Relay::CHANGE_SOUND);
    analogSignal[SOUND_KM7] = km7->getSoundSignal(Relay::CHANGE_SOUND);
    analogSignal[SOUND_KM8] = km8->getSoundSignal(Relay::CHANGE_SOUND);
    analogSignal[SOUND_KM9] = km9->getSoundSignal(Relay::CHANGE_SOUND);
    analogSignal[SOUND_KM11] = km11->getSoundSignal(Relay::CHANGE_SOUND);
    analogSignal[SOUND_KM12] = km12->getSoundSignal(Relay::CHANGE_SOUND);
    analogSignal[SOUND_KM13] = km13->getSoundSignal(Relay::CHANGE_SOUND);

    analogSignal[SOUND_KM43] = km43->getSoundSignal(Relay::CHANGE_SOUND);
    analogSignal[SOUND_KV11] = kv11->getSoundSignal(Relay::CHANGE_SOUND);
    analogSignal[SOUND_KV12] = kv12->getSoundSignal(Relay::CHANGE_SOUND);
    analogSignal[SOUND_KV13] = kv13->getSoundSignal(Relay::CHANGE_SOUND);
    analogSignal[SOUND_KV14] = kv14->getSoundSignal(Relay::CHANGE_SOUND);
    analogSignal[SOUND_KV15] = kv15->getSoundSignal(Relay::CHANGE_SOUND);
    analogSignal[SOUND_KT10] = kt10->getSoundSignal(Relay::CHANGE_SOUND);
    analogSignal[SOUND_KT1] = kt1->getSoundSignal(Relay::CHANGE_SOUND);
    analogSignal[SOUND_KT4] = kt4->getSoundSignal(Relay::CHANGE_SOUND);
    analogSignal[SOUND_KT5] = kt5->getSoundSignal(Relay::CHANGE_SOUND);
    analogSignal[SOUND_KM41] = km41->getSoundSignal(Relay::CHANGE_SOUND);
    analogSignal[SOUND_KM42] = km42->getSoundSignal(Relay::CHANGE_SOUND);
    analogSignal[SOUND_KM14] = km14->getSoundSignal(Relay::CHANGE_SOUND);
    analogSignal[SOUND_K1] = k1->getSoundSignal(Relay::CHANGE_SOUND);

    // КЛУБ
    analogSignal[SOUND_KLUB_ON] = klub_BEL->getSoundSignal(KLUB::ON_SOUND);
    analogSignal[SOUND_KLUB_BUTTONS] = klub_BEL->getSoundSignal(KLUB::BUTTON_SOUND);

    // Перестуки
    double Vkmh = abs(velocity) * Physics::kmh;
    analogSignal[SOUND_5_10] = sound_state_t::createSoundSignal((Vkmh > 1.0) && (Vkmh <= 10.0), Vkmh / 5.0);
    analogSignal[SOUND_10_20] = sound_state_t::createSoundSignal((Vkmh > 10.0) && (Vkmh <= 20.0));
    analogSignal[SOUND_20_30] = sound_state_t::createSoundSignal((Vkmh > 20.0) && (Vkmh <= 30.0));
    analogSignal[SOUND_30_40] = sound_state_t::createSoundSignal((Vkmh > 30.0) && (Vkmh <= 40.0));
    analogSignal[SOUND_40_50] = sound_state_t::createSoundSignal((Vkmh > 40.0) && (Vkmh <= 50.0));
    analogSignal[SOUND_50_60] = sound_state_t::createSoundSignal((Vkmh > 50.0) && (Vkmh <= 60.0));
    analogSignal[SOUND_60_70] = sound_state_t::createSoundSignal((Vkmh > 60.0) && (Vkmh <= 70.0));
    analogSignal[SOUND_70_80] = sound_state_t::createSoundSignal((Vkmh > 70.0) && (Vkmh <= 80.0));
    analogSignal[SOUND_80_90] = sound_state_t::createSoundSignal((Vkmh > 80.0) && (Vkmh <= 90.0));
    analogSignal[SOUND_90_100] = sound_state_t::createSoundSignal((Vkmh > 90.0) && (Vkmh <= 100.0));
    analogSignal[SOUND_100_110] = sound_state_t::createSoundSignal((Vkmh > 100.0) && (Vkmh <= 110.0));
    analogSignal[SOUND_110_120] = sound_state_t::createSoundSignal((Vkmh > 110.0) && (Vkmh <= 120.0));
    analogSignal[SOUND_120_130] = sound_state_t::createSoundSignal((Vkmh > 120.0) && (Vkmh <= 130.0));
    analogSignal[SOUND_130_140] = sound_state_t::createSoundSignal((Vkmh > 130.0) && (Vkmh <= 140.0));
    analogSignal[SOUND_140_INF] = sound_state_t::createSoundSignal(Vkmh > 140.0);

    analogSignal[SOUND_TED1] = trac_motor[TRAC_MOTOR1]->getSoundSignal();
    analogSignal[SOUND_TED2] = trac_motor[TRAC_MOTOR2]->getSoundSignal();
    analogSignal[SOUND_TED3] = trac_motor[TRAC_MOTOR3]->getSoundSignal();
    analogSignal[SOUND_TED4] = trac_motor[TRAC_MOTOR4]->getSoundSignal();
    analogSignal[SOUND_TED5] = trac_motor[TRAC_MOTOR5]->getSoundSignal();
    analogSignal[SOUND_TED6] = trac_motor[TRAC_MOTOR6]->getSoundSignal();
}
