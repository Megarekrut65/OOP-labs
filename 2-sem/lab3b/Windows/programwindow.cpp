#include "programwindow.h"
#include "ui_programwindow.h"

ProgramWindow::ProgramWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgramWindow)
{
    ui->setupUi(this);
    setWindowTitle("Program");
    QIcon icon("Images/program-window-icon.ico");
    setWindowIcon(icon);
}

ProgramWindow::~ProgramWindow()
{
    delete ui;
}

void ProgramWindow::on_pushButtonUpdate_clicked()
{

}
