#include    "ep1m.h"

#include    <QDir>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void EP1m::initAirSupplySystem()
{
    // Главный резервуар объемом 1020 литров
    main_res = new Reservoir(1.02);
    main_res->setFlowCoeff(main_res_leak);

    QString mk_cfg_path = config_dir + QDir::separator() + "motor-compressor.xml";
    main_compressor = new MotorCompressor(mk_cfg_path);

    press_reg = new PressureRegulator();
}
