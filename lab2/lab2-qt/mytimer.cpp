#include "mytimer.h"

MyTimer::MyTimer(): active(false), time(nullptr), name(""), type(Type::TIMER) {}
MyTimer::MyTimer( const QString& name, QTime* time, Type type)
{
  this->type = type;
  active = true;
  if(time) this->time = time;
  else this->time = new QTime(0,0,0);
  this->name = name;
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
    if(time) delete time;
}
 QString MyTimer::get_qString_time()
 {
     return time->toString("hh:mm:ss");
 }
 void MyTimer::set_time(QTime time)
 {
     this->time->setHMS(time.hour(),time.minute(), time.second());
 }
 void MyTimer::add_to_time(int sec)
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
             if(!active) return;
             *time = time->addSecs(-1);
         }
         break;
         case Type::AlARM_ClOCK:
         {
             if(!active) return;
         }
         break;
     }

 }
void MyTimer::turn_on()
{
    active = true;
}
void MyTimer::turn_off()
{
    active = false;
}
QTime MyTimer::get_time()
{
    return *time;
}
QString MyTimer::get_qString_timer()
{
    QString qStringType = "[A] ";
    switch (type)
    {
        case Type::TIMER: qStringType = "[T] ";
        break;
        case Type::AlARM_ClOCK:
        {
            if(active)
            {
                int sec = QTime::currentTime().second();
                if(sec % 2 == 0) qStringType = "[+] ";
            }
        }
        break;
    }
    return (qStringType  + "{" + get_qString_time() + "} " + name);
}
