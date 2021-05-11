#include "messagetextwindow.h"
#include "ui_messagetextwindow.h"

MessageTextWindow::MessageTextWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageTextWindow)
{
    ui->setupUi(this);
    QIcon icon("Images/program-window-icon.ico");
    setWindowIcon(icon);
    setWindowTitle("Message");
}

MessageTextWindow::~MessageTextWindow()
{
    delete ui;
}
void MessageTextWindow::set_message(const cnet::Message& message)
{
    ui->textEdit->setText(message.get_text());
    setWindowTitle(message_type_to_qstring(message.get_message_type())+"-message");
    QString path = "Images/";
    switch (message.get_message_type())
    {
        case cnet::MessageType::INFO : path += "info";
        break;
        case cnet::MessageType::ERROR : path += "error";
        break;
        case cnet::MessageType::WARNING : path += "warning";
        break;
        default: path += "none";
        break;
    }
    path+="-type.ico";
    QIcon icon(path);
    setWindowIcon(icon);
    ui->labelSender->setText(message.get_sender_info().get_string());
    ui->labelRecepient->setText(message.get_recipient_info().get_string());
}
