#pragma once
#include <vector>
#include "my_timer.h"
#include "my_file_writer.h"
#include "../sequential-algorithms/all_sorts.h"
#include "../parallel-algorithms/all_sorts.h"
#include "../sequential-algorithms/simple_multiplication.h"
#include "../sequential-algorithms/strassen_multiplication.h"
#include "../parallel-algorithms/simple_multiplication.h"
#include "../parallel-algorithms/strassen_multiplication.h"

using namespace mtimer;
using namespace fwriter;

namespace benmode
{
	struct Sizes
	{
		std::size_t current_size;
		std::size_t saved_size;
		std::size_t coefficient;
		bool more_one;
		Sizes(std::size_t current_size, std::size_t coefficient = 2);
		void increase();
	};
	template<typename T>
	class BenchmarkMode
	{
		std::size_t inizial_size;
		FileWriter writer;
		void measure_sorts(const std::vector<void(*)(std::vector<T>&)>& functions,
			const std::vector<std::string>& names);
		void measure_multiplications(
			const std::vector<Matrix<T>(*)(const Matrix<T>&, const Matrix<T>&)>& functions,
			const std::vector<std::string>& names);
		void measure_sorts_algorithms();
		void measure_multiplication_algorithms();
		void print_about_size(std::size_t size);
		void print_about_algorithm(const std::string& name, float time);

	public:
		BenchmarkMode(std::size_t inizial_size = 100);
		void start();
	};
}
namespace benmode
{
	Sizes::Sizes(std::size_t current_size, std::size_t coefficient)
		:current_size{current_size}, saved_size{ current_size },
		coefficient{coefficient},more_one{ false }{}
	void Sizes::increase()
	{
		if (more_one)
			current_size = saved_size * coefficient++;
		else
		{
			current_size *= 2;
			saved_size = current_size;
		}
	}
	template<typename T>
	BenchmarkMode<T>::BenchmarkMode(std::size_t inizial_size)
		:inizial_size{inizial_size}{}
	template<typename T>
	void BenchmarkMode<T>::print_about_size(std::size_t size)
	{
		writer.append("Size=" + std::to_string(size) + " {");
		std::cout << "\nSize=" << size << std::endl;
	}
	template<typename T>
	void BenchmarkMode<T>::print_about_algorithm(const std::string& name, float time)
	{
		writer.append(
			"algorithm=" + name+ " time=" + std::to_string(time) + "s");
		std::cout << name << ":\t" << time << "s" << std::endl;
	}
	template<typename T>
	void BenchmarkMode<T>::measure_sorts(
		const std::vector<void(*)(std::vector<T>&)>& functions,
		const std::vector<std::string>& names)
	{
		writer.clear();
		Sizes sizes{ inizial_size };
		float time;
		bool more_ten = false;
		while (true)
		{
			std::vector<T> arr = sorts::create_random_array<T>(sizes.current_size);
			print_about_size(sizes.current_size);
			for (std::size_t i = 0; i < functions.size(); i++)
			{
				std::vector<T> copy_arr = arr;
				{
					Timer timer(time);
					functions[i](copy_arr);
				}
				if (time > 1) sizes.more_one = true;
				if (time > 10) more_ten = true;
				print_about_algorithm(names[i], time);
			}
			writer.append("}");
			if (more_ten) break;
			sizes.increase();
		}
		writer.info();
	}
	template<typename T>
	void BenchmarkMode<T>::measure_multiplications(
		const std::vector<Matrix<T>(*)(const Matrix<T>&, const Matrix<T>&)>& functions,
		const std::vector<std::string>& names)
	{
		writer.clear();
		Sizes sizes{ inizial_size };
		float time;
		bool more_ten = false;
		while (true)
		{
			Matrix<T> matrix1 = Matrix<T>::create_random_matrix(sizes.current_size, 100),
				matrix2 = Matrix<T>::create_random_matrix(sizes.current_size, 100);

			print_about_size(sizes.current_size);
			for (std::size_t i = 0; i < functions.size(); i++)
			{
				Matrix<T> copy_matrix1 = matrix1, copy_matrix2 = matrix2;
				{
					Timer timer(time);
					auto res = functions[i](copy_matrix1, copy_matrix2);
				}
				if (time > 1) sizes.more_one = true;
				if (time > 10) more_ten = true;
				print_about_algorithm(names[i], time);
			}
			writer.append("}");
			if (more_ten) break;
			sizes.increase();
		}
		writer.info();
	}
	template<typename T>
	void BenchmarkMode<T>::measure_sorts_algorithms()
	{
		writer = FileWriter{ "sorts_algorithms_result.txt" };
		measure_sorts(
			{ &seqsorts::merge_sort, &parsorts::merge_sort,
			&seqsorts::quick_sort, &parsorts::quick_sort },
			{ "sequential merge sort","parallel merge sort",
			"sequential quick sort","parallel quick sort" });
	}
	template<typename T>
	void BenchmarkMode<T>::measure_multiplication_algorithms()
	{
		writer = FileWriter{ "matrix_multiplication_algorithms_result.txt" };
		measure_multiplications(
			{ &seqmulmatrix::simple_multiplication, &parmulmatrix::simple_multiplication,
			&seqmulmatrix::strassen_multiplication, &parmulmatrix::strassen_multiplication },
			{ "sequential simple multiplication","parallel simple multiplication",
			"sequential strassen multiplication","parallel strassen multiplication" });
	}
	template<typename T>
	void BenchmarkMode<T>::start()
	{
		measure_multiplication_algorithms();
		measure_sorts_algorithms();
	}
}