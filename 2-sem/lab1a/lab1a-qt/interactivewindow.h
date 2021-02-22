#ifndef INTERACTIVEWINDOW_H
#define INTERACTIVEWINDOW_H

#include <QDialog>
#include "addwindow.h"
#include "enteridwindow.h"
#include <QStandardItemModel>
#include <QString>
#include "findmenuwindow.h"
#include <QIcon>

namespace Ui {
class InteractiveWindow;
}

class InteractiveWindow : public QDialog
{
    Q_OBJECT

public:
    explicit InteractiveWindow(std::shared_ptr<OpeningMode> open_mode, QString name_mode, QWidget *parent = nullptr);
    ~InteractiveWindow();

private slots:
    void on_pushButtonBack_clicked();

    void on_pushButtonAdd_clicked();

    void on_pushButtonEdit_clicked();

    void on_pushButtonDelete_clicked();

    void on_pushButtonFind_clicked();


private:
    Ui::InteractiveWindow *ui;
    std::shared_ptr<OpeningMode> open_mode;
    QStandardItemModel* model;

    std::shared_ptr<Monster> get_monster();//returns the monsters with edtered id
    void add_all_monsters_to_table();//adds monsters to table view
};

#endif // INTERACTIVEWINDOW_H
