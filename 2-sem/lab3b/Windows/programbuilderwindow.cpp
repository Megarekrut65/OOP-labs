#include "programbuilderwindow.h"
#include "ui_programbuilderwindow.h"

ProgramBuilderWindow::ProgramBuilderWindow(cn::ProgramRegistry& registry,
                                           std::shared_ptr<cn::BasicServer> server,
                                           bool& is_added,
                                           QString& program_name,
                                           QWidget *parent):
    QDialog(parent),
    ui(new Ui::ProgramBuilderWindow),
    registry(registry),is_added(is_added),program_name(program_name), server(server)
{
    ui->setupUi(this);
    if(!server) this->close();
    setWindowTitle("Create new Program");
    QIcon icon("Images/program-icon.ico");
    setWindowIcon(icon);
    set_sending_types();
    ui->radioButtonAll->setChecked(true);
    is_added = false;
}

ProgramBuilderWindow::~ProgramBuilderWindow()
{
    delete ui;
}
void ProgramBuilderWindow::set_sending_types()
{
    ui->comboBoxSendingType->addItems(registry.get_all_types());
    ui->comboBoxSendingType->activated(0);
}
cn::ProgramType ProgramBuilderWindow::get_type()
{
    if(ui->radioButtonSend->isChecked()) return cn::ProgramType::SEND;
    if(ui->radioButtonReceive->isChecked()) return cn::ProgramType::RECEIVE;
    return cn::ProgramType::BOTH;
}
QString ProgramBuilderWindow::get_name()
{
    return ui->lineEditName->text();
}
std::size_t ProgramBuilderWindow::get_period()
{
    return ui->spinBoxPeriod->value();
}
void ProgramBuilderWindow::on_pushButtonCreate_clicked()
{
    QString name = get_name();
    if(name.isEmpty())
    {
        AppMessages::error_message(this,"Incorrect data","Name cannot be empty!");
        return;
    }
    if(server->get_program(name))
    {
        AppMessages::error_message(this,"Incorrect data","The program "+name+" has already been created!");
        return;
    }
    server->add_program(name,
                        registry.create_by_prototype(
                            ui->comboBoxSendingType->currentText(),
                            ProgramInfo(server->get_name(), name),
                            get_type(),
                            get_period()));
    is_added = true;
    program_name = name;
    on_pushButtonCancel_clicked();
}

void ProgramBuilderWindow::on_pushButtonCancel_clicked()
{
    this->close();
}
