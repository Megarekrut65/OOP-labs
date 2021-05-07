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
    QString type_to_string(ProgramType type);
    class BasicProgram
    {
    protected:
        std::stringstream buffer;
        const QVector<QString>& textes;
        ProgramInfo info;
        ProgramType type;
        std::size_t period;
        QString sending_type;
        QString create_text();
    public:
        BasicProgram( const QVector<QString>& textes, const ProgramInfo& info,
                      ProgramType type, std::size_t period, const QString& sending_type);
        BasicProgram( const QVector<QString>& textes, const QString& sending_type);
        void send(std::shared_ptr<BasicProgram> other_program, MessageType type = MessageType::NONE);
        void receive(const Message& message);
        ProgramInfo get_info() const;
        ProgramType get_type() const;
        std::size_t get_period() const;
        QString get_sending_type() const;
        friend std::ostream& operator<<(std::ostream& out, const BasicProgram& program);
        virtual void update() = 0;
        virtual std::shared_ptr<BasicProgram> create_program(const ProgramInfo& info, ProgramType type, std::size_t period) = 0;
    };
}
#endif // BASICPROGRAM_H
