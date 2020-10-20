#include "showtimer.h"
#include "ui_showtimer.h"

ShowTimer::ShowTimer(QVector<MyTimer*>& timers,int& indexOfCurrentTimer, QStandardItemModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowTimer), model(model), timers(timers), indexOfTimer(0), indexOfCurrentTimer(indexOfCurrentTimer)
{
    ui->setupUi(this);
    this->setWindowTitle("Showing timer");
    QIcon icon("images/ico/show.ico");
    this->setWindowIcon(icon);
    ui->lineTimerName->setStyleSheet("background:transparent; border: 0px;");
}
ShowTimer::~ShowTimer()
{
    model = nullptr;
    delete ui;
}
bool ShowTimer::questions_to_delete(QWidget* that, QString title, QString sentence)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(that, title, sentence, QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) return true;
    else return false;
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
    if(timers[indexOfTimer]) ui->lblTimer->setText(get_time_style());
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
    EditingTimer newWindow( timers, model, indexOfTimer, ui->lineTimerName);
    newWindow.setModal(true);
    newWindow.exec();
}
void ShowTimer::on_btnDelete_clicked()
{      
    if(indexOfTimer >= timers.size()) return;
    bool doDelete = ShowTimer::questions_to_delete(this,
                                   "Delete the timer",
                                   "Deleted timer will not be recoverable. Do you really want to delete the timer?");
    if(!doDelete) return;
    if(timers[indexOfTimer]) delete timers[indexOfTimer];
    timers.erase(timers.begin() + indexOfTimer);
    model->removeRow(indexOfTimer);
    indexOfTimer = 0;
    indexOfCurrentTimer = -1;
    hide();
}
void ShowTimer::set_timer(int indexOfTimer)
{
    if(indexOfTimer >= timers.size())
    {
        this->close();
        return;
    }
    this->indexOfTimer = indexOfTimer;
    ui->lineTimerName->setText(timers[indexOfTimer]->name);
    ui->lblType->setText(get_timer_type());
    update_timer();
}
