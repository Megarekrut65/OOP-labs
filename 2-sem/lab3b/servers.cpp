#include "servers.h"

namespace cn
{
    QMap<QString, std::shared_ptr<BasicServer>> Servers::all_servers = QMap<QString, std::shared_ptr<BasicServer>>();
    void Servers::add_server(std::shared_ptr<BasicServer> server)
    {
        all_servers[server->get_name()] = server;
    }
    std::shared_ptr<BasicServer> Servers::get_server(const QString& server_name)
    {
        if(all_servers.contains(server_name)) return all_servers[server_name];
        return nullptr;
    }
}
