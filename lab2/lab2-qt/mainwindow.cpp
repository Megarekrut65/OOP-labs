#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startTheTimer();
}

MainWindow::~MainWindow()
{
    delete oneSecondTimer;
    for(int i = 0; i < timers.size();i++)
    {
        delete timers[i];
    }
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
         timers[i]->updateTime();
         //update list
    }
}
/*void MainWindow::addNewTimer(QString name, QTime time)
{
    timers.push_back(MyTimer(name, time));
    indexOfCurrentTimer = timers.size() - 1;
    moveTimer();
}*/
/*void MainWindow::editTheTimer(QString name, QTime time)
{
    MyTimer* timer = &timers[indexOfCurrentTimer];
    timer->setTime(time);
    timer->name = name;
    timer->turnOn();
    moveTimer();
}*/
/*void MainWindow::on_btnTimer_clicked()
{
    EditingAndAddingTimers newWindow;
    newWindow.setModal(true);
    newWindow.addTimer(this);
    newWindow.exec();
}*/
/*void MainWindow::on_btnDelete_clicked()
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
}*/
void MainWindow::addEmptyTimer()
{
    timers.push_back(new MyTimer("Timer", QTime(0, 0, 0, 0)));
}


void MainWindow::on_btnStartAll_clicked()
{
    for(int i = 0; i < timers.size();i++)
    {
        timers[i]->turnOn();
    }
}

void MainWindow::on_btnPauseAll_clicked()
{
    for(int i = 0; i < timers.size();i++)
    {
        timers[i]->turnOff();
    }
}

void MainWindow::on_btnAdd_clicked()
{
    ui->listTimers->addItem("10:20:30");
}
