#include "findhpdamagewindow.h"
#include "ui_findhpdamagewindow.h"

FindHPDamageWindow::FindHPDamageWindow(std::shared_ptr<OpeningMode> open_mode, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindHPDamageWindow), open_mode(open_mode)
{
    ui->setupUi(this);
    this->setWindowTitle("Find by hp and damage");
    if(!open_mode) this->close();
    QIcon icon("images/find.ico");
    this->setWindowIcon(icon);
}

FindHPDamageWindow::~FindHPDamageWindow()
{
    delete ui;
}

void FindHPDamageWindow::on_pushButtonOK_clicked()
{
    if(ui->spinBoxHP->text().size() != 0 && ui->spinBoxDamage->text().size() != 0)
    {
        ShowMonsters show(open_mode->find_hp_damage(ui->spinBoxHP->value(),
                                                    ui->spinBoxDamage->value()));
        show.setModal(true);
        this->hide();
        show.exec();
        this->close();
    }
    else MyMessage::error_message(this, "Error", "There is empty field!");
}

void FindHPDamageWindow::on_pushButtonCancel_clicked()
{
    this->close();
}
