#ifndef PROGRAM_REGISTRY_H
#define PROGRAM_REGISTRY_H
#include "programs.h"
#include <QMap>

namespace cnm
{
    /*!
    *   \brief Class to save and get saved ptototypes of program by ptototype name
    */
    class ProgramRegistry
    {
    private:
        QMap<QString, std::shared_ptr<BasicProgram>> programs_prototype;/*!< Map to get pointer to some program by name of ptototype */

    public:
        /*!
        *   \brief Adds type and prototype to map
        *
        *   \param type - name of program ptototype
        *   \param prototype - ptototype of program
        */
        void registry_type(const QString& type, std::shared_ptr<BasicProgram> prototype);
        /*!
        *   \brief Adds type and prototype to map
        *
        *   But gives type with program prototype.
        *   \param prototype - ptototype of program
        */
        void registry_type(std::shared_ptr<BasicProgram> prototype);
        /*!
        *   \brief Returns prototype of program by type
        *
        *   \param type - name of program prototype
        */
        std::shared_ptr<BasicProgram> get_prototype(const QString& type);
        /*!
        *   \brief Creates program with parameters by prototype
        *
        *   \param type - type of program prototype
        *   \param info - information about server and program names
        *   \param program_type - type of program(not prototype)
        *   \param period - period of messages sending
        */
        std::shared_ptr<BasicProgram> create_by_prototype(
                const QString& type,const ProgramInfo& info,
                const ProgramType& program_type, std::size_t period);
        /*!
        *   \brief Returns list with all names of prototypes
        */
        QList<QString> get_all_types();
    };
}

#endif // PROGRAM_REGISTRY_H
