#ifndef BASICPROGRAM_H
#define BASICPROGRAM_H
#include <memory>
#include "message.h"
#include <sstream>
#include <mutex>
#include <thread>
#include <vector>
/*!
*   \brief Computer network
*/
namespace cn
{
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
        QString create_text();
        std::shared_ptr<BasicProgram> get_other_program();
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
        void clear_buffer();
        friend std::ostream& operator<<(std::ostream& out, const BasicProgram& program);
        friend std::istream& operator>>(std::istream& in, BasicProgram& program);
        virtual void update() = 0;
        virtual std::shared_ptr<BasicProgram> create_program(const ProgramInfo& info, ProgramType type, std::size_t period) = 0;
    };
}
#endif // BASICPROGRAM_H
