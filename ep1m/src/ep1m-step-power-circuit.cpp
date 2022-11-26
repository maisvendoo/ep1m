#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepPowerCircuit(double t, double dt)
{
    pant[PANT1]->setState(safety_valve->getState() &&
                          tumblers_panel->getTumblerState(TUMBLER_PANT1) &&
                          kv44->getContactState(1));

    pant[PANT2]->setState(safety_valve->getState() &&
                          tumblers_panel->getTumblerState(TUMBLER_PANT2) &&
                          kv44->getContactState(2));

    for (size_t i = 0; i < pant.size(); ++i)
    {
        pant[i]->setUks(Uks);
        pant[i]->step(t, dt);
    }

    Ukr = max(pant[PANT1]->getUout(), pant[PANT2]->getUout());

    main_switch->setU_in(Ukr);
    main_switch->setState(tumblers_panel->getTumblerState(TUMBLER_MAIN_SWITCH));
    main_switch->setHoldingCoilState(getHoldingCoilState());
    main_switch->step(t, dt);

    trac_trans->setInputVoltage(main_switch->getU_out());
    trac_trans->step(t, dt);

    safety_valve->setVoltage(Ucc * static_cast<double>(tumblers_panel->getTumblerState(TUMBLER_LOCK_VVK)));
    safety_valve->step(t, dt);

    // Задаем напряжения на якорях ТЭД
    trac_motor[TRAC_MOTOR1]->setAncorVoltage(vip[VIP1]->getU_out());
    trac_motor[TRAC_MOTOR2]->setAncorVoltage(vip[VIP1]->getU_out());
    trac_motor[TRAC_MOTOR3]->setAncorVoltage(vip[VIP1]->getU_out());

    trac_motor[TRAC_MOTOR4]->setAncorVoltage(vip[VIP2]->getU_out());
    trac_motor[TRAC_MOTOR5]->setAncorVoltage(vip[VIP2]->getU_out());
    trac_motor[TRAC_MOTOR6]->setAncorVoltage(vip[VIP2]->getU_out());

    for (size_t i = 0; i < trac_motor.size(); ++i)
    {
        // Передаем состояние реверсивного переключателя
        trac_motor[i]->setReversSate(reversor->getState());

        // Режим работы ТЭД от QT1
        trac_motor[i]->setMode(qt1->getContactState(0));

        // Передаем модели двигателя данные об угловой скорости его вала
        trac_motor[i]->setOmega(wheel_omega[i] * ip);

        // Выдаем момент на тяговые оси
        Q_a[i + 1] = trac_motor[i]->getTorque() * ip;

        // Моделируем работу ТЭД
        trac_motor[i]->step(t, dt);

        fast_switch[i]->step(t, dt);
    }

    vip[VIP1]->setU1(trac_trans->getUt1() * static_cast<double>(fast_switch[TRAC_MOTOR1]->getContactState(0)));
    vip[VIP1]->setU2(trac_trans->getUt2() * static_cast<double>(fast_switch[TRAC_MOTOR2]->getContactState(0)));
    vip[VIP1]->setU3(trac_trans->getUt3() * static_cast<double>(fast_switch[TRAC_MOTOR3]->getContactState(0)));

    // Полный ток, потребляемый от ВИП1
    double I_vip1 = trac_motor[TRAC_MOTOR1]->getAncorCurrent() +
            trac_motor[TRAC_MOTOR2]->getAncorCurrent() +
            trac_motor[TRAC_MOTOR3]->getAncorCurrent();

    vip[VIP1]->setI_out(I_vip1);
    vip[VIP1]->step(t, dt);

    vip[VIP2]->setU1(trac_trans->getUt1() * static_cast<double>(fast_switch[TRAC_MOTOR4]->getContactState(0)));
    vip[VIP2]->setU2(trac_trans->getUt2() * static_cast<double>(fast_switch[TRAC_MOTOR5]->getContactState(0)));
    vip[VIP2]->setU3(trac_trans->getUt3() * static_cast<double>(fast_switch[TRAC_MOTOR6]->getContactState(0)));

    // Полный ток, потребляемый от ВИП2
    double I_vip2 = trac_motor[TRAC_MOTOR4]->getAncorCurrent() +
            trac_motor[TRAC_MOTOR5]->getAncorCurrent() +
            trac_motor[TRAC_MOTOR6]->getAncorCurrent();

    vip[VIP2]->setI_out(I_vip2);
    vip[VIP2]->step(t, dt);

    // Работа реверсивного переключателя
    reversor->setForwardValveState(km->getReversHandlePos() == 1);
    reversor->setBackwardValveState(km->getReversHandlePos() == -1);
    reversor->step(t, dt);

    // Работа тормозного переключателя
    qt1->setPressure(0.55 * main_res->getPressure());

    // Сигнал на проводе Н36
    is_H36 = epk->getStateKey() &&
            sp4->getOutput() &&
            kv84->getContactState(0) &&
            kv12->getContactState(0) &&
            kv13->getContactState(0) &&
            kv14->getContactState(0);

    bool is_QT1_trac = is_H36 &&
            ( kt1->getContactState(0) || qt1->getContactState(1) );

    qt1->setTracValveState(is_QT1_trac);

    qt1->step(t, dt);
}
