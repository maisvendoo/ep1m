#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::signalsOutput()
{
    analogSignal[SIGNAL_UNLOCK_KEY] = TO_FLOAT(tumblers_panel->getUnlockKeyState());

    analogSignal[SIGNAL_TUMBLER_MSUD] = TO_FLOAT(tumblers_panel->getTumblerState(TUMBLER_MSUD));
    analogSignal[SIGNAL_TUMBLER_LOCK_VVK] = TO_FLOAT(tumblers_panel->getTumblerState(TUMBLER_LOCK_VVK));
    analogSignal[SIGNAL_TUMBLER_PANT1] = TO_FLOAT(tumblers_panel->getTumblerState(TUMBLER_PANT1));
    analogSignal[SIGNAL_TUMBLER_PANT2] = TO_FLOAT(tumblers_panel->getTumblerState(TUMBLER_PANT2));
    analogSignal[SIGNAL_TUMBLER_RETURN_PROTECTION] = TO_FLOAT(tumblers_panel->getTumblerState(TUMBLER_RETURN_PROTECTION));
    analogSignal[SIGNAL_TUMBLER_MAIN_SWITCH] = TO_FLOAT(tumblers_panel->getTumblerState(TUMBLER_MAIN_SWITCH));
    analogSignal[SIGNAL_TUMBLER_AUX_MACHINES] = TO_FLOAT(tumblers_panel->getTumblerState(TUMBLER_AUX_MACHINES));
    analogSignal[SIGNAL_TUMBLER_COMPRESSOR] = TO_FLOAT(tumblers_panel->getTumblerState(TUMBLER_COMPRESSOR));
    analogSignal[SIGNAL_TUMBLER_MOTOR_FAN1] = TO_FLOAT(tumblers_panel->getTumblerState(TUMBLER_MOTOR_FAN1));
    analogSignal[SIGNAL_TUMBLER_MOTOR_FAN2] = TO_FLOAT(tumblers_panel->getTumblerState(TUMBLER_MOTOR_FAN2));
    analogSignal[SIGNAL_TUMBLER_MOTOR_FAN3] = TO_FLOAT(tumblers_panel->getTumblerState(TUMBLER_MOTOR_FAN3));
    analogSignal[SIGNAL_TUMBLER_EPT] = TO_FLOAT(tumblers_panel->getTumblerState(TUMBLER_EPT));

    analogSignal[SIGNAL_PANT1] = TO_FLOAT(pant[PANT1]->getHeight());
    analogSignal[SIGNAL_PANT2] = TO_FLOAT(pant[PANT2]->getHeight());

    analogSignal[SIGNAL_REVERS] = km->getReversHandlePos();
    analogSignal[SIGNAL_KONTROLLER] = km->getHandlePosition();

    analogSignal[STRELKA_U_KS] = TO_FLOAT(main_switch->getU_out() / 30000.0);

    analogSignal[LAMP_GV] = TO_FLOAT(signals_module->getLampState(SM_GV));
    analogSignal[LAMP_MK1] = TO_FLOAT(signals_module->getLampState(SM_MK1));
    analogSignal[LAMP_MK2] = TO_FLOAT(signals_module->getLampState(SM_MK2));

    analogSignal[LAMP_MV1] = TO_FLOAT(signals_module->getLampState(SM_V1));
    analogSignal[LAMP_MV2] = TO_FLOAT(signals_module->getLampState(SM_V2));
    analogSignal[LAMP_MV3] = TO_FLOAT(signals_module->getLampState(SM_V3));

    analogSignal[LAMP_NCH] = TO_FLOAT(msud->getOutputData().is_MV_low_freq);

    analogSignal[STRELKA_GR] = TO_FLOAT(main_res->getPressure() / 1.6);
    analogSignal[STRELKA_TM] = TO_FLOAT(pTM / 1.0);
    analogSignal[STRELKA_UR] = TO_FLOAT(brake_crane->getEqReservoirPressure() / 1.0);
    analogSignal[STRELKA_TC] = TO_FLOAT(brake_mech[FWD_TROLLEY]->getBrakeCylinderPressure() / 1.6);

    analogSignal[RUK_395] = TO_FLOAT(brake_crane->getHandlePosition());
    analogSignal[KVT215_AXIS] = TO_FLOAT(loco_crane->getHandlePosition());
    analogSignal[KVT215_RUK] = TO_FLOAT(loco_crane->getHandleShift());

    analogSignal[SIGNAL_WHEEL1] = TO_FLOAT(dir * wheel_rotation_angle[0] / 2.0 / Physics::PI);
    analogSignal[SIGNAL_WHEEL2] = TO_FLOAT(dir * wheel_rotation_angle[1] / 2.0 / Physics::PI);
    analogSignal[SIGNAL_WHEEL3] = TO_FLOAT(dir * wheel_rotation_angle[2] / 2.0 / Physics::PI);
    analogSignal[SIGNAL_WHEEL4] = TO_FLOAT(dir * wheel_rotation_angle[3] / 2.0 / Physics::PI);
    analogSignal[SIGNAL_WHEEL5] = TO_FLOAT(dir * wheel_rotation_angle[4] / 2.0 / Physics::PI);
    analogSignal[SIGNAL_WHEEL6] = TO_FLOAT(dir * wheel_rotation_angle[5] / 2.0 / Physics::PI);

    analogSignal[SIGNAL_KLUB_U_POWER_SUPPLAY] = TO_FLOAT(Ucc >= 49);
    analogSignal[SIGNAL_KLUB_U_EPK] = TO_FLOAT(epk->getStateKey());

    analogSignal[SIGNAL_KLUB_U_PRESSURE_TM] = pTM;
    analogSignal[SIGNAL_KLUB_U_PRESSURE_UR] = brake_crane->getEqReservoirPressure();
    analogSignal[SIGNAL_KLUB_U_SPEED] = TO_FLOAT(klub_BEL->getVelocityKmh());
    analogSignal[SIGNAL_KLUB_U_SPEED_LIMIT] = TO_FLOAT(klub_BEL->getCurrentSpeedLimit());
    analogSignal[SIGNAL_KLUB_U_SPEED_LIMIT_2] = TO_FLOAT(klub_BEL->getNextSpeedLimit());
    analogSignal[SIGNAL_KLUB_U_COORDINATE] = TO_FLOAT(klub_BEL->getRailCoord());
    analogSignal[SIGNAL_KLUB_U_ALSN] = alsn_info.code_alsn;
    analogSignal[SIGNAL_KLUB_U_ALSN_FB] = 1;
    analogSignal[SIGNAL_KLUB_U_P] = 1.0f;
    analogSignal[SIGNAL_KLUB_U_CASSETE] = 1.0f;
    analogSignal[SIGNAL_KLUB_U_ACCELERATION] = TO_FLOAT(klub_BEL->getAcceleration());

    analogSignal[SIGNAL_KLUB_U_STATION_NUM] = klub_BEL->getStationIndex();
    analogSignal[SIGNAL_KLUB_U_SPEED_LIMIT] = klub_BEL->getCurrentSpeedLimit();
    analogSignal[SIGNAL_KLUB_U_SPEED_LIMIT_2] = klub_BEL->getNextSpeedLimit();
    analogSignal[SIGNAL_KLUB_U_BDITELNOST] = TO_FLOAT(klub_BEL->isCheckVigilanse());

    analogSignal[LAMP_EPT_O] = ept_pass_control->stateReleaseLamp();
    analogSignal[LAMP_EPT_P] = ept_pass_control->stateHoldLamp();
    analogSignal[LAMP_EPT_T] = ept_pass_control->stateBrakeLamp();

    analogSignal[STRELKA_EPT_AMP] = ept_current[0] / 10.0;
    analogSignal[STRELKA_EPT_VOLT] = ept_converter->getU_out() / 150.0;

    analogSignal[RB1] = TO_FLOAT(tumblers[BUTTON_RB].getState());
    analogSignal[RBS] = TO_FLOAT(tumblers[BUTTON_RBS].getState());

    bool is_visible = msud->getOutputData().state == MSUD_READY;
    analogSignal[SIGNAL_MSUD_POWER_SUPPLAY] = TO_FLOAT(is_visible);
    analogSignal[SIGNAL_MSUD_SPEED2] = TO_FLOAT(km->getRefSpeedLevel() * 160.0);
    analogSignal[SIGNAL_MSUD_SPEED1] = TO_FLOAT(velocity * Physics::kmh);
    analogSignal[SIGNAL_MSUD_CURRENT_ANHCOR2] = TO_FLOAT( (km->getTracLevel() +
                                                           qAbs(km->getBrakeLevel())) * 1600.0);
    analogSignal[SIGNAL_MSUD_CURRENT_ANHCOR1] = qAbs(msud_input.Ia[TRAC_MOTOR1]);
    analogSignal[SIGNAL_MSUD_MK] = TO_FLOAT(!main_compressor->isStarted() && press_reg->getState());
    analogSignal[SIGNAL_MSUD_DM] = TO_FLOAT(!main_compressor->isStarted());

    double trac_level = 0;

    if (msud_input.is_traction)
        trac_level = qAbs(msud_input.Ia[TRAC_MOTOR1] * 100.0 / 1300.0);

    if (msud_input.is_brake)
        trac_level = qAbs(msud_input.Ia[TRAC_MOTOR1] * 100.0 / 950.0);

    trac_level = cut(trac_level, 0.0, 100.0);

    analogSignal[SIGNAL_MSUD_TRACTION] = TO_FLOAT(trac_level);

    analogSignal[SIGNAL_MSUD_CURCUIT_VOZB] = TO_FLOAT(trac_motor[TRAC_MOTOR1]->getFieldCurrent());

    analogSignal[SIGNAL_MSUD_CURRENT_EPT] = ept_current[0];
    analogSignal[SIGNAL_MSUD_VOLTAGE_EPT] = ept_converter->getU_out();

    analogSignal[SIGNAL_MSUD_NC] = TO_FLOAT(msud->getOutputData().is_MV_low_freq);
    analogSignal[SIGNAL_MSUD_MPK] = TO_FLOAT(static_cast<int>(msud_input.tumbler_MPK) + 1);
    analogSignal[SIGNAL_MSUD_MODE] = TO_FLOAT(static_cast<int>(msud_input.is_automatic_mode) + 1);

    analogSignal[SIGNAL_TUMBLER_MPK] = TO_FLOAT(tumblers[TUMBLER_MPK].getState());
    analogSignal[SIGNAL_TUMBLER_AUTO_MODE] = TO_FLOAT(tumblers[TUMBLER_AUTO_MODE].getState());
    analogSignal[SIGNAL_TUMBLER_SIGNAL_PANEL] = TO_FLOAT(tumblers[TUMBLER_BS_002].getState());
    analogSignal[SIGNAL_TUMBLER_PCHF] = TO_FLOAT(tumblers[TUMBLER_PCHF].getState());

    bool is_MSUD_OB = main_switch->getU_out() >= 10000 && battery->getCargeCurrent() <= 0.0;
    analogSignal[SIGNAL_MSUD_OB] = TO_FLOAT(is_MSUD_OB);

    analogSignal[SIGNAL_MSUD_TC] = TO_FLOAT(msud->getOutputData().TC_status);
    for (size_t i = 0; i < brake_mech.size(); ++i)
    {
        analogSignal[LAMP_TC3 + i] = signals_module->getLampState(SM_LAMP_TC3 + i);
    }

    analogSignal[REF_SPEED] = TO_FLOAT(km->getRefSpeedLevel());

    analogSignal[LAMP_TD1] = TO_FLOAT(signals_module->getLampState(SM_TD1));
    analogSignal[LAMP_TD2] = TO_FLOAT(signals_module->getLampState(SM_TD2));
    analogSignal[LAMP_TD3] = TO_FLOAT(signals_module->getLampState(SM_TD3));
    analogSignal[LAMP_TD4] = TO_FLOAT(signals_module->getLampState(SM_TD4));
    analogSignal[LAMP_TD5] = TO_FLOAT(signals_module->getLampState(SM_TD5));
    analogSignal[LAMP_TD6] = TO_FLOAT(signals_module->getLampState(SM_TD6));

    analogSignal[SIGNAL_MSUD_VIP_ZONE] = TO_FLOAT(msud->getOutputData().vip_voltage_level);

    if (reversor->getState() == 1)
        analogSignal[SIGNAL_MSUD_REVERSOR] = 1.0f;

    if (reversor->getState() == -1)
        analogSignal[SIGNAL_MSUD_REVERSOR] = 2.0f;

    if (qt1->getContactState(9))
        analogSignal[SIGNAL_MSUD_TRACTION_TYPE] = 1.0f;
    else
        analogSignal[SIGNAL_MSUD_TRACTION_TYPE] = 2.0f;


    if (msud_input.is_traction || msud_input.is_brake)
        analogSignal[SIGNAL_MSUD_TRACTION_STATE] = 1.0f;
    else
        analogSignal[SIGNAL_MSUD_TRACTION_STATE] = 2.0f;

    bool is_DM_low = signals_module->getLampState(SM_DM1) ||
                     signals_module->getLampState(SM_DM2);

    if (is_DM_low)
        analogSignal[SIGNAL_MSUD_DM] = 1.0f;
    else
        analogSignal[SIGNAL_MSUD_DM] = 0.0f;

    analogSignal[LAMP_DM1] = signals_module->getLampState(SM_DM1);
    analogSignal[LAMP_DM2] = signals_module->getLampState(SM_DM2);

    analogSignal[STRELKA_I_TED] = TO_FLOAT(trac_motor[TRAC_MOTOR1]->getAncorCurrent() / 1500.0);

    analogSignal[BUTTON_SVISTOK] = TO_FLOAT(horn->isSvistok());
    analogSignal[BUTTON_TIFON] = TO_FLOAT(horn->isTifon());

    analogSignal[SIGNAL_MSUD_OSLAB_POLE1] = TO_FLOAT(msud->getOutputData().op[STEP1]);
    analogSignal[SIGNAL_MSUD_OSLAB_POLE2] = TO_FLOAT(msud->getOutputData().op[STEP2]);
    analogSignal[SIGNAL_MSUD_OSLAB_POLE3] = TO_FLOAT(msud->getOutputData().op[STEP3]);
}
