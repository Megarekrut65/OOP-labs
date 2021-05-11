#ifndef MESSAGETEXTWINDOW_H
#define MESSAGETEXTWINDOW_H

#include <QDialog>
#include "Computer-network/message.h"
#include <QIcon>

namespace Ui {
class MessageTextWindow;
}
/*!
*   \brief Window to show message information
*/
class MessageTextWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MessageTextWindow(QWidget *parent = nullptr);
    ~MessageTextWindow();
    /*!
    *   \brief Adds messages information to labels
    */
    void set_message(const cnm::Message& message);

private:
    Ui::MessageTextWindow *ui;
};

#endif // MESSAGETEXTWINDOW_H
