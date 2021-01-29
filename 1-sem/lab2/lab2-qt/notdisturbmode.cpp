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
    ui->timeEditBegin->setTime(period.get_begin());
    ui->timeEditEnd->setTime(period.get_end());
    ui->radioButtonOn->setChecked(period.is_active());
    ui->radioButtonOff->setChecked(!period.is_active());
}

NotDisturbMode::~NotDisturbMode()
{
    delete ui;
}
void NotDisturbMode::on_btnSave_clicked()
{
    QTime begin =  ui->timeEditBegin->time();
    QTime end = ui->timeEditEnd->time();
    bool active = ui->radioButtonOn->isChecked();
    period.set_period(begin, end, active);
    this->close();
}
void NotDisturbMode::on_btnCancel_clicked()
{
    this->close();
}
