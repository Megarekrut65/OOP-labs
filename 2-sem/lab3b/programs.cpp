#include "programs.h"

namespace cn
{
    PeriodicProgram::PeriodicProgram(
            const QVector<QString>& textes,
            const ProgramInfo& info, ProgramType& type, std::size_t period):
          BasicProgram{textes,info,type, period}{}
    void PeriodicProgram::update()
    {

    }
    RandomProgram::RandomProgram(
            const QVector<QString>& textes,
            const ProgramInfo& info, ProgramType& type, std::size_t period):
        BasicProgram{textes,info,type, period}{}
    void RandomProgram::update()
    {

    }
    AfterProgram::AfterProgram(
            const QVector<QString>& textes,
            const ProgramInfo& info, ProgramType& type, std::size_t period):
        BasicProgram{textes,info,type, period}{}
    void AfterProgram::update()
    {

    }
    WaitProgram::WaitProgram(
            const QVector<QString>& textes,
            const ProgramInfo& info, ProgramType& type, std::size_t period):
        BasicProgram{textes,info,type, period}{}
    void WaitProgram::update()
    {

    }
}
