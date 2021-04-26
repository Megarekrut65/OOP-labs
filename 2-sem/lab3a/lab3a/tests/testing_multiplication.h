#pragma once
#include "doctest.h"
#include <sstream>
#include "../sequential-algorithms/simple_multiplication.h"

using namespace mulmatrix;

TEST_CASE("testing multiplication")
{
	Matrix<int> matrix1 = { { {21,42,53},
							  {32,63,94},
							  {17,87,14}} },

				matrix2 = { { {20,11,16},
							  {13,41,28},
							  {75,81,32}} };
	Matrix<int> res = simple_multiplication(matrix1, matrix2);
	std::stringstream out;
	out << res;
	CHECK(out.str() == std::string("4941 6246 3208 \n8509 10549 5284 \n2521 4888 3156 \n"));
}