#pragma once
#include "my_matrix.h"

using namespace mymatrix;

namespace mulmatrix
{
	template<typename T>
	class MatrixParts
	{
	private:
		const Matrix<T>& matrix;
		std::size_t size;
		Matrix<T> matrix11;
		Matrix<T> matrix12;
		Matrix<T> matrix21;
		Matrix<T> matrix22;

		Matrix<T> set_matrix_part(
			std::size_t begin_row, std::size_t begin_column,
			std::size_t end_row, std::size_t end_column);
	public:
		MatrixParts();
		MatrixParts(const Matrix<T>& matrix,std::size_t size);
		Matrix<T> get11();
		Matrix<T> get12();
		Matrix<T> get21();
		Matrix<T> get22();
	};
	template<typename T>
	class Submatrices
	{
	protected:
		virtual Matrix<T> get_c11() = 0;
		virtual Matrix<T> get_c12() = 0;
		virtual Matrix<T> get_c21() = 0;
		virtual Matrix<T> get_c22() = 0;
		void copy_part_to_matrix(Matrix<T>& matrix,
			const Matrix<T>& part,
			std::size_t begin_row, std::size_t begin_column,
			std::size_t end_row, std::size_t end_column);
		const Matrix<T>& first_matrix;
		const Matrix<T>& second_matrix;
		std::size_t size;
		MatrixParts<T> first_matrix_parts;
		MatrixParts<T> second_matrix_parts;
	public:
		Submatrices(const Matrix<T>& first_matrix, const Matrix<T>& second_matrix, std::size_t size);
		Matrix<T> merge_submatrices();
	};
	template<typename T>
	bool check_correct_matrices_size(const Matrix<T>& first_matrix,
		const Matrix<T>& second_matrix);
	template<typename T>
	void add_zeros_to_matrices(Matrix<T>& firts_matrix,Matrix<T>& second_matrix);
	template<typename T>
	void add_zeros(Matrix<T>& matrix, std::size_t new_size);
	template<typename T>
	void remove_extra_zeros(Matrix<T>& matrix, std::size_t old_size);
}
namespace mulmatrix
{
	template<typename T>
	MatrixParts<T>::MatrixParts(): size( 0 ) {}
	template<typename T>
	MatrixParts<T>::MatrixParts(const Matrix<T>& matrix,std::size_t size) 
		: matrix{ matrix }, size{ size }
	{
		matrix11 = set_matrix_part(0, 0, size / 2, size / 2);
		matrix12 = set_matrix_part(0, size / 2, size / 2, size);
		matrix21 = set_matrix_part(size / 2, 0, size, size / 2);
		matrix22 = set_matrix_part(size / 2, size / 2, size, size);
	}
	template<typename T>
	Matrix<T> MatrixParts<T>::set_matrix_part(
		std::size_t begin_row, std::size_t begin_column,
		std::size_t end_row, std::size_t end_column)
	{
		Matrix<T> part(end_row - begin_row, end_column - begin_column);
		for (std::size_t i = begin_row; i < end_row; i++)
		{
			for (std::size_t j = begin_column; j < end_column; j++)
			{
				part[i - begin_row][j - begin_column] = matrix.get_item(i,j);
			}
		}

		return part;
	}
	template<typename T>
	Matrix<T> MatrixParts<T>::get11()
	{
		return matrix11;
	}
	template<typename T>
	Matrix<T> MatrixParts<T>::get12()
	{
		return matrix12;
	}
	template<typename T>
	Matrix<T> MatrixParts<T>::get21()
	{
		return matrix21;
	}
	template<typename T>
	Matrix<T> MatrixParts<T>::get22()
	{
		return matrix22;
	}

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
				matrix[i][j] = part.get_item(i - begin_row,j - begin_column);
			}
		}
	}
	template<typename T>
	bool check_correct_matrices_size(const Matrix<T>& first_matrix, const Matrix<T>& second_matrix)
	{
		return (first_matrix.get_row_size() == first_matrix.get_col_size() &&
				second_matrix.get_row_size() == second_matrix.get_col_size()&&
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