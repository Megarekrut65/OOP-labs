#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startTheTimer();
}

MainWindow::~MainWindow()
{
    delete ui;
}
MyTime:: MyTime():hour(0), min(0), sec(0) {}
MyTime:: MyTime(int hour, int min, int sec):hour(hour), min(min), sec(sec) {}
MyTime:: MyTime(QString stringTime)
{
    QStringList parts = stringTime.split(":");
    if(parts.size() == 3)
    {
        hour = parts[0].toInt();
        min =  parts[1].toInt();
        sec = parts[2].toInt();
    }
    else
    {
         hour = 0;
         min = 0;
         sec = 0;
    }
}
void MainWindow::on_btnTimer_clicked()
{
    QString add = ui->lblTimer->text();
    add+="+";
    ui->lblTimer->setText(add);
}
void MainWindow:: startTheTimer()
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateAllTimers);
    timer->start(1000);
}
void MainWindow::updateAllTimers()
{
    QString stringTime = ui->lblTimer->text();
    MyTime myTime(stringTime);
    if(!myTime.minusOne())
    {
        //end timer
    }
    ui->lblTimer->setText(myTime.getQString());
}
bool MyTime::minusOne()
 {
    if(sec > 0) sec--;
    else if(min > 0)
    {
        min--;
        sec = 59;
    }
    else if(hour > 0)
    {
        hour--;
        min = 59;
        sec = 59;
    }
    else return false;

    return true;
 }
QString MyTime::makeCorrect(int value)
{
    QString res = "";
    if(value / 10 == 0)
    {
        res += "0" + QString::number(value);
    }
    else
    {
        res += QString::number(value);
    }

    return res;
}
 QString MyTime::getQString()
 {
     QString res = makeCorrect(hour) + ":"
             + makeCorrect(min) + ":" + makeCorrect(sec);

     return res;
 }













