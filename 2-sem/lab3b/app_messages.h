#ifndef APPMESSAGES_H
#define APPMESSAGES_H
#include <QMessageBox>
#include <QString>

/*!
*   \brief Static methods to open window with error or queshion
*/
class AppMessages
{
public:
    /*!
    *   \brief Opens error window and show message
    *
    *   \param that - pointer to parent window
    *   \param title - name of this window
    *   \param message - message in this window
    */
    static void error_message(QWidget* that, const QString& title, const QString& message);
    /*!
    *   \brief Opens question window, show question and wait for answer
    *
    *   \param that - pointer to parent window
    *   \param title - name of this window
    *   \param message - question in this window
    *   \returns true or false by pushed button
    */
    static bool question_message(QWidget* that, const QString& title, const QString& message);
};

#endif // APPMESSAGES_H
