#include    "pkd-15.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
BrakeSwitcher::BrakeSwitcher(QObject *parent) : Device(parent)
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
BrakeSwitcher::~BrakeSwitcher()
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BrakeSwitcher::preStep(state_vector_t &Y, double t)
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BrakeSwitcher::ode_system(const state_vector_t &Y,
                               state_vector_t &dYdt,
                               double t)
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BrakeSwitcher::load_config(CfgReader &cfg)
{

}
