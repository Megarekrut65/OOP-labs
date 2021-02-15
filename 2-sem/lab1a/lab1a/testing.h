#pragma once
#include "doctest.h"

TEST_CASE("testing the creating of monsters")
{
    vector<info_monster> array;
    info_monster monster1("Big monster", 20, 10, 0.2, types_of_attack::CURE, array);
    CHECK(monster1.name == "Big monster");
    CHECK(monster1.hp == 20);
    CHECK(monster1.damage == 10);
    CHECK(monster1.chance == doctest::Approx(0.2));
    CHECK(monster1.type_of_attack == types_of_attack::CURE);
    CHECK(monster1.id == 1000);
    CHECK(array.size() == 0);
    info_monster monster2;
    SUBCASE("After creating the monster, you must add it to array get correct id")
    {
        array.push_back(monster1);
        monster2 = info_monster("Small monster", 1, 2, 0.1, types_of_attack::PARALYZE, array);
        CHECK(monster2.id == 1001);
        array.push_back(monster2);
    }
    SUBCASE("If don't add then all monsters will have id = 1000")
    {
        monster2 = info_monster("Small monster", 1, 2, 0.1, types_of_attack::PARALYZE, array);
        CHECK(monster2.id == 1000);
    }
    CHECK(monster2.name == "Small monster");
    CHECK(monster2.hp == 1);
    CHECK(monster2.damage == 2);
    CHECK(monster2.chance == doctest::Approx(0.1));
    CHECK(monster2.type_of_attack == types_of_attack::PARALYZE);
}
TEST_CASE("Saving, adding and reading monster to/from files")
{
    vector<info_monster> array;
    info_monster monster1("Big monster", 20, 10, 0.2, types_of_attack::CURE, array);
    //To save all monster to file, need to add their to array
    array.push_back(monster1);
    info_monster monster2("Small monster", 1, 2, 0.1, types_of_attack::PARALYZE, array);
    array.push_back(monster2);
    CHECK(save_text_file("file1.txt", array));
    CHECK(save_binary_file("file2.bin", array));
    info_monster monster3("Normal monster", 100, 200, 0.17, types_of_attack::INCREASE, array);
    //To add only one monster to file, don't need to add it to array, but next monsters will be incorrect
    REQUIRE(create_text_file("file1.txt"));//before adding monster to file, need check availability of file
    REQUIRE(create_binary_file("file2.bin"));
    CHECK(add_in_text_file(monster3, "file1.txt"));//monster will add to end of the file
    CHECK(add_in_binary_file(monster3, "file2.bin"));
    //to read monsters from file, need add their to array, using next function
    SUBCASE("text file")
    {
        array = open_text_file("file1.txt");
    }
    SUBCASE("binary file")
    {
        array = open_binary_file("file2.bin");
    }
    REQUIRE(array.size() == 3);
    CHECK(array[0].name == monster1.name);
    CHECK(array[0].id == monster1.id);
    CHECK(array[1].name == monster2.name);
    CHECK(array[1].id == monster2.id);
    CHECK(array[2].name == monster3.name);
    CHECK(array[2].id == monster3.id);
}
TEST_CASE("Deleting monsters")
{
    vector<info_monster> array;
    info_monster monster1("Big monster", 20, 10, 0.2, types_of_attack::CURE, array);
    array.push_back(monster1);
    info_monster monster2("Small monster", 1, 2, 0.1, types_of_attack::PARALYZE, array);
    array.push_back(monster2);
    info_monster monster3("Normal monster", 100, 200, 0.17, types_of_attack::INCREASE, array);
    array.push_back(monster3);
    CHECK(save_text_file("file1.txt", array));
    CHECK(save_binary_file("file2.bin", array));
    array = open_text_file("file1.txt");
    REQUIRE(array.size() == 3);
    impl::delete_monster_from_files(array[1].id, "file1.txt", "file2.bin");
    array = open_text_file("file1.txt");
    CHECK(array.size() == 2);
}
TEST_CASE("Finding monsters")
{
    vector<info_monster> array;
    info_monster monster1("Big monster", 20, 10, 0.2, types_of_attack::CURE, array);
    array.push_back(monster1);
    info_monster monster2("Small monster", 1, 2, 0.1, types_of_attack::PARALYZE, array);
    array.push_back(monster2);
    info_monster monster3("Normal monster", 100, 200, 0.17, types_of_attack::INCREASE, array);
    array.push_back(monster3);
    std::vector<int> indexes;
    SUBCASE("by time and types of attack")
    {
        const int time[] = { 2040, 1, 4, 10, 44, 38 };
        indexes = find_types_time(types_of_attack::INCREASE, time, array);
        REQUIRE(indexes.size() == 1);//function find only one monster with type of attack INCREASE
        CHECK(indexes[0] == 2);//index of this monster in array
        CHECK(array[indexes[0]].id == monster3.id);
    }
    SUBCASE("by hp and damage")
    {
        unsigned hp = 15, damage = 100;
        indexes = find_hp_damage(hp, damage, array);
        REQUIRE(indexes.size() == 1);//function find only one monster with hp >= 15 and damage <= 100
        CHECK(indexes[0] == 0);//index of this monster in array
        CHECK(array[indexes[0]].id == monster1.id);
    }
    SUBCASE("by fragment of name")
    {
        std::string name = "l mon";
        indexes = find_name(name, array);
        REQUIRE(indexes.size() == 2);//function find only two monsters with fragment of name "l mon"
        CHECK(indexes[0] == 1);//index of first monster in array
        CHECK(indexes[1] == 2);//index of second monster in array
        CHECK(array[indexes[0]].id == monster2.id);
        CHECK(array[indexes[1]].id == monster3.id);
    }
}
TEST_CASE("Edit monster in files")
{
    vector<info_monster> array;
    info_monster monster1("Big monster", 20, 10, 0.2, types_of_attack::CURE, array);
    array.push_back(monster1);
    info_monster monster2("Small monster", 1, 2, 0.1, types_of_attack::PARALYZE, array);
    array.push_back(monster2);
    info_monster monster3("Normal monster", 100, 200, 0.17, types_of_attack::INCREASE, array);
    array.push_back(monster3);
    CHECK(save_text_file("file1.txt", array));
    CHECK(save_binary_file("file2.bin", array));
    array = open_text_file("file1.txt");
    REQUIRE(array.size() == 3);
    int index = 1;
    CHECK(array[index].name == monster2.name);
    //To edit monster in file, need to edit monster in array
    array[index].name = "The monster";
    array[index].hp = 500;
    array[index].damage = 80;
    impl::save_edit_monster("file1.txt", "file2.bin", array[index]);//After saving monster will be edited   
    array = open_text_file("file1.txt");
    REQUIRE(array.size() == 3);
    CHECK(array[index].name == "The monster");
    CHECK(array[index].hp == 500);
    CHECK(array[index].damage == 80);
}