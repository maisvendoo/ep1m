#ifndef     EP1M_AUTOPILOT
#define     EP1M_AUTOPILOT

#include    <autopilot.h>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class EP1mAutopilot : public Autopilot
{
public:

    EP1mAutopilot();

    ~EP1mAutopilot();

    auto_control_t *getControl() override;

private:
};

#endif
