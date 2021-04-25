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
		template <typename U>
		class Column
		{
		private:
			std::vector<U>& array;
		public:
			Column(std::vector<U>& array);
			U& operator[](std::size_t index);
		};
		bool check_sizes();
	public:
		Matrix(const std::vector<std::vector<T>>& matrix);
		Matrix(std::size_t row_size, std::size_t col_size);
		Matrix();
		std::size_t get_row_size() const;
		std::size_t get_col_size() const;
		Matrix<T> operator+ (const Matrix<T>& matrix);
		Matrix<T> operator- (const Matrix<T>& matrix);
		template <typename T>
		friend std::ostream& operator<< (std::ostream& out, const Matrix<T>& matrix);	
		Column<T> operator[](std::size_t index);
	};
}
namespace mymatrix
{
	template<typename T>
	bool Matrix<T>::check_sizes()
	{
		if (container.size() == 0) return true;
		std::size_t col_size = container[0].size();
		for (std::size_t i = 1; i < container.size(); i++)
			if (container[i].size() != col_size) return false;
		return true;
	}
	template<typename T>
	Matrix<T>::Matrix(const std::vector<std::vector<T>>& matrix) 
		: container{ matrix } 
	{
		if (!check_sizes())
			throw std::logic_error{ "Numbers of columns must be same!" };
	}
	template<typename T>
	Matrix<T>::Matrix() {}
	template<typename T>
	Matrix<T>::Matrix(std::size_t row_size, std::size_t col_size)
		:container(std::vector<std::vector<T>>(row_size,std::vector<T>(col_size))){}
	
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
		Matrix<T> res(size_row, size_col);
		for (std::size_t i = 0; i < size_row; i++)
		{
			for (std::size_t j = 0; j < size_col; j++)
			{
				res[i][j] = this->container[i][j] + matrix.container[i][j];
			}
		}

		return res;
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
		Matrix<T> res(size_row, size_col);
		for (std::size_t i = 0; i < size_row; i++)
		{
			for (std::size_t j = 0; j < size_col; j++)
			{
				res[i][j] = this->container[i][j] - matrix.container[i][j];
			}
		}

		return res;
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
	template<typename T>
	template<typename U>
	Matrix<T>::Column<U>::Column(std::vector<U>& array) : array{array} {}
	template<typename T>
	template<typename U>
	U& Matrix<T>::Column<U>::operator[](std::size_t index)
	{
		if (index < this->array.size())
			return this->array[index];
		throw std::out_of_range{ "index=" + std::to_string(index) +
			" larger than columns number=" + std::to_string(this->array.size()) };
	}
	template<typename T>
	Matrix<T>::Column<T> Matrix<T>::operator[](std::size_t index)
	{
		if(index < this->container.size())
			return Column<T>(this->container[index]);
		throw std::out_of_range{ "index=" + std::to_string(index) + 
			" larger than rows number=" + std::to_string(this->container.size()) };
	}
}