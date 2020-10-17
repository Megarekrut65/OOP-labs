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
    int numberOfSignals;
    void signal();
    void timer_update();
    void alarm_update();
    bool qString_to_bool(const QString& line);
    Type qString_to_type(const QString& line);
    QTime qString_to_QTime(const QString& line);
    QString bool_to_QString(bool value);
    QString get_QString_type();
    void start_time_out();
public:
    bool active;
    bool timeOut;
    QString name;
    Type type;
    int maxNumberOfSignals;
    QString pathToSound;
    bool soundMode;
    MyTimer();
    MyTimer( const QString& name,  QTime* time, Type type, int maxNumberOfSignals = 15, QString nameOfSound = "timerSound1.wav");
    MyTimer( const QString& line);
    ~MyTimer();
    void set_time( QTime time);
    QTime get_time();
    void add_to_time(int sec);
    void update(bool soundMode = true);
    QString get_QString_time();
    QString get_QString_timer();
    QString get_timer_info();
    void turn_on();
    void turn_off();
    void set_path_to_sound(QString nameOfSound);
};
#endif // MYTIMER_H
