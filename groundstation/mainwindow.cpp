#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mSerial = new QSerialPort(this);
    updateSerialPorts();

    mSerialScanTimer = new QTimer(this);
    mSerialScanTimer->setInterval(1000);
    mSerialScanTimer->start();

    connect(mSerialScanTimer, &QTimer::timeout,
            this, &MainWindow::updateSerialPorts);

    connect(mSerialScanTimer, &QTimer::timeout,
            this, &MainWindow::serialReadyRead);

    connect(mSerial, &QSerialPort::readyRead,
            this, &MainWindow::serialReadyRead);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateSerialPorts()
{
    mSerialPorts = QSerialPortInfo::availablePorts();

    ui->cbPorts->clear();
    for (QSerialPortInfo port : mSerialPorts) {
        ui->cbPorts->addItem(port.portName(), port.systemLocation());
    }
}

void MainWindow::on_btn_openSerialPort_clicked()
{
    ui->btn_openSerialPort->setEnabled(false);
    QString serialLoc = ui->cbPorts->currentData().toString();

    if (mSerial->isOpen()) {
        QMessageBox msgBox;
        msgBox.setText("Already connected");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
        mSerial->close();
    }

    mSerial->setPortName(serialLoc);
    mSerial->setBaudRate(QSerialPort::Baud115200);
    mSerial->setDataBits(QSerialPort::Data8);
    mSerial->setParity(QSerialPort::NoParity);
    mSerial->setStopBits(QSerialPort::OneStop);
    mSerial->setFlowControl(QSerialPort::NoFlowControl);

    if(mSerial->open(QIODevice::ReadWrite)) {
        //qDebug() << "SERIAL: OK!";
    } else {
        QMessageBox msgBox;
        msgBox.setText("Could not connect");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
        mSerial->close();
    }
    ui->btn_openSerialPort->setEnabled(true);
}

void MainWindow::serialReadyRead()
{
    QByteArray data = mSerial->readAll();
    QString str = QString(data);
    ui->tb_output->insertPlainText(str);
//    QScrollBar *sb = ui->tb_output->verticalScrollBar();
//    sb->setValue(sb->maximum());
}


void MainWindow::on_btn_closePort_clicked()
{
    ui->btn_closePort->setEnabled(false);
    QString serialLoc = ui->cbPorts->currentData().toString();

    if (mSerial->isOpen()) {
        QMessageBox msgBox;
        msgBox.setText("Sucessfully disconnected");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
        mSerial->close();
    }
    ui->btn_closePort->setEnabled(true);
}

