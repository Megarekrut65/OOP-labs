#ifndef MESSAGE_H
#define MESSAGE_H
#include <QString>
#include <QDateTime>
#include <iostream>

struct ObjectInfo
{
    QString server_name;
    QString program_name;
    ObjectInfo(const QString& server_name = "none", const QString& program_name="none");
};
std::ostream& operator<<(std::ostream& out, const ObjectInfo& info);

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
    ObjectInfo sender;
    QString text;
    std::size_t size;/*!< Size of message in byte*/
    MessageType type;
    QString creating_time;
    ObjectInfo recipient;
public:
    Message(const ObjectInfo& sender = ObjectInfo(), const QString& text = "none",
            MessageType type = MessageType::NONE,
            const ObjectInfo& recipient = ObjectInfo(),
            std::size_t size = 0);
    friend std::ostream& operator<<(std::ostream& out, const Message& message);
};
QString size_to_qstring(std::size_t size);
QString message_type_to_qstring(MessageType type);

#endif // MESSAGE_H
