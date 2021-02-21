#ifndef INTERACTIVEWINDOW_H
#define INTERACTIVEWINDOW_H

#include <QDialog>
#include "addwindow.h"

namespace Ui {
class InteractiveWindow;
}

class InteractiveWindow : public QDialog
{
    Q_OBJECT

public:
    explicit InteractiveWindow(QWidget *parent = nullptr,
                               std::shared_ptr<OpeningMode> open_mode = nullptr);
    ~InteractiveWindow();

private slots:
    void on_pushButtonBack_clicked();

    void on_pushButtonAdd_clicked();

private:
    Ui::InteractiveWindow *ui;
    std::shared_ptr<OpeningMode> open_mode;
};

#endif // INTERACTIVEWINDOW_H
