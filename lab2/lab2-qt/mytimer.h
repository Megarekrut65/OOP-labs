#pragma once
#ifndef MYTIMER_H
#define MYTIMER_H
#include <QTime>
#include <QDir>
#include <QSound>
/*!
* Namespace for MyTimer
*/
namespace mt
{
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
    Type type;/*!< The type of the timer. See mt::Type */
    int maxNumberOfSignals;/*!< The number of timer signals that will be played at the end of the time*/
    QString pathToSound;/*!< Path to file with signal of timer*/
    bool soundMode;/*!< Indicates whether the timer is allowed to play the signal*/
/*!
* \brief Default Constructor
*
* Creates an empty non-active TIMER without time, name, pathToSound
*
*/
    MyTimer();
/*!
* \brief Parameterized constructor
*
* Creates active timer with the specified parameters
*
*/
    MyTimer( const QString& name,  QTime* time, Type type,
             int maxNumberOfSignals = 15, QString nameOfSound = "Sound1");
/*!
*
* Divides 'line' into parts and translates its parts into appropriate types
*
* Line like "active, timeOut, type, time(hh:mm:ss), name,
* maxNumberOfSignals, numberOfSignals, pathToSound"
*
* If line is incorrect then creates default timer
*
*/
    MyTimer( const QString& line);
/*!
* If time isn't nullptr then deletes it
*
*/
    ~MyTimer();
/*!
* \brief Edits the time of timer
*
* \param time - new time
*
*/
    void set_time( QTime time);
    QTime get_time();
/*!
* \brief Updating the timer
*
* If type is TIMER then reduces the time by one second
* else checks if the alarm time is correct.
* If the timer is suspended it does nothing
*
* Also sets the sound mode
*
*/
    void update(bool soundMode = true);
/*!
* \returns - QString like "hh mm ss" if now the number of seconds is even and timer is active
* \returns - QString like "hh:mm:ss" if now the number of seconds isn't even or timer isn't active
*/
    QString get_QString_time();
/*!
* \brief Creating QString timer
*
* Creates QString timer for List View in MainWindow
*
* \returns - QString like "ID.[Type] {Time(hh:mm:ss)} Name"
*
*/
    QString get_QString_timer();
/*!
* \brief Translates all timer parameters into a QString
*
* \returns - QString like "active, timeOut, Type, time(hh:mm:ss),
* name, maxNumberOfSignals, numberOfSignals, pathToSound"
*
*/
    QString get_timer_info();
/*!
* The finction starts timer
*
*/
    void turn_on();
/*!
* The function pauses timer
*
*/
    void turn_off();
/*!
* Creates correct path to sound 'nameOfSound'
*
*/
    void set_path_to_sound(QString nameOfSound);
};
}

#endif // MYTIMER_H
