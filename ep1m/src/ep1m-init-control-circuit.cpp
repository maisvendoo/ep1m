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

    km43 = new Relay(4);
    km43->read_custom_config(config_dir + QDir::separator() + "mk-69");
    km43->setInitContactState(0, false);
    km43->setInitContactState(1, false);
    km43->setInitContactState(2, false);
    km43->setInitContactState(3, false);

    kv11 = new Relay(4);
    kv11->read_custom_config(config_dir + QDir::separator() + "mk-69");
    kv11->setInitContactState(0, false);
    kv11->setInitContactState(1, false);
    kv11->setInitContactState(2, false);
    kv11->setInitContactState(3, false);

    kv12 = new Relay(4);
    kv12->read_custom_config(config_dir + QDir::separator() + "mk-69");
    kv12->setInitContactState(0, true);
    kv12->setInitContactState(1, false);
    kv12->setInitContactState(2, false);
    kv12->setInitContactState(3, false);

    kv13 = new Relay(4);
    kv13->read_custom_config(config_dir + QDir::separator() + "mk-69");
    kv13->setInitContactState(0, false);
    kv13->setInitContactState(1, false);
    kv13->setInitContactState(2, false);
    kv13->setInitContactState(3, false);

    kv14 = new Relay(4);
    kv14->read_custom_config(config_dir + QDir::separator() + "mk-69");
    kv14->setInitContactState(0, false);
    kv14->setInitContactState(1, false);
    kv14->setInitContactState(2, false);
    kv14->setInitContactState(3, false);

    sp4 = new HysteresisRelay(0.27, 0.45);
}
