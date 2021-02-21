#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "infowindow.h"
#include "Code/memory_opening_mode.h"
#include "Code/file_opening_mode.h"

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
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButtonMemory_clicked();

    void on_pushButtonText_clicked();

    void on_pushButtonBinary_clicked();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<InfoWindow> info;
    std::shared_ptr<om::OpeningMode> open_mode;
    std::string text_path;
    std::string binary_path;
};
#endif // MAINWINDOW_H
