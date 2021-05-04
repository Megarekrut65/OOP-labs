#pragma once
#include "../addition_matrix_functions.h"
#include "submatrices.h"

namespace seqmulmatrix
{
	template<typename T>
	Matrix<T> multiply_algorithm(const Matrix<T>& first_matrix,
		const Matrix<T>& second_matrix, 
		Matrix<T>(*multiply)(const Matrix<T>&, const Matrix<T>&));
}
namespace seqmulmatrix
{
	template<typename T>
	Matrix<T> multiply_algorithm(const Matrix<T>& first_matrix,
		const Matrix<T>& second_matrix,
		Matrix<T>(*multiply)(const Matrix<T>&, const Matrix<T>&))
	{
		if (!check_correct_matrices_size(first_matrix, second_matrix))
			throw std::logic_error{ "Matrices must have same size and be square!" };
		Matrix<T> copy_first = first_matrix, copy_second = second_matrix;
		add_zeros_to_matrices(copy_first, copy_second);
		Matrix<T> res = multiply(copy_first, copy_second);
		remove_extra_zeros(res, first_matrix.get_row_size());
		return res;
	}	
}