#ifndef MYTIMER_H
#define MYTIMER_H
#include <QTime>
#include <QDir>
#include <QSound>

enum class Type
{
    TIMER,
    AlARM_ClOCK,
};

class MyTimer
{
private:  
    QTime* time;
    int numberOfsignals;
    QString pathToSound;
    void signal();
    void timer_update();
    void alarm_update();
public:
    bool active;
    bool timeOut;
    QString name;
    Type type;

    MyTimer();
    MyTimer( const QString& name,  QTime* time, Type type = Type::TIMER);
    MyTimer( const QString& line);
    ~MyTimer();
    void set_time( QTime time);
    QTime get_time();
    void add_to_time(int sec);
    void update();
    QString get_qString_time();
    QString get_qString_timer();
    void turn_on();
    void turn_off();
};
#endif // MYTIMER_H
