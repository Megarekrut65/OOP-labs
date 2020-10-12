#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "mytimer.h"
#include <QKeyEvent>
#include <QStringListModel>
#include "addingtimer.h"
#include "showtimer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addNewTimer(MyTimer* newTimer);
private slots:

    void on_btnStartAll_clicked();

    void on_btnPauseAll_clicked();

    void on_btnAdd_clicked();

private:
    Ui::MainWindow *ui;
    QStringListModel *model;
    QTimer *oneSecondTimer;
    QVector<MyTimer*> timers;
    ShowTimer timerWindow;
    void startHeaderTimer();
    void updateAllTimers();
};
#endif // MAINWINDOW_H
