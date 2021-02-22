#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QDialog>
#include "mylibrary.h"
#include <QString>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QIcon>

namespace Ui {
class AddWindow;
}

class AddWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddWindow(QStandardItemModel* model,
                       std::shared_ptr<OpeningMode> open_mode,
                       std::shared_ptr<Monster> monster = nullptr,
                       bool edit = false,QWidget *parent = nullptr);
    ~AddWindow();

private slots:
    void on_pushButtonSave_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::AddWindow *ui;
    QStandardItemModel* model;
    std::shared_ptr<Monster> monster;
    std::shared_ptr<OpeningMode> open_mode;
    bool edit;
    AttackTypes get_type();//returns the type given the radio buttons
    void edit_monster();//puts to monster new data
    void set_data();//sets data of monster to items in window
    void add_monster();//adds new monster to table and model
    bool check_empty();//messeges about error if fields are empty
    bool is_empty();//checks the fields for emptiness
};

#endif // ADDWINDOW_H
