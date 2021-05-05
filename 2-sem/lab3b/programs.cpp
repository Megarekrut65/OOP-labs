#include "programs.h"

namespace cn
{
    PeriodicProgram::PeriodicProgram(
            const QVector<QString>& textes,
            const ProgramInfo& info, ProgramType& type):BasicProgram{textes,info,type}{}
    void PeriodicProgram::update()
    {

    }
    RandomProgram::RandomProgram(
            const QVector<QString>& textes,
            const ProgramInfo& info, ProgramType& type):BasicProgram{textes,info,type}{}
    void RandomProgram::update()
    {

    }
    AfterProgram::AfterProgram(
            const QVector<QString>& textes,
            const ProgramInfo& info, ProgramType& type):BasicProgram{textes,info,type}{}
    void AfterProgram::update()
    {

    }
    WaitProgram::WaitProgram(
            const QVector<QString>& textes,
            const ProgramInfo& info, ProgramType& type):BasicProgram{textes,info,type}{}
    void WaitProgram::update()
    {

    }
}
