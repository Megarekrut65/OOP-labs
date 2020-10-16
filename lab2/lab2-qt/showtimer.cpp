#include "showtimer.h"
#include "ui_showtimer.h"

ShowTimer::ShowTimer(QVector<MyTimer*>& timers, QStandardItemModel *model, QWidget *parent) :
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
QString ShowTimer::get_time_style()
{
    QString style = "<h3";
    if(!timers[indexOfTimer]->active) style += " style=\"color:#DAA520;\"";
    else if(timers[indexOfTimer]->timeOut) style += " style=\"color:#B22222;\"";
    style += ">" + timers[indexOfTimer]->get_QString_time() + "</h3>";

    return style;
}
QString ShowTimer::get_timer_type()
{
    if(timers[indexOfTimer]->type == Type::TIMER) return "Timer";
    return "Alarm clock";
}
void ShowTimer::update_timer()
{
    if(indexOfTimer >= timers.size()) return;
    if(timers[indexOfTimer])
    {
        ui->lblTimerName->setText(timers[indexOfTimer]->name);
        ui->lblTimer->setText(get_time_style());
        ui->lblType->setText(get_timer_type());
    }
}
void ShowTimer::on_btnStart_clicked()
{
    if(indexOfTimer >= timers.size()) return;
    timers[indexOfTimer]->turn_on();
    ui->lblTimer->setText(get_time_style());
    auto item = new QStandardItem(QString::number(indexOfTimer) + "." +
                                   timers[indexOfTimer]->get_QString_timer());
    if(timers[indexOfTimer]->timeOut) item->setBackground(QBrush(MyColors::timeOut));
    model->setItem(indexOfTimer, item);
}

void ShowTimer::on_btnPause_clicked()
{
    if(indexOfTimer >= timers.size()) return;
    timers[indexOfTimer]->turn_off();
    ui->lblTimer->setText(get_time_style());
    auto item = new QStandardItem(QString::number(indexOfTimer) + "." +
                                   timers[indexOfTimer]->get_QString_timer());
    item->setBackground(QBrush(MyColors::pausedItem));
    model->setItem(indexOfTimer, item);
}

void ShowTimer::on_btnEdit_clicked()
{
    EditingTimer newWindow( timers, model, indexOfTimer);
    newWindow.setModal(true);
    newWindow.exec();
    this->hide();
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
