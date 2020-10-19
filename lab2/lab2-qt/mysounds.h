#pragma once
#ifndef MY_SOUNDS_H
#define MY_SOUNDS_H
#include <QString>
#include <QVector>
/*!
* Class to use the right names of sounds in different places
*/
class MySounds
{
public:
    static QVector<QString> sounds;/*!< Array with names of sounds*/
/*!
* \brief Finds name of sound in 'pathToSound' and gets its index
*
* \param pathToSound path to file '.wav' with sound of timer
* \returns - index of sound that was found
* \returns - 0 if sound wasn't found
*
*/
    static int get_index_of_sound(const QString& pathToSound);
};

#endif // MY_SOUNDS_H
