#ifndef FINDMENUWINDOW_H
#define FINDMENUWINDOW_H

#include <QDialog>
#include "findnamewindow.h"
#include "findhpdamagewindow.h"
#include "findtypetimewindow.h"
#include "mylibrary.h"
#include <QIcon>

namespace Ui {
class FindMenuWindow;
}

class FindMenuWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FindMenuWindow(std::shared_ptr<OpeningMode> open_mode, QWidget *parent = nullptr);
    ~FindMenuWindow();

private slots:
    void on_pushButtonName_clicked();

    void on_pushButtonHp_clicked();

    void on_pushButtonType_clicked();

    void on_pushButtonClose_clicked();

private:
    Ui::FindMenuWindow *ui;
    std::shared_ptr<OpeningMode> open_mode;
};

#endif // FINDMENUWINDOW_H
