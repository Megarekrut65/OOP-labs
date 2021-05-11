#ifndef BASICPROGRAM_H
#define BASICPROGRAM_H
#include <memory>
#include "message.h"
#include <sstream>
#include <mutex>
#include <thread>
#include <chrono>
#include <vector>
/*!
*   \brief Computer network model
*
*   Some classes and functions for computer network model simulation.
*/
namespace cnm
{
    /*!
    *   \brief Class for information about count and size of all added messages
    */
    class AllMessagesInfo
    {
    private:
        std::size_t count;/*!< Number of added messages */
        std::size_t memory;/*!< Shared memory of added messages */
    public:
        /*!
        *   \brief Parameterized constructor
        *
        *   \param count - number of messages
        *   \param memory shared memory of messages
        */
        AllMessagesInfo(std::size_t count = 0, std::size_t memory = 0);
        /*!
        *   \brief Adds one message to object
        *
        *   Also increase count by one.
        *
        *   \param memory - memory of message
        */
        void add(std::size_t memory);
        /*!
        *   \brief Returns count
        */
        QString get_count() const;
        /*!
        *   \brief Returns memory
        */
        QString get_memory() const;
        /*!
        *   \brief Assigns zero values to all parameters
        */
        void clear();
    };
    /*!
    *   \brief Types of program
    */
    enum class ProgramType
    {
        SEND = 0,/*!< Program can only send messages */
        RECEIVE,/*!< Program can only receive messages */
        BOTH/*!< Program can send and receive messages */
    };
    /*!
    *   \brief Converts constants to constants names in QString
    */
    QString program_type_to_string(ProgramType type);
    /*!
    *   \brief Converts QString with costants names to costants
    *
    *   \param type - line with costants name
    *   \returns type of program if type is correct else BOTH-type
    */
    ProgramType qstring_to_program_type(const QString& type);
    /*!
    *   \brief Basic class for programs
    *
    *   Program capabilities:
    *
    *   - send messages;
    *
    *   - receive messages;
    *
    *   - save received messages;
    *
    *   - save information about sent and received messages;
    *
    *   - send messages by period;
    *
    *   - create same program.
    *
    */
    class BasicProgram
    {
    protected:
        QVector<Message> buffer;/*!< Container for received messages */
        const QVector<QString>& textes;/*!< Reference to list of phrases for sending */
        ProgramInfo info;/*!< Information about program and its server */
        ProgramType type;/*!< Type of program */
        std::size_t period;/*!< Sending messages period */
        QString sending_type;/*!< Type of sending */
        AllMessagesInfo sent_messages;/*!< Information about sent messages */
        AllMessagesInfo received_messages;/*!< Information about received messages */
        /*!
        *   \brief Returns random line from phrases list
        */
        QString create_text();
        /*!
        *   \brief Returns pointer to other program
        *
        *   Takes other program from static container with servers and programs Servers.
        */
        std::shared_ptr<BasicProgram> get_other_program();
        /*!
        *   \brief Pauses thread while message 'sending'
        *
        *   Sleep time is calculated as follows: the size of
        *   the message and the minimum speed between servers is
        *   taken then the size is divided by speed and we receive the necessary time.
        *
        *   \param message - message to send
        *   \param other_program - pointer to program to send message to it
        */
        void sleep_until_message_sending(const Message& message, std::shared_ptr<BasicProgram> other_program);
    public:
        /*!
        *   \brief Creates program with given parameters
        *
        *   Other parmeters will be empty.
        *
        *   \param textes - reference to list of phrases
        *   \param info - information about program and server names
        *   \param type - type of program
        *   \param period - period of messages sending
        *   \param sending_type - type of messages sending
        */
        BasicProgram( const QVector<QString>& textes, const ProgramInfo& info,
                      ProgramType type, std::size_t period, const QString& sending_type);
        /*!
        *   \brief Creates empty program. Do not use empty program
        */
        BasicProgram( const QVector<QString>& textes, const QString& sending_type);
        /*!
        *   \brief Clears buffer
        */
        ~BasicProgram();
        /*!
        *   \brief Sends random created message to other_program
        *
        *   The message will not be sent immediately,
        *   the transmission speed between servers is taken into account.
        *
        *   \param other_program - pointer to program to send message to it
        *   \param type - type of message
        */
        void send(std::shared_ptr<BasicProgram> other_program, MessageType type = MessageType::NONE);
        /*!
        *   \brief Receives message
        *
        *   Adds message to buffer.
        */
        void receive(const Message& message);
        /*!
        *   \brief Returns info
        */
        ProgramInfo get_info() const;
        /*!
        *   \brief Returns type
        */
        ProgramType get_type() const;
        /*!
        *   \brief Returns period
        */
        std::size_t get_period() const;
        /*!
        *   \brief Returns sending_type
        */
        QString get_sending_type() const;
        /*!
        *   \brief Returns all messages
        */
        QVector<Message> get_messages() const;
        /*!
        *   \brief Returns sent_messages_info
        */
        AllMessagesInfo get_sent_messages_info()const;
        /*!
        *   \brief Returns received_messages_info
        */
        AllMessagesInfo get_received_messages_info()const;
        /*!
        *   \brief Clears buffer and information about sent and recived messages
        */
        void clear_buffer();
        /*!
        *   \brief Operator<< for BasicProgram
        *
        *   Adds to ostream server and program names, progam and sending types and period.
        *   Makes lines as:
        *
        *   Server-name=info.server_name
        *
        *   Program-name=info.program_name
        *
        *   Program-type=type
        *
        *   Sending-type=sending_type
        *
        *   Sending-period=period
        *
        */
        friend std::ostream& operator<<(std::ostream& out, const BasicProgram& program);
        /*!
        *   \brief Operator>> for BasicProgram
        *
        *   Adds all parameters to empty program from istream.
        */
        friend std::istream& operator>>(std::istream& in, BasicProgram& program);
        /*!
        *   \brief Sends messages to random programs
        *
        *   Do not sends messages to self.
        */
        virtual void update() = 0;
        /*!
        *   \brief Creates program with same sending type and phrases list
        *
        *   \param info - information about server and program names
        *   \param type - type of program
        *   \param period - period of messages sending
        */
        virtual std::shared_ptr<BasicProgram> create_program(
                const ProgramInfo& info=ProgramInfo(),
                ProgramType type=ProgramType::BOTH, std::size_t period = 0) = 0;
    };
}
#endif // BASICPROGRAM_H
