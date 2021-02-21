#include "interactivewindow.h"
#include "ui_interactivewindow.h"

InteractiveWindow::InteractiveWindow(QWidget *parent, std::shared_ptr<OpeningMode> open_mode) :
    QDialog(parent),
    ui(new Ui::InteractiveWindow)
{
    if(!open_mode) this->close();
    this->open_mode = open_mode;
    ui->setupUi(this);
}

InteractiveWindow::~InteractiveWindow()
{
    delete ui;
}

void InteractiveWindow::on_pushButtonBack_clicked()
{
    this->close();
}

void InteractiveWindow::on_pushButtonAdd_clicked()
{
    std::shared_ptr<mon::Monster> monster = nullptr;
    AddWindow add(this, open_mode, monster);
    add.setModal(true);
    add.exec();
}
