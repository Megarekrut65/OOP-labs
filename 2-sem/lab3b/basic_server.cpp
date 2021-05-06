#include "basic_server.h"

namespace cn
{
    void BasicServer::add_program(const QString& program_name, std::shared_ptr<BasicProgram> program)
    {
        programs[program_name] = program;
    }
    std::shared_ptr<BasicProgram> BasicServer::get_program(const QString& name)
    {
        if(programs.contains(name)) return programs[name];
        return nullptr;
    }
    QString BasicServer::get_name() const
    {
        return server_name;
    }
    BasicServer::BasicServer(const QString& server_name):server_name(server_name){}
    std::shared_ptr<BasicProgram> BasicServer::get_random_program()
    {
        auto names = programs.keys();
        return programs[names[rand()%names.size()]];
    }
}
