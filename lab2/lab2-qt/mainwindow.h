#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "mytimer.h"
#include <QStandardItemModel>
#include "addingtimer.h"
#include "showtimer.h"
#include "my_colors.h"
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void on_btnStartAll_clicked();

    void on_btnPauseAll_clicked();

    void on_btnAdd_clicked();

    void on_listTimers_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    QTimer *oneSecondTimer;
    QVector<MyTimer*> timers;
    ShowTimer* timerWindow;
    bool AllActive;
    const QString filePath;
    QString statusBar;
    QString fileModel;
    void start_header_timer();
    void update_all_timers();
    void read_all_timers_from_file();
    void write_all_timers_to_file();
};
#endif // MAINWINDOW_H
