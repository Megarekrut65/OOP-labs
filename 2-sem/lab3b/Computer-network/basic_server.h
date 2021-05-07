#ifndef BASICSERVER_H
#define BASICSERVER_H
#include "programs.h"

namespace cn
{
    class BasicServer
    {
    private:
        QMap<QString, std::shared_ptr<BasicProgram>> programs;
        QString server_name;
    public:
        BasicServer(const QString& server_name);
        void add_program(const QString& program_name, std::shared_ptr<BasicProgram> program);
        void remove_program(const QString& program_name);
        std::shared_ptr<BasicProgram> get_program(const QString& name);
        QString get_name() const;
        std::shared_ptr<BasicProgram> get_random_program();
    };

}
#endif // BASICSERVER_H
