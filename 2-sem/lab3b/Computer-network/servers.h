#ifndef SERVERS_H
#define SERVERS_H
#include "basic_server.h"

namespace cnm
{
    /*!
    *   \brief Class with static members and methods to save all servers in same place
    */
    class Servers
    {
    private:
        static QMap<QString, std::shared_ptr<BasicServer>> all_servers;/*!< Map to get pointer to server by name */
        static double acceleration_factor;/*!< Factor of acceleration */
        static std::mutex mut;/*!< Mutex to lock threads */
    public:
        /*!
        *   \brief Returns reference to mut
        */
        static std::mutex& get_mutex();
        /*!
        *   \brief Returns acceleration_factor
        */
        static double get_acceleration_factor();
        /*!
        *   \brief Edits acceleration_factor
        */
        static void set_acceleration_factor(double acceleration_factor);
        /*!
        *   \brief Adds server to all servers
        *
        *   Can not add two or more servers with same name.
        *
        *   \param server - server to add
        */
        static void add_server(std::shared_ptr<BasicServer> server);
        /*!
        *   \brief Removes server from all servers and server file
        *
        *   If there is not the server with name than do nothing.
        *
        *   \param server_name - name of server to remove
        *   \param folder_name - name of folder
        */
        static void remove_server(const QString& server_name, const QString& folder_name);
        /*!
        *   \brief Gets server by name
        *
        *   \returns - pointer to server if there is the server with server_name
        *   \returns - nullptr else
        */
        static std::shared_ptr<BasicServer> get_server(const QString& server_name);
        /*!
        *   \brief Returns list with all names of all servers
        */
        static QList<QString> get_servers_names();
        /*!
        *   \brief Returns random server from all servers
        */
        static std::shared_ptr<BasicServer> get_random_server();
        /*!
        *   \brief Removes all servers from memory
        */
        static void clear();
        /*!
        *   \brief Removes all servers from memory and files
        *
        *   \param folder_name - name of folder
        */
        static void remove_all(const QString& folder_name);
        /*!
        *   \brief Saves settings to setting file
        *
        *   \param path - path to file with settings
        *   \param folder_name - name of folder
        */
        static void save_settings(const QString& path, const QString& folder_name = "");
        /*!
        *   \brief Reads settings from setting file
        *
        *   \param path - path to file with settings
        *   \param folder_name - name of folder
        *
        */
        static void read_settings(const QString& path, const QString& folder_name = "");
        /*!
        *   \brief Saves all servers to their files
        *
        *   \param path - path to file with servers names
        *   \param folder_name - name of folder
        */
        static void save_all_servers(const QString& path, const QString& folder_name = "");
        /*!
        *   \brief Adds servers from file to all servers
        *
        *   \param registry - program registry to create empty programs
        *   \param path - path to file with servers names
        *   \param folder_name - name of folder
        *
        */
        static void add_saved_servers(ProgramRegistry& registry, const QString& path, const QString& folder_name = "");
    };
}
#endif // SERVERS_H
