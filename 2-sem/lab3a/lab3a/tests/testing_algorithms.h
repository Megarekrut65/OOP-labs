#pragma once
#include "doctest.h"
#include "../sequential-algorithms/all_sorts.h"

TEST_CASE("testing operator== for std::vector")
{
    std::vector<int> arr = { 34,89,12,43 };
    CHECK(arr == std::vector<int>{34, 89, 12, 43});
    CHECK(!(arr == std::vector<int>{33, 89, 12, 43}));
    CHECK(!(arr == std::vector<int>{89, 12, 43}));
}
void subcase_sorts(std::vector<int>& arr)
{
    SUBCASE("merge sort")
    {
        sorts::merge_sort(arr);
    }
    SUBCASE("quick sort")
    {
        sorts::quick_sort(arr);
    }
}
void test_all_sorts(std::vector<int>& arr)
{
    std::vector<int> copy_array = arr;
    std::sort(arr.begin(), arr.end());
    CHECK(!(copy_array == arr));
    subcase_sorts(copy_array);
    CHECK(copy_array == arr);
}
TEST_CASE("testing on random items")
{
    std::size_t size = 100;
    std::vector<int> arr = sorts::create_random_array<int>(size);
    test_all_sorts(arr);
}
TEST_CASE("testing on ordered items")
{
    std::size_t size = 100;
    std::vector<int> arr = sorts::create_ordered_array<int>(size, 8 * size / 10);
    test_all_sorts(arr);
}
TEST_CASE("testing on reverse ordered items")
{
    std::size_t size = 100;
    std::vector<int> arr = sorts::create_reverse_ordered_array<int>(size, 8 * size / 10);
    test_all_sorts(arr);
}
TEST_CASE("testing on own items")
{
    std::vector<int> arr = { 4,8,1,3,9,3,2,0,1,0,4,3,2,17,43,7,12,89,32,6,3,1,9,5,4 };
    std::vector<int> copy_array = arr;
    subcase_sorts(copy_array);
    CHECK(copy_array == std::vector<int>{0, 0, 1, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 5, 6, 7, 8, 9, 9, 12, 17, 32, 43, 89 });
}
TEST_CASE("testing creating about ordered array")
{
    std::size_t size = 100, part = 8 * size / 10;
    std::vector<int> arr = sorts::create_ordered_array<int>(size, part);
    REQUIRE(size == arr.size());
    std::size_t number = 0;
    for (std::size_t i = 1; i < size; i++)
    {
        if (arr[i - 1] < arr[i]) number++;
        else break;
    }
    CHECK(number >= part);
}
TEST_CASE("testing creating about reverse ordered array")
{
    std::size_t size = 100, part = 8 * size / 10;
    std::vector<int> arr = sorts::create_reverse_ordered_array<int>(size, part);
    REQUIRE(size == arr.size());
    std::size_t number = 0;
    for (std::size_t i = 1; i < size; i++)
    {
        if (arr[i - 1] > arr[i]) number++;
        else break;
    }
    CHECK(number >= part);
}
TEST_CASE("testing creating random array")
{
    std::size_t size = 100;
    std::vector<int> arr = sorts::create_random_array<int>(size);
    REQUIRE(size == arr.size());
}