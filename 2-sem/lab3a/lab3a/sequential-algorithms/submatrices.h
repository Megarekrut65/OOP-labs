#pragma once
#include "../matrix_parts.h"

using namespace mymatrix;
/**
*	\brief Namespace for sequential multiplication algorithms
*/
namespace seqmulmatrix
{
	/**
	*	\brief Basic class for sequential multiplication algorithms
	*/
	template<typename T>
	class Submatrices
	{
	protected:
		/**
		*	\brief Returns matrix C11 as in algorithm
		*/
		virtual Matrix<T> get_c11() = 0;
		/**
		*	\brief Returns matrix C11 as in algorithm
		*/
		virtual Matrix<T> get_c12() = 0;
		/**
		*	\brief Returns matrix C11 as in algorithm
		*/
		virtual Matrix<T> get_c21() = 0;
		/**
		*	\brief Returns matrix C11 as in algorithm
		*/
		virtual Matrix<T> get_c22() = 0;
		/**
		*	\brief Copies part to matrix by indexes
		*/
		void copy_part_to_matrix(Matrix<T>& matrix,
			const Matrix<T>& part,
			std::size_t begin_row, std::size_t begin_column,
			std::size_t end_row, std::size_t end_column);

		const Matrix<T>& first_matrix;/**< Reference to first matrix */
		const Matrix<T>& second_matrix;/**< Reference to second matrix */
		std::size_t size;/**< Size of matrices */
		MatrixParts<T> first_matrix_parts;/**< Parts of first matrix */
		MatrixParts<T> second_matrix_parts;/**< Parts of second matrix */
	public:
		/**
		*	\brief Paramatrized constructor
		*/
		Submatrices(const Matrix<T>& first_matrix, const Matrix<T>& second_matrix, std::size_t size);
		/**
		*	\brief Copies the multiplied parts of the matrix to the result
		*/
		Matrix<T> merge_submatrices();
	};
}
namespace seqmulmatrix
{
	template<typename T>
	Submatrices<T>::Submatrices(
		const Matrix<T>& first_matrix,
		const Matrix<T>& second_matrix,
		std::size_t size)
		: first_matrix{ first_matrix }, second_matrix{ second_matrix }, size{ size },
		first_matrix_parts{ MatrixParts<T>(first_matrix, size) },
		second_matrix_parts{ MatrixParts<T>(second_matrix, size) } {}
	template<typename T>
	Matrix<T> Submatrices<T>::merge_submatrices()
	{
		Matrix<T> res(size, size);
		copy_part_to_matrix(res, get_c11(), 0, 0, size / 2, size / 2);
		copy_part_to_matrix(res, get_c12(), 0, size / 2, size / 2, size);
		copy_part_to_matrix(res, get_c21(), size / 2, 0, size, size / 2);
		copy_part_to_matrix(res, get_c22(), size / 2, size / 2, size, size);

		return res;
	}
	template<typename T>
	void Submatrices<T>::copy_part_to_matrix(Matrix<T>& matrix, const Matrix<T>& part,
		std::size_t begin_row, std::size_t begin_column,
		std::size_t end_row, std::size_t end_column)
	{
		for (std::size_t i = begin_row; i < end_row; i++)
		{
			for (std::size_t j = begin_column; j < end_column; j++)
			{
				matrix[i][j] = part.get_item(i - begin_row, j - begin_column);
			}
		}
	}
}