#ifndef FINDTYPETIMEWINDOW_H
#define FINDTYPETIMEWINDOW_H

#include <QDialog>
#include "mylibrary.h"
#include "showmonsters.h"
#include <QDateTime>
#include <QIcon>

namespace Ui {
class FindTypeTimeWindow;
}

class FindTypeTimeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FindTypeTimeWindow(std::shared_ptr<OpeningMode> open_mode, QWidget *parent = nullptr);
    ~FindTypeTimeWindow();

private slots:
    void on_pushButtonOK_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::FindTypeTimeWindow *ui;
    std::shared_ptr<OpeningMode> open_mode;
    AttackTypes get_type();//returns the type given the radio buttons
    std::vector<int> get_time();//creates array where items are data-time
};

#endif // FINDTYPETIMEWINDOW_H
