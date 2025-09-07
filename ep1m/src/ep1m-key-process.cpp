#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::keyProcess(const simulator_time_t& t, const double& dt)
{
    // Сцепные устройства
    oper_rod_fwd->setControl(&pressed_keys);
    oper_rod_bwd->setControl(&pressed_keys);

    // Концевые краны и рукава тормозной магистрали
    anglecock_bp_fwd->setControl(&pressed_keys);
    anglecock_bp_bwd->setControl(&pressed_keys);
    hose_bp_fwd->setControl(&pressed_keys);
    hose_bp_bwd->setControl(&pressed_keys);

    // Концевые краны и рукава питательной магистрали
    anglecock_fl_fwd->setControl(&pressed_keys);
    anglecock_fl_bwd->setControl(&pressed_keys);
    hose_fl_fwd->setControl(&pressed_keys);
    hose_fl_bwd->setControl(&pressed_keys);

    // Песочница
    sand_system->setControl(&pressed_keys);
    // Тифон и свисток
    horn->setControl(&pressed_keys);

    // Управление ослаблением поля через МСУД
    msud->setControl(&pressed_keys);

    tumblers_panel->setControl(&pressed_keys);
    km->setControl(&pressed_keys);

    // Управляем блокировкой тормозов
        brake_lock->setControl(&pressed_keys);

        // Управляем краном, учитывая возможное наличие внешнего пульта
        // TODO // перенести freejoy во вьювер, его команды передавать по сети,
        // TODO // и также указывая индекс кабины
        if (control_signals.analogSignal[CS_BRAKE_CRANE].is_active)
        {
            int brake_crane_pos = static_cast<int>(control_signals.analogSignal[CS_BRAKE_CRANE].cur_value);
            brake_crane->setHandlePosition(brake_crane_pos);
        }
        else
        {
            brake_crane->setControl(&pressed_keys);
        }

        // Управляем краном, учитывая возможное наличие внешнего пульта
        // TODO // перенести freejoy во вьювер, его команды передавать по сети,
        // TODO // и также указывая индекс кабины
        if (control_signals.analogSignal[CS_LOCO_CRANE].is_active)
        {
            double pos = 0.0;

            if (static_cast<bool>(control_signals.analogSignal[CS_RELEASE_VALVE].cur_value))
            {
                loco_crane->release(true);
                pos = -1.0;
            }
            else
            {
                loco_crane->release(false);
                pos = control_signals.analogSignal[CS_LOCO_CRANE].cur_value;
            }

            loco_crane->setHandlePosition(pos);
        }
        else
        {
            loco_crane->setControl(&pressed_keys);
        }

    // Включение/выключение шкафа питания ШП-21
    if (getKeyState(KEY_H))
    {
        if (isShift())
            tumblers[TUMBLER_POWER_SUPPLY_ON].set();
        else
            tumblers[TUMBLER_POWER_SUPPLY_ON].reset();
    }

    // Перевод реверсивной рукоятки
    if (getKeyState(KEY_W))
    {
        tumblers[SWITCH_REVERS_FWD].set();
    }
    else
    {
        tumblers[SWITCH_REVERS_FWD].reset();
    }

    if (getKeyState(KEY_S))
    {
        tumblers[SWITCH_REVERS_BWD].set();
    }
    else
    {
        tumblers[SWITCH_REVERS_BWD].reset();
    }

    // Включение блока сигнализации
    if (getKeyState(KEY_8) && !isAlt())
    {
        if (isShift())
            tumblers[TUMBLER_BS_002].set();
        else
            tumblers[TUMBLER_BS_002].reset();
    }

    // РБ
    if (getKeyState(KEY_Z))
        tumblers[BUTTON_RB].set();
    else
        tumblers[BUTTON_RB].reset();    

    // Если активна РБС на внешнем пульте
    if (control_signals.analogSignal[CS_RBS].is_active)
    {
        // реагируем на состояние РБС на внешнем пульте
        if (static_cast<bool>(control_signals.analogSignal[CS_RBS].cur_value))
            tumblers[BUTTON_RBS].set();
        else
            tumblers[BUTTON_RBS].reset();
    }
    else // иначе
    {
        // обрабатываем клавиши
        if (getKeyState(KEY_M))
            tumblers[BUTTON_RBS].set();
        else
            tumblers[BUTTON_RBS].reset();
    }

    // ЭПК
    if (getKeyState(KEY_N))
    {
        if (isShift())
            tumblers[EPK_KEY].set();
        else
            tumblers[EPK_KEY].reset();
    }

    // Выбор МПК
    if (getKeyState(KEY_1) && !isAlt())
    {
        if (isShift())
            tumblers[TUMBLER_MPK].set();
        else
            tumblers[TUMBLER_MPK].reset();
    }

    // Вкл/Выкл "АВТОРЕГУЛИРОВАНИЕ"
    if (getKeyState(KEY_F))
    {
        if (isShift())
            tumblers[TUMBLER_AUTO_MODE].reset();
        else
            tumblers[TUMBLER_AUTO_MODE].set();
    }

    // Отключение ПЧФ
    if (getKeyState(KEY_2) && !isAlt())
    {
        if (isShift())
            tumblers[TUMBLER_PCHF].set();
        else
            tumblers[TUMBLER_PCHF].reset();
    }

    // Отпуск тормозов
    if (getKeyState(KEY_R))
        tumblers[BRAKE_RELEASE_BUTTON].set();
    else
        tumblers[BRAKE_RELEASE_BUTTON].reset();

    // Кнопка "Песок"
    if (getKeyState(KEY_Delete))
    {
        button_sandbox.set();
    }
    else
    {
        button_sandbox.reset();
    }
}
