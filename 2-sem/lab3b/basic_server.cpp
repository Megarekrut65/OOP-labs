#include "basic_server.h"

namespace cn
{
    void BasicServer::create_new_periodic_program(
            ProgramType type, const QString& program_name, std::size_t period)
    {
        programs[program_name] = factory.create_periodic_program(
                    type,
                    ProgramInfo(server_name,program_name), period);
    }
    void BasicServer::create_new_random_program(
            ProgramType type, const QString& program_name, std::size_t period)
    {
        programs[program_name] = factory.create_random_program(
                    type,
                    ProgramInfo(server_name,program_name), period);
    }
    void BasicServer::create_new_after_program(
            ProgramType type, const QString& program_name, std::size_t period)
    {
        programs[program_name] = factory.create_after_program(
                    type,
                    ProgramInfo(server_name,program_name), period);
    }
    void BasicServer::create_new_wait_program(
            ProgramType type, const QString& program_name, std::size_t period)
    {
        programs[program_name] = factory.create_wait_program(
                    type,
                    ProgramInfo(server_name,program_name), period);
    }
    QString BasicServer::get_name() const
    {
        return server_name;
    }
    BasicServer::BasicServer(const QString& server_name):server_name(server_name){}
}
