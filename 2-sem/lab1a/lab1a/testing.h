#pragma once
#include "doctest.h"
#include "memory_opening_mode.h"

TEST_CASE("testing the creating of monsters")
{
    std::shared_ptr<om::OpeningMode> open = std::make_shared<mmode::MemoryMode>();
    mon::Monster monster1("Big monster", 20, 10, 0.2, 
        mon::AttackTypes::CURE, open->get_time_now(), 1000);
    CHECK(monster1.get_name() == "Big monster");
    CHECK(monster1.get_hp() == 20);
    CHECK(monster1.get_damage() == 10);
    CHECK(monster1.get_chance() == doctest::Approx(0.2));
    CHECK(monster1.get_type() == mon::AttackTypes::CURE);
    CHECK(monster1.get_id() == 1000);//id is created manually, but you can use a function open->get_id()
    open->append_monster(monster1);//to id will be correct need to add monster to open mode
    mon::Monster monster2("Small monster", 202, 130, 0.21, 
        mon::AttackTypes::INCREASE, open->get_time_now(), open->get_id());
    CHECK(monster2.get_name() == "Small monster");
    CHECK(monster2.get_hp() == 202);
    CHECK(monster2.get_damage() == 130);
    CHECK(monster2.get_chance() == doctest::Approx(0.21));
    CHECK(monster2.get_type() == mon::AttackTypes::INCREASE);
    CHECK(monster2.get_id() == 1001);//next id after 1000
    open->append_monster(monster2);
}
TEST_CASE("Getting the monster by id")
{
    std::shared_ptr<om::OpeningMode> open = std::make_shared<mmode::MemoryMode>();
    mon::Monster monster1("Big monster", 20, 10, 0.2,
        mon::AttackTypes::CURE, open->get_time_now(), open->get_id());
    open->append_monster(monster1);
    mon::Monster monster2("Small monster", 120, 210, 0.22,
        mon::AttackTypes::CURE, open->get_time_now(), open->get_id());
    open->append_monster(monster2);
    mon::Monster monster4 = open->get_monster(monster2.get_id());
    CHECK(monster4.get_name() == monster2.get_name());
    CHECK(monster4.get_hp() == monster2.get_hp());
    CHECK(monster4.get_damage() == monster2.get_damage());
    CHECK(monster4.get_chance() == doctest::Approx(monster2.get_chance()));
    CHECK(monster4.get_type() == monster2.get_type());
    CHECK(monster4.get_id() == monster2.get_id());
}
TEST_CASE("Deleting monsters")
{
    std::shared_ptr<om::OpeningMode> open = std::make_shared<mmode::MemoryMode>();
    mon::Monster monster1("Big monster", 20, 10, 0.2, 
        mon::AttackTypes::CURE, open->get_time_now(), open->get_id());
    open->append_monster(monster1);
    mon::Monster monster2("Small monster", 120, 210, 0.22,
        mon::AttackTypes::CURE, open->get_time_now(), open->get_id());
    open->append_monster(monster2);
    mon::Monster monster3("Monster", 230, 160, 0.212,
        mon::AttackTypes::CURE, open->get_time_now(), open->get_id());
    open->append_monster(monster3);
    mon::Monster monster4 = open->get_monster(monster2.get_id());
    CHECK(monster4.get_id() == monster2.get_id());
    open->delete_the_monster(monster2);
    monster4 = open->get_monster(monster2.get_id());
    CHECK(monster4.get_id() != monster2.get_id());
    CHECK(monster4.get_id() == 9999);//if in open mode won't be  the monster with id than be return a default monster with id 9999
}
TEST_CASE("Finding monsters")
{
    std::shared_ptr<om::OpeningMode> open = std::make_shared<mmode::MemoryMode>();
    mon::Monster monster1("Big monster", 20, 1000, 0.2,
        mon::AttackTypes::INCREASE, open->get_time_now(), open->get_id());
    open->append_monster(monster1);
    mon::Monster monster2("Small monster", 120, 88, 0.22,
        mon::AttackTypes::CURE, open->get_time_now(), open->get_id());
    open->append_monster(monster2);
    mon::Monster monster3("Monster77", 230, 160, 0.212,
        mon::AttackTypes::PARALYZE, open->get_time_now(), open->get_id());
    open->append_monster(monster3);
    std::vector<std::shared_ptr<mon::Monster>> ptr_monsters;
    SUBCASE("by time and types of attack")
    {
        std::vector<int> time = { 2040, 1, 4, 10, 44, 38 };
        ptr_monsters = open->find_types_time(mon::AttackTypes::INCREASE, time);
        REQUIRE(ptr_monsters.size() == 1);//function find only one monster with type of attack INCREASE
        CHECK(ptr_monsters[0]->get_id() == monster1.get_id());
    }
    SUBCASE("by hp and damage")
    {
        unsigned hp = 15, damage = 100;
        ptr_monsters = open->find_hp_damage(hp, damage);
        REQUIRE(ptr_monsters.size() == 1);//function find only one monster with hp >= 15 and damage <= 100
        CHECK(ptr_monsters[0]->get_id() == monster2.get_id());
    }
    SUBCASE("by fragment of name")
    {
        std::string name = "TeR7";
        ptr_monsters = open->find_name(name);
        REQUIRE(ptr_monsters.size() == 1);//function find only one monster with fragment of name "TeR7"
        CHECK(ptr_monsters[0]->get_id() == monster2.get_id());
    }
}
TEST_CASE("Editing monsters")
{
    std::shared_ptr<om::OpeningMode> open = std::make_shared<mmode::MemoryMode>();
    mon::Monster monster1("Big monster", 20, 1000, 0.2,
        mon::AttackTypes::INCREASE, open->get_time_now(), open->get_id());
    open->append_monster(monster1);
    mon::Monster monster2("Small monster", 120, 88, 0.22,
        mon::AttackTypes::CURE, open->get_time_now(), open->get_id());
    open->append_monster(monster2);
    mon::Monster monster3("Monster77", 230, 160, 0.212,
        mon::AttackTypes::PARALYZE, open->get_time_now(), open->get_id());
    open->append_monster(monster3);
    open->save_edited_monster(
        mon::Monster("New monster", 111, 405, 0.45, //edit monster2 in open mode
            mon::AttackTypes::REPEAT, open->get_time_now(), monster2.get_id()));
    mon::Monster new_monster2 = open->get_monster(monster2.get_id());
    CHECK(new_monster2.get_name() == "New monster");
    CHECK(new_monster2.get_hp() == 111);
    CHECK(new_monster2.get_damage() == 405);
    CHECK(new_monster2.get_chance() == doctest::Approx(0.45));
    CHECK(new_monster2.get_type() == mon::AttackTypes::REPEAT);
    CHECK(new_monster2.get_id() == monster2.get_id());
}