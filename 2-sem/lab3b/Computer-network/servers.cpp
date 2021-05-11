#include "servers.h"

namespace cn
{
    std::mutex Servers::mut = std::mutex();
    QMap<QString, std::shared_ptr<BasicServer>> Servers::all_servers = QMap<QString, std::shared_ptr<BasicServer>>();
    float Servers::acceleration_factor = 1.f;
    std::mutex& Servers::get_mutex()
    {
        return mut;
    }
    float Servers::get_acceleration_factor()
    {
        return acceleration_factor;
    }
    void Servers::set_acceleration_factor(float acceleration_factor)
    {
        Servers::acceleration_factor = acceleration_factor;
    }
    void Servers::clear()
    {
        std::lock_guard<std::mutex> lock(Servers::mut);
        all_servers.clear();
    }
 void Servers::add_server(std::shared_ptr<BasicServer> server)
    {
        if(server->get_name() != "")
            all_servers[server->get_name()] = server;
    }
    void Servers::remove_server(const QString& server_name, const QString& folder_name)
    {
        std::lock_guard<std::mutex> lock(Servers::mut);
        if(all_servers.contains(server_name) && all_servers[server_name] != nullptr)
            all_servers[server_name]->clear_own_file(folder_name);
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
        std::ofstream file((folder_name+"/"+path).toStdString());
        file << "Servers:" << std::endl;
        QList<QString> servers_list = all_servers.keys();
        for(auto& key:servers_list)
        {
            if(all_servers[key] == nullptr) continue;
            all_servers[key]->add_to_own_file(folder_name);
            file << all_servers[key]->get_name() << std::endl;
        }
        file.close();
    }
    void Servers::add_saved_servers(ProgramRegistry& registry, const QString& path, const QString& folder_name)
    {
        std::ifstream file((folder_name+"/"+path).toStdString());
        std::string line;
        std::getline(file, line);
        while(!file.eof())
        {
            std::getline(file, line);
            auto server = std::make_shared<BasicServer>(line.c_str());
            server->get_from_own_file(registry, folder_name);
            add_server(server);
        }
        file.close();
    }
    QList<QString> Servers::get_servers_names()
    {
        return all_servers.keys();
    }
    void Servers::remove_all(const QString& folder_name)
    {
        QList<QString> keys = get_servers_names();
        for(auto& key:keys)
            remove_server(key, folder_name);
    }
}
