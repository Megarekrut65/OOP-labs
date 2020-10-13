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
