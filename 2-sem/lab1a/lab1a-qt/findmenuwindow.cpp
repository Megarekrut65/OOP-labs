#include "findmenuwindow.h"
#include "ui_findmenuwindow.h"

FindMenuWindow::FindMenuWindow(std::shared_ptr<OpeningMode> open_mode, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindMenuWindow), open_mode(open_mode)
{
    ui->setupUi(this);
    this->setWindowTitle("Find menu");
    if(!open_mode) this->close();
    QIcon icon("images/find.ico");
    this->setWindowIcon(icon);
}

FindMenuWindow::~FindMenuWindow()
{
    delete ui;
}

void FindMenuWindow::on_pushButtonName_clicked()
{
    FindNameWindow find(open_mode);
    find.setModal(true);
    this->hide();
    find.exec();
    this->close();
}

void FindMenuWindow::on_pushButtonHp_clicked()
{
    FindHPDamageWindow find(open_mode);
    find.setModal(true);
    this->hide();
    find.exec();
    this->close();
}

void FindMenuWindow::on_pushButtonType_clicked()
{
    FindTypeTimeWindow find(open_mode);
    find.setModal(true);
    this->hide();
    find.exec();
    this->close();
}

void FindMenuWindow::on_pushButtonClose_clicked()
{
    this->close();
}
