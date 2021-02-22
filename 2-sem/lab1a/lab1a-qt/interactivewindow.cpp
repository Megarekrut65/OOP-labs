#include "interactivewindow.h"
#include "ui_interactivewindow.h"

InteractiveWindow::InteractiveWindow(std::shared_ptr<OpeningMode> open_mode, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InteractiveWindow),model(new QStandardItemModel)
{
    if(!open_mode) this->close();
    this->open_mode = open_mode;
    ui->setupUi(this);
    this->setWindowTitle("Menu");
    ModelFunctions::set_the_model(model, ui->tableView);
}
InteractiveWindow::~InteractiveWindow()
{
    delete model;
    delete ui;
}


void InteractiveWindow::on_pushButtonBack_clicked()
{
    this->close();
}

void InteractiveWindow::on_pushButtonAdd_clicked()
{
    AddWindow add(this, model, open_mode);
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
        AddWindow add(this, model, open_mode, monster, true);
        add.setModal(true);
        add.exec();
    }
}

void InteractiveWindow::on_pushButtonDelete_clicked()
{
    std::shared_ptr<Monster> monster = get_monster();
    if(monster)
    {
        if(MyMessage::question_message(this,
                                    "Delete the monster",
                                    ("Are you sure you want to delete " + monster->get_name()).c_str()))
        {
            open_mode->delete_the_monster(*monster);
            ModelFunctions::delete_monster_from_table(model, monster);
        }
    }
}

void InteractiveWindow::on_pushButtonFind_clicked()
{
    FindMenuWindow find(open_mode);
    find.setModal(true);
    find.exec();
}
