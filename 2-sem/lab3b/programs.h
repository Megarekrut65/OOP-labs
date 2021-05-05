#ifndef PROGRAMS_H
#define PROGRAMS_H
#include <memory>
#include "message.h"
#include <sstream>
#include <mutex>
#include <thread>
#include <vector>
/*!
*   \brief computer network
*/
namespace cn
{
    class Program
    {
    private:
        std::stringstream buffer;
        const QVector<QString>& textes;
        ProgramInfo info;
        QString create_text();
    public:
        Program( const QVector<QString>& textes, const ProgramInfo& info);
        virtual void send(std::shared_ptr<Program> other_program, MessageType type = MessageType::NONE);
        virtual void receive(const Message& message);
        ProgramInfo get_info() const;
        friend std::ostream& operator<<(std::ostream& out, const Program& program);
    };
    /*class SendProgram: public Program
    {
        void receive(const Message& message) override = 0;
    };
    class ReceiveProgram: public Program
    {
        void send(std::shared_ptr<Program> other_program, MessageType type = MessageType::NONE) override = 0 ;
    };
    class SendReceiveProgram: public Program{};*/
}

#endif // PROGRAMS_H
