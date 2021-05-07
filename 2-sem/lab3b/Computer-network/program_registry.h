#ifndef PROGRAM_REGISTRY_H
#define PROGRAM_REGISTRY_H
#include "programs.h"
#include <QMap>

namespace cn
{
    class ProgramRegistry
    {
    private:
        QMap<QString, std::shared_ptr<BasicProgram>> programs_prototype;

    public:
        void registry_type(const QString& type, std::shared_ptr<BasicProgram> prototype);
        void registry_type(std::shared_ptr<BasicProgram> prototype);
        std::shared_ptr<BasicProgram> get_prototype(const QString& type);
        std::shared_ptr<BasicProgram> create_by_prototype(
                const QString& type,const ProgramInfo& info,
                const ProgramType& program_type, std::size_t period);
        QList<QString> get_all_types();
    };
}

#endif // PROGRAM_REGISTRY_H
