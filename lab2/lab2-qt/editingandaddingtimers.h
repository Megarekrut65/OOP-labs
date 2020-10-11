#ifndef EDITINGANDADDINGTIMERS_H
#define EDITINGANDADDINGTIMERS_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class EditingAndAddingTimers;
}

class EditingAndAddingTimers : public QDialog
{
    Q_OBJECT

public:
    explicit EditingAndAddingTimers(QWidget *parent = nullptr);
    ~EditingAndAddingTimers();
    void editTimer(MyTimer* timer, MainWindow* window);
    void addTimer(MainWindow* window);
private slots:
    void on_btnCreate_clicked();

    void on_btnCancel_clicked();

private:
    Ui::EditingAndAddingTimers *ui;
    MainWindow* mainWindow;
};

#endif // EDITINGANDADDINGTIMERS_H
