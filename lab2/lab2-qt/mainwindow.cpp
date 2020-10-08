#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timers.push_back(MyTimer("Timer", 0,0,0));
    indexOfCurrentTimer = 0;
    moveTimer();
    startTheTimer();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_btnTimer_clicked()
{
   timers.push_back(MyTimer("my timer", 5, 10, 13));
   indexOfCurrentTimer = timers.size() - 1;
   moveTimer();
}
void MainWindow:: startTheTimer()
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateAllTimers);
    timer->start(1000);
}
void MainWindow::updateAllTimers()
{
    for(int i = 0; i < timers.size(); i++)
    {
         timers[i].updateTime();
    }
    ui->lblTimer->setText(timers[indexOfCurrentTimer].getQStringTime());
}
MyTimer::MyTimer(): active(false), hour(0), min(0), sec(0) {}
MyTimer::MyTimer( const QString& name, int hour, int min, int sec)
{
  this->name = name;
  active = true;
  if(hour < 0) hour = 0;
  if(min < 0) min = 0;
  if(sec < 0) sec = 0;
  if(hour == 0 && min == 0 && sec == 0) active = false;
  this->hour = hour;
  this->min = min;
  this->sec = sec;
}
MyTimer::MyTimer(const QString& name, const QString& qstringTime)
{
    QStringList parts = qstringTime.split(":");
    if(parts.size() == 3)
    {
        MyTimer(name, parts[0].toInt(), parts[1].toInt(), parts[2].toInt());
    }
    else
    {
        MyTimer();
    }
}
QString MyTimer::makeCorrect(int value)
{
    QString res = "";
    if(value / 10 == 0)
    {
        res += "0" + QString::number(value);
    }
    else
    {
        res += QString::number(value);
    }

    return res;
}
 QString MyTimer::getQStringTime()
 {
     QString res = makeCorrect(hour) + ":"
             + makeCorrect(min) + ":" + makeCorrect(sec);

     return res;
 }
 void MyTimer::setTime(int hour, int min, int sec)
 {
     MyTimer(this->name, hour, min, sec);
 }
 void MyTimer::addTime(int sec)
 {
    if(sec <= 0) return;
    sec += sec;
    if(sec >= 60)
    {
        min+= sec/60;
        sec %= 60;
        if(min >= 60)
        {
            hour+= min/60;
            min %= 60;
        }
    }
 }
 void MyTimer::updateTime()
 {
     if(!active) return;
     if(sec > 0) sec--;
     else if(min > 0)
     {
         min--;
         sec = 59;
     }
     else if(hour > 0)
     {
         hour--;
         min = 59;
         sec = 59;
     }
     else active = false;
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
