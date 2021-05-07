#ifndef PROGRAMBUILDERWINDOW_H
#define PROGRAMBUILDERWINDOW_H

#include <QDialog>

namespace Ui {
class ProgramBuilderWindow;
}

class ProgramBuilderWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ProgramBuilderWindow(QWidget *parent = nullptr);
    ~ProgramBuilderWindow();

private:
    Ui::ProgramBuilderWindow *ui;
};

#endif // PROGRAMBUILDERWINDOW_H
