#include "showtimer.h"
#include "ui_showtimer.h"

ShowTimer::ShowTimer(QWidget *parent, MyTimer* timer) :
    QDialog(parent),
    ui(new Ui::ShowTimer)
{
    ui->setupUi(this);
    this->timer = timer;
}

ShowTimer::~ShowTimer()
{
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
    EditingAndAddingTimers newWindow;
    newWindow.setModal(true);
    newWindow.editTimer(timer);
    newWindow.exec();
}

void ShowTimer::on_btnDelete_clicked()
{

}
