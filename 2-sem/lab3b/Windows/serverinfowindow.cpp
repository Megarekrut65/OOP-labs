#include "serverinfowindow.h"
#include "ui_serverinfowindow.h"

ServerInfoWindow::ServerInfoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServerInfoWindow)
{
    ui->setupUi(this);
    QIcon icon("Images/server-window-icon.ico");
    setWindowIcon(icon);
}

ServerInfoWindow::~ServerInfoWindow()
{
    delete ui;
}
void ServerInfoWindow::set_data(std::shared_ptr<cnet::BasicServer> server)
{
    setWindowTitle(server->get_name());
    ui->labelName->setText(server->get_name());
    ui->labelUpload->setText(QString::number(server->get_speed().upload)+" bit/s");
    ui->labelDownload->setText(QString::number(server->get_speed().download)+" bit/s");
}

void ServerInfoWindow::on_pushButton_clicked()
{
    this->hide();
}
