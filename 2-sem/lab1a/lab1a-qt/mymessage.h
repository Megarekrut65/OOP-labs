#ifndef MYMESSAGE_H
#define MYMESSAGE_H

#include <QMessageBox>
#include <QString>

class MyMessage
{
public:
    static void error_message(QWidget* that, const QString& title, const QString& message);//shows error message
    static bool question_message(QWidget* that, const QString& title, const QString& message);//shows question message
};

#endif // MYMESSAGE_H
