#pragma once
#include <vector>
#include <iostream>
#include <cmath>
/*
namespace sm//strassen multiplication
{
	
	template<typename T>
	class MatrixMultiplication
	{
	private:
		Matrix<T>& matrix1;
		Matrix<T>& matrix2;
	public:
		MatrixMultiplication(Matrix<T>& matrix1, Matrix<T>& matrix2);
	};
	/*
	
	
	class StrassenSubmatrices : public Submatrices
	{
	private:
		std::vector<std::vector<int>> matrixM1;
		std::vector<std::vector<int>> matrixM2;
		std::vector<std::vector<int>> matrixM3;
		std::vector<std::vector<int>> matrixM4;
		std::vector<std::vector<int>> matrixM5;
		std::vector<std::vector<int>> matrixM6;
		std::vector<std::vector<int>> matrixM7;
		std::vector<std::vector<int>> createM1();
		std::vector<std::vector<int>> createM2();
		std::vector<std::vector<int>> createM3();
		std::vector<std::vector<int>> createM4();
		std::vector<std::vector<int>> createM5();
		std::vector<std::vector<int>> createM6();
		std::vector<std::vector<int>> createM7();
		std::vector<std::vector<int>> getC11();
		std::vector<std::vector<int>> getC12();
		std::vector<std::vector<int>> getC21();
		std::vector<std::vector<int>> getC22();
	public:
		StrassenSubmatrices(
			const std::vector<std::vector<int>>& matrixA,
			const std::vector<std::vector<int>>& matrixB,
			std::size_t size);
	};*/

	/*
	
	std::vector<std::vector<int>> recursiveStrassenMultiplication(
		const std::vector<std::vector<int>>& matrixA,
		const std::vector<std::vector<int>>& matrixB);
	std::vector<std::vector<int>> strassenMultiplication(
		const std::vector<std::vector<int>>& matrix1,
		const std::vector<std::vector<int>>& matrix2);*/
/*}
namespace sm
{
	template<typename T>
	MatrixMultiplication<T>::MatrixMultiplication(
		Matrix<T>& matrix1, Matrix<T>& matrix2) : matrix1{ matrix1 }, matrix2{ matrix2 } {}
	//classes
	//PartOfMatrices
	/*
	//SimpleSubmatrices
	
	//StrassenSubmatrices
	StrassenSubmatrices::StrassenSubmatrices(
		const std::vector<std::vector<int>>& matrixA,
		const std::vector<std::vector<int>>& matrixB,
		std::size_t size) : Submatrices(matrixA, matrixB, size)
	{
		matrixM1 = createM1();
		matrixM2 = createM2();
		matrixM3 = createM3();
		matrixM4 = createM4();
		matrixM5 = createM5();
		matrixM6 = createM6();
		matrixM7 = createM7();
	}
	std::vector<std::vector<int>> StrassenSubmatrices::createM1()
	{
		return recursiveStrassenMultiplication(partA.get11() + partA.get22(), partB.get11() + partB.get22());
	}
	std::vector<std::vector<int>> StrassenSubmatrices::createM2()
	{
		return recursiveStrassenMultiplication(partA.get21() + partA.get22(), partB.get11());
	}
	std::vector<std::vector<int>> StrassenSubmatrices::createM3()
	{
		return recursiveStrassenMultiplication(partA.get11(), partB.get12() - partB.get22());
	}
	std::vector<std::vector<int>> StrassenSubmatrices::createM4()
	{
		return recursiveStrassenMultiplication(partA.get22(), partB.get21() - partB.get11());
	}
	std::vector<std::vector<int>> StrassenSubmatrices::createM5()
	{
		return recursiveStrassenMultiplication(partA.get11() + partA.get12(), partB.get22());
	}
	std::vector<std::vector<int>> StrassenSubmatrices::createM6()
	{
		return recursiveStrassenMultiplication(
			partA.get21() - partA.get11(),
			partB.get11() + partB.get12());
	}
	std::vector<std::vector<int>> StrassenSubmatrices::createM7()
	{
		return recursiveStrassenMultiplication(
			partA.get12() - partA.get22(),
			partB.get21() + partB.get22());
	}
	std::vector<std::vector<int>> StrassenSubmatrices::getC11()
	{
		return (((matrixM1 + matrixM4) - matrixM5) + matrixM7);
	}
	std::vector<std::vector<int>> StrassenSubmatrices::getC12()
	{
		return (matrixM3 + matrixM5);
	}
	std::vector<std::vector<int>> StrassenSubmatrices::getC21()
	{
		return (matrixM2 + matrixM4);
	}
	std::vector<std::vector<int>> StrassenSubmatrices::getC22()
	{
		return (((matrixM1 - matrixM2) + matrixM3) + matrixM6);
	}*/

	
	/*	
	//functions
	
	
	std::vector<std::vector<int>> strassenMultiplication(
		const std::vector<std::vector<int>>& matrix1,
		const std::vector<std::vector<int>>& matrix2)
	{
		if (!checkSizesOfMatrices(matrix1, matrix2)) return { };
		std::vector<std::vector<int>> matrixA = matrix1, matrixB = matrix2;
		addZerosToMatrices(matrixA, matrixB);
		std::vector<std::vector<int>> matrixC = recursiveStrassenMultiplication(matrixA, matrixB);
		removeExtraZeros(matrixC, matrix1.size());
		return matrixC;
	}
	
	std::vector<std::vector<int>> recursiveStrassenMultiplication(
		const std::vector<std::vector<int>>& matrixA,
		const std::vector<std::vector<int>>& matrixB)
	{
		std::size_t size = matrixA.size();
		if (size <= 4)
		{
			return simpleRecursiveMultiplication(matrixA, matrixB);
		}
		StrassenSubmatrices submatrices(matrixA, matrixB, size);
		return submatrices.mergeMatrices();
	}
	
}*/
