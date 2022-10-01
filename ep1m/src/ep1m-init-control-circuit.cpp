#include    "ep1m.h"

#include    <QDir>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::initControlCircuit()
{
    kv44 = new Relay(3);
    kv44->read_custom_config(config_dir + QDir::separator() + "mk-69");
    kv44->setInitContactState(0, false);
    kv44->setInitContactState(1, false);
    kv44->setInitContactState(2, false);

    kv39 = new Relay(3);
    kv39->read_custom_config(config_dir + QDir::separator() + "mk-69");
    kv39->setInitContactState(0, false);
    kv39->setInitContactState(1, false);
    kv39->setInitContactState(2, false);
}
