#ifndef CLUB_U_DISPLAY_H
#define CLUB_U_DISPLAY_H

#include    <QTimer>

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


private:

    QTimer          *updateTimer;

    ALSN            *alsn_;
    TopBlock        *topBlock_;
    MiddleBlock     *middleBlock_;
    RightBlock      *rightBlock_;
    BottomBlock     *bottomBlock_;

    std::vector<QString>    stations;
    int stationsCount_;


    void loadStations();
    void initMainWindow();
    void initBlocks_();



private slots:

    void slotUpdateTimer();

};

#endif // CLUB_U_DISPLAY_H
