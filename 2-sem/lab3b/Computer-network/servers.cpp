#include "servers.h"

namespace cn
{
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
        return all_servers[names[rand()%names.size()]];
    }
}
