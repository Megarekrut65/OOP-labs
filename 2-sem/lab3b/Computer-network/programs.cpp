#include "programs.h"
#include "servers.h"
namespace cn
{
    PeriodicProgram::PeriodicProgram(const QVector<QString>& textes):BasicProgram{textes}{}
    PeriodicProgram::PeriodicProgram(
            const QVector<QString>& textes,
            const ProgramInfo& info, ProgramType& type, std::size_t period):
          BasicProgram{textes,info,type, period}{}
    void PeriodicProgram::update()
    {

    }
    std::shared_ptr<BasicProgram> PeriodicProgram::create_program(
            const ProgramInfo& info, ProgramType& type, std::size_t period)
    {
        return std::make_shared<PeriodicProgram>(this->textes, info, type, period);
    }
    RandomProgram::RandomProgram(const QVector<QString>& textes):BasicProgram{textes}{}
    RandomProgram::RandomProgram(
            const QVector<QString>& textes,
            const ProgramInfo& info, ProgramType& type, std::size_t period):
        BasicProgram{textes,info,type, period}{}
    void RandomProgram::update()
    {

    }
    std::shared_ptr<BasicProgram> RandomProgram::create_program(
            const ProgramInfo& info, ProgramType& type, std::size_t period)
    {
        return std::make_shared<RandomProgram>(this->textes, info, type, period);
    }
    AfterProgram::AfterProgram(const QVector<QString>& textes):BasicProgram{textes}{}
    AfterProgram::AfterProgram(
            const QVector<QString>& textes,
            const ProgramInfo& info, ProgramType& type, std::size_t period):
        BasicProgram{textes,info,type, period}{}
    void AfterProgram::update()
    {

    }
    std::shared_ptr<BasicProgram> AfterProgram::create_program(
            const ProgramInfo& info, ProgramType& type, std::size_t period)
    {
        return std::make_shared<AfterProgram>(this->textes, info, type, period);
    }
    WaitProgram::WaitProgram(const QVector<QString>& textes):BasicProgram{textes}{}
    WaitProgram::WaitProgram(
            const QVector<QString>& textes,
            const ProgramInfo& info, ProgramType& type, std::size_t period):
        BasicProgram{textes,info,type, period}{}
    void WaitProgram::update()
    {

    }
    std::shared_ptr<BasicProgram> WaitProgram::create_program(
            const ProgramInfo& info, ProgramType& type, std::size_t period)
    {
        return std::make_shared<WaitProgram>(this->textes, info, type, period);
    }
}
