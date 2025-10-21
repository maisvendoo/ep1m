#ifndef CLUB_U_DISPLAY_H
#define CLUB_U_DISPLAY_H

#include    "display.h"

class ALSN;
class TopBlock;
class MiddleBlock;
class RightBlock;
class BottomBlock;



class ClubUDisplay : public AbstractDisplay
{
public:
    ClubUDisplay(QWidget *parent = Q_NULLPTR,
                  Qt::WindowFlags f = Qt::WindowFlags());

    ~ClubUDisplay();

    void init();

    void update(double t, double dt);

private:

    ALSN            *alsn_ = nullptr;
    TopBlock        *topBlock_ = nullptr;
    MiddleBlock     *middleBlock_ = nullptr;
    RightBlock      *rightBlock_ = nullptr;
    BottomBlock     *bottomBlock_ = nullptr;

    double upd_interval = 0.1;
    double upd_time = 0.0;
    int  upd_block = 0;

    void initMainWindow();
    void initBlocks_();
};

#endif // CLUB_U_DISPLAY_H
