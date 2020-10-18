#include "notdisturbmode.h"
#include "ui_notdisturbmode.h"

NotDisturbMode::NotDisturbMode(TimePeriod& period, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NotDisturbMode), period(period)
{
    ui->setupUi(this);
    this->setWindowTitle("Not Disturb mode");
    QIcon icon("images/ico/not-distrub.ico");
    this->setWindowIcon(icon);
    ui->timeEditBegin->setTime(period.begin);
    ui->timeEditEnd->setTime(period.end);
    ui->radioButtonOn->setChecked(period.active);
    ui->radioButtonOff->setChecked(!period.active);
}

NotDisturbMode::~NotDisturbMode()
{
    delete ui;
}

void NotDisturbMode::on_btnSave_clicked()
{
    QTime begin =  ui->timeEditBegin->time();
    QTime end = ui->timeEditEnd->time();
    if(begin < end)
    {
        period.begin = begin;
        period.end = end;
    }
    else
    {
        period.begin = end;
        period.end = begin;
    }
    period.active = ui->radioButtonOn->isChecked();
    period.write_to_file();
    this->hide();
}
void NotDisturbMode::on_btnCancel_clicked()
{
    this->hide();
}
