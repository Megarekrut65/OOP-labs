#include "mytimer.h"

MyTimer::MyTimer(): active(false), time(nullptr), name(""), openOutside(false), isRemoved(false) {}
MyTimer::MyTimer( const QString& name, QTime* time)
{
  active = true;
  if(time) this->time = time;
  else this->time = new QTime(0,0,0);
  this->name = name;
  openOutside = false;
  isRemoved = false;
}
MyTimer::MyTimer(const QString& line)
{
    QStringList nameAndTime = line.split(",");
    if(nameAndTime.size() == 2)
    {
        QStringList parts = nameAndTime[1].split(":");
        if(parts.size() == 3)
        {
            MyTimer(nameAndTime[0],
                    new QTime(nameAndTime[0].toInt(), nameAndTime[1].toInt(), nameAndTime[2].toInt()));
        }
        else
        {
            MyTimer();
        }
    }
    else
    {
        MyTimer();
    }
}
 MyTimer::~MyTimer()
{
    if(!isRemoved) delete time;
}
 QString MyTimer::getQStringTime()
 {
     return time->toString("hh:mm:ss");
 }
 void MyTimer::setTime(QTime time)
 {
     this->time->setHMS(time.hour(),time.minute(), time.second());
 }
 void MyTimer::addTime(int sec)
 {
    if(sec <= 0) return;
    *time = time->addSecs(sec);
 }
 void MyTimer::updateTime()
 {
     if(time->hour() == 0 && time->minute() == 0 && time->second() == 0) active = false;
     if(!active || isRemoved) return;
     *time = time->addSecs(-1);
 }
void MyTimer::turnOn()
{
    active = true;
}
void MyTimer::turnOff()
{
    active = false;
}
QTime MyTimer::getTime()
{
    return *time;
}
QString MyTimer::getQStringTimer()
{
    return (name + " " + getQStringTime());
}
