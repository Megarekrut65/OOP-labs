#pragma once
#include <vector>
#include <string>
#include <iostream>

namespace mymatrix
{
	template <typename T>
	class Matrix
	{
	private:
		std::vector<std::vector<T>> container;
	public:
		Matrix(const std::vector<std::vector<T>>& matrix);
		Matrix();
		std::size_t get_row_size() const;
		std::size_t get_col_size() const;
		Matrix<T> operator+ (const Matrix<T>& matrix);
		Matrix<T> operator- (const Matrix<T>& matrix);
		template <typename T>
		friend std::ostream& operator<< (std::ostream& out, const Matrix<T>& matrix);
		
		/*T operator[][](std::size_t i, std::size_t j);
		
		
		
		friend std::istream& operator >> (std::istream& in, Matrix<T>& matrix);*/
	};
}
namespace mymatrix
{
	template<typename T>
	Matrix<T>::Matrix(const std::vector<std::vector<T>>& matrix) : container{ matrix } {}
	template<typename T>
	Matrix<T>::Matrix() {}
	template<typename T>
	std::size_t Matrix<T>::get_row_size() const
	{
		return container.size();
	}
	template<typename T>
	std::size_t Matrix<T>::get_col_size() const
	{
		return container.size() > 0 ? container[0].size() : 0;
	}
	template<typename T>
	Matrix<T> Matrix<T>::operator+ (const Matrix<T>& matrix)
	{
		std::size_t size_row = matrix.get_row_size();
		std::size_t size_col = matrix.get_col_size();
		std::string message = "Matrixes must have same size!";
		if (this->get_row_size() != size_row || this->get_col_size() != size_col)
		{
			throw std::logic_error{ message };
			return Matrix<T>();
		}
		std::vector<std::vector<T>> res(size_row, std::vector<T>(size_col));
		for (std::size_t i = 0; i < size_row; i++)
		{
			for (std::size_t j = 0; j < size_col; j++)
			{
				res[i][j] = this->container[i][j] + matrix.container[i][j];
			}
		}

		return Matrix<T>(res);
	}
	template<typename T>
	Matrix<T> Matrix<T>::operator- (const Matrix<T>& matrix)
	{
		std::size_t size_row = matrix.get_row_size();
		std::size_t size_col = matrix.get_col_size();
		std::string message = "Matrixes must have same size!";
		if (this->get_row_size() != size_row || this->get_col_size() != size_col)
		{
			throw std::logic_error{ message };
			return Matrix<T>();
		}
		std::vector<std::vector<T>> res(size_row, std::vector<T>(size_col));
		for (std::size_t i = 0; i < size_row; i++)
		{
			for (std::size_t j = 0; j < size_col; j++)
			{
				res[i][j] = this->container[i][j] - matrix.container[i][j];
			}
		}

		return Matrix<T>(res);
	}
	template<typename T>
	std::ostream& operator<< (std::ostream& out, const Matrix<T>& matrix)
	{
		for (std::size_t i = 0; i < matrix.get_row_size(); i++)
		{
			for (std::size_t j = 0; j < matrix.get_col_size(); j++)
			{
				out << matrix.container[i][j] << " ";
			}
			out << std::endl;
		}

		return out;
	}
}