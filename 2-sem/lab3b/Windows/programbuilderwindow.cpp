#include "programbuilderwindow.h"
#include "ui_programbuilderwindow.h"

ProgramBuilderWindow::ProgramBuilderWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgramBuilderWindow)
{
    ui->setupUi(this);
    setWindowTitle("Create new Program");
    QIcon icon("Images/program-icon.ico");
    setWindowIcon(icon);
}

ProgramBuilderWindow::~ProgramBuilderWindow()
{
    delete ui;
}
