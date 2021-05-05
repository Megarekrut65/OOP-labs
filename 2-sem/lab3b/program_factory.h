#ifndef PROGRAM_FACTORY_H
#define PROGRAM_FACTORY_H
#include "programs.h"

namespace cn
{
    class ProgramFactory
    {
    private:
        enum class ProgramFactoryType
        {
            PERIODIC = 0,
            RANDOM,
            AFTER,
            WAIT
        };
        QVector<QString> textes;

        std::shared_ptr<BasicProgram> create_program(ProgramFactoryType factory_type, ProgramType type, const ProgramInfo& info);
    public:
        ProgramFactory();
        std::shared_ptr<BasicProgram> create_periodic_program(ProgramType type, const ProgramInfo& info);
        std::shared_ptr<BasicProgram> create_random_program(ProgramType type, const ProgramInfo& info);
        std::shared_ptr<BasicProgram> create_after_program(ProgramType type, const ProgramInfo& info);
        std::shared_ptr<BasicProgram> create_wait_program(ProgramType type, const ProgramInfo& info);
    };
}

#endif // PROGRAM_FACTORY_H
