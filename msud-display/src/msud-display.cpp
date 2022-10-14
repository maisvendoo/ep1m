#include "msud-display.h"

#include    <QVBoxLayout>
#include    <QLabel>



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
MsudDisplay::MsudDisplay(QWidget *parent, Qt::WindowFlags f)
    : AbstractDisplay(parent, f)
{
    this->setWindowFlag(Qt::WindowType::FramelessWindowHint);
    this->resize(800, 408);
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(QColor(0, 0, 0)));

    this->setLayout(new QVBoxLayout);
    this-> setFocusPolicy(Qt::FocusPolicy::NoFocus);
    this->layout()->setContentsMargins(0, 0, 0, 0);


   // this->setStyleSheet("border: 4px solid green");


    connect(&updateTimer_, &QTimer::timeout, this, &MsudDisplay::slotUpdateTimer, Qt::QueuedConnection);
    updateTimer_.setInterval(1000);
    updateTimer_.start();


    updateTimer_.start(100);

}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
MsudDisplay::~MsudDisplay()
{

}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void MsudDisplay::init()
{

    initDisplay_();

    AbstractDisplay::init();
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void MsudDisplay::initDisplay_()
{
    // Фоновый виджет
    fon_ = new QLabel(this);
    fon_->setFrameShape(QLabel::NoFrame);
    QPixmap pic;
    if (!pic.load(":/rcc/msud-fon")) { return; }
    fon_->setFixedSize(pic.size());
    //fon->setGeometry(0,0, pic.size().width(), pic.size().height());
    fon_->setPixmap(pic);
    fon_->move(0, 0);
    //fon_->setStyleSheet("border: 1px solid red");
    this->layout()->addWidget(fon_);


    int fooX = 34;
    int fooY = 51;
    int fooW = 233;
    int fooH = 28;
    int fooDeltaX = 252;

    createLab_(labMode_, QSize(fooW, fooH), "yellow");
    labMode_->move(fooX, fooY);


    createLab_(labControl_, QSize(fooW*2 + 20, fooH), "red");
    labControl_->move(fooX + fooDeltaX, fooY);

    fooY  = 124;

    createLab_(labPC1_, QSize(fooW, fooH), "yellow");
    labPC1_->move(fooX, fooY);

    fooX += fooDeltaX;

    createLab_(labPC2_, QSize(fooW, fooH), "yellow");
    labPC2_->move(fooX, fooY);

    fooX += fooDeltaX;

    createLab_(labPC3_, QSize(fooW, fooH), "red");
    labPC3_->move(fooX, fooY);


    fooY = 188;

    // Тяга
    sbTyaga_ = new StatusBar(QSize(252, 37), fon_);
    sbTyaga_->move(38, fooY);

    // Ток возбуждения
    sbCurrent_ = new StatusBar(QSize(252, 37), fon_);
    sbCurrent_->move(417, fooY);

    createLab_(labTyaga_, QSize(64, fooH), "black", Qt::AlignRight);
    labTyaga_->move(303, fooY);

    createLab_(labCurrent_, QSize(80, fooH), "black", Qt::AlignRight);
    labCurrent_->move(683, fooY);



    fooY = 394;

    createLab_(labV1_, QSize(67, fooH), "yellow", Qt::AlignRight);
    labV1_->move(110, fooY);

    createLab_(labV2_, QSize(66, fooH), "yellow", Qt::AlignRight);
    labV2_->move(255, fooY);

    createLab_(labI1_, QSize(85, fooH), "yellow", Qt::AlignRight);
    labI1_->move(475, fooY);

    createLab_(labI2_, QSize(85, fooH), "yellow", Qt::AlignRight);
    labI2_->move(625, fooY);




    fooY = 449;

    // Ток ЭПТ
    sbCurrentEPT_ = new StatusBar(QSize(253, 37), fon_);
    sbCurrentEPT_->move(432, fooY);

    createLab_(labCurrentEPT_, QSize(45, fooH), "yellow", Qt::AlignRight);
    labCurrentEPT_->move(698, fooY);

    fooY = 513;

    // Напряжение ЭПТ
    sbVoltageEPT_ = new StatusBar(QSize(253, 37), fon_);
    sbVoltageEPT_->move(432, fooY);

    createLab_(labVoltageEPT_, QSize(62, fooH), "yellow", Qt::AlignRight);
    labVoltageEPT_->move(698, fooY);


    //
    manArrV_ = new ManometerArrow(QSize(310, 113), 160, fon_);
    manArrV_->move(55, 280);

    manArrI_ = new ManometerArrow(QSize(310, 113), 1600, fon_);
    manArrI_->move(434, 280);
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void MsudDisplay::createLab_(QLabel* &lab, QSize size, QString color, Qt::Alignment align)
{
    lab = new QLabel("0", fon_);
    lab->resize(size);
    lab->setFont(QFont("Arial", 18, 87));
    lab->setStyleSheet("border: 1px solid red;"
                        "color: " + color + ";");
    lab->setAlignment(align);
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void MsudDisplay::slotUpdateTimer()
{

    labMode_->setText("АВТОРЕГ");
    labControl_->setText("zzzzz");
    labPC1_->setText("вперед");
    labPC2_->setText("тяга");
    labPC3_->setText("собрана");
    labTyaga_->setText("5");
    labCurrent_->setText("0");
    labCurrentEPT_->setText("0");
    labVoltageEPT_->setText("3");


    sbTyaga_->setVal(50);
    sbCurrent_->setVal(40);
    sbCurrentEPT_->setVal(20);
    sbVoltageEPT_->setVal(10);



    if (val1_ > 1600)
        val1_ = 0;
    if (val2_ > 1600)
        val2_ = 0;
    val2_ += 10;

    QPair<int, int> pair1 = manArrV_->setVals(++val1_, val2_);
    if (pair1.first != -1)
    {
        labV1_->setText(QString::number(pair1.first));
        labV2_->setText(QString::number(pair1.second));
    }

    QPair<int, int> pair2 = manArrI_->setVals(++val1_, val2_);
    if (pair2.first != -1)
    {
        labI1_->setText(QString::number(pair2.first));
        labI2_->setText(QString::number(pair2.first));
    }


}





// Важная штука, чтобы в RRS работало.
GET_DISPLAY(MsudDisplay)