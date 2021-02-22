#include "infowindow.h"
#include "ui_infowindow.h"

InfoWindow::InfoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Info");
    QIcon icon("images/info.ico");
    this->setWindowIcon(icon);
}

InfoWindow::~InfoWindow()
{
    delete ui;
}

void InfoWindow::on_pushButton_clicked()
{
    this->hide();
}
