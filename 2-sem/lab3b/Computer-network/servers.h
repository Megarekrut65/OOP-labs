#ifndef SERVERS_H
#define SERVERS_H
#include "basic_server.h"

namespace cnet
{
    class Servers
    {
    private:
        static QMap<QString, std::shared_ptr<BasicServer>> all_servers;
        static double acceleration_factor;
        static std::mutex mut;
    public:
        static std::mutex& get_mutex();
        static double get_acceleration_factor();
        static void set_acceleration_factor(double acceleration_factor);
        static void add_server(std::shared_ptr<BasicServer> server);
        static void remove_server(const QString& server_name, const QString& folder_name);
        static std::shared_ptr<BasicServer> get_server(const QString& server_name);
        static QList<QString> get_servers_names();
        static std::shared_ptr<BasicServer> get_random_server();
        static void clear();
        static void remove_all(const QString& folder_name);
        static void save_settings(const QString& path, const QString& folder_name = "");
        static void read_settings(const QString& path, const QString& folder_name = "");
        static void save_all_servers(const QString& path, const QString& folder_name = "");
        static void add_saved_servers(ProgramRegistry& registry, const QString& path, const QString& folder_name = "");
    };
}
#endif // SERVERS_H
