#include "programs.h"
namespace cnm
{
    PeriodicProgram::PeriodicProgram(const QVector<QString>& textes):BasicProgram{textes,"Periodic sending"}{}
    PeriodicProgram::PeriodicProgram(
            const QVector<QString>& textes,
            const ProgramInfo& info, ProgramType type, std::size_t period):
          BasicProgram{textes,info,type, period,"Periodic sending"}{}
    void PeriodicProgram::update()
    {
        auto program = this->get_other_program();
        this->send(program, MessageType::INFO);
    }
    std::shared_ptr<BasicProgram> PeriodicProgram::create_program(
            const ProgramInfo& info, ProgramType type, std::size_t period)
    {
        return std::make_shared<PeriodicProgram>(this->textes, info, type, period);
    }
    RandomProgram::RandomProgram(const QVector<QString>& textes):BasicProgram{textes,"Random sending"}{}
    RandomProgram::RandomProgram(
            const QVector<QString>& textes,
            const ProgramInfo& info, ProgramType type, std::size_t period):
        BasicProgram{textes,info,type, period,"Random sending"}{}
    void RandomProgram::update()
    {
        auto program = this->get_other_program();
        this->send(program, MessageType::ERROR);
    }
    std::shared_ptr<BasicProgram> RandomProgram::create_program(
            const ProgramInfo& info, ProgramType type, std::size_t period)
    {
        return std::make_shared<RandomProgram>(this->textes, info, type, period);
    }
    AfterProgram::AfterProgram(const QVector<QString>& textes):BasicProgram{textes,"After receive"}{}
    AfterProgram::AfterProgram(
            const QVector<QString>& textes,
            const ProgramInfo& info, ProgramType type, std::size_t period):
        BasicProgram{textes,info,type, period,"After receive"}{}
    void AfterProgram::update()
    {
        auto program = this->get_other_program();
        this->send(program, MessageType::WARNING);
    }
    std::shared_ptr<BasicProgram> AfterProgram::create_program(
            const ProgramInfo& info, ProgramType type, std::size_t period)
    {
        return std::make_shared<AfterProgram>(this->textes, info, type, period);
    }
    WaitProgram::WaitProgram(const QVector<QString>& textes):BasicProgram{textes,"Wait for receive"}{}
    WaitProgram::WaitProgram(
            const QVector<QString>& textes,
            const ProgramInfo& info, ProgramType type, std::size_t period):
        BasicProgram{textes,info,type, period,"Wait for receive"}{}
    void WaitProgram::update()
    {
        auto program = this->get_other_program();
        this->send(program, MessageType::NONE);
    }
    std::shared_ptr<BasicProgram> WaitProgram::create_program(
            const ProgramInfo& info, ProgramType type, std::size_t period)
    {
        return std::make_shared<WaitProgram>(this->textes, info, type, period);
    }
}
