#include "interactivewindow.h"
#include "ui_interactivewindow.h"

InteractiveWindow::InteractiveWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InteractiveWindow)
{
    ui->setupUi(this);
}

InteractiveWindow::~InteractiveWindow()
{
    delete ui;
}
