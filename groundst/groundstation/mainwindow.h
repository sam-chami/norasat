#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include <QElapsedTimer>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_openSerialPort_clicked();
    void serialReadyRead();

    void on_btn_closePort_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *mSerial;

    QList<QSerialPortInfo> mSerialPorts;
    QTimer *mSerialScanTimer;

    void updateSerialPorts();

    QElapsedTimer s_passed;
    void updateTemp(double value);
    void updatePres(double value);
};
#endif // MAINWINDOW_H
