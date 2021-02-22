#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mylibrary.h"
#include "infowindow.h"
#include "interactivewindow.h"
#include <QIcon>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
using namespace mmode;
using namespace fmode;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_pushButtonMemory_clicked();

    void on_pushButtonText_clicked();

    void on_pushButtonBinary_clicked();

    void on_actionInfo_triggered();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<InfoWindow> info;
    std::shared_ptr<om::OpeningMode> open_mode;
    QString name_mode;
    std::string text_path;
    std::string binary_path;

    void open_interactive_mode();
};
#endif // MAINWINDOW_H
