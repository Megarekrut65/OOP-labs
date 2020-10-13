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
    timerWindow = new ShowTimer(timers, model, this);
    ui->listTimers->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listTimers->setStyleSheet("background-color: #FFFFFF;");
    ui->statusbar->showMessage("[T]-Timer, [A]-Alarm clock");
    start_header_timer();
}
MainWindow::~MainWindow()
{
    delete oneSecondTimer;
    timers.clear();
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
            model->setData(model->index(i),
                           QString::number(i) + "." + timers[i]->get_qString_timer());
        }
    }
    timerWindow->update_timer();
}
void MainWindow::on_btnStartAll_clicked()
{
    AllActive = true;
    ui->listTimers->setStyleSheet("background-color: #FFFFFF;");
    for(int i = 0; i < timers.size();i++)
    {
        timers[i]->turn_on();
    }
}

void MainWindow::on_btnPauseAll_clicked()
{
    AllActive = false;
    ui->listTimers->setStyleSheet("background-color: #F5F5F5;");
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
