#include    "vuv-118.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
FieldRect::FieldRect(QObject *parent) : Device(parent)
  , U_in(0.0)
  , U_out(0.0)
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
FieldRect::~FieldRect()
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void FieldRect::preStep(state_vector_t &Y, double t)
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void FieldRect::ode_system(const state_vector_t &Y,
                           state_vector_t &dYdt,
                           double t)
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void FieldRect::load_config(CfgReader &cfg)
{

}

