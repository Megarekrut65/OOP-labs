#ifndef MODELFUNCTIONS_H
#define MODELFUNCTIONS_H

#include <QStandardItemModel>
#include <memory>
#include "Code/monster.h"
#include <QTableView>

using namespace mon;
class ModelFunctions
{
private:
    static void add_item_to_table(QStandardItemModel* model,const QString& value, int row, int colmm);//adds value to table where row and colmn are indexes
    static void edit_items_in_table(QStandardItemModel* model, std::shared_ptr<Monster> monster, int row);//edits monster in line with index row
    static int find_row_of_monster(QStandardItemModel* model, std::shared_ptr<Monster> monster);//returns index of line where is the monster
public:
    static void add_monster_to_table(QStandardItemModel* model, std::shared_ptr<Monster> monster);//adds this monster to table
    static void edit_monster_in_table(QStandardItemModel* model, std::shared_ptr<Monster> monster);//replaces an existing monster with a transferred one
    static void delete_monster_from_table(QStandardItemModel* model, std::shared_ptr<Monster> monster);//deletes the monster
    static void set_the_model(QStandardItemModel* model, QTableView* table);//adds table to model and sets headers
};

#endif // MODELFUNCTIONS_H
