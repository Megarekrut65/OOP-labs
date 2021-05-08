#include "basic_program.h"
#include "servers.h"
namespace cn
{
    std::shared_ptr<BasicProgram> BasicProgram::get_other_program()
    {
        if(type == ProgramType::SEND ||type == ProgramType::BOTH)
        {
            auto server = cn::Servers::get_random_server();
            if(server)
            {
                auto program = server->get_random_program();
                if(program.get() != this) return program;
            }
        }
        return nullptr;
    }
    QString BasicProgram::get_sending_type() const
    {
        return sending_type;
    }
    QString type_to_string(ProgramType type)
    {
        switch (type)
        {
            case ProgramType::SEND: return "Send";
            case ProgramType::RECEIVE: return "Receive";
        default:break;
        }
        return "Send and Receive";
    }
    ProgramType BasicProgram::get_type() const
    {
        return type;
    }
    std::size_t BasicProgram::get_period() const
    {
        return period;
    }
    std::ostream& operator<<(std::ostream& out, const BasicProgram& program)
    {
        out << "Server: " << program.info.server_name
            << ", program: " << program.info.program_name <<", buffer:\n"
            << program.buffer.str();
        return out;
    }
    BasicProgram::BasicProgram(const QVector<QString>& textes,
                               const ProgramInfo& info, ProgramType type,
                               std::size_t period, const QString& sending_type):
        textes{textes},info{info}, type{type}, period{period},sending_type{sending_type} {}
    BasicProgram::~BasicProgram()
    {
        buffer.clear();
    }
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
        if(!other_program || this->type == ProgramType::RECEIVE) return;
        Message message(info, create_text(), type,other_program->get_info(),
                        rand()%SIZE_MAX);
        other_program->receive(message);
    }
    void BasicProgram::receive(const Message& message)
    {
        if(this->type == ProgramType::SEND) return;
        buffer << message << std::endl;
    }
    BasicProgram::BasicProgram( const QVector<QString>& textes,const QString& sending_type):
        textes{textes}, info{ProgramInfo()}, type{ProgramType::BOTH}, period{0},sending_type{sending_type}{}
}

