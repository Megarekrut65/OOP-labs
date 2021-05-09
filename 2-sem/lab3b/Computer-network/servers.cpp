#include "servers.h"

namespace cn
{
    void Servers::clear()
    {
        all_servers.clear();
    }
    QMap<QString, std::shared_ptr<BasicServer>> Servers::all_servers = QMap<QString, std::shared_ptr<BasicServer>>();
    void Servers::add_server(std::shared_ptr<BasicServer> server)
    {
        all_servers[server->get_name()] = server;
    }
    void Servers::remove_server(const QString& server_name)
    {
        all_servers[server_name] = nullptr;
    }
    std::shared_ptr<BasicServer> Servers::get_server(const QString& server_name)
    {
        if(all_servers.contains(server_name)) return all_servers[server_name];
        return nullptr;
    }
    std::shared_ptr<BasicServer> Servers::get_random_server()
    {
        auto names = all_servers.keys();
        if(names.size()==0) return nullptr;
        return all_servers[names[rand()%names.size()]];
    }
    void Servers::save_all_servers(const QString& path, const QString& folder_name)
    {
        QList<QString> servers_list = all_servers.keys();
        std::ofstream file((folder_name+"/"+path).toStdString());
        file << "Servers:" << std::endl;
        for(auto& key:servers_list)
        {
            all_servers[key]->add_to_own_file();
            file << all_servers[key]->get_name() << std::endl;
        }
        file.close();
    }
    void Servers::get_saved_servers(const QString& path, const QString& folder_name)
    {
        std::ifstream file((folder_name+"/"+path).toStdString());
        std::string line;
        std::getline(file, line);
        while(!file.eof())
        {
            std::getline(file, line);
            auto server = std::make_shared<BasicServer>(line.c_str());
            server->get_from_own_file(folder_name);
            add_server(server);
        }
        file.close();
    }
    QList<QString> Servers::get_servers_names()
    {
        return all_servers.keys();
    }
}
