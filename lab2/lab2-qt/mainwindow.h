#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MyTimer
{
private:
    bool active;
    int hour;
    int min;
    int sec;
    QString makeCorrect(int value);
public:
    MyTimer();
    MyTimer(int hour, int min, int sec);
    MyTimer(QString stringTime);
    void setTime(int hour, int min, int sec);
    void addTime(int sec);
    void updateTime();
    QString getQString();
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnTimer_clicked();

private:
    Ui::MainWindow *ui;
    QVector<MyTimer> timers;
    int indexOfCurrentTimer;
    void startTheTimer();
    void updateAllTimers();
};
#endif // MAINWINDOW_H
