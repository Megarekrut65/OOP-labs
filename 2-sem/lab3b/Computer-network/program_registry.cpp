#include "program_registry.h"

namespace cn
{
    void ProgramRegistry::registry_type(const QString& type, std::shared_ptr<BasicProgram> prototype)
    {
        programs_prototype[type] = prototype;
    }
    std::shared_ptr<BasicProgram> ProgramRegistry::get_prototype(const QString& type)
    {
        if(programs_prototype.contains(type)) return programs_prototype[type];
        return nullptr;
    }
    QList<QString> ProgramRegistry::get_all_types()
    {
        return programs_prototype.keys();
    }
    std::shared_ptr<BasicProgram> ProgramRegistry::create_by_prototype(
            const QString& type,const ProgramInfo& info,
            ProgramType& program_type, std::size_t period)
    {
        if(programs_prototype.contains(type))
            return programs_prototype[type]->create_program(info,program_type,period);
        return nullptr;
    }
}
