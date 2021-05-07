#ifndef PROGRAMWINDOW_H
#define PROGRAMWINDOW_H

#include <QDialog>
#include "../Computer-network/servers.h"
#include <QTimer>

namespace Ui {
class ProgramWindow;
}

class ProgramWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ProgramWindow(std::shared_ptr<cn::BasicProgram> program, QWidget *parent = nullptr);
    ~ProgramWindow();

private slots:
    void on_pushButtonUpdate_clicked();

private:
    Ui::ProgramWindow *ui;
    std::shared_ptr<cn::BasicProgram> program;
    std::shared_ptr<QTimer> timer;
    void set_data();
    void set_timer();
};

#endif // PROGRAMWINDOW_H
