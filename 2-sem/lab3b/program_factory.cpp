#include "program_factory.h"

namespace cn
{
    ProgramFactory::ProgramFactory()
    {
        textes = {
                "Hello, wold!",
                "How are you doing?",
                "Mama Mia!",
                "Guten Tag!",
                "Are you creizy?"};
    }

    std::shared_ptr<BasicProgram> ProgramFactory::create_program(
            ProgramFactoryType factory_type, ProgramType type, const ProgramInfo& info)
    {
        switch (factory_type)
        {
            case ProgramFactoryType::PERIODIC: return std::make_shared<PeriodicProgram>(textes, info, type);
            case ProgramFactoryType::RANDOM: return std::make_shared<RandomProgram>(textes, info, type);
            case ProgramFactoryType::AFTER: return std::make_shared<AfterProgram>(textes, info, type);
        default:
            break;
        }
        return std::make_shared<WaitProgram>(textes, info, type);
    }
    std::shared_ptr<BasicProgram> ProgramFactory::create_periodic_program(ProgramType type, const ProgramInfo& info)
    {
        return create_program(ProgramFactoryType::PERIODIC, type, info);
    }
    std::shared_ptr<BasicProgram> ProgramFactory::create_random_program(ProgramType type, const ProgramInfo& info)
    {
        return create_program(ProgramFactoryType::RANDOM, type, info);
    }
    std::shared_ptr<BasicProgram> ProgramFactory::create_after_program(ProgramType type, const ProgramInfo& info)
    {
        return create_program(ProgramFactoryType::AFTER, type, info);
    }
    std::shared_ptr<BasicProgram> ProgramFactory::create_wait_program(ProgramType type, const ProgramInfo& info)
    {
        return create_program(ProgramFactoryType::WAIT, type, info);
    }
}
