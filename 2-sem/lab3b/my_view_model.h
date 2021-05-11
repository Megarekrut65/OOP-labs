#ifndef MYCOLUMNVIEW_H
#define MYCOLUMNVIEW_H
#include <QStandardItemModel>
#include "Computer-network/message.h"
#include <QMap>

/*!
*   \brief Class to managment table view with messages data( cnm::Message )
*/
class MyViewModel
{
private:
    std::shared_ptr<QStandardItemModel> model;/*!< Pointer to model of view */
    QMap<QString,int> item_columns;/*!< Map to get column id by column name */
    /*!
    *   \brief Adds strings to view by row and colmn
    */
    void add_item_to_view(const QString& value, int row, int colmm);
    /*!
    *   \brief Edits message in view by row
    */
    void edit_items_in_view(const cnm::Message& message, int row);
    /*!
    *   \brief Sets header names
    */
    void set_header();
public:
    /*!
    *   \brief Adds model and set header
    *
    *   \param model - model of view
    */
    MyViewModel(std::shared_ptr<QStandardItemModel> model);
    /*!
    *   \brief Adds message to view
    *   \param message - message to add
    */
    void add_message(const cnm::Message& message);
    /*!
    *   \brief Clears view
    */
    void clear();
};

#endif // MYCOLUMNVIEW_H
