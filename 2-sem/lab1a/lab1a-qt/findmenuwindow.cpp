#include "findmenuwindow.h"
#include "ui_findmenuwindow.h"

FindMenuWindow::FindMenuWindow(std::shared_ptr<OpeningMode> open_mode, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindMenuWindow), open_mode(open_mode)
{
    ui->setupUi(this);
    this->setWindowTitle("Find menu");
}

FindMenuWindow::~FindMenuWindow()
{
    delete ui;
}

void FindMenuWindow::on_pushButtonName_clicked()
{
    FindNameWindow find(open_mode);
    find.setModal(true);
    find.exec();
    this->close();
}

void FindMenuWindow::on_pushButtonHp_clicked()
{

}

void FindMenuWindow::on_pushButtonType_clicked()
{

}

void FindMenuWindow::on_pushButtonClose_clicked()
{
    this->close();
}
