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
*   \brief Computer network
*/
namespace cnet
{
    class AllMessagesInfo
    {
    private:
        std::size_t count;
        std::size_t memory;
    public:
        AllMessagesInfo(std::size_t count = 0, std::size_t memory = 0);
        void add(std::size_t memory);
        QString get_count() const;
        QString get_memory() const;
    };

    enum class ProgramType
    {
        SEND = 0,
        RECEIVE,
        BOTH
    };
    QString program_type_to_string(ProgramType type);
    ProgramType qstring_to_program_type(const QString& type);
    class BasicProgram
    {
    protected:
        QVector<Message> buffer;
        const QVector<QString>& textes;
        ProgramInfo info;
        ProgramType type;
        std::size_t period;
        QString sending_type;
        AllMessagesInfo sent_messages;
        AllMessagesInfo received_messages;
        QString create_text();
        std::shared_ptr<BasicProgram> get_other_program();
        void sleep_until_message_sending(const Message& message, std::shared_ptr<BasicProgram> other_progtam);
    public:
        BasicProgram( const QVector<QString>& textes, const ProgramInfo& info,
                      ProgramType type, std::size_t period, const QString& sending_type);
        BasicProgram( const QVector<QString>& textes, const QString& sending_type);
        ~BasicProgram();
        void send(std::shared_ptr<BasicProgram> other_program, MessageType type = MessageType::NONE);
        void receive(const Message& message);
        ProgramInfo get_info() const;
        ProgramType get_type() const;
        std::size_t get_period() const;
        QString get_sending_type() const;
        QVector<Message> get_messages() const;
        AllMessagesInfo get_sent_messages_info()const;
        AllMessagesInfo get_received_messages_info()const;
        void clear_buffer();
        friend std::ostream& operator<<(std::ostream& out, const BasicProgram& program);
        friend std::istream& operator>>(std::istream& in, BasicProgram& program);
        virtual void update() = 0;
        virtual std::shared_ptr<BasicProgram> create_program(
                const ProgramInfo& info=ProgramInfo(),
                ProgramType type=ProgramType::BOTH, std::size_t period = 0) = 0;
    };
}
#endif // BASICPROGRAM_H
