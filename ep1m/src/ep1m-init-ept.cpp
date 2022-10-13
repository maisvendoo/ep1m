#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::initEPT()
{
    // Инициализация линии управления
    ept_control.resize(1);
    ept_current.resize(1);

    ept_control[0] = ept_current[0] = 0.0;

    // Инициализация источника питания
    ept_converter = new EPTConverter();
    ept_converter->read_config("ept-converter");

    // Инциализация блока управления
    ept_pass_control = new EPTPassControl();
}
