#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
     model(new QStandardItemModel)
{
    ui->setupUi(this);
    oneSecondTimer = nullptr;
    AllActive = true;
    ui->listTimers->setModel(model);
    timerWindow = new ShowTimer(timers, model, this);
    ui->listTimers->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listTimers->setStyleSheet("background-color: " + MyColors::startedListBackground);
    ui->statusbar->showMessage("[T]-Timer, [A]-Alarm clock");

    start_header_timer();
}
MainWindow::~MainWindow()
{
    while(timers.size() > 0)
    {
        qDebug() << timers[0]->get_timer_info();
        if(timers[0]) delete timers[0];
        timers.erase(timers.begin());
    }
    delete oneSecondTimer;
    delete timerWindow;
    delete model;
    delete ui;
}
void MainWindow:: start_header_timer()
{
    oneSecondTimer = new QTimer(this);
    connect(oneSecondTimer, &QTimer::timeout, this, &MainWindow::update_all_timers);
    oneSecondTimer->start(1000);
}
void MainWindow::update_all_timers()
{
    if(!AllActive) return;
    for(int i = 0; i < timers.size(); i++)
    {
        if(i < 0) break;
        if(timers[i])
        {
            timers[i]->update();
            auto item = new QStandardItem( QString::number(i) + "." + timers[i]->get_QString_timer());
            if(!timers[i]->active) item->setBackground(QBrush(MyColors::pausedItem));
            else if(timers[i]->timeOut) item->setBackground(QBrush(MyColors::timeOut));
            model->setItem(i, item);
        }
    }
    timerWindow->update_timer();
}
void MainWindow::on_btnStartAll_clicked()
{
    AllActive = true;
    ui->listTimers->setStyleSheet("background-color: " + MyColors::startedListBackground);
    for(int i = 0; i < timers.size();i++)
    {
        timers[i]->turn_on();
    }
}

void MainWindow::on_btnPauseAll_clicked()
{
    AllActive = false;
    ui->listTimers->setStyleSheet("background-color: "  +MyColors::pausedListBackground);
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
    timerWindow->set_timer(indexOfTimer);
    timerWindow->show();
}
