#include "timeperiod.h"

TimePeriod::TimePeriod():  path(""), begin(QTime(0,0,0)), end(QTime(0,0,0)), active(false) {}
TimePeriod::TimePeriod(QString path)
    :   path(path),  begin(QTime(0,0,0)), end(QTime(0,0,0)), active(false)
{
    QFile file(path);
    if(!file.exists())
    {
        if(file.open(QIODevice::WriteOnly))
        {
            write_to_file();
            file.close();
        }
    }
    else if (file.open(QIODevice::ReadOnly))
    {
        if(file.atEnd()) return;
        QString title = file.readLine();
        if(file.atEnd()) return;
        QString line = file.readLine();
        QStringList parts = line.split(",");
        if(parts.size() != 3) return;
        begin = qString_to_QTime(parts[0]);
        end = qString_to_QTime(parts[1]);
        if(parts[2] == "true") active = true;
        else active = false;
        file.close();
    }
}
QTime TimePeriod::qString_to_QTime(QString line)
{
    QStringList parts = line.split(":");
    if(parts.size() != 3) return QTime(0,0,0);
    return QTime(parts[0].toInt(),parts[1].toInt(),parts[2].toInt());
}
bool TimePeriod::is_period()
{
    if(!active) return false;
    QTime current = QTime::currentTime();
    if(begin < end && (current >= begin && current <= end)) return true;
    if(begin > end)
    {
        if(current > end && current < begin) return false;
        return true;
    }
    return false;
}
void TimePeriod::write_to_file()
{
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)) return;
    file.write("Time period:\r\n");
    QString line = begin.toString() + "," + end.toString() + ",";
    if(active) line += "true";
    else line += "false";
    file.write(line.toStdString().c_str());
    file.close();
}
QTime TimePeriod::get_begin()
{
    return begin;
}
QTime TimePeriod::get_end()
{
    return end;
}
bool TimePeriod::is_active()
{
    return active;
}
void TimePeriod::set_period(QTime begin, QTime end, bool active)
{
    this->begin = begin;
    this->end = end;
    this->active = active;
    write_to_file();
}
