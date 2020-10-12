#include "mytimer.h"

MyTimer::MyTimer(): active(false), time(nullptr), name(""), openOutside(false), isRemoved(false), type(Type::TIMER) {}
MyTimer::MyTimer( const QString& name, QTime* time, Type type)
{
  this->type = type;
  active = true;
  if(time) this->time = time;
  else this->time = new QTime(0,0,0);
  this->name = name;
  openOutside = false;
  isRemoved = false;
}
MyTimer::MyTimer(const QString& line)
{
    /*QStringList qStringTimer = line.split(",");
    if(qStringTimer.size() == 3)
    {
        Type type;
        QStringList parts = qStringTimer[1].split(":");
        if(qStringTimer[2] == "T") type = Type::TIMER;
        else if(qStringTimer[2] == "A") type = Type::AlARM_ClOCK;
        if(parts.size() == 3)
        {
            MyTimer(qStringTimer[0],
                    new QTime(parts[0].toInt(), parts[1].toInt(), parts[2].toInt()), type);
        }
        else
        {
            MyTimer();
        }
    }
    else
    {
        MyTimer();
    }*/
    MyTimer();
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
 void MyTimer::update()
 {
     switch (type)
     {
         case Type::TIMER:
         {
             if(time->hour() == 0 && time->minute() == 0 && time->second() == 0) active = false;
             if(!active || isRemoved) return;
             *time = time->addSecs(-1);
         }
         break;
         case Type::AlARM_ClOCK:
         {
             if(!active || isRemoved) return;
         }
         break;
     }

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
    QString qStringType = "[_] ";
    switch (type)
    {
        case Type::TIMER: qStringType = "[T] ";
        break;
        case Type::AlARM_ClOCK:
        {
            int sec = QTime::currentTime().second();
            if(sec % 2 == 0) qStringType = "[A] ";
        }
        break;
    }
    return (qStringType  + "{" + getQStringTime() + "} " + name);
}
