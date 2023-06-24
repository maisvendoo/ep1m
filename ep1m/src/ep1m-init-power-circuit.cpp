#include    "ep1m.h"

#include    <QDir>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::initPowerCircuit()
{
    for (size_t i = 0; i < pant.size(); ++i)
    {
        pant[i] = new Pantograph();
        pant[i]->read_custom_config(config_dir +
                                    QDir::separator() +
                                    "pantograph");
    }

    main_switch = new ProtectiveDevice();


    trac_trans = new TractionTransformer();

    safety_valve = new ElectroValve();
    safety_valve->read_custom_config(config_dir + QDir::separator() + "vz-6");
    safety_valve->setSoundName("Lock_VVK");

    for (size_t i = 0; i < trac_motor.size(); ++i)
    {
        trac_motor[i] = new TractionMotor();
        trac_motor[i]->read_custom_config(config_dir + QDir::separator() + "nb-520v");
        trac_motor[i]->load_magnetic_char(config_dir + QDir::separator() + "nb-520v.txt");
        trac_motor[i]->load_eff_coeff(config_dir + QDir::separator() + "nb-520v-eff-coeff.txt");

        fast_switch[i] = new FastSwitch();
        fast_switch[i]->read_custom_config(config_dir + QDir::separator() + "bv-8");
        fast_switch[i]->setInitContactState(0, false);
        fast_switch[i]->setInitContactState(1, true);
        fast_switch[i]->setInitContactState(2, true);
        fast_switch[i]->setInitContactState(3, false);
    }

    vip[VIP1] = new RectInvertConverter();
    vip[VIP1]->read_custom_config(config_dir + QDir::separator() + "vip-5600");

    vip[VIP2] = new RectInvertConverter();
    vip[VIP2]->read_custom_config(config_dir + QDir::separator() + "vip-5600");

    reversor = new Reversor();
    reversor->read_custom_config(config_dir + QDir::separator() + "reversor");

    // Тормозной переключатель QT1
    qt1 = new BrakeSwitcher(10);
    qt1->read_custom_config(config_dir + QDir::separator() + "pkd-15");
    qt1->setInitContactState(0, true);
    qt1->setInitContactState(1, true);
    qt1->setInitContactState(2, true);
    qt1->setInitContactState(3, true);
    qt1->setInitContactState(4, false);
    qt1->setInitContactState(5, false);
    qt1->setInitContactState(6, false);
    qt1->setInitContactState(7, true);
    qt1->setInitContactState(8, true);
    qt1->setInitContactState(9, true);

    // Шунты ослабления возбуждения
    shunts = new ShuntsModule();
    shunts->read_custom_config(config_dir + QDir::separator() + "shunts-module");
}
