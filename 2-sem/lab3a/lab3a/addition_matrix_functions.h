#pragma once
#include "my_matrix.h"

namespace mymatrix
{
	template<typename T>
	bool check_correct_matrices_size(const Matrix<T>& first_matrix,
		const Matrix<T>& second_matrix);
	template<typename T>
	void add_zeros_to_matrices(Matrix<T>& firts_matrix, Matrix<T>& second_matrix);
	template<typename T>
	void add_zeros(Matrix<T>& matrix, std::size_t new_size);
	template<typename T>
	void remove_extra_zeros(Matrix<T>& matrix, std::size_t old_size);
}
namespace mymatrix
{
	template<typename T>
	bool check_correct_matrices_size(const Matrix<T>& first_matrix, const Matrix<T>& second_matrix)
	{
		return (first_matrix.get_row_size() == first_matrix.get_col_size() &&
			second_matrix.get_row_size() == second_matrix.get_col_size() &&
			first_matrix.get_row_size() == second_matrix.get_row_size());
	}
	template<typename T>
	void add_zeros(Matrix<T>& matrix, std::size_t new_size)
	{
		std::size_t zeros_number = new_size - matrix.get_row_size();
		matrix.add_rows(zeros_number);
		matrix.add_columns(zeros_number);
	}
	template<typename T>
	void add_zeros_to_matrices(Matrix<T>& first_matrix, Matrix<T>& second_matix)
	{
		std::size_t new_size = (std::size_t)pow(2, ceil(log2(first_matrix.get_row_size())));
		add_zeros(first_matrix, new_size);
		add_zeros(second_matix, new_size);
	}
	template<typename T>
	void remove_extra_zeros(Matrix<T>& matrix, std::size_t old_size)
	{
		std::size_t size = matrix.get_row_size();
		std::size_t zeros_number = size - old_size;
		matrix.remove_rows(zeros_number);
		matrix.remove_columns(zeros_number);
	}
}