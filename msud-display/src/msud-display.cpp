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
    updateTimer_.start(0);

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
    /*QLabel* */fon = new QLabel(this);
    fon->setFrameShape(QLabel::NoFrame);
    QPixmap pic;
    if (!pic.load(":/rcc/msud-fon")) { return; }
    fon->setFixedSize(pic.size());
    //fon->setGeometry(0,0, pic.size().width(), pic.size().height());
    fon->setPixmap(pic);
    fon->move(0, 0);
    //fon->setStyleSheet("border: 1px solid red");
    this->layout()->addWidget(fon);


    int fooX = 34;
    int fooY = 51;
    int fooW = 233;
    int fooH = 28;
    int fooDeltaX = 252;

    createLab_(labMode_, QSize(fooW, fooH));
    labMode_->move(fooX, fooY);



    createLab_(labControl_, QSize(fooW*2 + 20, fooH));
    labControl_->move(fooX + fooDeltaX, fooY);

    fooY  = 124;

    createLab_(labPC1_, QSize(fooW, fooH));
    labPC1_->move(fooX, fooY);

    fooX += fooDeltaX;

    createLab_(labPC2_, QSize(fooW, fooH));
    labPC2_->move(fooX, fooY);

    fooX += fooDeltaX;

    createLab_(labPC3_, QSize(fooW, fooH));
    labPC3_->move(fooX, fooY);


    fooY = 188;

    // Тяга
    sbTyaga_ = new StatusBar(QSize(252, 28), fon);
    sbTyaga_->move(38, fooY);

    // Ток возбуждения
    sbCurrent_ = new StatusBar(QSize(252, 28), fon);
    sbCurrent_->move(417, fooY);

    createLab_(labTyaga_, QSize(64, fooH), Qt::AlignRight);
    labTyaga_->move(303, fooY);

    createLab_(labCurrent_, QSize(80, fooH), Qt::AlignRight);
    labCurrent_->move(683, fooY);



    fooY = 394;

    createLab_(labV1_, QSize(67, fooH), Qt::AlignRight);
    labV1_->move(110, fooY);

    createLab_(labV2_, QSize(66, fooH), Qt::AlignRight);
    labV2_->move(255, fooY);

    createLab_(labI1_, QSize(85, fooH), Qt::AlignRight);
    labI1_->move(475, fooY);

    createLab_(labI2_, QSize(85, fooH), Qt::AlignRight);
    labI2_->move(625, fooY);




    fooY = 449;

    // Ток ЭПТ
    sbTyaga_ = new StatusBar(QSize(253, 28), fon);
    sbTyaga_->move(432, fooY);

    createLab_(labCurrentEPT_, QSize(45, fooH), Qt::AlignRight);
    labCurrentEPT_->move(698, fooY);

    fooY = 513;

    // Напряжение ЭПТ
    sbCurrent_ = new StatusBar(QSize(253, 28), fon);
    sbCurrent_->move(432, fooY);

    createLab_(labVoltageEPT_, QSize(62, fooH), Qt::AlignRight);
    labVoltageEPT_->move(698, fooY);
}



void MsudDisplay::createLab_(QLabel* &lab, QSize size, Qt::Alignment align)
{
    lab = new QLabel("0", fon);
    lab->resize(size);

    lab->setFont(QFont("Arial", 18, 87));
    lab->setStyleSheet("border: 1px solid red;"
                        "color: white;");

    lab->setAlignment(align);
}



void MsudDisplay::slotUpdateTimer()
{

    labMode_->setText("АВТОРЕГ");
    labControl_->setText("zzzzz");
    labPC1_->setText("вперед");
    labPC2_->setText("тяга");
    labPC3_->setText("собрана");
    labTyaga_->setText("5");
    labCurrent_->setText("0");
    labV1_->setText("0");
    labV2_->setText("140");
    labI1_->setText("0");
    labI2_->setText("410");
    labCurrentEPT_->setText("0");
    labVoltageEPT_->setText("3");


}





// Важная штука, чтобы в RRS работало.
GET_DISPLAY(MsudDisplay)
