#pragma once
#include "../matrix_parts.h"

using namespace mymatrix;
/**
*	\brief Namespace for parallel multiplication algorithms
*/
namespace parmulmatrix
{
	/**
	*	\brief Basic class for parallel multiplication algorithms
	*/
	template<typename T>
	class Submatrices
	{
	protected:
		virtual Matrix<T> get_c11() = 0;
		virtual Matrix<T> get_c12() = 0;
		virtual Matrix<T> get_c21() = 0;
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
		thnum::ThdNumber& th_number;
	public:
		/**
		*	\brief Paramatrized constructor
		*/
		Submatrices(const Matrix<T>& first_matrix, const Matrix<T>& second_matrix, std::size_t size, thnum::ThdNumber& th_number);
		/**
		*	\brief Copies the multiplied parts of the matrix to the result
		*/
		Matrix<T> merge_submatrices();
	};
}
namespace parmulmatrix
{
	template<typename T>
	Submatrices<T>::Submatrices(
		const Matrix<T>& first_matrix,
		const Matrix<T>& second_matrix,
		std::size_t size, thnum::ThdNumber& th_number)
		: first_matrix{ first_matrix }, second_matrix{ second_matrix }, size{ size },
		first_matrix_parts{ MatrixParts<T>(first_matrix, size) },
		second_matrix_parts{ MatrixParts<T>(second_matrix, size) },
		th_number{ th_number }{}
	template<typename T>
	Matrix<T> Submatrices<T>::merge_submatrices()
	{
		Matrix<T> res(size, size);
		std::vector<std::thread> ths;
		if (this->th_number.increase())
			ths.push_back(std::thread([=, &res]()
				{ copy_part_to_matrix(res, get_c11(), 0, 0, size / 2, size / 2); }));
		else copy_part_to_matrix(res, get_c11(), 0, 0, size / 2, size / 2);
		if (this->th_number.increase())
			ths.push_back(std::thread([=, &res]()
				{ copy_part_to_matrix(res, get_c12(), 0, size / 2, size / 2, size); }));
		else copy_part_to_matrix(res, get_c12(), 0, size / 2, size / 2, size);
		if (this->th_number.increase())
			ths.push_back(std::thread([=, &res]()
				{ copy_part_to_matrix(res, get_c21(), size / 2, 0, size, size / 2); }));
		else copy_part_to_matrix(res, get_c21(), size / 2, 0, size, size / 2);
		if (this->th_number.increase())
			ths.push_back(std::thread([=, &res]()
				{ copy_part_to_matrix(res, get_c22(), size / 2, size / 2, size, size); }));
		else copy_part_to_matrix(res, get_c22(), size / 2, size / 2, size, size);
		for (auto& item : ths)
		{
			if (item.joinable()) item.join();
			this->th_number.decrease();
		}
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