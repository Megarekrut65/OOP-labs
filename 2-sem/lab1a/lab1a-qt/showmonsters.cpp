#include "showmonsters.h"
#include "ui_showmonsters.h"

ShowMonsters::ShowMonsters(std::vector<std::shared_ptr<Monster>> monsters, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowMonsters), model(new QStandardItemModel)
{
    ui->setupUi(this);
    this->setWindowTitle("Monsters");
    ModelFunctions::set_the_model(model, ui->tableView);
    for(std::size_t i = 0; i < monsters.size(); i++)
        ModelFunctions::add_monster_to_table(model, monsters[i]);
}

ShowMonsters::~ShowMonsters()
{
    delete model;
    delete ui;
}

void ShowMonsters::on_pushButtonClose_clicked()
{
    this->close();
}
