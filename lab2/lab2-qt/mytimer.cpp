#include "mytimer.h"

MyTimer::MyTimer()
    : active(false),timeOut(true), time(nullptr),numberOfsignals(0), name(""), type(Type::TIMER) {}
MyTimer::MyTimer( const QString& name, QTime* time, Type type)
    :active(true),timeOut(false), numberOfsignals(0), name(name), type(type)
{
  if(time) this->time = time;
  else this->time = new QTime(0,0,0);
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
void MyTimer::signal()
{
    if(active && numberOfsignals <= 0) return;
    QSound::play(":/sounds/timer-signal.wav");
    numberOfsignals--;
    if(numberOfsignals == 0) active = false;
}
 void MyTimer::update()
 {
     if(timeOut)
     {
         signal();
         return;
     }
     switch (type)
     {
         case Type::TIMER:
         {
             if(!active) return;
             if(time->hour() == 0 && time->minute() == 0 && time->second() == 0) timeOut = true;
             else *time = time->addSecs(-1);
         }
         break;
         case Type::AlARM_ClOCK:
         {
             if(!active) return;
             QTime now = QTime::currentTime();
             if(time->hour() == now.hour() &&
                     time->minute() == now.minute() &&
                     time->second() == now.second())
             {
                timeOut = true;
                numberOfsignals = 5;
             }
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
    numberOfsignals = 0;
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
