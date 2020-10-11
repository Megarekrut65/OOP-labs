#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMessageBox>
#include <QAbstractButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MyTimer
{
private:
    bool active;
    QTime* time;
    QString makeCorrect(int value);
public:
    QString name;
    MyTimer();
    MyTimer( const QString& name,  QTime time);
    MyTimer( const QString& name, const QString& stringTime);
    void setTime( QTime time);
    QTime getTime();
    void addTime(int sec);
    void updateTime();
    QString getQStringTime();
    void turnOn();
    void turnOff();
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnTimer_clicked();

    void on_btnRight_clicked();

    void on_btnLeft_clicked();

    void on_btnStart_clicked();

    void on_btnPause_clicked();

    void on_btnCreate_clicked();

    void on_btnCancel_clicked();

    void on_btnEdit_clicked();

    void on_btnDelete_clicked();

private:
    Ui::MainWindow *ui;
    QVector<MyTimer> timers;
    int indexOfCurrentTimer;
    bool isShowed;
    void startTheTimer();
    void updateAllTimers();
    void moveTimer();
    void showTimer(bool show);
    void addNewTimer();
    void editTheTimer();
    void addEmptyTimer();
};
#endif // MAINWINDOW_H
