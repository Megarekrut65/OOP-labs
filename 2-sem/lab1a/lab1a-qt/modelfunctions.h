#ifndef MODELFUNCTIONS_H
#define MODELFUNCTIONS_H

#include <QStandardItemModel>
#include <memory>
#include "Code/monster.h"

using namespace mon;
class ModelFunctions
{
private:
    static void add_item_to_table(QStandardItemModel* model,const QString& value, int row, int colmm);
    static void edit_items_in_table(QStandardItemModel* model, std::shared_ptr<Monster> monster, int row);
    static int find_row_of_monster(QStandardItemModel* model, std::shared_ptr<Monster> monster);
public:
    static void add_monster_to_table(QStandardItemModel* model, std::shared_ptr<Monster> monster);
    static void edit_monster_in_table(QStandardItemModel* model, std::shared_ptr<Monster> monster);
    static void delete_monster_from_table(QStandardItemModel* model, std::shared_ptr<Monster> monster);
};

#endif // MODELFUNCTIONS_H
