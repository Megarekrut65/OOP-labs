#ifndef ENTERIDWINDOW_H
#define ENTERIDWINDOW_H

#include <QDialog>

namespace Ui {
class EnterIdWindow;
}

class EnterIdWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EnterIdWindow(unsigned& id, QWidget *parent = nullptr);
    ~EnterIdWindow();

private slots:
    void on_pushButtonOk_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::EnterIdWindow *ui;
    unsigned& id;
};

#endif // ENTERIDWINDOW_H
