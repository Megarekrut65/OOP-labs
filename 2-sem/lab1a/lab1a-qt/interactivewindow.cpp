#include "interactivewindow.h"
#include "ui_interactivewindow.h"

InteractiveWindow::InteractiveWindow(QWidget *parent, std::shared_ptr<OpeningMode> open_mode) :
    QDialog(parent),
    ui(new Ui::InteractiveWindow),model(new QStandardItemModel)
{
    if(!open_mode) this->close();
    this->open_mode = open_mode;
    ui->setupUi(this);
    this->setWindowTitle("Menu");
    set_the_model();
    add_monster_to_table(get_monster());
}
void InteractiveWindow::set_the_model()
{
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    model->setHorizontalHeaderLabels({"ID", "Name","HP","Damage","Chance","Type of attack","Time and Data"});

}
InteractiveWindow::~InteractiveWindow()
{
    delete model;
    delete ui;
}
void InteractiveWindow::add_item_to_table(const QString& value, int row, int colmm)
{
    auto item = new QStandardItem;
    item->setText(value);
    model->setItem(row, colmm, item);
}
void InteractiveWindow::add_monster_to_table(std::shared_ptr<Monster> monster)
{
    int row_count = model->rowCount();
    model->insertRow(row_count);
    int i = 0;
    add_item_to_table(QString::number(monster->get_id()), row_count, i++);
    add_item_to_table(monster->get_name().c_str(), row_count, i++);
    add_item_to_table(QString::number(monster->get_hp()), row_count, i++);
    add_item_to_table(QString::number(monster->get_damage()), row_count, i++);
    add_item_to_table(QString::number(monster->get_chance()), row_count, i++);
    add_item_to_table(monster->string_type().substr(32).c_str(), row_count, i++);
    add_item_to_table(monster->string_time().substr(24).c_str(), row_count, i++);
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
