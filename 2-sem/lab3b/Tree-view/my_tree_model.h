#ifndef MYTABLEMODEL_H
#define MYTABLEMODEL_H
#include <QStandardItemModel>
#include <memory>
#include "../Computer-network/servers.h"
#include <QString>
class MyTreeModel
{
private:
    std::shared_ptr<QStandardItemModel> model;
public:
    MyTreeModel(std::shared_ptr<QStandardItemModel> model);
    void add_server(const std::shared_ptr<cn::BasicServer> server);
    void add_program(const std::shared_ptr<cn::BasicProgram> program);
    void remove_server(const std::shared_ptr<cn::BasicServer> server);
    void remove_program(const std::shared_ptr<cn::BasicServer> server);
};

#endif // MYTABLEMODEL_H
