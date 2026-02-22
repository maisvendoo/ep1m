#include    <ep1m.h>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::stepAutopilot(double t, double dt)
{
    double v_lim = 0;
    double v_lim_next = 0;
    double limit_dist = 0;
    double signal_dist = 0;
    ALSN alsn_code = ALSN::NO_CODE;

    int cab_idx = 0;

    if (km[CAB1]->isReversHandle())
    {
        v_lim = speedmap_fwd->getCurrentLimit();
        v_lim_next = speedmap_fwd->getNextLimit();
        limit_dist = speedmap_fwd->getNextLimitDistance();
        alsn_code = coil_ALSN_fwd->getCode();
        signal_dist = coil_ALSN_fwd->getNextSignalDistance();

        cab_idx = CAB1;
    }

    if (km[CAB2]->isReversHandle())
    {
        v_lim = speedmap_bwd->getCurrentLimit();
        v_lim_next = speedmap_bwd->getNextLimit();
        limit_dist = speedmap_bwd->getNextLimitDistance();
        alsn_code = coil_ALSN_bwd->getCode();
        signal_dist = coil_ALSN_bwd->getNextSignalDistance();

        cab_idx = CAB2;
    }

    if (autopilot[cab_idx] == nullptr)
    {
        return;
    }

    // Включение и выключение автоведения
    autopilot_switcher[cab_idx].getState() ? autopilot[cab_idx]->on() : autopilot[cab_idx]->off();

    // TODO: обратная связь конкретно от данного локомотива

    // Сигнал контроля бдительности от цепей КЛУБ
    auto_feedback[cab_idx]->is_vigilance_control = klub_BEL->isCheckVigilanse();


    // Принимаем сигналы обратной связи от оборудования
    autopilot[cab_idx]->setFeedback(auto_feedback[cab_idx]);

    // Выполняем шаг управления
    autopilot[cab_idx]->step(t, dt);

    // Получаем управляющие воздействия
    auto_control[cab_idx] = dynamic_cast<ep1m_control_t *>(autopilot[cab_idx]->getControl());

    // Действия по управлению, только если автоведение активно
    if (autopilot[cab_idx]->isActive())
    {
        // TODO: действия по управления конкретно этим локомотивом

        // Проверка бдительности
        auto_control[cab_idx]->press_RB ? tumblers[BUTTON_RBS][cab_idx].set() : tumblers[BUTTON_RBS][cab_idx].reset();
    }
}
