#ifndef CLUB_U_DISPLAY_H
#define CLUB_U_DISPLAY_H

#include    "display.h"

#include    "structures-CLUB-U.h"
#include    "ALSN.h"
#include    "top-block.h"
#include    "block-middle.h"

#include <QTimer>


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

    structs_CLUB_U_t structs_CLUB_U;

    std::vector<QString>    stations;


    void loadStations();
    void initMainWindow();
    void initBlocks_();

    //
    QString getCfgPath(QString cfgName);


private slots:

    void slotUpdateTimer();

};

#endif // CLUB_U_DISPLAY_H
