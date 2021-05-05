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
                "Are you creizy?",
                "Just do it!",
                "There is amazing weather today, isn't?",
                "Banana man...",
                "Go away!",
                "Potatos roal"};
    }

    std::shared_ptr<BasicProgram> ProgramFactory::create_program(
            ProgramFactoryType factory_type, ProgramType type, const ProgramInfo& info, std::size_t period)
    {
        switch (factory_type)
        {
            case ProgramFactoryType::PERIODIC:
            return std::make_shared<PeriodicProgram>(textes, info, type, period);
            case ProgramFactoryType::RANDOM:
            return std::make_shared<RandomProgram>(textes, info, type, period);
            case ProgramFactoryType::AFTER:
            return std::make_shared<AfterProgram>(textes, info, type, period);
        default:
            break;
        }
        return std::make_shared<WaitProgram>(textes, info, type, period);
    }
    std::shared_ptr<BasicProgram> ProgramFactory::create_periodic_program(
            ProgramType type, const ProgramInfo& info, std::size_t period)
    {
        return create_program(ProgramFactoryType::PERIODIC, type, info, period);
    }
    std::shared_ptr<BasicProgram> ProgramFactory::create_random_program(
            ProgramType type, const ProgramInfo& info, std::size_t period)
    {
        return create_program(ProgramFactoryType::RANDOM, type, info, period);
    }
    std::shared_ptr<BasicProgram> ProgramFactory::create_after_program(
            ProgramType type, const ProgramInfo& info, std::size_t period)
    {
        return create_program(ProgramFactoryType::AFTER, type, info, period);
    }
    std::shared_ptr<BasicProgram> ProgramFactory::create_wait_program(
            ProgramType type, const ProgramInfo& info, std::size_t period)
    {
        return create_program(ProgramFactoryType::WAIT, type, info, period);
    }
}
