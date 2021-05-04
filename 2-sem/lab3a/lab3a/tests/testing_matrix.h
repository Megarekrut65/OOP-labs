#pragma once
#include "doctest.h"
#include <sstream>
#include "../my_matrix.h"

using namespace mymatrix;
TEST_CASE("testing operator<<")
{
	Matrix<int> matrix1 = { { {2,4,5},
							  {3,6,9} } };
	std::stringstream out;
	out << matrix1;
	CHECK(out.str() == "2 4 5 \n3 6 9 \n");	
}
TEST_CASE("testing constructors")
{
	Matrix<int> matrix1 = { { {2,4,5},
							  {3,6,9} } };
	CHECK(matrix1.get_row_size() == 2);
	CHECK(matrix1.get_col_size() == 3);
	matrix1 = Matrix<int>(4, 7);
	CHECK(matrix1.get_row_size() == 4);
	CHECK(matrix1.get_col_size() == 7);
	matrix1 = Matrix<int>(0, 7);
	CHECK(matrix1.get_row_size() == 0);
	CHECK(matrix1.get_col_size() == 7);
	matrix1 = Matrix<int>(7,0);
	CHECK(matrix1.get_row_size() == 7);
	CHECK(matrix1.get_col_size() == 0);
	matrix1 = Matrix<int>();
	CHECK(matrix1.get_row_size() == 0);
	CHECK(matrix1.get_col_size() == 0);
	CHECK_THROWS_WITH_AS(matrix1 = Matrix<int>({ {3,6,8},
												 {1,2,3},
												 {4,8} }),
		"Numbers of columns must be same!",
		std::logic_error);
}
TEST_CASE("testing get, add and remove rows/columns")
{
	Matrix<int> matrix1 = { { {2,4,5},
							  {3,6,9} } };
	CHECK(matrix1.get_row_size() == 2);
	CHECK(matrix1.get_col_size() == 3);
	matrix1.add_rows(3);
	matrix1.add_columns(5);
	CHECK(matrix1.get_row_size() == 2 + 3);
	CHECK(matrix1.get_col_size() == 3 + 5);
	CHECK(matrix1[3][5] == 0);
	matrix1.remove_rows(1);
	matrix1.remove_columns(2);
	CHECK(matrix1.get_row_size() == 2 + 3 - 1);
	CHECK(matrix1.get_col_size() == 3 + 5 - 2);
	CHECK_THROWS_WITH_AS(matrix1.remove_rows(10),
		"There are 4 rows but need to remove 10 rows!",
		std::out_of_range);
	CHECK_THROWS_WITH_AS(matrix1.remove_columns(10),
		"There are 6 columns but need to remove 10 columns!",
		std::out_of_range);
	matrix1 = Matrix<int>(0, 5);
	matrix1.add_rows(2);
	CHECK(matrix1.get_row_size() == 2);
	CHECK(matrix1.get_col_size() == 5);
	CHECK(matrix1[1][4] == 0);
}
TEST_CASE("testing operator[][]")
{
	Matrix<int> matrix1({ {2,4,5},
						  {3,6,0} });
	CHECK(matrix1[0][0] == 2);
	CHECK(matrix1[0][1] == 4);
	CHECK(matrix1[0][2] == 5);
	CHECK(matrix1[1][0] == 3);
	CHECK(matrix1[1][1] == 6);
	CHECK(matrix1[1][2] == 0);
	matrix1[0][0] = -9;
	CHECK(matrix1[0][0] == -9);
	CHECK_THROWS_WITH_AS(matrix1[3][1], 
		"index=3 larger than rows number=2", 
		std::out_of_range);
	CHECK_THROWS_WITH_AS(matrix1[1][3], 
		"index=3 larger than columns number=3", 
		std::out_of_range);
	const Matrix<int> matrix2({ {2,4,5},
								{3,6,0} });
	CHECK(matrix2.get_item(0, 0) == 2);
	CHECK(matrix2.get_item(0, 1) == 4);
	CHECK(matrix2.get_item(0, 2) == 5);
	CHECK(matrix2.get_item(1, 0) == 3);
	CHECK(matrix2.get_item(1, 1) == 6);
	CHECK(matrix2.get_item(1, 2) == 0);
	CHECK_THROWS_WITH_AS(matrix2.get_item(3, 1),
		"The index=3 larger than rows number=2 or the index=1 larger than columns number=3",
		std::out_of_range);
	CHECK_THROWS_WITH_AS(matrix2.get_item(1, 3),
		"The index=1 larger than rows number=2 or the index=3 larger than columns number=3",
		std::out_of_range);
}
TEST_CASE("testing operator+ and operator-")
{
	Matrix<int> matrix1({ {2,4},
						  {3,6} }),
				matrix2({ {1,5},
					      {2,3} }),
				matrix3({ {1,4,5},
						  {2,6,8} });
	Matrix<int> res;
	std::stringstream out;
	SUBCASE("operator+")
	{
		res = matrix1 + matrix2;
		out << res;
		CHECK(out.str() == "3 9 \n5 9 \n");
		CHECK_THROWS_WITH_AS(res = matrix1 + matrix3,
			"Matrixes must have same size!",
			std::logic_error);
	}
	SUBCASE("operator-")
	{
		res = matrix1 - matrix2;
		out << res;
		CHECK(out.str() == "1 -1 \n1 3 \n");
		CHECK_THROWS_WITH_AS(res = matrix1 - matrix3,
			"Matrixes must have same size!",
			std::logic_error);
	}
}