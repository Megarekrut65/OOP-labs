#define DOCTEST_CONFIG_IMPLEMENT
#include <iostream>
#include <ctime>
#include<conio.h>
#include "tests/doctest.h"
#include "tests/testing_sort_algorithms.h"
#include "tests/testing_matrix.h"
#include "tests/testing_multiplication.h"
#include "benchmark/benchmark_mode.h"

void bencmark_menu()
{
    benmode::BenchmarkMode<int> mode;
    while (true)
    {
        std::cout << "\nMenu:\n1)Start measuring of sorts algorithms.\n"
            << "2)Start measuring of matrix multiplication algorithms.\n"
            << "3)Start all measuring.\n0)Exit." << std::endl;
        switch (_getch())
        {
        case '1': mode.start_measuring_sorts_algorithms();
            break;
        case '2': mode.start_measuring_multiplication_algorithms();
            break;
        case '3': mode.start_all();
            break;
        case '0': return;
            break;
        default:
            std::cout << "\nPress correct key!\n" << std::endl;
            break;
        }
    }
}
int main(int argc, char** argv)
{
    doctest::Context context;

    // defaults
 //    context.addFilter("test-case-exclude", "*math*"); // exclude test cases with "math" in their name
 //    context.setOption("abort-after", 5);              // stop test execution after 5 failed assertions
 //    context.setOption("order-by", "name");            // sort the test cases by their name

    context.applyCommandLine(argc, argv);

    // overrides
//    context.setOption("no-breaks", true);             // don't break in the debugger when assertions fail

    int res = context.run(); // run

    if (context.shouldExit()) // important - query flags (and --exit) rely on the user doing this
        return res;          // propagate the result of the tests

    int client_stuff_return_code = 0;
    // your program - if the testing framework is integrated in your production code
    bencmark_menu();
    return res + client_stuff_return_code; // the result from doctest is propagated here as well
}

