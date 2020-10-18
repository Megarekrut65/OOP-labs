#pragma once
#ifndef TIMEPERIOD_H
#define TIMEPERIOD_H
#include <QTime>
#include <QString>
#include <QFile>

class TimePeriod
{
private:
    QString path;
    QTime qString_to_QTime(QString line);
public:
    QTime begin;
    QTime end;
    bool active;

    TimePeriod();
    TimePeriod(QString path);
    bool is_period();
    void write_to_file();
};

#endif // TIMEPERIOD_H
