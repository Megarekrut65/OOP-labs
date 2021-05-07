#include "message.h"

std::ostream& operator<<(std::ostream& out, const QString& line)
{
    out << line.toStdString();
    return out;
}
std::ostream& operator<<(std::ostream& out, const ProgramInfo& info)
{
    out << "(" <<  info.server_name << ")" << info.program_name;

    return out;
}
std::istream& operator>>(std::istream& in, ProgramInfo& info)
{
    char rubbish;
    in>>rubbish>>info.server_name>>rubbish>>info.program_name;
    return in;
}
MessageType qstring_to_message_type(const QString& line)
{
    if(line=="Info") return MessageType::INFO;
    if(line=="Error") return MessageType::ERROR;
    if(line=="Warning") return MessageType::WARNING;
    return MessageType::NONE;
}
QDateTime qstring_to_qdate_time(const QString& line)
{
    return QDateTime::fromString(line,"yyyy-MM-dd HH:mm:ss");
}
std::ostream& operator<<(std::ostream& out, const Message& message)
{
    out << "[" << message_type_to_qstring(message.type) << "-message, sent "
    << message.creating_time << ", from " <<  message.sender << " to "
    << message.recipient << ", " << message.size <<"]: " << message.text;
    return out;
}
std::istream& operator>>(std::istream& in, QString& line)
{
    std::string std_line;
    in>>std_line;
    line = std_line.c_str();
    return in;
}
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
ProgramInfo::ProgramInfo(const QString& server_name, const QString& program_name)
    :server_name{server_name},program_name{program_name}{}
Message::Message(const ProgramInfo& sender, const QString& text,
                 MessageType type, const ProgramInfo& recipient,
                 std::size_t size)
    :sender{sender},text{text},size{size > unsigned(text.size())?size:text.size()},type{type},
     creating_time{QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss")},
     recipient{recipient}{}
