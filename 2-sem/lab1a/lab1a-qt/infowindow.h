#ifndef INFOWINDOW_H
#define INFOWINDOW_H

#include <QDialog>
#include <QIcon>

namespace Ui {
class InfoWindow;
}

class InfoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit InfoWindow(QWidget *parent = nullptr);
    ~InfoWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::InfoWindow *ui;
};

#endif // INFOWINDOW_H
