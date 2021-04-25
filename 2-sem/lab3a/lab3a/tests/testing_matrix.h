#pragma once
#include "doctest.h"
#include <sstream>
#include "../sequential-algorithms/my_matrix.h"

using namespace mymatrix;
TEST_CASE("testing operator<<")
{
	std::vector<std::vector<int>>
		container1 = { {2,4},
					   {3,6} };
	Matrix<int> matrix1(container1);
	std::stringstream out;
	out << matrix1;
	CHECK(out.str() == "2 4 \n3 6 \n");
}
TEST_CASE("testing operator+ and operator-")
{
	std::vector<std::vector<int>> 
		container1 = { {2,4},
					   {3,6} },
		container2 = { {1,5},
					   {2,3} };
	Matrix<int> matrix1(container1), matrix2(container2);
	Matrix<int> res;
	std::stringstream out;
	SUBCASE("operator+")
	{
		res = matrix1 + matrix2;
		out << res;
		CHECK(out.str() == "3 9 \n5 9 \n");
	}
	SUBCASE("operator-")
	{
		res = matrix1 - matrix2;
		out << res;
		CHECK(out.str() == "1 -1 \n1 3 \n");
	}
}