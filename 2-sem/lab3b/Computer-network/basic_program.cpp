#include "basic_program.h"
namespace cn
{
    std::ostream& operator<<(std::ostream& out, const BasicProgram& program)
    {
        out << "Server: " << program.info.server_name
            << ", program: " << program.info.program_name <<", buffer:\n"
            << program.buffer.str();
        return out;
    }
    BasicProgram::BasicProgram(const QVector<QString>& textes,
                               const ProgramInfo& info, ProgramType type, std::size_t period):
        textes{textes},info{info}, type{type}, period{period} {}
    ProgramInfo BasicProgram::get_info() const
    {
        return info;
    }
    QString BasicProgram::create_text()
    {
       return textes[rand()%textes.size()];
    }
    void BasicProgram::send(std::shared_ptr<BasicProgram> other_program, MessageType type)
    {
        Message message(info, create_text(), type,other_program->get_info(),
                        rand()%SIZE_MAX);
        other_program->receive(message);
    }
    void BasicProgram::receive(const Message& message)
    {
        buffer << message << std::endl;
    }
    BasicProgram::BasicProgram( const QVector<QString>& textes):
        textes{textes}, info{ProgramInfo()}, type{ProgramType::ALL}, period{0}{}
}

