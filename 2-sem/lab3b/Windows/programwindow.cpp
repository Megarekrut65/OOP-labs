#include "programwindow.h"
#include "ui_programwindow.h"

ProgramWindow::ProgramWindow(std::shared_ptr<cn::BasicProgram> program,
                             QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgramWindow),program(program)
{
    ui->setupUi(this);
    if(!program) return;
    setWindowTitle("Program");
    QIcon icon("Images/program-window-icon.ico");
    setWindowIcon(icon);
    set_data();
}

ProgramWindow::~ProgramWindow()
{
    delete ui;
}
void ProgramWindow::set_data()
{
    ui->labelName->setText(program->get_info().program_name);
    ui->labelType->setText(cn::type_to_string(program->get_type()));
    ui->labelSendingType->setText(program->get_sending_type());
    ui->labelPeriod->setText(QString::number(program->get_period())+"ms");
}
void ProgramWindow::on_pushButtonUpdate_clicked()
{
    program->update();
}
