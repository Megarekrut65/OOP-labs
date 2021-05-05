#ifndef BASICSERVER_H
#define BASICSERVER_H
#include "program_factory.h"
#include <QMap>
namespace cn
{
    class BasicServer
    {
    private:
        QMap<QString, std::shared_ptr<BasicProgram>> programs;
        QString server_name;
        ProgramFactory factory;
    public:
        void create_new_periodic_program(ProgramType type, const QString& program_name);
        void create_new_random_program(ProgramType type, const QString& program_name);
        void create_new_after_program(ProgramType type, const QString& program_name);
        void create_new_wait_program(ProgramType type, const QString& program_name);
        QString get_name() const;
    };

}
#endif // BASICSERVER_H
