#pragma once
#include "matrix_multiplication.h"

namespace seqmulmatrix
{
	/**
	*	\brief Class for multiplication of matrices using simple seauence multiplication algorithm
	*/
	template<typename T>
	class SimpleSubmatrices : public Submatrices<T>
	{
	private:
		/**
		*	\brief Gets matrix c11 (see algorithm of matrix multiplication)
		* 
		*	Added and multiply some parts of matrices.
		*/
		Matrix<T> get_c11() override;
		/**
		*	\brief Gets matrix c12 (see algorithm of matrix multiplication)
		*
		*	Added and multiply some parts of matrices.
		*/
		Matrix<T> get_c12() override;
		/**
		*	\brief Gets matrix c21 (see algorithm of matrix multiplication)
		*
		*	Added and multiply some parts of matrices.
		*/
		Matrix<T> get_c21() override;
		/**
		*	\brief Gets matrix c22 (see algorithm of matrix multiplication)
		*
		*	Added and multiply some parts of matrices.
		*/
		Matrix<T> get_c22() override;
	public:
		/**
		*	\brief Paramatrized constructor
		*/
		SimpleSubmatrices(const Matrix<T>& first_matrix,
			const Matrix<T>& second_matrix,std::size_t size);
	};
	/**
	*	\brief Multiplies parts of square matrices with same sizes
	* 
	*	\param first_matrix - first matrix to multiply
	*	\param second_matrix - second matrix to multiply
	*	\returns result of multiplication
	*/
	template<typename T>
	Matrix<T> simple_parts_multiplication(const Matrix<T>& first_matrix,
		const Matrix<T>& second_matrix);
	/**
	*	\brief Multiplies two matrices using simple multiplication algorithm
	*/
	template<typename T>
	Matrix<T> simple_multiplication(const Matrix<T>& first_matrix,
		const Matrix<T>& second_matrix);
}
namespace seqmulmatrix
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
		return multiply_algorithm(first_matrix,second_matrix, &simple_parts_multiplication);
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