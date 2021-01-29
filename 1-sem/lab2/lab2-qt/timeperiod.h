#pragma once
#ifndef TIMEPERIOD_H
#define TIMEPERIOD_H
#include <QTime>
#include <QString>
#include <QFile>
/*!
* \brief Class to represent the time period
*
* Used for NotDisturbMode
*
*/
class TimePeriod
{
private:
    QString path;//path to file with information about 'do not disturb mode'
    QTime qString_to_QTime(QString line);//line like hh:mm:ss
    QTime begin;//The begin of time period
    QTime end;//The end of time period
     bool active;//Indicates whether the time period is active
    void write_to_file();//writes the time period to file
public:
/*!
* Default constructor
*
*/
    TimePeriod();
/*!
* The constructor reads parametres from file with 'path'.
* If is errors with file then create zero non-active time period
*
*/
    TimePeriod(QString path);
/*!
* \brief Checks whether the specified time is included in the time period
*
* \returns - true if now is time in time period
* \returns - false if now isn't time in time period or time period is non-active
*/
    bool is_period(); 
    QTime get_begin();
    QTime get_end();
/*!
* \brief Checks if the period is active
* \returns - true if period is active
* \returns - false id period isn't active
*/
    bool is_active();
/*!
* \brief Receives and changes class parameters
*
* \param begin the begin of time period
* \param end the end of time period
* \param active is true if time period is active else is false
*/
    void set_period(QTime begin, QTime end, bool active);
};

#endif // TIMEPERIOD_H
