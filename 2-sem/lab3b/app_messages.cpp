#include "app_messages.h"

void AppMessages::error_message(QWidget* that,const QString& title, const QString& message)
{
    QMessageBox messageBox;
    messageBox.critical(that, title, message);
    messageBox.setFixedSize(500,200);
}
bool AppMessages::question_message(QWidget* that, const QString& title, const QString& message)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(that, title, message, QMessageBox::Yes|QMessageBox::No);
    return (reply == QMessageBox::Yes);
}
