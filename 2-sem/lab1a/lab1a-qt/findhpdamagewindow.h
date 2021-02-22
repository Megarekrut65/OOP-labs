#ifndef FINDHPDAMAGEWINDOW_H
#define FINDHPDAMAGEWINDOW_H

#include <QDialog>
#include "mylibrary.h"
#include "showmonsters.h"
#include <QIcon>

namespace Ui {
class FindHPDamageWindow;
}

class FindHPDamageWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FindHPDamageWindow(std::shared_ptr<OpeningMode> open_mode, QWidget *parent = nullptr);
    ~FindHPDamageWindow();

private slots:
    void on_pushButtonOK_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::FindHPDamageWindow *ui;
    std::shared_ptr<OpeningMode> open_mode;
};

#endif // FINDHPDAMAGEWINDOW_H
