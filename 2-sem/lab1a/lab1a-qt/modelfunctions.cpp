#include "modelfunctions.h"

void ModelFunctions::add_item_to_table(QStandardItemModel* model,const QString& value, int row, int colmm)
{
    auto item = new QStandardItem;
    item->setText(value);
    model->setItem(row, colmm, item);
}
void ModelFunctions::edit_items_in_table(QStandardItemModel* model, std::shared_ptr<Monster> monster, int row)
{
    int i = 0;
    add_item_to_table(model, QString::number(monster->get_id()), row, i++);
    add_item_to_table(model,monster->get_name().c_str(), row, i++);
    add_item_to_table(model,QString::number(monster->get_hp()), row, i++);
    add_item_to_table(model,QString::number(monster->get_damage()), row, i++);
    add_item_to_table(model,QString::number(monster->get_chance()), row, i++);
    add_item_to_table(model,monster->string_type().substr(32).c_str(), row, i++);
    add_item_to_table(model,monster->string_time().substr(24).c_str(), row, i++);
}
void ModelFunctions::add_monster_to_table(QStandardItemModel* model, std::shared_ptr<Monster> monster)
{
    if(!monster) return;
    int row_count = model->rowCount();
    model->insertRow(row_count);
    edit_items_in_table(model, monster, row_count);
}
int ModelFunctions::find_row_of_monster(QStandardItemModel* model, std::shared_ptr<Monster> monster)
{
    for(int i = 0; i < model->rowCount(); i++)
    {
        QModelIndex index = model->index(i,0);
        if(index.data() == QString::number(monster->get_id()))
            return i;
    }
    return -1;
}
void ModelFunctions::edit_monster_in_table(QStandardItemModel* model, std::shared_ptr<Monster> monster)
{
    int row = find_row_of_monster(model, monster);
    if(row >= 0) edit_items_in_table(model, monster, row);
}
void ModelFunctions::delete_monster_from_table(QStandardItemModel* model, std::shared_ptr<Monster> monster)
{
    model->removeRow(find_row_of_monster(model, monster));
}
void ModelFunctions::set_the_model(QStandardItemModel* model, QTableView* table)
{
    table->setModel(model);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    model->setHorizontalHeaderLabels({"ID", "Name","HP","Damage","Chance","Type of attack","Time and Data"});

}
