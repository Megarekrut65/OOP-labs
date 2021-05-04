#pragma once
#include "doctest.h"
#include <sstream>
#include "../sequential-algorithms/simple_multiplication.h"
#include "../sequential-algorithms/strassen_multiplication.h"
#include "../parallel-algorithms/simple_multiplication.h"
#include "../parallel-algorithms/strassen_multiplication.h"

TEST_CASE("testing multiplication")
{
	Matrix<int>(*multiply)(const Matrix<int>&, const Matrix<int>&) = &seqmulmatrix::simple_multiplication<int>;
	SUBCASE("sequential simple multiplication")
	{
		multiply = &seqmulmatrix::simple_multiplication<int>;
	}
	SUBCASE("sequential Strassen multiplication")
	{
		multiply = &seqmulmatrix::strassen_multiplication<int>;
	}
	SUBCASE("parallel simple multiplication")
	{
		multiply = &parmulmatrix::simple_multiplication<int>;
	}
	SUBCASE("parallel Strassen multiplication")
	{
		multiply = &parmulmatrix::strassen_multiplication<int>;
	}
	Matrix<int> matrix1 = { { {21,42,53},
							  {32,63,94},
							  {17,87,14}} },

				matrix2 = { { {20,11,16},
							  {13,41,28},
							  {75,81,32}} };
	Matrix<int> res = multiply(matrix1, matrix2);
	std::stringstream out;
	out << res;
	CHECK(out.str() == std::string("4941 6246 3208 \n8509 10549 5284 \n2521 4888 3156 \n"));
	CHECK(!(multiply(matrix1, matrix2) == multiply(matrix2, matrix1)));
	matrix2 = { { {20,11},
				  {13,41}} };
	CHECK_THROWS_WITH_AS(res = multiply(matrix1, matrix2),
		"Matrices must have same size and be square!",std::logic_error);
	matrix1 = { { {40,11,12},
				  {33,21,12}} };

	matrix2 = { { {20,11,12},
				  {13,41,12}} };
	CHECK_THROWS_WITH_AS(res = multiply(matrix1, matrix2),
		"Matrices must have same size and be square!", std::logic_error);
}