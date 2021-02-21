#include "enteridwindow.h"
#include "ui_enteridwindow.h"

EnterIdWindow::EnterIdWindow(unsigned& id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnterIdWindow),id(id)
{
    ui->setupUi(this);
    this->setWindowTitle("Id");
}

EnterIdWindow::~EnterIdWindow()
{
    delete ui;
}

void EnterIdWindow::on_pushButtonOk_clicked()
{
    if(ui->spinBox->text().size() != 0)
    {
        id = ui->spinBox->value();
    }
    this->close();
}

void EnterIdWindow::on_pushButtonCancel_clicked()
{
    this->close();
}
