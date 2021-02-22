#ifndef MYMESSAGE_H
#define MYMESSAGE_H

#include <QMessageBox>
#include <QString>

class MyMessage
{
public:
    static void error_message(QWidget* that, const QString& title, const QString& message);
    static bool question_message(QWidget* that, const QString& title, const QString& message);
};

#endif // MYMESSAGE_H
