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
    timerWindow = new ShowTimer(model, this);
    //timerWindow->setModal(true);
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
            if(timers[i]->isRemoved)
            {
                timers.erase(timers.begin() + i);
                i--;
                continue;
            }
            timers[i]->updateTime();
            QModelIndex index = model->index(i);
            model->setData(index, timers[i]->getQStringTimer());
        }
    }
    timerWindow->updateTimer();
}
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
    timerWindow->show();
}
