#ifndef PROGRAMWINDOW_H
#define PROGRAMWINDOW_H

#include <QDialog>
#include "../Computer-network/servers.h"
namespace Ui {
class ProgramWindow;
}

class ProgramWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ProgramWindow(QWidget *parent = nullptr);
    ~ProgramWindow();

private slots:
    void on_pushButtonUpdate_clicked();

private:
    Ui::ProgramWindow *ui;
};

#endif // PROGRAMWINDOW_H
