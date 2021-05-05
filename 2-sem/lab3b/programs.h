#ifndef PROGRAMS_H
#define PROGRAMS_H
#include "basic_program.h"

namespace cn
{

    class PeriodicProgram: public BasicProgram
    {
    private:

    public:

        PeriodicProgram(const QVector<QString>& textes, const ProgramInfo& info, ProgramType& type, std::size_t period);
        void update() override;
    };
    class RandomProgram: public BasicProgram
    {
    public:
        RandomProgram(const QVector<QString>& textes, const ProgramInfo& info, ProgramType& type, std::size_t period);
        void update() override;
    };
    class AfterProgram: public BasicProgram
    {
    public:
        AfterProgram(const QVector<QString>& textes, const ProgramInfo& info, ProgramType& type, std::size_t period);
        void update() override;
    };
    class WaitProgram: public BasicProgram
    {
    public:
        WaitProgram(const QVector<QString>& textes, const ProgramInfo& info, ProgramType& type, std::size_t period);
        void update() override;
    };
}

#endif // PROGRAMS_H
