#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "mytimer.h"
#include "showtimer.h"
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /*void addNewTimer(QString name, QTime time);
    void editTheTimer(QString name, QTime time);*/
private slots:

    void on_btnStartAll_clicked();

    void on_btnPauseAll_clicked();

    void on_btnAdd_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *oneSecondTimer;
    QVector<MyTimer*> timers;
    void startTheTimer();
    void updateAllTimers();
    void moveTimer();
    void showTimer(bool show);
    void addEmptyTimer();
};
#endif // MAINWINDOW_H
