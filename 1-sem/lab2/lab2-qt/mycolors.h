#pragma once
#ifndef MYCOLORS_H
#define MYCOLORS_H

#include <QColor>
#include <QString>

/*!
* Class to use the right colors in different places
*/
class MyColors
{
public:    
    static const QColor pausedItem;/*!< Backgrounf color of item in List View when timer is paused, when timer is started background color is default*/
    static const QColor timeOut;/*!< Backgrounf color of item in List View when timer is paused*/
    static const QString startedListBackground;/*!< Backgrounf color of List View when all timers are started*/
    static const QString pausedListBackground;/*!< Backgrounf color of List View when all timers are paused*/
};
#endif // MYCOLORS_H
