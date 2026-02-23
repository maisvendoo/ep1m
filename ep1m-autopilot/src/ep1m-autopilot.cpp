#include    <ep1m-autopilot.h>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
EP1mAutopilot::EP1mAutopilot() : Autopilot(nullptr)
{
    connect(km_delay, &Timer::process, this, &EP1mAutopilot::slotDelayKM);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
EP1mAutopilot::~EP1mAutopilot()
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
auto_control_t *EP1mAutopilot::getControl()
{
    return auto_control;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1mAutopilot::step(double t, double dt)
{
    Autopilot::step(t, dt);

    km_delay->step(t, dt);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1mAutopilot::initAutoBrakeControl(const QString &config_name,
                                         const QString &custom_cfg_dir)
{
    brake_control->read_config(config_name, custom_cfg_dir);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1mAutopilot::press_RB()
{
    auto_control->press_RB = true;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1mAutopilot::release_RB()
{
    auto_control->press_RB = false;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1mAutopilot::load_config(CfgReader &cfg)
{
    Autopilot::load_config(cfg);

    QString secName = "Device";

    cfg.getDouble(secName, "Imax", Imax);
    cfg.getDouble(secName, "Kp", Kp);
    cfg.getDouble(secName, "Ks", Ks);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1mAutopilot::preStep(state_vector_t &Y, double t)
{
    // Приводим общую структуру обратной связи к нашему типу
    auto_feedback = dynamic_cast<ep1m_feedback_t *>(feedback);

    if (auto_feedback == nullptr)
    {
        return;
    }

    // Вычисляем ошибку по скорости
    dv = v_ref - feedback->v_cur;

    // Вычисляем абсолютную скорость проскальзывания
    double dv_s = pf(feedback->v_tau - feedback->v_cur);

    // Задание по  току
    double I_ref = Imax * (Kp * dv - Ks * dv_s);

    // И рекуперацию тоже учитываем
    I_ref = cut(I_ref, -Imax, Imax);

    // Выбираем режим работы привода
    mode_pos_old = mode_pos;
    mode_pos = tree_pos_relay(I_ref, -5.0, 5.0);

    traction_control(mode_pos, I_ref / I_ref_max);

    // Задаем скорость для регулятора
    auto_control->v_level = v_ref / v_constr;
    //auto_control->mode_pos = -1;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
int8_t EP1mAutopilot::tree_pos_relay(double x, double x_min, double x_max)
{
    if (x > x_max)
    {
        return 1;
    }

    if (x < x_min)
    {
        return -1;
    }

    return 0;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1mAutopilot::traction_control(int8_t mode_pos, double level)
{
    if (km_delay->isStarted())
    {
        return;
    }

    // Перекладываем ручку на другой режим - только через ноль
    if (mode_pos * mode_pos_old < 0 && !auto_feedback->km_is_zero)
    {
        auto_control->mode_pos = 0;

        if (!km_delay->isStarted())
        {
            km_delay->start();
        }

        return;
    }

    // Если не не собрана схема, ставим рукоятку в нужный режим подготовки
    if (!auto_feedback->is_LC_ON && auto_feedback->km_is_zero)
    {
        auto_control->mode_pos = mode_pos;

        if (!km_delay->isStarted())
        {
            km_delay->start();
        }

        return;
    }

    // Задаем уровень тяги/ЭДТ
    auto_control->level = level;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1mAutopilot::slotDelayKM()
{
    km_delay->stop();
}

GET_AUTOPILOT(EP1mAutopilot)
