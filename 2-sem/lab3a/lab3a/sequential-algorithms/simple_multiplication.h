#pragma once
#include "matrix_multiplication.h"

namespace mulmatrix
{
	template<typename T>
	class SimpleSubmatrices : public Submatrices<T>
	{
	private:
		Matrix<T> get_c11() override;
		Matrix<T> get_c12() override;
		Matrix<T> get_c21() override;
		Matrix<T> get_c22() override;
	public:
		SimpleSubmatrices(const Matrix<T>& first_matrix,
			const Matrix<T>& second_matrix,std::size_t size);
	};
	template<typename T>
	Matrix<T> simple_parts_multiplication(const Matrix<T>& first_matrix,
		const Matrix<T>& second_matrix);
	template<typename T>
	Matrix<T> simple_multiplication(const Matrix<T>& first_matrix,
		const Matrix<T>& second_matrix);
}
namespace mulmatrix
{
	template<typename T>
	SimpleSubmatrices<T>::SimpleSubmatrices(const Matrix<T>& first_matrix, 
		const Matrix<T>& second_matrix,std::size_t size) 
		: Submatrices<T>(first_matrix, second_matrix, size) {}
	template<typename T>
	Matrix<T> SimpleSubmatrices<T>::get_c11()
	{
		return (
			simple_parts_multiplication(this->first_matrix_parts.get11(), this->second_matrix_parts.get11())
			+
			simple_parts_multiplication(this->first_matrix_parts.get12(), this->second_matrix_parts.get21()));
	}
	template<typename T>
	Matrix<T> SimpleSubmatrices<T>::get_c12()
	{
		return (
			simple_parts_multiplication(this->first_matrix_parts.get11(), this->second_matrix_parts.get12())
			+
			simple_parts_multiplication(this->first_matrix_parts.get12(), this->second_matrix_parts.get22()));
	}
	template<typename T>
	Matrix<T> SimpleSubmatrices<T>::get_c21()
	{
		return (
			simple_parts_multiplication(this->first_matrix_parts.get21(), this->second_matrix_parts.get11())
			+
			simple_parts_multiplication(this->first_matrix_parts.get22(), this->second_matrix_parts.get21()));
	}
	template<typename T>
	Matrix<T> SimpleSubmatrices<T>::get_c22()
	{
		return (
			simple_parts_multiplication(this->first_matrix_parts.get21(), this->second_matrix_parts.get12())
			+
			simple_parts_multiplication(this->first_matrix_parts.get22(), this->second_matrix_parts.get22()));
	}
	template<typename T>
	Matrix<T> simple_multiplication(const Matrix<T>& first_matrix,
		const Matrix<T>& second_matrix)
	{
		if (!check_correct_matrices_size(first_matrix, second_matrix))
			throw std::logic_error{ "Matrices must have same size and be square!" };
		Matrix<T> copy_first = first_matrix, copy_second = second_matrix;
		add_zeros_to_matrices(copy_first, copy_second);
		Matrix<T> res = simple_parts_multiplication(copy_first, copy_second);
		remove_extra_zeros(res, first_matrix.get_row_size());
		return res;
	}
	template<typename T>
	Matrix<T> simple_parts_multiplication(const Matrix<T>& first_matrix,
		const Matrix<T>& second_matrix)
	{
		std::size_t size = first_matrix.get_row_size();
		if (size == 1)
		{
			return { { {first_matrix.get_item(0,0) * second_matrix.get_item(0,0)} } };
		}
		SimpleSubmatrices<T> submatrices(first_matrix, second_matrix, size);
		return submatrices.merge_submatrices();
	}
}