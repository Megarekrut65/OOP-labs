#ifndef PROGRAMS_H
#define PROGRAMS_H
#include "basic_program.h"

namespace cnet
{

    class PeriodicProgram: public BasicProgram
    {
    private:

    public:
        PeriodicProgram(const QVector<QString>& textes);
        PeriodicProgram(const QVector<QString>& textes, const ProgramInfo& info, ProgramType type, std::size_t period);
        void update() override;
        std::shared_ptr<BasicProgram> create_program(
                const ProgramInfo& info=ProgramInfo(),
                ProgramType type=ProgramType::BOTH, std::size_t period = 0) override;
    };
    class RandomProgram: public BasicProgram
    {
    public:
        RandomProgram(const QVector<QString>& textes);
        RandomProgram(const QVector<QString>& textes, const ProgramInfo& info, ProgramType type, std::size_t period);
        void update() override;
        std::shared_ptr<BasicProgram> create_program(
                const ProgramInfo& info=ProgramInfo(),
                ProgramType type=ProgramType::BOTH, std::size_t period = 0) override;
    };
    class AfterProgram: public BasicProgram
    {
    public:
        AfterProgram(const QVector<QString>& textes);
        AfterProgram(const QVector<QString>& textes, const ProgramInfo& info, ProgramType type, std::size_t period);
        void update() override;
        std::shared_ptr<BasicProgram> create_program(
                const ProgramInfo& info=ProgramInfo(),
                ProgramType type=ProgramType::BOTH, std::size_t period = 0) override;
    };
    class WaitProgram: public BasicProgram
    {
    public:
        WaitProgram(const QVector<QString>& textes);
        WaitProgram(const QVector<QString>& textes, const ProgramInfo& info, ProgramType type, std::size_t period);
        void update() override;
        std::shared_ptr<BasicProgram> create_program(
                const ProgramInfo& info=ProgramInfo(),
                ProgramType type=ProgramType::BOTH, std::size_t period = 0) override;
    };
}

#endif // PROGRAMS_H
