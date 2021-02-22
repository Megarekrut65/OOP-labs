#ifndef FINDNAMEWINDOW_H
#define FINDNAMEWINDOW_H

#include <QDialog>
#include "mylibrary.h"

namespace Ui {
class FindNameWindow;
}

class FindNameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FindNameWindow(QWidget *parent = nullptr,
                            std::shared_ptr<OpeningMode> open_mode = nullptr);
    ~FindNameWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::FindNameWindow *ui;
    std::shared_ptr<OpeningMode> open_mode;
};

#endif // FINDNAMEWINDOW_H
