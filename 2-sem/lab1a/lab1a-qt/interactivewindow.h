#ifndef INTERACTIVEWINDOW_H
#define INTERACTIVEWINDOW_H

#include <QDialog>
#include "addwindow.h"
#include "enteridwindow.h"
#include <QStandardItemModel>
#include <QList>
#include "findmenuwindow.h"

namespace Ui {
class InteractiveWindow;
}

class InteractiveWindow : public QDialog
{
    Q_OBJECT

public:
    explicit InteractiveWindow(std::shared_ptr<OpeningMode> open_mode, QWidget *parent = nullptr);
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

    std::shared_ptr<Monster> get_monster();
};

#endif // INTERACTIVEWINDOW_H
