#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
     model(new QStandardItemModel),
     timersPath(QDir::currentPath()+"/files/timers.txt"),
     periodPath(QDir::currentPath()+"/files/period.txt")
{
    ui->setupUi(this);
    this->setWindowTitle("Smart timers");
    QIcon icon("images/ico/timer.ico");
    this->setWindowIcon(icon);
    oneSecondTimer = nullptr;
    AllActive = true;
    ui->listTimers->setModel(model);
    timerWindow = new ShowTimer(timers, indexOfCurrentTimer, model, this);
    ui->listTimers->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listTimers->setStyleSheet("background-color: " + MyColors::startedListBackground);
    set_status_bar();
    fileModel = "File model: active, time out, timer type, time(hh:mm:ss),"
                " timer name, max number of signals, number of signals, path to sound\r\n";
    soundMode = true;
    indexOfCurrentTimer = -1;
    indexOfShowedTimer = -1;
    notDisturbPeriod = TimePeriod(periodPath);
    read_all_timers_from_file();
    start_header_timer();
}
void MainWindow::set_status_bar()
{
    statusBar = "[T]-Timer, [A]-Alarm clock";
    soundBar = "";
    notDisturbBar = "";
    ui->statusbar->showMessage(statusBar + soundBar + notDisturbBar);
    ui->menuFile->menuAction()->setStatusTip(statusBar + soundBar + notDisturbBar);
    ui->menuTools->menuAction()->setStatusTip(statusBar + soundBar + notDisturbBar);
    ui->menuSetting->menuAction()->setStatusTip(statusBar + soundBar + notDisturbBar);
}
MainWindow::~MainWindow()
{
    write_all_timers_to_file();
    if(oneSecondTimer) delete oneSecondTimer;
    if(timerWindow) delete timerWindow;
    if(model) delete model;
    delete ui;
}
void MainWindow::write_all_timers_to_file()
{
    QFile file(timersPath);
    if(!file.open(QIODevice::WriteOnly)) return;
    ui->statusbar->showMessage(statusBar + ". Save...");
    file.write(fileModel.toStdString().c_str());
    while(timers.size() > 0)
    {
        file.write((timers[0]->get_timer_info().toStdString() + "\r\n").c_str() );
        if(timers[0]) delete timers[0];
        timers.erase(timers.begin());
    }
    file.close();
}
void MainWindow:: read_all_timers_from_file()
{
    QFile file(timersPath);
    if(!file.exists())
    {
        if(file.open(QIODevice::WriteOnly)) file.close();
        return;
    }
    if (file.open(QIODevice::ReadOnly))
    {
        while(!file.atEnd())
        {
            if(timers.size() == 0) file.readLine();//read file model
            if(file.atEnd()) break;
            QString line = file.readLine();
            line.remove("\r\n");
            timers.push_back(new MyTimer(line));
            int size = model->rowCount();
            model->insertRow(size);
            auto item = new QStandardItem( QString::number(timers.size() - 1) + "."
                                           + timers[size]->get_QString_timer());
            if(!timers[size]->active) item->setBackground(QBrush(MyColors::pausedItem));
            else if(timers[size]->timeOut) item->setBackground(QBrush(MyColors::timeOut));
            model->setItem(size, item);
        }
        file.close();
    }
}
void MainWindow:: start_header_timer()
{
    oneSecondTimer = new QTimer(this);
    connect(oneSecondTimer, &QTimer::timeout, this, &MainWindow::update_all_timers);
    oneSecondTimer->start(1000);
}
void MainWindow::update_all_timers()
{
    bool saving = false;
    QFile file(timersPath);
    if(soundMode) soundBar =  ". Sound on";
    else soundBar =  ". Sound off";
    if(notDisturbPeriod.is_period()) notDisturbBar = ". Not disturb mode";
    else notDisturbBar = "";
    QString saveBar = "";
    if(QTime::currentTime().second() == 0)
    {
        saving = true;
        saveBar=  ". Save...";
        if(!file.open(QIODevice::WriteOnly)) saving = false;
    }
    ui->statusbar->showMessage(statusBar + soundBar + notDisturbBar + saveBar);
    if(saving) file.write(fileModel.toStdString().c_str());
    for(int i = 0; i < timers.size(); i++)
    {
        if(timers[i])
        {
            if(AllActive && notDisturbPeriod.is_period()) timers[i]->update(false);
            else if(AllActive) timers[i]->update(soundMode);
            auto item = new QStandardItem( QString::number(i) + "." + timers[i]->get_QString_timer());
            if(!timers[i]->active) item->setBackground(QBrush(MyColors::pausedItem));
            else if(timers[i]->timeOut) item->setBackground(QBrush(MyColors::timeOut));
            model->setItem(i, item);
            if(saving) file.write(( timers[i]->get_timer_info().toStdString()+ "\r\n").c_str());
        }
    }
    if(saving) file.close();
    timerWindow->update_timer();
}
void MainWindow::on_listTimers_doubleClicked(const QModelIndex &index)
{
    show_the_timer(index.row());
}
void MainWindow::on_actionQuit_triggered()
{
    this->close();
}
void MainWindow::on_actionStart_all_timers_triggered()
{
    AllActive = true;
    ui->listTimers->setStyleSheet("background-color: " + MyColors::startedListBackground);
    for(int i = 0; i < timers.size();i++)
    {
        timers[i]->turn_on();
    }
}
void MainWindow::on_actionPause_all_timers_triggered()
{
    AllActive = false;
    ui->listTimers->setStyleSheet("background-color: " + MyColors::pausedListBackground);
}
void MainWindow::on_actionAdd_new_timer_triggered()
{
    AddingTimer window(&timers, model);
    window.setModal(true);
    window.exec();
}
void MainWindow::on_actionDelete_all_timers_triggered()
{
    bool doDelete = ShowTimer::questions_to_delete(this,
                                   "Delete all timers",
                                   "Deleted timers will not be recoverable. Do you really want to delete all timers?");
    if (doDelete)
    {
      timerWindow->hide();
      indexOfCurrentTimer = -1;
      while(timers.size() > 0)
      {
          if(timers[0]) delete timers[0];
          timers.erase(timers.begin());
          model->removeRow(0);
      }
    }
}
void MainWindow::on_actionSound_on_triggered()
{
    soundMode = true;
}
void MainWindow::on_actionSound_off_triggered()
{
    soundMode = false;
}
void MainWindow::on_actionDo_not_disturb_mode_triggered()
{
    NotDisturbMode window(notDisturbPeriod);
    window.setModal(true);
    window.exec();
}
void MainWindow::on_actionStart_selected_timer_triggered()
{
    if(indexOfCurrentTimer < 0) return;
    timers[indexOfCurrentTimer]->turn_on();
}
void MainWindow::on_actionPause_selected_timer_triggered()
{
    if(indexOfCurrentTimer < 0) return;
    timers[indexOfCurrentTimer]->turn_off();
}
void MainWindow::on_actionDelete_selected_timer_triggered()
{
    if(indexOfCurrentTimer < 0) return;
    bool doDelete = ShowTimer::questions_to_delete(this,
                                   "Delete the timer",
                                   "Deleted timer will not be recoverable. Do you really want to delete the timer?");
    if(!doDelete) return;
    if(timers[indexOfCurrentTimer]) delete timers[indexOfCurrentTimer];
    timers.erase(timers.begin() + indexOfCurrentTimer);
    model->removeRow(indexOfCurrentTimer);
    if(indexOfShowedTimer == indexOfCurrentTimer) timerWindow->hide();
    else if (indexOfShowedTimer > indexOfCurrentTimer)
    {
        indexOfShowedTimer--;
        timerWindow->set_timer(indexOfShowedTimer);
    }
    indexOfCurrentTimer = -1;
}
void MainWindow::on_listTimers_clicked(const QModelIndex &index)
{
    indexOfCurrentTimer = index.row();
}
void MainWindow::show_the_timer(int index)
{
    indexOfShowedTimer = index;
    timerWindow->set_timer(indexOfShowedTimer);
    timerWindow->show();
}
void MainWindow::on_actionShow_selected_timer_triggered()
{
    if(indexOfCurrentTimer < 0) return;
    show_the_timer(indexOfCurrentTimer);
}
