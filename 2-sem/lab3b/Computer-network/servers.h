#ifndef SERVERS_H
#define SERVERS_H
#include "basic_server.h"

namespace cn
{
    class Servers
    {
    private:
        static QMap<QString, std::shared_ptr<BasicServer>> all_servers;
    public:
        static void add_server(std::shared_ptr<BasicServer> server);
        static std::shared_ptr<BasicServer> get_server(const QString& server_name);
        static std::shared_ptr<BasicServer> get_random_server();
    };
}
#endif // SERVERS_H
