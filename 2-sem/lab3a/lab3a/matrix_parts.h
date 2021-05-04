#pragma once
#include "my_matrix.h"

namespace mymatrix
{
	/**
	*	\brief Class for getting parts of square matrix
	*
	*	If use it for non-square matrix than may be some other results.
	*/
	template<typename T>
	class MatrixParts
	{
	private:
		const Matrix<T>& matrix;/**<Reference to matrix to get its parts*/
		std::size_t size;/**<Size of matrix*/
		Matrix<T> matrix11;/**<First part*/
		Matrix<T> matrix12;/**<Second part*/
		Matrix<T> matrix21;/**<Third part*/
		Matrix<T> matrix22;/**<Fourth part*/
		/**
		*	\brief Creates part of matrix by this matrix by indexes
		*
		*	\param begin_row - begin index of row
		*	\param begin_column - begin index of column
		*	\param end_row - end index of row
		*	\param end_column - end index of column
		*
		*	\returns part of matrix
		*/
		Matrix<T> set_matrix_part(
			std::size_t begin_row, std::size_t begin_column,
			std::size_t end_row, std::size_t end_column);
	public:
		/**
		*	\brief Default constructor
		*/
		MatrixParts();
		/**
		*	\brief Creates four parts of matrix
		*/
		MatrixParts(const Matrix<T>& matrix, std::size_t size);
		/**
		*	\returns first part of matrix
		*/
		Matrix<T> get11();
		/**
		*	\returns second part of matrix
		*/
		Matrix<T> get12();
		/**
		*	\returns third part of matrix
		*/
		Matrix<T> get21();
		/**
		*	\returns four part of matrix
		*/
		Matrix<T> get22();
	};
}
namespace mymatrix
{
	template<typename T>
	MatrixParts<T>::MatrixParts() : size(0) {}
	template<typename T>
	MatrixParts<T>::MatrixParts(const Matrix<T>& matrix, std::size_t size)
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
				part[i - begin_row][j - begin_column] = matrix.get_item(i, j);
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

}