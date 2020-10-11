#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "editingandaddingtimers.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    indexOfCurrentTimer = 0;
    addEmptyTimer();
    startTheTimer();
}

MainWindow::~MainWindow()
{
    delete oneSecondTimer;
    timers.clear();
    delete ui;
}
void MainWindow:: startTheTimer()
{
    oneSecondTimer = new QTimer(this);
    connect(oneSecondTimer, &QTimer::timeout, this, &MainWindow::updateAllTimers);
    oneSecondTimer->start(1000);
}
void MainWindow::updateAllTimers()
{
    for(int i = 0; i < timers.size(); i++)
    {
         timers[i].updateTime();
    }
    ui->lblTimer->setText(timers[indexOfCurrentTimer].getQStringTime());
}
MyTimer::MyTimer(): active(false), time(nullptr) {}
MyTimer::MyTimer( const QString& name, QTime time)
{
  this->name = name;
  active = true;
  this->time = new QTime(time);
}
MyTimer::MyTimer(const QString& name, const QString& qStringTime)
{
    QStringList parts = qStringTime.split(":");
    if(parts.size() == 3)
    {
        MyTimer(name, QTime(parts[0].toInt(), parts[1].toInt(), parts[2].toInt()));
    }
    else
    {
        MyTimer();
    }
}
 QString MyTimer::getQStringTime()
 {
     return time->toString("hh:mm:ss");
 }
 void MyTimer::setTime(QTime time)
 {
     this->time->setHMS(time.hour(),time.minute(), time.second());
 }
 void MyTimer::addTime(int sec)
 {
    if(sec <= 0) return;
    *time = time->addSecs(sec);
 }
 void MyTimer::updateTime()
 {
     if(time->hour() == 0 && time->minute() == 0 && time->second() == 0) active = false;
     if(!active) return;
     *time = time->addSecs(-1);
 }
void MainWindow::on_btnRight_clicked()
{
    if(indexOfCurrentTimer >= timers.size() - 1) return;
    indexOfCurrentTimer++;
    moveTimer();
}
void MainWindow::on_btnLeft_clicked()
{
    if(indexOfCurrentTimer <= 0) return;
    indexOfCurrentTimer--;
    moveTimer();
}
void MainWindow::moveTimer()
{
    ui->lblTimer->setText(timers[indexOfCurrentTimer].getQStringTime());
    ui->lblTimerName->setText(timers[indexOfCurrentTimer].name);
}
void MyTimer::turnOn()
{
    active = true;
}
void MyTimer::turnOff()
{
    active = false;
}
void MainWindow::on_btnStart_clicked()
{
    timers[indexOfCurrentTimer].turnOn();
}

void MainWindow::on_btnPause_clicked()
{
     timers[indexOfCurrentTimer].turnOff();
}
void MainWindow::addNewTimer(QString name, QTime time)
{
    timers.push_back(MyTimer(name, time));
    indexOfCurrentTimer = timers.size() - 1;
    moveTimer();
}
void MainWindow::editTheTimer(QString name, QTime time)
{
    MyTimer* timer = &timers[indexOfCurrentTimer];
    timer->setTime(time);
    timer->name = name;
    timer->turnOn();
    moveTimer();
}
void MainWindow::on_btnTimer_clicked()
{
    EditingAndAddingTimers newWindow;
    newWindow.setModal(true);
    newWindow.addTimer(this);
    newWindow.exec();
}
void MainWindow::on_btnEdit_clicked()
{
    EditingAndAddingTimers newWindow;
    newWindow.setModal(true);
    MyTimer* timer = &timers[indexOfCurrentTimer];
    newWindow.editTimer(timer, this);
    newWindow.exec();
}
void MainWindow::on_btnDelete_clicked()
{
    timers.erase(timers.begin() + indexOfCurrentTimer);
    indexOfCurrentTimer = 0;
    if(timers.size() == 0)
    {
        addEmptyTimer();
    }
    else
    {
        moveTimer();
    }
}
void MainWindow::addEmptyTimer()
{
    timers.push_back(MyTimer("Timer", QTime(0, 0, 0, 0)));
    moveTimer();
}
QTime MyTimer::getTime()
{
    return *time;
}
