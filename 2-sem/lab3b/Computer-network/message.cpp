#include "message.h"

namespace cnm
{
    std::ostream& operator<<(std::ostream& out, const QString& line)
    {
        out << line.toStdString();
        return out;
    }
    std::ostream& operator<<(std::ostream& out, const ProgramInfo& info)
    {
        out << info.get_string();

        return out;
    }
    QString ProgramInfo::get_string() const
    {
        return "("+server_name+")"+program_name;
    }
    MessageType qstring_to_message_type(const QString& line)
    {
        if(line=="Info") return MessageType::INFO;
        if(line=="Error") return MessageType::ERROR;
        if(line=="Warning") return MessageType::WARNING;
        return MessageType::NONE;
    }
    std::ostream& operator<<(std::ostream& out, const Message& message)
    {
        out << "[" << message_type_to_qstring(message.type) << "-message, sent "
        << message.creating_time << ", from " <<  message.sender << " to "
        << message.recipient << ", " << size_to_qstring(message.size) <<"]: " << message.text;
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
    ProgramInfo Message::get_sender_info() const
    {
        return sender;
    }
    ProgramInfo Message::get_recipient_info() const
    {
        return recipient;
    }
    MessageType Message::get_message_type() const
    {
        return type;
    }
    QString Message::get_creating_time() const
    {
        return creating_time;
    }
    std::size_t Message::get_message_size() const
    {
        return size;
    }
    QString Message::get_text() const
    {
        return text;
    }
    QString get_date_time_format()
    {
        return "yyyy-MM-dd HH:mm:ss";
    }
    ProgramInfo::ProgramInfo(const QString& server_name, const QString& program_name)
        :server_name{server_name},program_name{program_name}{}
    Message::Message(const ProgramInfo& sender, const QString& text,
                     MessageType type, const ProgramInfo& recipient,
                     std::size_t size)
        :sender{sender},text{text},size{size > unsigned(text.size())?size:text.size()},type{type},
         creating_time{QDateTime::currentDateTime().toString(get_date_time_format())},
         recipient{recipient}{}

}
