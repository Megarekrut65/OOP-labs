#ifndef MESSAGE_H
#define MESSAGE_H
#include <QString>
#include <QDateTime>
#include <iostream>

struct ProgramInfo
{
    QString server_name;
    QString program_name;
    ProgramInfo(const QString& server_name = "none", const QString& program_name="none");
};
std::ostream& operator<<(std::ostream& out, const ProgramInfo& info);
std::ostream& operator<<(std::ostream& out, const QString& line);
enum class MessageType
{
    NONE = 0,
    INFO,
    ERROR,
    WARNING
};

class Message
{
private:
    ProgramInfo sender;
    QString text;
    std::size_t size;/*!< Size of message in byte*/
    MessageType type;
    QString creating_time;
    ProgramInfo recipient;
public:
    Message(const ProgramInfo& sender = ProgramInfo(), const QString& text = "none",
            MessageType type = MessageType::NONE,
            const ProgramInfo& recipient = ProgramInfo(),
            std::size_t size = 0);
    friend std::ostream& operator<<(std::ostream& out, const Message& message);
};
QString size_to_qstring(std::size_t size);
QString message_type_to_qstring(MessageType type);

#endif // MESSAGE_H
