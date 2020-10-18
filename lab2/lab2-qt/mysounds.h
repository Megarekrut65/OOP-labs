#pragma once
#ifndef MY_SOUNDS_H
#define MY_SOUNDS_H
#include <QString>
#include <QVector>

class MySounds
{
public:
    static QVector<QString> sounds;
    static int get_number_of_sound(const QString& pathToSound);
};

#endif // MY_SOUNDS_H
