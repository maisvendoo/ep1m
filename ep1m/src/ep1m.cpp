#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
EP1m::EP1m(QObject *parent) : Vehicle (parent)
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
EP1m::~EP1m()
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::initialization()
{
    // Инициализация пульта управления в кабине
    initPanel();

    // Инициализация микропроцессорной системы управления и диагностики (МСУД)
    initMSUD();

    // Инициализация озвучки
    initSounds();
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::step(double t, double dt)
{
    // Работа приборов управления в кабине
    stepPanel(t, dt);

    // Работа микропроцессорной системы управления и диагностики
    stepMSUD(t, dt);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
GET_VEHICLE(EP1m)
