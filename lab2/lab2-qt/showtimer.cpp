#include "showtimer.h"
#include "ui_showtimer.h"

ShowTimer::ShowTimer(QVector<MyTimer*>& timers, QStringListModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowTimer), model(model), timers(timers), indexOfTimer(0)
{
    ui->setupUi(this);
}

ShowTimer::~ShowTimer()
{
    model = nullptr;
    delete ui;
}
void ShowTimer::update_timer()
{
    if(indexOfTimer >= timers.size()) return;
    if(timers[indexOfTimer])
    {
        ui->lblTimerName->setText(timers[indexOfTimer]->name);
        ui->lblTimer->setText(timers[indexOfTimer]->get_qString_time());
    }
}
void ShowTimer::on_btnStart_clicked()
{
    if(indexOfTimer >= timers.size()) return;
    timers[indexOfTimer]->turn_on();
}

void ShowTimer::on_btnPause_clicked()
{
    if(indexOfTimer >= timers.size()) return;
     timers[indexOfTimer]->turn_off();
}

void ShowTimer::on_btnEdit_clicked()
{
    EditingTimer newWindow( timers, model, indexOfTimer);
    newWindow.setModal(true);
    newWindow.exec();
}

void ShowTimer::on_btnDelete_clicked()
{      
    if(indexOfTimer >= timers.size()) return;
    if(timers[indexOfTimer]) delete timers[indexOfTimer];
    timers.erase(timers.begin() + indexOfTimer);
    model->removeRow(indexOfTimer);
    indexOfTimer = 0;
    hide();
}
void ShowTimer::set_timer(int indexOfTimer)
{
    this->indexOfTimer = indexOfTimer;
    update_timer();
}
