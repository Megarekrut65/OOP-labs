#include "editingandaddingtimers.h"
#include "ui_editingandaddingtimers.h"

EditingAndAddingTimers::EditingAndAddingTimers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditingAndAddingTimers)
{
    ui->setupUi(this);
    mainWindow = nullptr;
}

EditingAndAddingTimers::~EditingAndAddingTimers()
{
    mainWindow = nullptr;
    delete ui;
}
void EditingAndAddingTimers::editTimer(MyTimer* timer, MainWindow* window)
{
    mainWindow = window;
    ui->btnCreate->setText("Save");
    ui->labelAdd->setText("Edit the timer");
    timer->turnOff();
    ui->timeEditAdd->setTime(timer->getTime());
    ui->lineEditNameTimer->setText(timer->name);
}
void EditingAndAddingTimers::addTimer(MainWindow* window)
{
    mainWindow = window;
    ui->btnCreate->setText("Create");
    ui->labelAdd->setText("Add new timer");
    ui->timeEditAdd->setTime(QTime(0,0,0));
    ui->lineEditNameTimer->setText("Enter name of timer...");
}

void EditingAndAddingTimers::on_btnCreate_clicked()
{
    QString name = ui->lineEditNameTimer->text();
    QTime time = ui->timeEditAdd->time();
    if(ui->btnCreate->text() == "Create")
    {
        if(mainWindow) mainWindow->addNewTimer(name, time);
    }
    else if(ui->btnCreate->text() == "Save")
    {
         if(mainWindow) mainWindow->editTheTimer(name, time);
    }
    this->close();
}

void EditingAndAddingTimers::on_btnCancel_clicked()
{
    this->close();
}
