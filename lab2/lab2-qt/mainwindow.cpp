#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->groupBoxAdding->hide();
    indexOfCurrentTimer = 0;
    isShowed = true;
    addEmptyTimer();
    startTheTimer();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_btnTimer_clicked()
{
   addNewTimer();
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
    if(isShowed) ui->lblTimer->setText(timers[indexOfCurrentTimer].getQStringTime());
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
    return (QString::number(value/10) + QString::number(value % 10));
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
 void MainWindow::showTimer(bool show)
 {
    if(show && !isShowed)
    {
        ui->groupBoxTimer->show();
        ui->groupBoxAdding->hide();
    }
    else if (!show && isShowed)
    {
        ui->groupBoxAdding->show();
        ui->groupBoxTimer->hide();
    }
    isShowed = show;
 }
void MainWindow::moveTimer()
{
    if(!isShowed) return;
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
void MainWindow::on_btnCreate_clicked()
{
    QString name = ui->lineEditNameTimer->text();
    QTime time = ui->timeEditAdd->time();
    timers.push_back(MyTimer(name, time.hour(), time.minute(), time.second()));
    indexOfCurrentTimer = timers.size() - 1;
    showTimer(true);
    moveTimer();
}
void MainWindow::on_btnCancel_clicked()
{
    showTimer(true);
}
void MainWindow::addNewTimer()
{
    ui->btnCreate->setText("Create");
    ui->labelAdd->setText("Add new timer");
    ui->timeEditAdd->setTime(QTime());
    ui->lineEditNameTimer->setText("Enter name of timer...");
    showTimer(false);
}
void MainWindow::editTheTimer()
{
    ui->btnCreate->setText("Save");
    ui->labelAdd->setText("Edit the timer");
    ui->timeEditAdd->setTime(QTime());
    ui->lineEditNameTimer->setText("edit name of timer...");
    showTimer(false);
}

void MainWindow::on_btnEdit_clicked()
{
    editTheTimer();
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
    timers.push_back(MyTimer("Timer", 0,0,0));
    moveTimer();
}
