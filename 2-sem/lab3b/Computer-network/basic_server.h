#ifndef BASICSERVER_H
#define BASICSERVER_H
#include "program_registry.h"
#include <fstream>

namespace cnm
{
    /*!
    *   \brief Struct to save upload and download speeds
    */
    struct Speed
    {
       std::size_t upload;/*!< Upload speed */
       std::size_t download;/*!< Downdload speed */
       /*!
       *   \brief Parameterized constructor
       *
       *   \param upload - upload speed
       *   \param download - downdload speed
       */
       Speed(std::size_t upload = 0, std::size_t download = 0);
    };
    /*!
    *   \brief Operator<< for Speed
    *
    *   Makes lines as:
    *
    *   Upload-speed=upload
    *
    *   Download-speed=download
    */
    std::ostream& operator<<(std::ostream& out, const Speed& speed);
    /*!
    *   \brief Operator>> for Speed
    *
    *   Adds parameters from istream to speed
    */
    std::istream& operator>>(std::istream& in, Speed& speed);
    /*!
    *   \brief A class for representing a server on a computer network
    *
    *   Server capabilities:
    *
    *   - add program to server;
    *
    *   - remove program from server;
    *
    *   - write all added programs to file;
    *
    *   - read all added programs from file;
    *
    *   - get program by name;
    *
    *   - get random program;
    *
    *   - get names of all programs.
    */
    class BasicServer
    {
    private:
        QMap<QString, std::shared_ptr<BasicProgram>> programs;/*!< Map to get pointer to program by program name */
        QString server_name;/*!< Name of server */
        Speed speed;/*!< Upload and sownload speeds */
        /*!
        *   \brief Creates path to file with programs
        *
        *   Add to folder_name '/' and server name and '.txt'
        *
        *   \param folder_name - name of folder with datas
        *   \returns correct path to file with programs of this server
        */
        std::string make_path(const QString& folder_name = "");
    public:
        /*!
        *   \brief Parameterized constructor
        *
        *   \param server_name - name of server
        *   \param speed - upload and download server speeds
        */
        BasicServer(const QString& server_name = "none", Speed speed = Speed());
        /*!
        *   \brief Adds program to server
        *
        *   Can not add two or more programs with same name.
        *
        *   \param program_name - name of program to add
        *   \param program - pointer to program
        */
        void add_program(const QString& program_name, std::shared_ptr<BasicProgram> program);
        /*!
        *   \brief Removes program from server
        *
        *   If there is not the program with this name than do nothing
        *
        *   \param program_name - name of program to remove
        */
        void remove_program(const QString& program_name);
        /*!
        *   \brief Gets program by name
        *
        *   \param name - name of program
        *   \returns - pointer to program if there is the program with name
        *   \returns - nullptr else
        */
        std::shared_ptr<BasicProgram> get_program(const QString& name);
        /*!
        *   \brief Returns name
        */
        QString get_name() const;
        /*!
        *   \brief Returns speed
        */
        Speed get_speed() const;
        /*!
        *   \brief Returns random program from this server
        */
        std::shared_ptr<BasicProgram> get_random_program();
        /*!
        *   \brief Returns list with all programs names
        */
        QList<QString> get_programs_names();
        /*!
        *   \brief Clears program from memory
        */
        void clear();
        /*!
        *   \brief Adds programs to file
        *
        *   \param folder_name - name of folder
        */
        void add_to_own_file(const QString& folder_name = "");
        /*!
        *   \brief Reads ans adds programs from file
        *
        *   \param registry - program registry to create empty program
        *   \param folder_name - name of folder
        */
        void get_from_own_file(ProgramRegistry& registry, const QString& folder_name = "");
        /*!
        *   \brief Clears program from memory and delete server file
        *   \param folder_name - name of folder
        */
        void clear_own_file(const QString& folder_name = "");
        /*!
        *   \brief Removes all programs
        */
        ~BasicServer();
    };

}
#endif // BASICSERVER_H
