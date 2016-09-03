#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QFile>
#include <unistd.h>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    timeouter = new QTimer(this);
    timeouter_2 = new QTimer(this);

    connect(timeouter, SIGNAL(timeout()), this, SLOT(piccer()));
    timeouter->start(1000);

    connect(timeouter_2, SIGNAL(timeout()), ui->labelPic, SLOT(clear()));
    connect(timeouter_2, SIGNAL(timeout()), ui->labelPic_2, SLOT(raise()));

    //    ttyArduino = new QFile("/dev/ttyUSB0");
    //    connect(ttyArduino, SIGNAL(readChannelFinished()), this, SLOT(readTTY()));

    /////
}

Widget::~Widget()
{
    delete ui;
}

//void Widget::readTTY(){

//    if(!ttyArduino->isOpen())
//        ttyArduino->open(QIODevice::ReadOnly);

//    qDebug() << ttyArduino->readLine();

//}

void Widget::piccer(){
    QString fileName = "/tmp/kapikulu.jpg";
    QFile picFile(fileName);

    if (!fileName.isEmpty() && picFile.exists()) {
        QImage image(fileName);
        if (image.isNull()) {
            QMessageBox::information(this, tr("Image Viewer"),
                                     tr("Cannot load %1.").arg(fileName));
            return;
        }
        //! [2] //! [3]
        ui->labelPic->raise();
        ui->labelPic->setAlignment(Qt::AlignCenter);
        ui->labelPic->setPixmap(QPixmap::fromImage(image.scaled(240,320)));
        //! [3] //! [4]
        ui->labelPic->adjustSize();
        /////

        picFile.remove();
        timeouter_2->start(120000); //2 minutes
    }
}
