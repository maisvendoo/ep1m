#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::soundsOutput(const simulator_time_t& t, const double& dt)
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

    // Проверяем ток тяговых двигателей
    bool is_motors_On = false;

    for (size_t i = 0; i < trac_motor.size(); ++i)
    {
        is_motors_On = is_motors_On || qAbs(trac_motor[i]->getAncorCurrent()) >= 100.0;
    }

    analogSignal[SOUND_TED_4_6] = sound_state_t::createSoundSignal((Vkmh > 0.5) && (Vkmh <=6) && is_motors_On, Vkmh / 4.0, 0.5f + Vkmh / 10.0);
    analogSignal[SOUND_TED_6_8] = sound_state_t::createSoundSignal((Vkmh > 6) && (Vkmh <=8) && is_motors_On);
    analogSignal[SOUND_TED_8_10] = sound_state_t::createSoundSignal((Vkmh > 8) && (Vkmh <=10) && is_motors_On);
    analogSignal[SOUND_TED_10_12] = sound_state_t::createSoundSignal((Vkmh > 10) && (Vkmh <=12) && is_motors_On);
    analogSignal[SOUND_TED_12_14] = sound_state_t::createSoundSignal((Vkmh > 12) && (Vkmh <=14) && is_motors_On);
    analogSignal[SOUND_TED_14_16] = sound_state_t::createSoundSignal((Vkmh > 14) && (Vkmh <=16) && is_motors_On);
    analogSignal[SOUND_TED_16_18] = sound_state_t::createSoundSignal((Vkmh > 16) && (Vkmh <=18) && is_motors_On);
    analogSignal[SOUND_TED_18_20] = sound_state_t::createSoundSignal((Vkmh > 18) && (Vkmh <=20) && is_motors_On);
    analogSignal[SOUND_TED_20_22] = sound_state_t::createSoundSignal((Vkmh > 20) && (Vkmh <=22) && is_motors_On);
    analogSignal[SOUND_TED_22_24] = sound_state_t::createSoundSignal((Vkmh > 22) && (Vkmh <=24) && is_motors_On);
    analogSignal[SOUND_TED_24_26] = sound_state_t::createSoundSignal((Vkmh > 24) && (Vkmh <=26) && is_motors_On);
    analogSignal[SOUND_TED_26_28] = sound_state_t::createSoundSignal((Vkmh > 26) && (Vkmh <=28) && is_motors_On);
    analogSignal[SOUND_TED_28_30] = sound_state_t::createSoundSignal((Vkmh > 28) && (Vkmh <=30) && is_motors_On);
    analogSignal[SOUND_TED_30_32] = sound_state_t::createSoundSignal((Vkmh > 30) && (Vkmh <=32) && is_motors_On);
    analogSignal[SOUND_TED_32_34] = sound_state_t::createSoundSignal((Vkmh > 32) && (Vkmh <=34) && is_motors_On);
    analogSignal[SOUND_TED_34_36] = sound_state_t::createSoundSignal((Vkmh > 34) && (Vkmh <=36) && is_motors_On);
    analogSignal[SOUND_TED_36_38] = sound_state_t::createSoundSignal((Vkmh > 36) && (Vkmh <=38) && is_motors_On);
    analogSignal[SOUND_TED_38_40] = sound_state_t::createSoundSignal((Vkmh > 38) && (Vkmh <=40) && is_motors_On);
    analogSignal[SOUND_TED_40_42] = sound_state_t::createSoundSignal((Vkmh > 40) && (Vkmh <=42) && is_motors_On);
    analogSignal[SOUND_TED_42_44] = sound_state_t::createSoundSignal((Vkmh > 42) && (Vkmh <=44) && is_motors_On);
    analogSignal[SOUND_TED_44_46] = sound_state_t::createSoundSignal((Vkmh > 44) && (Vkmh <=46) && is_motors_On);
    analogSignal[SOUND_TED_46_48] = sound_state_t::createSoundSignal((Vkmh > 46) && (Vkmh <=48) && is_motors_On);
    analogSignal[SOUND_TED_48_50] = sound_state_t::createSoundSignal((Vkmh > 48) && (Vkmh <=50) && is_motors_On);
    analogSignal[SOUND_TED_50_52] = sound_state_t::createSoundSignal((Vkmh > 50) && (Vkmh <=52) && is_motors_On);
    analogSignal[SOUND_TED_52_54] = sound_state_t::createSoundSignal((Vkmh > 52) && (Vkmh <=54) && is_motors_On);
    analogSignal[SOUND_TED_54_56] = sound_state_t::createSoundSignal((Vkmh > 54) && (Vkmh <=56) && is_motors_On);
    analogSignal[SOUND_TED_56_58] = sound_state_t::createSoundSignal((Vkmh > 56) && (Vkmh <=58) && is_motors_On);
    analogSignal[SOUND_TED_58_60] = sound_state_t::createSoundSignal((Vkmh > 58) && (Vkmh <=60) && is_motors_On);
    analogSignal[SOUND_TED_60_62] = sound_state_t::createSoundSignal((Vkmh > 60) && (Vkmh <=62) && is_motors_On);
    analogSignal[SOUND_TED_62_64] = sound_state_t::createSoundSignal((Vkmh > 62) && (Vkmh <=64) && is_motors_On);
    analogSignal[SOUND_TED_64_66] = sound_state_t::createSoundSignal((Vkmh > 64) && (Vkmh <=66) && is_motors_On);
    analogSignal[SOUND_TED_66_68] = sound_state_t::createSoundSignal((Vkmh > 66) && (Vkmh <=68) && is_motors_On);
    analogSignal[SOUND_TED_68_70] = sound_state_t::createSoundSignal((Vkmh > 68) && (Vkmh <=70) && is_motors_On);
    analogSignal[SOUND_TED_70_72] = sound_state_t::createSoundSignal((Vkmh > 70) && (Vkmh <=72) && is_motors_On);
    analogSignal[SOUND_TED_72_74] = sound_state_t::createSoundSignal((Vkmh > 72) && (Vkmh <=74) && is_motors_On);
    analogSignal[SOUND_TED_74_76] = sound_state_t::createSoundSignal((Vkmh > 74) && (Vkmh <=76) && is_motors_On);
    analogSignal[SOUND_TED_76_78] = sound_state_t::createSoundSignal((Vkmh > 76) && (Vkmh <=78) && is_motors_On);
    analogSignal[SOUND_TED_78_80] = sound_state_t::createSoundSignal((Vkmh > 78) && (Vkmh <=80) && is_motors_On);
    analogSignal[SOUND_TED_80_82] = sound_state_t::createSoundSignal((Vkmh > 80) && (Vkmh <=82) && is_motors_On);
    analogSignal[SOUND_TED_82_84] = sound_state_t::createSoundSignal((Vkmh > 82) && (Vkmh <=84) && is_motors_On);
    analogSignal[SOUND_TED_84_86] = sound_state_t::createSoundSignal((Vkmh > 84) && (Vkmh <=86) && is_motors_On);
    analogSignal[SOUND_TED_86_88] = sound_state_t::createSoundSignal((Vkmh > 86) && (Vkmh <=88) && is_motors_On);
    analogSignal[SOUND_TED_88_90] = sound_state_t::createSoundSignal((Vkmh > 88) && (Vkmh <=90) && is_motors_On);
    analogSignal[SOUND_TED_90_92] = sound_state_t::createSoundSignal((Vkmh > 90) && (Vkmh <=92) && is_motors_On);
    analogSignal[SOUND_TED_92_94] = sound_state_t::createSoundSignal((Vkmh > 92) && (Vkmh <=94) && is_motors_On);
    analogSignal[SOUND_TED_94_96] = sound_state_t::createSoundSignal((Vkmh > 94) && (Vkmh <=96) && is_motors_On);
    analogSignal[SOUND_TED_96_98] = sound_state_t::createSoundSignal((Vkmh > 96) && (Vkmh <=98) && is_motors_On);
    analogSignal[SOUND_TED_98_100] = sound_state_t::createSoundSignal((Vkmh > 98) && (Vkmh <=100) && is_motors_On);
    analogSignal[SOUND_TED_100_102] = sound_state_t::createSoundSignal((Vkmh > 100) && (Vkmh <=102) && is_motors_On);
    analogSignal[SOUND_TED_102_104] = sound_state_t::createSoundSignal((Vkmh > 102) && (Vkmh <=104) && is_motors_On);
    analogSignal[SOUND_TED_104_106] = sound_state_t::createSoundSignal((Vkmh > 104) && (Vkmh <=106) && is_motors_On);
    analogSignal[SOUND_TED_106_108] = sound_state_t::createSoundSignal((Vkmh > 106) && (Vkmh <=108) && is_motors_On);
    analogSignal[SOUND_TED_108_110] = sound_state_t::createSoundSignal((Vkmh > 108) && (Vkmh <=110) && is_motors_On);
    analogSignal[SOUND_TED_110_112] = sound_state_t::createSoundSignal((Vkmh > 110) && (Vkmh <=112) && is_motors_On);
    analogSignal[SOUND_TED_112_114] = sound_state_t::createSoundSignal((Vkmh > 112) && (Vkmh <=114) && is_motors_On);
    analogSignal[SOUND_TED_114_116] = sound_state_t::createSoundSignal((Vkmh > 114) && (Vkmh <=116) && is_motors_On);
    analogSignal[SOUND_TED_116_118] = sound_state_t::createSoundSignal((Vkmh > 116) && (Vkmh <=118) && is_motors_On);
    analogSignal[SOUND_TED_118_120] = sound_state_t::createSoundSignal((Vkmh > 118) && (Vkmh <=120) && is_motors_On);
    analogSignal[SOUND_TED_120_122] = sound_state_t::createSoundSignal((Vkmh > 120) && (Vkmh <=122) && is_motors_On);
    analogSignal[SOUND_TED_122_124] = sound_state_t::createSoundSignal((Vkmh > 122) && (Vkmh <=124) && is_motors_On);
    analogSignal[SOUND_TED_124_126] = sound_state_t::createSoundSignal((Vkmh > 124) && (Vkmh <=126) && is_motors_On);
    analogSignal[SOUND_TED_126_128] = sound_state_t::createSoundSignal((Vkmh > 126) && (Vkmh <=128) && is_motors_On);
    analogSignal[SOUND_TED_128_130] = sound_state_t::createSoundSignal((Vkmh > 128) && (Vkmh <=130) && is_motors_On);
    analogSignal[SOUND_TED_130_132] = sound_state_t::createSoundSignal((Vkmh > 130) && (Vkmh <=132) && is_motors_On);
    analogSignal[SOUND_TED_132_134] = sound_state_t::createSoundSignal((Vkmh > 132) && (Vkmh <=134) && is_motors_On);
    analogSignal[SOUND_TED_134_136] = sound_state_t::createSoundSignal((Vkmh > 134) && (Vkmh <=136) && is_motors_On);
    analogSignal[SOUND_TED_136_138] = sound_state_t::createSoundSignal((Vkmh > 136) && (Vkmh <=138) && is_motors_On);
    analogSignal[SOUND_TED_138_140] = sound_state_t::createSoundSignal((Vkmh > 138) && is_motors_On);

    // Свисток ЭПК
    analogSignal[SOUND_EPK] = epk->getSoundSignal();

    // Песочница
    analogSignal[SOUND_SAND_DELIVERY] = sand_system->getSoundSignal();
}
