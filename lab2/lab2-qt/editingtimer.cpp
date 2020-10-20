#include "editingtimer.h"
#include "ui_editingtimer.h"

EditingTimer::EditingTimer(QVector<MyTimer*>& timers,  QStandardItemModel *model,
                           int indexOfTimer, QLineEdit* timerName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditingTimer), timers(timers), model(model),
    timerName(timerName),
    indexOfTimer(indexOfTimer)
{
    ui->setupUi(this);
    this->setWindowTitle("Editing timer");
    QIcon icon("images/ico/edit.ico");
    this->setWindowIcon(icon);
    if(indexOfTimer>= timers.size()||!timerName) this->close();
    else
    {
        if(timers[indexOfTimer])
        {
            turn_off_timer();
            ui->lineEditName->setText(timers[indexOfTimer]->name);
            ui->timeEditTime->setTime(timers[indexOfTimer]->get_time());
            ui->spinBoxNumber->setValue(timers[indexOfTimer]->maxNumberOfSignals);
            add_sounds();
            ui->seletcSound->setCurrentIndex(MySounds::get_index_of_sound(timers[indexOfTimer]->pathToSound));
        }
    }
}
void EditingTimer::turn_off_timer()
{
    timers[indexOfTimer]->turn_off();
    if(indexOfTimer>= timers.size() || !timers[indexOfTimer]) return;
    auto item = new QStandardItem(QString::number(indexOfTimer) + "." +
                                   timers[indexOfTimer]->get_QString_timer());
    item->setBackground(QBrush(MyColors::pausedItem));
    model->setItem(indexOfTimer, item);
}
void EditingTimer::turn_on_timer()
{
    if(indexOfTimer>= timers.size() || !timers[indexOfTimer]) return;
    auto item = new QStandardItem(QString::number(indexOfTimer) + "." +
                                   timers[indexOfTimer]->get_QString_timer());
    model->setItem(indexOfTimer, item);
    timers[indexOfTimer]->turn_on();
}
EditingTimer::~EditingTimer()
{
    turn_on_timer();
    model = nullptr;
    timerName = nullptr;
    delete ui;
}
void  EditingTimer::add_sounds()
{
    for(int i = 0; i < MySounds::sounds.size(); i++)
    {
         ui->seletcSound->addItem(MySounds::sounds[i]);
    }
}
void EditingTimer::on_btnSave_clicked()
{
    if(timers[indexOfTimer] && model)
    {
        timers[indexOfTimer]->name = ui->lineEditName->text();
        timerName->setText(ui->lineEditName->text());
        timers[indexOfTimer]->set_time(ui->timeEditTime->time());
        timers[indexOfTimer]->set_path_to_sound(ui->seletcSound->currentText());
        timers[indexOfTimer]->maxNumberOfSignals = ui->spinBoxNumber->value();
    }
    this->close();
}

void EditingTimer::on_btnCancel_clicked()
{
    this->close();
}

void EditingTimer::on_seletcSound_activated(const QString &arg1)
{
    QString soundPath = QDir::currentPath() + "/Sounds/timer" + arg1 + ".wav";
    QSound::play(soundPath);
}
