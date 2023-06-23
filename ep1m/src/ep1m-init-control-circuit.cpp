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

    kv23 = new Relay(4);
    kv23->read_custom_config(config_dir + QDir::separator() + "mk-69");
    kv23->setInitContactState(0, false);
    kv23->setInitContactState(1, false);
    kv23->setInitContactState(2, false);
    kv23->setInitContactState(3, false);

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

    kv15 = new Relay(4);
    kv15->read_custom_config(config_dir + QDir::separator() + "mk-69");
    kv15->setInitContactState(0, false);
    kv15->setInitContactState(1, false);
    kv15->setInitContactState(2, false);
    kv15->setInitContactState(3, false);

    sp4 = new HysteresisRelay(0.27, 0.45);

    kv84 = new Relay(4);
    kv84->read_custom_config(config_dir + QDir::separator() + "mk-69");
    kv84->setInitContactState(0, false);
    kv84->setInitContactState(1, false);
    kv84->setInitContactState(2, false);
    kv84->setInitContactState(3, false);

    kt10 = new TimeRelay(4);
    kt10->read_custom_config(config_dir + QDir::separator() + "mk-69");
    kt10->setInitContactState(0, false);
    kt10->setInitContactState(1, false);
    kt10->setInitContactState(2, false);
    kt10->setInitContactState(3, false);
    kt10->setTimeout(1.5);

    kt1 = new TimeRelay(5);
    kt1->read_custom_config(config_dir + QDir::separator() + "mk-69");

    // Контакты цепи схемы "Тяга"
    kt1->setInitContactState(0, true);
    kt1->setInitContactState(1, false);
    kt1->setInitContactState(2, false);
    kt1->setInitContactState(3, false);
    // Контакты цепи схемы "Рекуперация"
    kt1->setInitContactState(4, true);
    kt1->setTimeout(1.5);

    km41 = new Relay(4);
    km41->read_custom_config(config_dir + QDir::separator() + "mk-69");
    km41->setInitContactState(0, false);
    km41->setInitContactState(1, false);
    km41->setInitContactState(2, false);
    km41->setInitContactState(3, false);

    km42 = new Relay(4);
    km42->read_custom_config(config_dir + QDir::separator() + "mk-69");
    km42->setInitContactState(0, false);
    km42->setInitContactState(1, false);
    km42->setInitContactState(2, false);
    km42->setInitContactState(3, false);
}
