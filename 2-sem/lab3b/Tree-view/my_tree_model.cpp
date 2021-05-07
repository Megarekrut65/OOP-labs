#include "my_tree_model.h"

MyTreeModel::MyTreeModel(std::shared_ptr<QStandardItemModel> model):model{model}
{
    model->setHeaderData(0,Qt::Horizontal,"Servers");
}
void MyTreeModel::add_server(const std::shared_ptr<cn::BasicServer> server)
{

}
void MyTreeModel::add_program(const std::shared_ptr<cn::BasicProgram> program)
{

}
void MyTreeModel::remove_server(const std::shared_ptr<cn::BasicServer> server)
{

}
void MyTreeModel::remove_program(const std::shared_ptr<cn::BasicServer> server)
{

}
