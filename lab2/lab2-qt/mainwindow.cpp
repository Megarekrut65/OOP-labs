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
    if(ui->btnCreate->text() == "Create")
    {
        timers.push_back(MyTimer(name, time));
        indexOfCurrentTimer = timers.size() - 1;
    }
    else if(ui->btnCreate->text() == "Save")
    {
         MyTimer* timer = &timers[indexOfCurrentTimer];
         timer->setTime(time);
         timer->name = name;
         timer->turnOn();
    }
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
    ui->timeEditAdd->setTime(QTime(0,0,0));
    ui->lineEditNameTimer->setText("Enter name of timer...");
    showTimer(false);
}
void MainWindow::editTheTimer()
{
    ui->btnCreate->setText("Save");
    ui->labelAdd->setText("Edit the timer");
    MyTimer* timer = &timers[indexOfCurrentTimer];
    timer->turnOff();
    ui->timeEditAdd->setTime(timer->getTime());
    ui->lineEditNameTimer->setText(timer->name);
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
    timers.push_back(MyTimer("Timer", QTime(0, 0, 0, 0)));
    moveTimer();
}
QTime MyTimer::getTime()
{
    return *time;
}
