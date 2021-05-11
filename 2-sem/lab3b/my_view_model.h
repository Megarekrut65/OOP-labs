#ifndef MYCOLUMNVIEW_H
#define MYCOLUMNVIEW_H
#include <QStandardItemModel>
#include "Computer-network/message.h"
#include <QMap>

/*!
*   \brief
*/
class MyViewModel
{
private:
    std::shared_ptr<QStandardItemModel> model;/*!< */
    QMap<QString,int> item_columns;/*!< */

    void add_item_to_view(const QString& value, int row, int colmm);
    void edit_items_in_view(const cnet::Message& message, int row);
    void set_header();
public:
    MyViewModel(std::shared_ptr<QStandardItemModel> model);
    void add_message(const cnet::Message& message);
    void clear();
};

#endif // MYCOLUMNVIEW_H
