#ifndef MYTABLEMODEL_H
#define MYTABLEMODEL_H
#include <QStandardItemModel>
#include <memory>
#include <iostream>
#include <QString>
class MyTreeModel
{
private:
    std::shared_ptr<QStandardItemModel> model;
public:
    MyTreeModel();

};

#endif // MYTABLEMODEL_H
