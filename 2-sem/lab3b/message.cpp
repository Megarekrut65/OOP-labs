#include "message.h"

QString size_to_qstring(std::size_t size)
{
    QString types[] = {"B","KB","MB","GB"};
    int types_size = 4;
    QString res = "";
    int i = 0;
    for(; i < types_size; i++)
    {
        if(size < 1024)
        {
            res = QString::number(size);
            break;
        }
        else
        {
            size/= 1024;
        }
    }
    return res + types[i];
}
QString message_type_to_qstring(MessageType type)
{
    switch (type)
    {
        case MessageType::INFO : return"Info";
        case MessageType::ERROR : return"Error";
        case MessageType::WARNING : return"Warning";
        default: return"None";
    }
}
ObjectInfo::ObjectInfo(const QString& server_name, const QString& program_name)
    :server_name{server_name},program_name{program_name}{}
std::ostream& operator<<(std::ostream& out, const ObjectInfo& info)
{
    out << "(" <<  info.server_name.toStdString() << ")" << info.program_name.toStdString();

    return out;
}
Message::Message(const ObjectInfo& sender, const QString& text,
                 MessageType type, const ObjectInfo& recipient,
                 std::size_t size)
    :sender{sender},text{text},size{size > unsigned(text.size())?size:text.size()},type{type},
     creating_time{QDateTime::currentDateTime().toString("yyyy-MM-dd, HH:mm:ss")},
     recipient{recipient}{}
std::ostream& operator<<(std::ostream& out, const Message& message)
{
    out << "[" << message_type_to_qstring(message.type).toStdString() << "-message, sent "
    << message.creating_time.toStdString() << ", from " <<  message.sender << " to "
    << message.recipient << ", " << size_to_qstring(message.size).toStdString() <<"]: " << message.text.toStdString();
    return out;
}
