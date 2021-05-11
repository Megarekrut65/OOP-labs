#ifndef TESTING_PROGRAM_H
#define TESTING_PROGRAM_H
#include "doctest.h"
#include "../Computer-network/programs.h"

TEST_CASE("testing creating")
{
    std::shared_ptr<cnm::BasicProgram> program = nullptr;
    cnm::ProgramInfo info = {"server","program"};
    cnm::ProgramType type = cnm::ProgramType::BOTH;
    std::size_t period = 10;
    QVector<QString> textes;
    SUBCASE("Periodic program")
    {
        program = std::make_shared<cnm::PeriodicProgram>(textes,info, type, period);
        CHECK(program->get_sending_type()=="Periodic sending");
    }
    SUBCASE("Random program")
    {
        program = std::make_shared<cnm::RandomProgram>(textes,info, type, period);
        CHECK(program->get_sending_type()=="Random sending");
    }
    SUBCASE("After program")
    {
        program = std::make_shared<cnm::AfterProgram>(textes,info, type, period);
        CHECK(program->get_sending_type()=="After receive");
    }
    SUBCASE("Wait program")
    {
        program = std::make_shared<cnm::WaitProgram>(textes,info, type, period);
        CHECK(program->get_sending_type()=="Wait for receive");
    }
}
#endif // TESTING_PROGRAM_H
