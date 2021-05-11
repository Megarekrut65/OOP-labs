#ifndef APPMESSAGES_H
#define APPMESSAGES_H
#include <QMessageBox>
#include <QString>

/*!
*   \brief
*/
class AppMessages
{
public:
    static void error_message(QWidget* that, const QString& title, const QString& message);//shows error message
    static bool question_message(QWidget* that, const QString& title, const QString& message);//shows question message
};

#endif // APPMESSAGES_H
