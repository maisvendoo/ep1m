#include    "ep1m.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::initAZV()
{
    for (size_t i = 0; i < azv.size(); ++i)
    {
        azv[i].set();
    }
}
