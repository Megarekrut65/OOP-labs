#ifndef MYTIMER_H
#define MYTIMER_H
#include <QTime>

class MyTimer
{
private:
    bool active;
    QTime* time;
public:
    QString name;
    bool openOutside;
    bool isRemoved;

    MyTimer();
    MyTimer( const QString& name,  QTime* time);
    MyTimer( const QString& line);
    ~MyTimer();
    void setTime( QTime time);
    QTime getTime();
    void addTime(int sec);
    void updateTime();
    QString getQStringTime();
    QString getQStringTimer();
    void turnOn();
    void turnOff();
};
#endif // MYTIMER_H
