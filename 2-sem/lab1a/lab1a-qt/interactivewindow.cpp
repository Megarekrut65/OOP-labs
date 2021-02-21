#include "interactivewindow.h"
#include "ui_interactivewindow.h"

InteractiveWindow::InteractiveWindow(QWidget *parent, std::shared_ptr<OpeningMode> open_mode) :
    QDialog(parent),
    ui(new Ui::InteractiveWindow)
{
    if(!open_mode) this->close();
    this->open_mode = open_mode;
    ui->setupUi(this);
    this->setWindowTitle("Menu");
}

InteractiveWindow::~InteractiveWindow()
{
    delete ui;
}

void InteractiveWindow::on_pushButtonBack_clicked()
{
    this->close();
}

void InteractiveWindow::on_pushButtonAdd_clicked()
{
    std::shared_ptr<mon::Monster> monster = nullptr;
    AddWindow add(this, open_mode, monster);
    add.setModal(true);
    add.exec();
}
std::shared_ptr<Monster> InteractiveWindow::get_monster()
{
    unsigned id = 1000;
    EnterIdWindow enter_id(id);
    enter_id.setModal(true);
    enter_id.exec();
    std::shared_ptr<mon::Monster> monster = std::make_shared<Monster>(open_mode->get_monster(id));
    if(monster->get_id() != 0)
    {
        return monster;
    }
    QMessageBox messageBox;
    messageBox.critical(0,"Error","There isn't monster with entered id!");
    messageBox.setFixedSize(500,200);
    return nullptr;
}
void InteractiveWindow::on_pushButtonEdit_clicked()
{
    std::shared_ptr<Monster> monster = get_monster();
    if(monster)
    {
        AddWindow add(this, open_mode, monster, true);
        add.setModal(true);
        add.exec();
        //need edit in table
    }
}

void InteractiveWindow::on_pushButtonDelete_clicked()
{
    std::shared_ptr<Monster> monster = get_monster();
    if(monster)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this,
                                      "Delete the monster",
                                      ("Are you sure you want to delete " + monster->get_name()).c_str(),
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) open_mode->delete_the_monster(*monster);
    }
}

void InteractiveWindow::on_pushButtonFind_clicked()
{

}
