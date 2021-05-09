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
        static void remove_server(const QString& server_name);
        static std::shared_ptr<BasicServer> get_server(const QString& server_name);
        static QList<QString> get_servers_names();
        static std::shared_ptr<BasicServer> get_random_server();
        static void clear();
        static void save_all_servers(const QString& path, const QString& folder_name = "");
        static void get_saved_servers(const QString& path, const QString& folder_name = "");
    };
}
#endif // SERVERS_H
