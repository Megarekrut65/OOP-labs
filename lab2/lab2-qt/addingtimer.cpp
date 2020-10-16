#include "addingtimer.h"
#include "ui_addingtimer.h"

AddingTimer::AddingTimer(QVector<MyTimer*>* timers,
                         QStandardItemModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddingTimer), timers(timers), model(model)
{
    ui->setupUi(this);
}

AddingTimer::~AddingTimer()
{
    timers = nullptr;
    model = nullptr;
    delete ui;
}
Type AddingTimer::setType()
{
    if(ui->radioButtonTimer->isChecked()) return Type::TIMER;
    else if(ui->radioButtonAlarm->isChecked()) return Type::AlARM_ClOCK;

    return Type::TIMER;
}
void AddingTimer::on_btnCreate_clicked()
{
    QString name = ui->lineAddName->text();
    QTime* time = new QTime(ui->timeAdd->time());
    if(timers && model)
    {
        Type type = setType();
        MyTimer* timer = new MyTimer(name, time, type);
        timers->push_back(timer);
        int size = model->rowCount();
        model->insertRow(size);
        auto item = new QStandardItem( QString::number(timers->size() - 1) + "." +timer->get_QString_timer());
        model->setItem(size, item);
        timer = nullptr;
    }
    this->close();
}

void AddingTimer::on_btnCancel_clicked()
{
    this->close();
}
