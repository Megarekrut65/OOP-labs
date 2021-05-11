#include "my_view_model.h"

MyViewModel::MyViewModel(std::shared_ptr<QStandardItemModel> model):model{model}
{
    if(model)
    {
        set_header();
    }
}
void MyViewModel::set_header()
{
    QStringList list = {"Message type", "Date","Time","Sender","Size","Text"};
    model->insertColumns(0, list.size());
    for(int i = 0; i < list.size(); i++)
    {
        item_columns[list[i]] = i;
        model->setHeaderData(i,Qt::Horizontal,QObject::tr(list[i].toStdString().c_str()));
    }
}
void MyViewModel::add_message(const cn::Message& message)
{
    if(!model) return;
    int row_count = model->rowCount();
    model->insertRow(row_count);
    edit_items_in_view(message, row_count);
}
void MyViewModel::clear()
{
    if(model)
    {
        model->clear();
        set_header();
    }
}
void MyViewModel::add_item_to_view(const QString& value, int row, int colmm)
{
    auto item = new QStandardItem();
    item->setText(value);
    model->setItem(row, colmm, item);
}
void MyViewModel::edit_items_in_view(const cn::Message& message, int row)
{
    add_item_to_view(message.get_sender_info().get_string(), row, item_columns["Sender"]);
    add_item_to_view(cn::size_to_qstring(message.get_message_size()), row, item_columns["Size"]);
    add_item_to_view(message_type_to_qstring(message.get_message_type()), row, item_columns["Message type"]);
    QDateTime date_time = QDateTime::fromString(message.get_creating_time(), cn::get_date_time_format());
    add_item_to_view(date_time.date().toString("yyyy-MM-dd"), row, item_columns["Date"]);
    add_item_to_view(date_time.time().toString("HH:mm:ss"), row, item_columns["Time"]);
    add_item_to_view(message.get_text(), row, item_columns["Text"]);
}
