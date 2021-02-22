#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QDialog>
#include "mylibrary.h"
#include <QString>
#include <QMessageBox>
#include <QStandardItemModel>

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
    AttackTypes get_type();
    void edit_monster();
    void set_data();
    void add_monster();
    bool check_empty();
    bool is_empty();
};

#endif // ADDWINDOW_H
