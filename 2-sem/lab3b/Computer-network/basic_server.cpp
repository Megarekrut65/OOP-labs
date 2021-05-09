#include "basic_server.h"

namespace cn
{
    void BasicServer::clear()
    {
        programs.clear();
    }
    void BasicServer::remove_program(const QString& program_name)
    {
        programs[program_name] = nullptr;
    }
    void BasicServer::add_program(const QString& program_name, std::shared_ptr<BasicProgram> program)
    {
        if(program_name != "") programs[program_name] = program;
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
    BasicServer::~BasicServer()
    {
        programs.clear();
    }
    std::shared_ptr<BasicProgram> BasicServer::get_random_program()
    {
        auto names = programs.keys();
        if(names.size()==0) return nullptr;
        return programs[names[rand()%names.size()]];
    }
    std::string BasicServer::make_path(const QString& folder_name)
    {
        QString folder = folder_name == ""?"":folder_name+"/";
        return (folder+server_name+".txt").toStdString();
    }
    void BasicServer::add_to_own_file(const QString& folder_name)
    {
        std::ofstream file(make_path(folder_name));
        QList<QString> keys = programs.keys();
        for(auto& key:keys)
            if(programs[key]) file << *programs[key] << std::endl;
        file.close();
    }
    void BasicServer::clear_own_file(const QString& folder_name)
    {
        std::remove(make_path(folder_name).c_str());
    }
    void BasicServer::get_from_own_file(ProgramRegistry& registry, const QString& folder_name)
    {
        std::ifstream file(make_path(folder_name));
        while(!file.eof())
        {
            QVector<QString> textes = {};
            std::shared_ptr<BasicProgram> program = std::make_shared<AfterProgram>(textes);
            file >>*program;
            if(program->get_info().program_name == "") break;
            auto the_program = registry.create_by_prototype(
                        program->get_sending_type(),
                        program->get_info(),
                        program->get_type(),
                        program->get_period());
            if(the_program) add_program(the_program->get_info().program_name, the_program);
        }
        file.close();
    }
    QList<QString> BasicServer::get_programs_names()
    {
        return programs.keys();
    }
}
