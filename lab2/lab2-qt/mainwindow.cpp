#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
     model(new QStringListModel)
{
    ui->setupUi(this);
    oneSecondTimer = nullptr;
    AllActive = true;
    ui->listTimers->setModel(model);
    timerWindow = new ShowTimer(model);
    timerWindow->setModal(true);
    startHeaderTimer();
}
MainWindow::~MainWindow()
{
    delete oneSecondTimer;
    timers.clear();
    delete ui;
}
void MainWindow:: startHeaderTimer()
{
    oneSecondTimer = new QTimer(this);
    connect(oneSecondTimer, &QTimer::timeout, this, &MainWindow::updateAllTimers);
    oneSecondTimer->start(1000);
}
void MainWindow::updateAllTimers()
{
    if(!AllActive) return;
    for(int i = 0; i < timers.size(); i++)
    {
        if(i < 0) break;
        if(timers[i])
        {
            /*if(timers[i]->isRemoved)
            {
                delete  ui->listTimers->takeItem(i);
                timers.erase(timers.begin() + i);
                i--;
                continue;
            }*/
            timers[i]->updateTime();
            QModelIndex index = model->index(i);
            model->setData(index, timers[i]->getQStringTimer());
        }
    }
    timerWindow->updateTimer();
}
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
void MainWindow::on_btnStartAll_clicked()
{
    AllActive = true;
    for(int i = 0; i < timers.size();i++)
    {
        timers[i]->turnOn();
    }
}

void MainWindow::on_btnPauseAll_clicked()
{
    AllActive = false;
}
void MainWindow::on_btnAdd_clicked()
{
    AddingTimer window(&timers, model);
    window.setModal(true);
    window.exec();
}

void MainWindow::on_listTimers_doubleClicked(const QModelIndex &index)
{
    int indexOfTimer = index.row();
    timerWindow->setTimer(timers[indexOfTimer], indexOfTimer);
    timerWindow->exec();
}
