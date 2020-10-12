#ifndef MYTIMER_H
#define MYTIMER_H
#include <QTime>

enum class Type
{
    TIMER,
    AlARM_ClOCK,
};

class MyTimer
{
private:
    bool active;
    QTime* time;
public:
    QString name;
    bool openOutside;
    bool isRemoved;
    Type type;

    MyTimer();
    MyTimer( const QString& name,  QTime* time, Type type = Type::TIMER);
    MyTimer( const QString& line);
    ~MyTimer();
    void setTime( QTime time);
    QTime getTime();
    void addTime(int sec);
    void update();
    QString getQStringTime();
    QString getQStringTimer();
    void turnOn();
    void turnOff();
};
#endif // MYTIMER_H
