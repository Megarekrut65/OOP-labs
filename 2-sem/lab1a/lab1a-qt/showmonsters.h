#ifndef SHOWMONSTERS_H
#define SHOWMONSTERS_H

#include <QDialog>
#include "mylibrary.h"
#include <QStandardItemModel>

namespace Ui {
class ShowMonsters;
}

class ShowMonsters : public QDialog
{
    Q_OBJECT

public:
    explicit ShowMonsters(std::vector<std::shared_ptr<Monster>> monsters, QWidget *parent = nullptr);
    ~ShowMonsters();

private slots:
    void on_pushButtonClose_clicked();

private:
    Ui::ShowMonsters *ui;
    QStandardItemModel* model;
};

#endif // SHOWMONSTERS_H
