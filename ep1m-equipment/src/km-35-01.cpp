#include    "km-35-01.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
TracController::TracController(QObject *parent) : Device(parent)
  , mode_pos(0)
  , fwd_key_state(false)
  , old_fwd_key_state(false)
  , bwd_key_state(false)
  , old_bwd_key_state(false)
  , revers_pos(0)
  , reversSoundName("Revers")
  , old_traction_key(false)
  , old_brake_key(false)
{

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
void TracController::preStep(state_vector_t &Y, double t)
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TracController::ode_system(const state_vector_t &Y,
                                state_vector_t &dYdt,
                                double t)
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TracController::load_config(CfgReader &cfg)
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TracController::stepKeysControl(double t, double dt)
{
    processDiscretePositions(getKeyState(KEY_A), old_traction_key, 1);
    processDiscretePositions(getKeyState(KEY_D), old_brake_key, -1);

    // Тут реализуем процесс перемещения главной рукоятки!!!

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
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TracController::processDiscretePositions(bool key_state,
                                              bool old_key_state,
                                              int dir)
{

}
