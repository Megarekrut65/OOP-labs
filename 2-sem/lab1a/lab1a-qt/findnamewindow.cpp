#include "findnamewindow.h"
#include "ui_findnamewindow.h"

FindNameWindow::FindNameWindow(std::shared_ptr<OpeningMode> open_mode, QWidget *parent ) :
    QDialog(parent),
    ui(new Ui::FindNameWindow), open_mode(open_mode)
{
    ui->setupUi(this);
    this->setWindowTitle("Find by name");
    if(!open_mode) this->close();
    QIcon icon("images/find.ico");
    this->setWindowIcon(icon);
}

FindNameWindow::~FindNameWindow()
{
    delete ui;
}
void FindNameWindow::on_pushButtonOK_clicked()
{
    if(ui->lineEdit->text().size() == 0)
        MyMessage::error_message(this, "Error", "There is empty field!");
    else
    {
        ShowMonsters show(open_mode->find_name(ui->lineEdit->text().toStdString()));
        show.setModal(true);
        this->hide();
        show.exec();
        this->close();
    }
}

void FindNameWindow::on_pushButtonCancel_clicked()
{
    this->close();
}
