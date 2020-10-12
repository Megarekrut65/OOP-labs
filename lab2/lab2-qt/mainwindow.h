#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "mytimer.h"
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
private slots:

    void on_btnStartAll_clicked();

    void on_btnPauseAll_clicked();

    void on_btnAdd_clicked();

    void on_listTimers_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QStringListModel *model;
    QTimer *oneSecondTimer;
    QVector<MyTimer*> timers;
    ShowTimer* timerWindow;
    bool AllActive;
    void startHeaderTimer();
    void updateAllTimers();
};
#endif // MAINWINDOW_H
