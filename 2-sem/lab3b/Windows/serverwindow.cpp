#include "serverwindow.h"
#include "ui_serverwindow.h"

ServerWindow::ServerWindow(QString& server_name,bool& is_added,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServerWindow), server_name(server_name), is_added(is_added)
{
    ui->setupUi(this);
    is_added = false;
    server_name = "";
    setWindowTitle("Create server");
    QIcon icon("Images/server-window-icon.ico");
    setWindowIcon(icon);
    ui->lineEditName->setFocus();
}

ServerWindow::~ServerWindow()
{
    delete ui;
}

void ServerWindow::on_pushButtonCreate_clicked()
{
    server_name = ui->lineEditName->text();
    if(server_name.isEmpty())
    {
        AppMessages::error_message(this,"Incorrect data","Name cannot be empty!");
        return;
    }
    if(cnm::Servers::get_server(server_name))
    {
        AppMessages::error_message(this,"Incorrect data","The server "+
                                   server_name+
                                   " has already been created!");
        return;
    }
    cnm::Servers::add_server(
                std::make_shared<cnm::BasicServer>(
                    server_name,
                    cnm::Speed(
                        ui->spinBoxUpload->value(),
                        ui->spinBoxDownload->value()
                        )));
    is_added = true;
    this->close();
}

void ServerWindow::on_pushButtonCancel_clicked()
{
    this->close();
}
