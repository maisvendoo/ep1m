#include    "ep1m.h"
#include    <QDir>

void EP1m::initBlockKON(const QString &modules_dir, const QString &custom_cfg_dir)
{
    (void) custom_cfg_dir;

    block_KON = loadPluginBlockKON(modules_dir + QDir::separator() + "block-KON");

    if(block_KON == nullptr)
        return;

    block_KON->read_config("block-KON");
}
