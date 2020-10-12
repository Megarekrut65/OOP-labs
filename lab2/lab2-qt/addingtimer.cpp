#include "addingtimer.h"
#include "ui_addingtimer.h"

AddingTimer::AddingTimer(QVector<MyTimer*>* timers,
                         QStringListModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddingTimer)
{
    ui->setupUi(this);
    this->timers = timers;
    this->model = model;
}

AddingTimer::~AddingTimer()
{
    timers = nullptr;
    model = nullptr;
    delete ui;
}

void AddingTimer::on_btnCreate_clicked()
{
    QString name = ui->lineAddName->text();
    QTime* time = new QTime(ui->timeAdd->time());
    if(timers && model)
    {
        MyTimer* timer = new MyTimer(name, time);
        timers->push_back(timer);
        int size = model->rowCount();
        model->insertRow(size);
        QModelIndex index = model->index(size);
        model->setData(index, timer->getQStringTimer());
        timer = nullptr;
    }
    this->close();
}

void AddingTimer::on_btnCancel_clicked()
{
    this->close();
}
