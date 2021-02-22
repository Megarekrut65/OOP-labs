#include "findnamewindow.h"
#include "ui_findnamewindow.h"

FindNameWindow::FindNameWindow(QWidget *parent, std::shared_ptr<OpeningMode> open_mode) :
    QDialog(parent),
    ui(new Ui::FindNameWindow), open_mode(open_mode)
{
    ui->setupUi(this);
}

FindNameWindow::~FindNameWindow()
{
    delete ui;
}

void FindNameWindow::on_pushButton_2_clicked()
{

}

void FindNameWindow::on_pushButton_clicked()
{

}
