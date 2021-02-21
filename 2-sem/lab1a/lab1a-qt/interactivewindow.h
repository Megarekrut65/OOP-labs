#ifndef INTERACTIVEWINDOW_H
#define INTERACTIVEWINDOW_H

#include <QDialog>

namespace Ui {
class InteractiveWindow;
}

class InteractiveWindow : public QDialog
{
    Q_OBJECT

public:
    explicit InteractiveWindow(QWidget *parent = nullptr);
    ~InteractiveWindow();

private:
    Ui::InteractiveWindow *ui;
};

#endif // INTERACTIVEWINDOW_H
