#ifndef FINDNAMEWINDOW_H
#define FINDNAMEWINDOW_H

#include <QDialog>
#include "mylibrary.h"
#include "showmonsters.h"
#include <QIcon>

namespace Ui {
class FindNameWindow;
}

class FindNameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FindNameWindow(std::shared_ptr<OpeningMode> open_mode, QWidget *parent = nullptr);
    ~FindNameWindow();

private slots:

    void on_pushButtonOK_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::FindNameWindow *ui;
    std::shared_ptr<OpeningMode> open_mode;
};

#endif // FINDNAMEWINDOW_H
