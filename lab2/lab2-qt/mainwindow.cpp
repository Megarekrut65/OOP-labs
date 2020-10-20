#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
     model(new QStandardItemModel),
     oneSecondTimer(nullptr),
     timersPath(QDir::currentPath()+"/files/timers.txt"),
     periodPath(QDir::currentPath()+"/files/period.txt"),
     soundModePath(QDir::currentPath()+"/files/sound.txt"),
     allActivePath(QDir::currentPath()+"/files/all-active.txt"),
     indexOfCurrentTimer(-1),
     indexOfShowedTimer(-1)
{
    ui->setupUi(this);
    this->setWindowTitle("Smart timers");
    QIcon icon("images/ico/timer.ico");
    this->setWindowIcon(icon);
    timerWindow = new ShowTimer(timers, indexOfCurrentTimer, model, this);
    fileModel = "File model: active, time out, timer type, time(hh:mm:ss),"
                " timer name, max number of signals, number of signals, path to sound\r\n";
    notDisturbPeriod = TimePeriod(periodPath);
    set_list_model();
    allActive = read_bool_variable_from_file(allActivePath, "All active:");
    if(!allActive) ui->listTimers->setStyleSheet("background-color: " + MyColors::pausedListBackground);
    soundMode = read_bool_variable_from_file(soundModePath, "Sound mode:");
    set_status_bar();
    read_all_timers_from_file();
    start_header_timer();
}
void MainWindow::edit_file_with_bool_variable(QString path, QString title, bool value)
{
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)) return;
    file.write((title.toStdString() + "\r\n").c_str());
    if(value) file.write("true");
    else file.write("false");
    file.close();
}
bool MainWindow::read_bool_variable_from_file(QString path, QString title)
{
    QFile file(path);
    if(!file.exists())
    {
        if(file.open(QIODevice::WriteOnly))
        {
            file.write((title.toStdString() + "\r\n").c_str());
            file.write("true");
            file.close();
        }
        return true;
    }
    if (file.open(QIODevice::ReadOnly))
    {
        if(file.atEnd())
        {
             file.close();
            return true;
        }
        QString line = file.readLine();//reads the title
        if(file.atEnd())
        {
             file.close();
            return true;
        }
        line = file.readLine();
        if(line == "false") return false;
        file.close();
    }
    return true;
}
void MainWindow::set_list_model()
{
    ui->listTimers->setModel(model);
    ui->listTimers->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listTimers->setStyleSheet("background-color: " + MyColors::startedListBackground);
}
void MainWindow::set_status_bar()
{
    statusBar = "[T]-Timer, [A]-Alarm clock";
    soundBar = ". Sound";
    notDisturbBar = "";
    ui->statusbar->showMessage(statusBar + soundBar + notDisturbBar);
    ui->menuFile->menuAction()->setStatusTip(statusBar + soundBar + notDisturbBar);
    ui->menuTools->menuAction()->setStatusTip(statusBar + soundBar + notDisturbBar);
    ui->menuTimer->menuAction()->setStatusTip(statusBar + soundBar + notDisturbBar);
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
void MainWindow::edit_status_bar(QString otherBar)
{
    if(soundMode) soundBar =  ". Sound on";
    else soundBar =  ". Sound off";
    if(notDisturbPeriod.is_period()) notDisturbBar = ". Not disturb mode";
    else notDisturbBar = "";
    ui->statusbar->showMessage(statusBar + soundBar + notDisturbBar + otherBar);
}
void MainWindow::update_all_timers()
{
    bool saving = false;
    QFile file(timersPath);
    QString saveBar = "";
    if(QTime::currentTime().second() == 0)
    {
        saving = true;
        saveBar=  ". Save...";
        if(!file.open(QIODevice::WriteOnly)) saving = false;
    }
    edit_status_bar(saveBar);
    if(saving) file.write(fileModel.toStdString().c_str());
    for(int i = 0; i < timers.size(); i++)
    {
        if(timers[i])
        {
            if(allActive && notDisturbPeriod.is_period()) timers[i]->update(false);
            else if(allActive) timers[i]->update(soundMode);
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
    allActive = true;
    edit_file_with_bool_variable(allActivePath, "All active:", allActive);
    ui->listTimers->setStyleSheet("background-color: " + MyColors::startedListBackground);
    for(int i = 0; i < timers.size();i++)
    {
        timers[i]->turn_on();
    }
}
void MainWindow::on_actionPause_all_timers_triggered()
{
    allActive = false;
    edit_file_with_bool_variable(allActivePath, "All active:", allActive);
    ui->listTimers->setStyleSheet("background-color: " + MyColors::pausedListBackground);
}
void MainWindow::on_actionAdd_new_timer_triggered()
{
    AddingTimer window(timers, model);
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
    edit_file_with_bool_variable(soundModePath, "Sound mode:", soundMode);
}
void MainWindow::on_actionSound_off_triggered()
{
    soundMode = false;
    edit_file_with_bool_variable(soundModePath, "Sound mode:", soundMode);
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
