#ifndef BASICSERVER_H
#define BASICSERVER_H
#include "program_registry.h"
#include <fstream>

namespace cn
{
    class BasicServer
    {
    private:
        QMap<QString, std::shared_ptr<BasicProgram>> programs;
        QString server_name;
        std::string make_path(const QString& folder_name = "");
    public:
        BasicServer(const QString& server_name = "none");
        void add_program(const QString& program_name, std::shared_ptr<BasicProgram> program);
        void remove_program(const QString& program_name);
        std::shared_ptr<BasicProgram> get_program(const QString& name);
        QString get_name() const;
        std::shared_ptr<BasicProgram> get_random_program();
        QList<QString> get_programs_names();
        void clear();
        void add_to_own_file(const QString& folder_name = "");
        void get_from_own_file(ProgramRegistry& registry, const QString& folder_name = "");
        void clear_own_file(const QString& folder_name = "");
        ~BasicServer();
    };

}
#endif // BASICSERVER_H
