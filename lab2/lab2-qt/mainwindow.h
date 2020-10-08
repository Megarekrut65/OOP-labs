#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MyTime
{
private:
    int hour;
    int min;
    int sec;
    QString makeCorrect(int value);
public:
    MyTime();
    MyTime(int hour, int min, int sec);
    MyTime(QString stringTime);
    bool minusOne();
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
    void startTheTimer();
    void updateAllTimers();
};
#endif // MAINWINDOW_H
