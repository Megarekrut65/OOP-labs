#include "mytimer.h"

namespace mt
{

MyTimer::MyTimer()
    :  time(nullptr), numberOfSignals(0), active(false),
      timeOut(true), name(""),type(Type::TIMER), maxNumberOfSignals(0),
      pathToSound(""), soundMode(true) {}
MyTimer::MyTimer( const QString& name, QTime* time, Type type, const int maxNumberOfSignals, QString nameOfSound)
    :  numberOfSignals(0), active(true), timeOut(false),
      name(name), type(type), maxNumberOfSignals(maxNumberOfSignals), soundMode(true)
{
  if(time) this->time = time;
  else this->time = new QTime(0,0,0);
  set_path_to_sound(nameOfSound);
}
void MyTimer::set_path_to_sound(QString nameOfSound)
{
   pathToSound = QDir::currentPath() + "/Sounds/timer" + nameOfSound + ".wav";
}
bool MyTimer::qString_to_bool(const QString& line)
{
    if(line == "true") return true;
    return false;
}
Type MyTimer::qString_to_type(const QString& line)
{
    if(line == "A") return Type::AlARM_ClOCK;
    return Type::TIMER;
}
QTime MyTimer::qString_to_QTime(const QString& line)
{
    QStringList parts = line.split(":");
    if(parts.size() != 3) return QTime(0,0,0);
    return QTime(parts[0].toInt(), parts[1].toInt(), parts[2].toInt());
}
MyTimer::MyTimer(const QString& line)
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
        soundMode = true;
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
QString MyTimer::get_timer_info()
{
    return (bool_to_QString(active) + "," +
            bool_to_QString(timeOut) + "," +
            get_QString_type() + "," +
            time->toString("hh:mm:ss") + "," +
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
void MyTimer::signal()
{
    if(numberOfSignals <= 0) return;
    if(soundMode) QSound::play(pathToSound);
    numberOfSignals--;
    if(numberOfSignals == 0) active = false;
}
void MyTimer::start_time_out()
{
    timeOut = true;
    numberOfSignals = maxNumberOfSignals;
    signal();
}
void MyTimer::timer_update()
{
    if(time->hour() == 0 &&
            time->minute() == 0 &&
            time->second() == 0)  start_time_out();
    else *time = time->addSecs(-1);
}
void MyTimer::alarm_update()
{
    QTime now = QTime::currentTime();
    if(time->hour() == now.hour() &&
            time->minute() == now.minute() &&
            time->second() == now.second()) start_time_out();
}
 void MyTimer::update(bool soundMode)
 {
     this->soundMode = soundMode;
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
}
