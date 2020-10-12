#include "showtimer.h"
#include "ui_showtimer.h"

ShowTimer::ShowTimer(QStringListModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowTimer)
{
    ui->setupUi(this);
    timer = nullptr;
    this->model = model;
    indexOfTimer = 0;
}

ShowTimer::~ShowTimer()
{
    timer = nullptr;
    model = nullptr;
    delete ui;
}
void ShowTimer::updateTimer()
{
    if(timer)
    {
        ui->lblTimerName->setText(timer->name);
        ui->lblTimer->setText(timer->getQStringTime());
    }
}
void ShowTimer::on_btnStart_clicked()
{
    timer->turnOn();
}

void ShowTimer::on_btnPause_clicked()
{
    timer->turnOff();
}

void ShowTimer::on_btnEdit_clicked()
{
    EditingTimer newWindow(timer, model, indexOfTimer);
    newWindow.setModal(true);
    newWindow.exec();
}

void ShowTimer::on_btnDelete_clicked()
{

}
void ShowTimer::setTimer(MyTimer* timer,  int indexOfTimer)
{
    if(this->timer) timer->openOutside = false;
    this->timer = timer;
    if(this->timer) timer->openOutside = true;
    this->indexOfTimer = indexOfTimer;
    updateTimer();
}
