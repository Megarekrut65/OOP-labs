#ifndef MESSAGE_H
#define MESSAGE_H
#include <QString>
#include <QDateTime>
#include <iostream>

namespace cnet
{
    /*!
    *   \brief Struct for a few information about program
    */
    struct ProgramInfo
    {
        QString server_name;/*!< Name of server where is the program */
        QString program_name;/*!< Name of program */
        /*!
        *   \brief Parameterized constructor
        */
        ProgramInfo(const QString& server_name = "none", const QString& program_name="none");
        /*!
        *   \brief Makes string as (server_name)program_name
        *
        *   \returns information about program in string way
        */
        QString get_string() const;
    };
    /*!
    *   \brief Operator<< for struct ProgramInfo
    *
    *   Adds to ostream server_name and program_name as (server_name)program_name.
    */
    std::ostream& operator<<(std::ostream& out, const ProgramInfo& info);
    /*!
    *   \brief Operator<< for QString
    *
    *   Just convert QString to std::string and adds it to ostream.
    */
    std::ostream& operator<<(std::ostream& out, const QString& line);
    /*!
    *   \brief Operator>> for QString
    *
    *   Just gets std::string from istream and convert it to QString.
    */
    std::istream& operator>>(std::istream& in, QString& line);
    /*!
    *   \brief Types of message
    */
    enum class MessageType
    {
        NONE = 0,/*!< The message without type */
        INFO,/*!< Information message */
        ERROR,/*!< Error message */
        WARNING/*!< Warning message */
    };
    /*!
    *   \brief Class to present an abstract message
    */
    class Message
    {
    private:
        ProgramInfo sender;/*!< Information about message sender */
        QString text;/*!< Body of message */
        std::size_t size;/*!< Size of message (in bytes) */
        MessageType type;/*!< Type of message */
        QString creating_time;/*!< Date and time of creating message */
        ProgramInfo recipient;/*!< Information about message recipient */
    public:
        /*!
        *   \brief Parameterized constructor
        *
        *   Parametr creating_time is created by time when message is created.
        *
        *   \param sender - program that send the message
        *   \param text - body of message
        *   \param type - type of message
        *   \param recipient - program that receive the message
        *   \param size - size of message in bytes
        */
        Message(const ProgramInfo& sender = ProgramInfo(), const QString& text = "none",
                MessageType type = MessageType::NONE,
                const ProgramInfo& recipient = ProgramInfo(),
                std::size_t size = 0);
        /*!
        *   \brief Returns sender
        */
        ProgramInfo get_sender_info() const;
        /*!
        *   \brief Returns recipient
        */
        ProgramInfo get_recipient_info() const;
        /*!
        *   \brief Returns type
        */
        MessageType get_message_type() const;
        /*!
        *   \brief Returns creating_time
        */
        QString get_creating_time() const;
        /*!
        *   \brief  Returns size
        */
        std::size_t get_message_size() const;
        /*!
        *   \brief Returns text
        */
        QString get_text() const;
        /*!
        *   \brief Operator<< for Message
        *
        *   Adds to ostream all parametrs of message.
        *
        *   Makes line as '[type, creating_time, sender, recipient, size]: text'.
        */
        friend std::ostream& operator<<(std::ostream& out, const Message& message);
    };
    /*!
    *   \brief Convers message size to QString
    *
    *   The size is in bytes.
    *   \param size - size in bytes
    *   \returns If 0 byte <= size < 1024 byte - size B
    *   \returns If 1024 byte <= size < 1024*1024 byte - size KB
    *   \returns If 1024*1024 byte <= size < 1024*1024*1024 byte - size MB
    *   \returns If 1024*1024*1024 byte <= size - size GB
    */
    QString size_to_qstring(std::size_t size);
    /*!
    *   \brief Converts constants to constants names in QString
    */
    QString message_type_to_qstring(MessageType type);
    /*!
    *   \brief Converts QString with costants names to costants
    *
    *   \param line - line with costants name
    *   \returns type of message if line is correct else none-type
    */
    MessageType qstring_to_message_type(const QString& line);
    /*!
    *   \brief Returns DateTime format to convert QDateTime in QString by same format
    */
    QString get_date_time_format();

}

#endif // MESSAGE_H
