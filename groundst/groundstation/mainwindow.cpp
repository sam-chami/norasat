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
    mSerialScanTimer->setInterval(5000);
    mSerialScanTimer->start();

    connect(mSerialScanTimer, &QTimer::timeout,
            this, &MainWindow::updateSerialPorts);

//    connect(mSerialScanTimer, &QTimer::timeout,
//            this, &MainWindow::serialReadyRead);

    connect(mSerial, &QSerialPort::readyRead,
            this, &MainWindow::serialReadyRead);

    // DECLARE TEMP CHART


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTemp(double value) {
    QLineSeries *sr_temp = new QLineSeries();
    sr_temp->append(s_passed.elapsed()  , value);

    *sr_temp << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);
    QChart *ch_temp = new QChart();
    ch_temp->legend()->hide();
    ch_temp->addSeries(sr_temp);
    ch_temp->createDefaultAxes();
    ch_temp->setTitle("Temperature");
    ui->chartTemp->setChart(ch_temp);
    ui->chartTemp->setRenderHint(QPainter::Antialiasing);
}
void MainWindow::updatePres(double value) {

}

void MainWindow::updateSerialPorts()
{
    mSerialPorts = QSerialPortInfo::availablePorts();

    ui->cbPorts->clear();
    for (const QSerialPortInfo &port : qAsConst(mSerialPorts)) {
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

    s_passed.start();

    ui->btn_openSerialPort->setEnabled(true);
}

void MainWindow::serialReadyRead()
{
    QByteArray data = mSerial->readLine();
    QString str = "23;45.43;67.23"; //QString(data);
    ui->tb_output->insertPlainText(str);


}


void MainWindow::on_btn_closePort_clicked()
{
    ui->btn_closePort->setEnabled(false);

    if (mSerial->isOpen()) {
        QMessageBox msgBox;
        msgBox.setText("Sucessfully disconnected");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
        mSerial->close();
    } else {
        QString awsd = QString("-23;45.43;9812.23"); //QString(data);
        QStringList values = awsd.split(";");
        ui->ln_rssi->display(values[0] + "dBi");
        ui->ln_temp->display(values[1]);
        ui->ln_kpa->display(values[2].toDouble() / 1000);
        ui->ln_atm->display(values[2].toDouble() / 101325);
        updateTemp(values[1].toDouble());

    }
    ui->btn_closePort->setEnabled(true);
}

