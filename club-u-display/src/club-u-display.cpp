#include "club-u-display.h"

#include    <QVBoxLayout>
#include    <QLabel>
#include    <QDir>

#include    "CfgReader.h"
#include    "club-u-funcs.h"
#include    "ep1m-signals.h"

#include    "ALSN.h"
#include    "block-top.h"
#include    "block-middle.h"
#include    "block-right.h"
#include    "block-bottom.h"



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
ClubUDisplay::ClubUDisplay(QWidget *parent, Qt::WindowFlags f)
    : AbstractDisplay(parent, f)
    , updateTimer(Q_NULLPTR)
    , alsn_(Q_NULLPTR)
    , topBlock_(Q_NULLPTR)
    , middleBlock_(Q_NULLPTR)
    , rightBlock_(Q_NULLPTR)
    , bottomBlock_(Q_NULLPTR)
    , stations()
    , stationsCount_(0)
{
    this->setWindowFlag(Qt::WindowType::FramelessWindowHint);
    this->resize(847, 895);
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(QColor(0, 0, 0)));

    this->setLayout(new QVBoxLayout);
    this-> setFocusPolicy(Qt::FocusPolicy::NoFocus);

}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
ClubUDisplay::~ClubUDisplay()
{

}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void ClubUDisplay::init()
{
    loadStations();
    initMainWindow();
    initBlocks_();

    AbstractDisplay::init();
}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void ClubUDisplay::loadStations()
{
    QString path = QDir::toNativeSeparators(route_dir) +
            QDir::separator() +
            "stations.conf";

    QFile stations_file(path);

    if (stations_file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!stations_file.atEnd())
        {
            QByteArray line = stations_file.readLine();
            QStringList tokens = QString(line).remove('\n').split(';');

            if (tokens.size() < 3)
                continue;

            stations.push_back(tokens[2]);
        }
    }

    stationsCount_ = stations.size();
}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void ClubUDisplay::initMainWindow()
{
    CfgReader cfg;

    int     sizeWindow_X = 847;
    int     sizeWindow_Y = 895;
    bool    hideCursor = false;
    int     timeInterval = 100;

    if (cfg.load(config_dir + getConfigPath("main.xml")))
    {
        QString sectionName = "Main";
        cfg.getInt(sectionName, "sizeWindow_X", sizeWindow_X);
        cfg.getInt(sectionName, "sizeWindow_Y", sizeWindow_Y);
        cfg.getBool(sectionName, "hideCursor", hideCursor);
        cfg.getInt(sectionName, "timeInterval", timeInterval);        
    }

    this->setCursor( hideCursor ? Qt::BlankCursor : Qt::ArrowCursor);

    this->setWindowFlag(Qt::WindowType::FramelessWindowHint);
    this->resize(sizeWindow_X, sizeWindow_Y);
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(QColor(0, 0, 0)));


    //
    updateTimer = new QTimer;
    connect(updateTimer, &QTimer::timeout,
            this, &ClubUDisplay::slotUpdateTimer, Qt::QueuedConnection);
    updateTimer->setInterval(timeInterval);
    updateTimer->start();
}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void ClubUDisplay::initBlocks_()
{
    // пусть к конфигам
    QString cfg_path = config_dir + getConfigPath("");


    // Фоновый виджет
    QLabel* fon = new QLabel(this);
    fon->setFrameShape(QLabel::NoFrame);
    QPixmap pic;
    if (!pic.load(":/rcc/club-u-fon")) { return; }
    fon->setFixedSize(pic.size());
    //fon->setGeometry(0,0, pic.size().width(), pic.size().height());
    fon->setPixmap(pic);
    fon->move(0, 0);
    //fon->setStyleSheet("border: 2px solid red");
    this->layout()->addWidget(fon);


    // Локомотивный светофор
    alsn_ = new ALSN(QSize(98,350), fon);
    alsn_->move(70, 242);

    // Верхний блок
    topBlock_ = new TopBlock(QSize(670, 135), fon);
    topBlock_->move(90, 60);

    // Центральный блок
    middleBlock_ = new MiddleBlock(QSize(330, 330), cfg_path, fon);
    middleBlock_->move(225, 240);

    // Правый блок
    rightBlock_ = new RightBlock(QSize(155, 372), fon);
    rightBlock_->move(622, 215);
    rightBlock_->setNumTrack("1пр");

    // Нижний блок
    bottomBlock_ = new BottomBlock(QSize(585, 30), fon);
    bottomBlock_->move(133, 622);
    bottomBlock_->setTargetName("н1а");

}



//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void ClubUDisplay::slotUpdateTimer()
{

    if (!static_cast<bool>(input_signals[SIGNAL_KLUB_U_POWER_SUPPLAY]))
    {
        alsn_->setVisible(false);
        topBlock_->setVisible(false);
        middleBlock_->setVisible(false);
        rightBlock_->setVisible(false);
        bottomBlock_->setVisible(false);

        return;
    }

    if (!static_cast<bool>(input_signals[SIGNAL_KLUB_U_EPK]))
    {
        alsn_->setVisible(true);
        alsn_->setSignal(ALSN_COLORS::GREEN, 0);

        topBlock_->setVisible(true);
        topBlock_->setIndM(false);
        topBlock_->setCassete(false);
        topBlock_->setBditelnost(false);

        middleBlock_->setVisible(true);
        middleBlock_->setSpeedLimitVisible(false);
        middleBlock_->setCurSpeedLimit(-5);
        middleBlock_->setNextSpeedLimit(-5);
        middleBlock_->blinkingSpeed(true);

        rightBlock_->setVisible(true);

        bottomBlock_->setVisible(true);

        return;
    }


    alsn_->setSignal(static_cast<int>(input_signals[SIGNAL_KLUB_U_ALSN]),
                     static_cast<int>(input_signals[SIGNAL_KLUB_U_ALSN_FB]));

    topBlock_->setBditelnost(static_cast<bool>(input_signals[SIGNAL_KLUB_U_BDITELNOST]));
    topBlock_->setCassete(static_cast<bool>(input_signals[SIGNAL_KLUB_U_CASSETE]));
    topBlock_->setIndM(static_cast<bool>(input_signals[SIGNAL_KLUB_U_M]));
    topBlock_->setIndP(static_cast<bool>(input_signals[SIGNAL_KLUB_U_P]));
    topBlock_->setCoordinate(static_cast<double>(input_signals[SIGNAL_KLUB_U_COORDINATE]));
    int stationNum = static_cast<int>(input_signals[SIGNAL_KLUB_U_STATION_NUM]);
    if ((stationsCount_ > 0) && (stationNum < stationsCount_))
        topBlock_->setStationName(stations[stationNum]);

    middleBlock_->setSpeedLimitVisible(true);
    middleBlock_->setCurSpeed(static_cast<int>(input_signals[SIGNAL_KLUB_U_SPEED]));
    middleBlock_->setCurSpeedLimit(static_cast<int>(input_signals[SIGNAL_KLUB_U_SPEED_LIMIT]));
    middleBlock_->setNextSpeedLimit(static_cast<int>(input_signals[SIGNAL_KLUB_U_SPEED_LIMIT_2]));
    middleBlock_->setReverse(static_cast<int>(input_signals[SIGNAL_KLUB_U_REVERSOR]));

    rightBlock_->setPressureTM(static_cast<double>(input_signals[SIGNAL_KLUB_U_PRESSURE_TM]));
    rightBlock_->setPressureUR(static_cast<double>(input_signals[SIGNAL_KLUB_U_PRESSURE_UR]));
    rightBlock_->setAcceleration(static_cast<double>(input_signals[SIGNAL_KLUB_U_ACCELERATION]));
    rightBlock_->setIndZapretOtpuska(static_cast<bool>(input_signals[SIGNAL_KLUB_U_ZAPRET_OTPUSKA]));

    bottomBlock_->setDistToTarget(static_cast<int>(input_signals[SIGNAL_KLUB_U_TARGET_DIST]));

}




// Важная штука, чтобы в RRS работало.
GET_DISPLAY(ClubUDisplay)
