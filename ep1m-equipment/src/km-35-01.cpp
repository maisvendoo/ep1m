#include    "km-35-01.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
TracController::TracController(QObject *parent) : Device(parent)
  , mode_pos(0)
  , mode_pos_old(0)
  , fwd_key_state(false)
  , old_fwd_key_state(false)
  , bwd_key_state(false)
  , old_bwd_key_state(false)
  , revers_pos(0)
  , reversSoundName("Revers")
  , mainHandleSoundName("KM_main")
  , old_traction_key(false)
  , old_brake_key(false)
  , trac_level(0)
  , brake_level(0)
  , dir(0)
  , ref_speed_level(0)
  , ref_speed_step(0.5)
  , ref_speed_dir(0)
{
    tracTimer.setTimeout(0.1);
    connect(&tracTimer, &Timer::process,
            this, &TracController::slotTracLevelProcess);

    brakeTimer.setTimeout(0.1);
    connect(&brakeTimer, &Timer::process,
            this, &TracController::slotBrakeLevelProcess);

    speedTimer.setTimeout(0.1);
    //connect(&speedTimer, &Timer::process,
      //      this, &TracController::slotSpeedLevelProcess);
    //speedTimer.start();
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
TracController::~TracController()
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
float TracController::getHandlePosition() const
{
    float handle_pos = mode_pos * 0.2f + trac_level / 125.0f - brake_level / 125.f;

    return handle_pos;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TracController::preStep(state_vector_t &Y, double t)
{
    Q_UNUSED(Y)
    Q_UNUSED(t)

    if (mode_pos != mode_pos_old)
    {
        emit soundPlay(mainHandleSoundName);
        mode_pos_old = mode_pos;
    }
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TracController::ode_system(const state_vector_t &Y,
                                state_vector_t &dYdt,
                                double t)
{
    Q_UNUSED(Y)
    Q_UNUSED(dYdt)
    Q_UNUSED(t)
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TracController::load_config(CfgReader &cfg)
{
    QString secName = "Device";

    double timeout = 0.0;
    cfg.getDouble(secName, "KM_main_Timeout", timeout);

    tracTimer.setTimeout(timeout);
    brakeTimer.setTimeout(timeout);

    cfg.getDouble(secName, "Ref_Speed_Timeout", timeout);
    speedTimer.setTimeout(timeout);
    connect(&speedTimer, &Timer::process,
            this, &TracController::slotSpeedLevelProcess);
    speedTimer.start();
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TracController::stepKeysControl(double t, double dt)
{
    processDiscretePositions(getKeyState(KEY_A), old_traction_key, 1);
    processDiscretePositions(getKeyState(KEY_D), old_brake_key, -1);

    // Тут реализуем процесс перемещения главной рукоятки!!!

    if (mode_pos == -1)
    {
        traction.reset();
        dir = 0;

        if (!brakeTimer.isStarted())
            brakeTimer.start();

        if (getKeyState(KEY_A))
        {
            if (brake_level == 0)
            {
                mode_pos = 0;
                brakeTimer.stop();
                brake.reset();
            }
            else
            {
                dir = 1;
            }
        }

        if (getKeyState(KEY_D))
        {
            if (brake.getState())
                dir = -1;

            if (isControl())
            {
                mode_pos = 0;
                brakeTimer.stop();
                brake.reset();
            }
        }
        else
        {
            brake.set();
        }
    }

    brakeTimer.step(t, dt);

    if (mode_pos == 1)
    {
        brake.reset();
        dir = 0;

        if (!tracTimer.isStarted())
            tracTimer.start();

        if (getKeyState(KEY_D))
        {
            if ( (trac_level == 0) || isControl() )
            {
                mode_pos = 0;
                tracTimer.stop();
                traction.reset();
            }
            else
            {
                dir = -1;
            }
        }

        if (getKeyState(KEY_A))
        {
            if (traction.getState())
                dir = 1;
        }
        else
        {
            traction.set();
        }
    }

    tracTimer.step(t, dt);

    old_traction_key = getKeyState(KEY_A);
    old_brake_key = getKeyState(KEY_D);

    if (fwd_key_state && !old_fwd_key_state && isZero())
    {
        revers_pos++;

        if (revers_pos <= 1)
            emit soundPlay(reversSoundName);
    }

    if (bwd_key_state && !old_bwd_key_state && isZero())
    {
        revers_pos--;

        if (revers_pos >= -1)
            emit soundPlay(reversSoundName);
    }

    revers_pos = cut(revers_pos, -1, 1);

    old_fwd_key_state = fwd_key_state;
    old_bwd_key_state = bwd_key_state;

    ref_speed_dir = 0;

    if (getKeyState(KEY_Q))
    {
        ref_speed_dir = 1;
    }

    if (getKeyState(KEY_E))
    {
        ref_speed_dir = -1;

        if (isControl())
        {
            ref_speed_dir = 0;
            ref_speed_level = 0;
        }
    }

    speedTimer.step(t, dt);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TracController::processDiscretePositions(bool key_state,
                                              bool old_key_state,
                                              int dir)
{
    if (revers_pos == 0)
        return;

    if (mode_pos != 0)
        return;

    trac_level = brake_level = 0;
    traction.reset();
    brake.reset();

    if (key_state && !old_key_state)
    {
        mode_pos += dir;
        mode_pos = cut(mode_pos, -1, 1);
    }
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TracController::slotTracLevelProcess()
{
    trac_level += dir * mode_pos;

    trac_level = cut(trac_level, 0, 100);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TracController::slotBrakeLevelProcess()
{
    brake_level += dir * mode_pos;

    brake_level = cut(brake_level, 0, 100);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TracController::slotSpeedLevelProcess()
{
    ref_speed_level += ref_speed_dir * ref_speed_step;

    ref_speed_level = cut(ref_speed_level, 0.0, 100.0);
}
