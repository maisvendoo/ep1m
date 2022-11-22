#include    "ep1m.h"

#include    <QDir>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::initControlCircuit()
{
    kv44 = new Relay(4);
    kv44->read_custom_config(config_dir + QDir::separator() + "mk-69");
    kv44->setInitContactState(0, false);
    kv44->setInitContactState(1, false);
    kv44->setInitContactState(2, false);
    kv44->setInitContactState(3, false);

    kv39 = new Relay(3);
    kv39->read_custom_config(config_dir + QDir::separator() + "mk-69");
    kv39->setInitContactState(0, false);
    kv39->setInitContactState(1, false);
    kv39->setInitContactState(2, false);

    kv21 = new Relay(3);
    kv21->read_custom_config(config_dir + QDir::separator() + "mk-69");
    kv21->setInitContactState(0, false);
    kv21->setInitContactState(1, false);
    kv21->setInitContactState(2, false);

    kv22 = new Relay(3);
    kv22->read_custom_config(config_dir + QDir::separator() + "mk-69");
    kv22->setInitContactState(0, false);
    kv22->setInitContactState(1, false);
    kv22->setInitContactState(2, false);

    kv23 = new Relay(3);
    kv23->read_custom_config(config_dir + QDir::separator() + "mk-69");
    kv23->setInitContactState(0, false);
    kv23->setInitContactState(1, false);
    kv23->setInitContactState(2, false);

    kv41 = new Relay(4);
    kv41->read_custom_config(config_dir + QDir::separator() + "mk-69");
    kv41->setInitContactState(0, false);
    kv41->setInitContactState(1, true);
    kv41->setInitContactState(2, false);
    kv41->setInitContactState(3, false);

    sp4 = new HysteresisRelay(0.27, 0.45);
}
