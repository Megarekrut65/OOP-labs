#include "addingtimer.h"
#include "ui_addingtimer.h"

AddingTimer::AddingTimer(QVector<MyTimer*>* timers,
                         QStandardItemModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddingTimer), timers(timers), model(model)
{
    ui->setupUi(this);
    add_sounds();
}

AddingTimer::~AddingTimer()
{
    timers = nullptr;
    model = nullptr;
    delete ui;
}
void  AddingTimer::add_sounds()
{
    for(int i = 0; i < MySounds::sounds.size(); i++)
    {
         ui->seletcSound->addItem(MySounds::sounds[i]);
    }
}
Type AddingTimer::set_type()
{
    if(ui->radioButtonTimer->isChecked()) return Type::TIMER;
    else if(ui->radioButtonAlarm->isChecked()) return Type::AlARM_ClOCK;

    return Type::TIMER;
}
void AddingTimer::on_btnCreate_clicked()
{
    if(timers && model)
    {
        QString name = ui->lineAddName->text();
        QTime* time = new QTime(ui->timeAdd->time());
        Type type = set_type();
        int maxNumberOfSignals = ui->spinBoxNumber->value();
        QString soundName = ui->seletcSound->currentText();
        MyTimer* timer = new MyTimer(name, time, type, maxNumberOfSignals, soundName);
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

void AddingTimer::on_seletcSound_activated(const QString &arg1)
{
    QString soundPath = QDir::currentPath() + "/Sounds/timer" + arg1 + ".wav";
    QSound::play(soundPath);
}
