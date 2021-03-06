#pragma once
#include "matrix_multiplication.h"


namespace parmulmatrix
{
	/**
	*	\brief Class for multiplication of matrices using strassen parallel multiplication algorithm
	*/
	template<typename T>
	class StrassenSubmatrices : public Submatrices<T>
	{
	private:
		Matrix<T> matrix_m1;/**< Matrix M1 in algorithm*/
		Matrix<T> matrix_m2;/**< Matrix M2 in algorithm*/
		Matrix<T> matrix_m3;/**< Matrix M3 in algorithm*/
		Matrix<T> matrix_m4;/**< Matrix M4 in algorithm*/
		Matrix<T> matrix_m5;/**< Matrix M5 in algorithm*/
		Matrix<T> matrix_m6;/**< Matrix M6 in algorithm*/
		Matrix<T> matrix_m7;/**< Matrix M7 in algorithm*/
		/**
		*	\brief Creates matrix M1
		*/
		Matrix<T> create_matrix_m1();
		/**
		*	\brief Creates matrix M2
		*/
		Matrix<T> create_matrix_m2();
		/**
		*	\brief Creates matrix M3
		*/
		Matrix<T> create_matrix_m3();
		/**
		*	\brief Creates matrix M4
		*/
		Matrix<T> create_matrix_m4();
		/**
		*	\brief Creates matrix M5
		*/
		Matrix<T> create_matrix_m5();
		/**
		*	\brief Creates matrix M6
		*/
		Matrix<T> create_matrix_m6();
		/**
		*	\brief Creates matrix M7
		*/
		Matrix<T> create_matrix_m7();
		Matrix<T> get_c11() override;
		Matrix<T> get_c12() override;
		Matrix<T> get_c21() override;
		Matrix<T> get_c22() override;
	public:
		/**
		*	\brief Paramatrized constructor
		*/
		StrassenSubmatrices(const Matrix<T>& first_matrix, const Matrix<T>& second_matrix,
			std::size_t size, thnum::ThdNumber& th_number);
	};
	/**
	*	\brief Multiplies parts of square matrices with same sizes
	*
	*	Parallel version of algorithm
	*
	*	\param first_matrix - first matrix to multiply
	*	\param second_matrix - second matrix to multiply
	*	\param th_number - class for saving number of open threads
	*	\returns result of multiplication
	*/
	template<typename T>
	Matrix<T> strassen_parts_multiplication(const Matrix<T>& first_matrix,const Matrix<T>& second_matrix, thnum::ThdNumber& th_number);
	/**
	*	\brief Multiplies two matrices using strassen multiplication algorithm
	*/
	template<typename T>
	Matrix<T> strassen_multiplication(const Matrix<T>& first_matrix, const Matrix<T>& second_matrix);
}
namespace parmulmatrix
{
	template<typename T>
	StrassenSubmatrices<T>::StrassenSubmatrices(const Matrix<T>& first_matrix,const Matrix<T>& second_matrix,
		std::size_t size, thnum::ThdNumber& th_number) : Submatrices<T>{ first_matrix, second_matrix, size, th_number }
	{
		std::vector<std::thread> ths;
		if (th_number.increase())
			ths.push_back(std::thread([&]()
				{ matrix_m1 = create_matrix_m1(); }));
		else matrix_m1 = create_matrix_m1();
		if (th_number.increase())
			ths.push_back(std::thread([&]()
				{ matrix_m2 = create_matrix_m2(); }));
		else matrix_m2 = create_matrix_m2();
		if (th_number.increase())
			ths.push_back(std::thread([&]()
				{ matrix_m3 = create_matrix_m3(); }));
		else matrix_m3 = create_matrix_m3();
		if (th_number.increase())
			ths.push_back(std::thread([&]()
				{ matrix_m4 = create_matrix_m4(); }));
		else matrix_m4 = create_matrix_m4();
		if (th_number.increase())
			ths.push_back(std::thread([&]()
				{ matrix_m5 = create_matrix_m5(); }));
		else matrix_m5 = create_matrix_m5();
		if (th_number.increase())
			ths.push_back(std::thread([&]()
				{ matrix_m6 = create_matrix_m6(); }));
		else matrix_m6 = create_matrix_m6();
		if (th_number.increase())
			ths.push_back(std::thread([&]()
				{ matrix_m7 = create_matrix_m7(); }));
		else matrix_m7 = create_matrix_m7();
		for (auto& item : ths)
		{
			if (item.joinable()) item.join();
			this->th_number.decrease();
		}
	}
	template<typename T>
	Matrix<T> StrassenSubmatrices<T>::create_matrix_m1()
	{
		return strassen_parts_multiplication(
			this->first_matrix_parts.get11() + this->first_matrix_parts.get22(),
			this->second_matrix_parts.get11() + this->second_matrix_parts.get22(), this->th_number);
	}
	template<typename T>
	Matrix<T> StrassenSubmatrices<T>::create_matrix_m2()
	{
		return strassen_parts_multiplication(
			this->first_matrix_parts.get21() + this->first_matrix_parts.get22(),
			this->second_matrix_parts.get11(), this->th_number);
	}
	template<typename T>
	Matrix<T> StrassenSubmatrices<T>::create_matrix_m3()
	{
		return strassen_parts_multiplication(
			this->first_matrix_parts.get11(),
			this->second_matrix_parts.get12() - this->second_matrix_parts.get22(), this->th_number);
	}
	template<typename T>
	Matrix<T> StrassenSubmatrices<T>::create_matrix_m4()
	{
		return strassen_parts_multiplication(
			this->first_matrix_parts.get22(),
			this->second_matrix_parts.get21() - this->second_matrix_parts.get11(), this->th_number);
	}
	template<typename T>
	Matrix<T> StrassenSubmatrices<T>::create_matrix_m5()
	{
		return strassen_parts_multiplication(
			this->first_matrix_parts.get11() + this->first_matrix_parts.get12(),
			this->second_matrix_parts.get22(), this->th_number);
	}
	template<typename T>
	Matrix<T> StrassenSubmatrices<T>::create_matrix_m6()
	{
		return strassen_parts_multiplication(
			this->first_matrix_parts.get21() - this->first_matrix_parts.get11(),
			this->second_matrix_parts.get11() + this->second_matrix_parts.get12(), this->th_number);
	}
	template<typename T>
	Matrix<T> StrassenSubmatrices<T>::create_matrix_m7()
	{
		return strassen_parts_multiplication(
			this->first_matrix_parts.get12() - this->first_matrix_parts.get22(),
			this->second_matrix_parts.get21() + this->second_matrix_parts.get22(), this->th_number);
	}
	template<typename T>
	Matrix<T> StrassenSubmatrices<T>::get_c11()
	{
		return (((matrix_m1 + matrix_m4) - matrix_m5) + matrix_m7);
	}
	template<typename T>
	Matrix<T> StrassenSubmatrices<T>::get_c12()
	{
		return (matrix_m3 + matrix_m5);
	}
	template<typename T>
	Matrix<T> StrassenSubmatrices<T>::get_c21()
	{
		return (matrix_m2 + matrix_m4);
	}
	template<typename T>
	Matrix<T> StrassenSubmatrices<T>::get_c22()
	{
		return (((matrix_m1 - matrix_m2) + matrix_m3) + matrix_m6);
	}

	template<typename T>
	Matrix<T> strassen_multiplication(const Matrix<T>& first_matrix,const Matrix<T>& second_matrix)
	{
		return multiply_algorithm(first_matrix, second_matrix, &strassen_parts_multiplication);
	}	
	template<typename T>
	Matrix<T> strassen_parts_multiplication(
		const Matrix<T>& first_matrix,
		const Matrix<T>& second_matrix, thnum::ThdNumber& th_number)
	{
		std::size_t size = first_matrix.get_row_size();
		if (size == 1)
		{
			return { { {first_matrix.get_item(0,0) * second_matrix.get_item(0,0)} } };
		}
		StrassenSubmatrices<T> submatrices(first_matrix, second_matrix, size, th_number);
		return submatrices.merge_submatrices();
	}
	
}
