#include "mytimer.h"

MyTimer::MyTimer()
    :  time(nullptr),maxNumberOfSignals(0), numberOfSignals(0),
      pathToSound(""),active(false), timeOut(true), name(""), type(Type::TIMER) {}
MyTimer::MyTimer( const QString& name, QTime* time, Type type, const int maxNumberOfSignals, QString nameOfSound)
    : maxNumberOfSignals(maxNumberOfSignals), numberOfSignals(0),
      active(true), timeOut(false), name(name), type(type)
{
  if(time) this->time = time;
  else this->time = new QTime(0,0,0);
  pathToSound = QDir::currentPath() + "/Sounds/" + nameOfSound;
}
bool MyTimer::qString_to_bool(const QString& line)
{
    if(line == "true") return true;
    return false;
}
Type MyTimer::qString_to_type(const QString& line)
{
    if(line == "T") return Type::TIMER;
    return Type::AlARM_ClOCK;
}
QTime MyTimer::qString_to_QTime(const QString& line)
{
    QStringList parts = line.split(":");
    if(parts.size() != 3) return QTime(0,0,0);
    return QTime(parts[0].toInt(), parts[1].toInt(), parts[2].toInt());
}
MyTimer::MyTimer(const QString& line)//active, timeOut, T, 10:10:10, Name, maxNumber, number, nameSound
{
    QStringList parts = line.split(",");
    if(parts.size() == 8)
    {
        active = qString_to_bool(parts[0]);
        timeOut = qString_to_bool(parts[1]);
        type = qString_to_type(parts[2]);
        time = new QTime(qString_to_QTime(parts[3]));
        name = parts[4];
        maxNumberOfSignals = parts[5].toInt();
        numberOfSignals = parts[6].toInt();
        pathToSound = parts[7];
    }
    else
    {
        MyTimer();
    }
}
MyTimer::~MyTimer()
{
    if(time) delete time;
}
QString  MyTimer::bool_to_QString(bool value)
{
    if(value) return "true";
    return "false";
}
QString MyTimer::get_timer_info()//active, timeOut, T, 10:10:10, Name, maxNumber, number, nameSound
{
    return (bool_to_QString(active) + "," +
            bool_to_QString(timeOut) + "," +
            get_QString_type() + "," +
            get_QString_time() + "," +
            name + "," +
            QString::number(maxNumberOfSignals) + "," +
            QString::number(numberOfSignals) + "," +
            pathToSound);
}
QString MyTimer::get_QString_type()
{
    if(type == Type::TIMER) return "T";
    return "A";
}
 QString MyTimer::get_QString_time()
 {
     int sec = QTime::currentTime().second();
     if(active && sec % 2 == 0) return time->toString("hh mm ss");
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
    if(numberOfSignals <= 0) return;
    QSound::play(pathToSound);
    numberOfSignals--;
    if(numberOfSignals == 0) active = false;
}
void MyTimer::timer_update()
{
    if(time->hour() == 0 && time->minute() == 0 && time->second() == 0)
    {
        timeOut = true;
        numberOfSignals = 15;
        signal();
    }
    else *time = time->addSecs(-1);
}
void MyTimer::alarm_update()
{
    QTime now = QTime::currentTime();
    if(time->hour() == now.hour() &&
            time->minute() == now.minute() &&
            time->second() == now.second())
    {
       timeOut = true;
       numberOfSignals = 15;
       signal();
    }
}
 void MyTimer::update()
 {
     if(!active) return;
     if(timeOut)
     {
         signal();
         return;
     }
     switch (type)
     {
         case Type::TIMER: timer_update();
         break;
         case Type::AlARM_ClOCK: alarm_update();
         break;
     }
 }
void MyTimer::turn_on()
{
    active = true;
    timeOut = false;
}
void MyTimer::turn_off()
{
    active = false;
    numberOfSignals = 0;
}
QTime MyTimer::get_time()
{
    return *time;
}
QString MyTimer::get_QString_timer()
{
    QString qStringType = "";
    switch (type)
    {
        case Type::TIMER: qStringType = "[T] ";
        break;
        case Type::AlARM_ClOCK: qStringType = "[A] ";
        break;
    }
    return (qStringType  + "{" + get_QString_time() + "} " + name);
}
