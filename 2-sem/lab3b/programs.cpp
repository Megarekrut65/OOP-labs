#include "programs.h"

namespace cn
{
    std::ostream& operator<<(std::ostream& out, const Program& program)
    {
        out << "Server: " << program.info.server_name
            << ", program: " << program.info.program_name <<", buffer:\n"
            << program.buffer.str();
        return out;
    }
    Program::Program(const QVector<QString>& textes,  const ProgramInfo& info):
        textes{textes},info{info}{}
    ProgramInfo Program::get_info() const
    {
        return info;
    }
    QString Program::create_text()
    {
       return textes[rand()%textes.size()];
    }
    void Program::send(std::shared_ptr<Program> other_program, MessageType type)
    {
        Message message(info, create_text(), type,other_program->get_info(),
                        rand()%SIZE_MAX);
        other_program->receive(message);
    }
    void Program::receive(const Message& message)
    {
        buffer << message << std::endl;
    }
}
