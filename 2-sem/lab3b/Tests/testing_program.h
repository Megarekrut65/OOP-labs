#ifndef TESTING_PROGRAM_H
#define TESTING_PROGRAM_H
#include "doctest.h"
#include "../Computer-network/programs.h"

TEST_CASE("testing creating")
{
    std::shared_ptr<cnet::BasicProgram> program = nullptr;
    cnet::ProgramInfo info = {"server","program"};
    cnet::ProgramType type = cnet::ProgramType::BOTH;
    std::size_t period = 10;
    QVector<QString> textes;
    SUBCASE("Periodic program")
    {
        program = std::make_shared<cnet::PeriodicProgram>(textes,info, type, period);
        CHECK(program->get_sending_type()=="Periodic sending");
    }
    SUBCASE("Random program")
    {
        program = std::make_shared<cnet::RandomProgram>(textes,info, type, period);
        CHECK(program->get_sending_type()=="Random sending");
    }
    SUBCASE("After program")
    {
        program = std::make_shared<cnet::AfterProgram>(textes,info, type, period);
        CHECK(program->get_sending_type()=="After receive");
    }
    SUBCASE("Wait program")
    {
        program = std::make_shared<cnet::WaitProgram>(textes,info, type, period);
        CHECK(program->get_sending_type()=="Wait for receive");
    }
}
#endif // TESTING_PROGRAM_H
