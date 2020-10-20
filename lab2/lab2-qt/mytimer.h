#pragma once
#ifndef MYTIMER_H
#define MYTIMER_H
#include <QTime>
#include <QDir>
#include <QSound>
/*!
* \brief A enum class to distinguish between timers and alarm clocks
*
* Used in class MyTimer
*/
enum class Type
{
    TIMER,
    AlARM_ClOCK,
};
/*!
* \brief Class for presenting timers and alarm clocks
*
* The timer consists of name, time, type, signal, and number of signals.
* The timer can be turned on or off. When the TIMER is off, the time does not decrease,
* and when the ALARM_CLOCK is off, the set time is not checked.
* When the time expires(TIMER) or when the desired time comes(ALARM_CLOCK),
* the timer plays the signal 'maxNumberOfSignals' times.
* But if 'soundMode' is false then timer can't play signal.
* After the last signal the timer is turn off
*
*/
class MyTimer
{
private:  
    QTime* time;//the time of timer
    int numberOfSignals;//current number of signals
    void signal();//plays timer signal
    void timer_update();//if the time is not over, reduce it by one second
    void alarm_update();//checks if the right time has come
    bool qString_to_bool(const QString& line);
    Type qString_to_type(const QString& line);
    QTime qString_to_QTime(const QString& line);
    QString bool_to_QString(bool value);
    QString get_QString_type();//returns the type of timer as a QString
    void start_time_out();//sets the initial parameters and starts the timer signal
public:
    bool active;/*!< Indicates whether the timer is active*/
    bool timeOut;/*!< Indicates whether the timer has expired*/
    QString name;/*!< Name of the timer*/
    Type type;/*!< The type of the timer. See Type */
    int maxNumberOfSignals;/*!< The number of timer signals that will be played at the end of the time*/
    QString pathToSound;/*!< Path to file with signal of timer*/
    bool soundMode;/*!< Indicates whether the timer is allowed to play the signal*/
    MyTimer();
    MyTimer( const QString& name,  QTime* time, Type type, int maxNumberOfSignals = 15, QString nameOfSound = "Sound1");
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
