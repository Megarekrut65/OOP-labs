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
	/*class PartOfMatrices
	{
	private:
		const std::vector<std::vector<int>>& matrix;
		std::size_t size;
		std::vector<std::vector<int>> matrix11;
		std::vector<std::vector<int>> matrix12;
		std::vector<std::vector<int>> matrix21;
		std::vector<std::vector<int>> matrix22;

		std::vector<std::vector<int>> createPartOfMatrix(
			std::size_t beginRow, std::size_t beginColumn,
			std::size_t endRow, std::size_t endColumn);
	public:
		PartOfMatrices();
		PartOfMatrices(const std::vector<std::vector<int>>& matrix,
			std::size_t size);
		std::vector<std::vector<int>> get11();
		std::vector<std::vector<int>> get12();
		std::vector<std::vector<int>> get21();
		std::vector<std::vector<int>> get22();
	};
	class Submatrices
	{
	private:
		virtual std::vector<std::vector<int>> getC11();
		virtual std::vector<std::vector<int>> getC12();
		virtual std::vector<std::vector<int>> getC21();
		virtual std::vector<std::vector<int>> getC22();
		void copyPartToMatrix(std::vector<std::vector<int>>& matrix,
			const std::vector<std::vector<int>>& part,
			std::size_t beginRow, std::size_t beginColumn,
			std::size_t endRow, std::size_t endColumn);
	protected:
		const std::vector<std::vector<int>>& matrixA;
		const std::vector<std::vector<int>>& matrixB;
		std::size_t size;
		PartOfMatrices partA;
		PartOfMatrices partB;
	public:
		Submatrices(
			const std::vector<std::vector<int>>& matrixA,
			const std::vector<std::vector<int>>& matrixB,
			std::size_t size);
		std::vector<std::vector<int>> mergeMatrices();
	};
	class SimpleSubmatrices : public Submatrices
	{
	private:
		std::vector<std::vector<int>> getC11();
		std::vector<std::vector<int>> getC12();
		std::vector<std::vector<int>> getC21();
		std::vector<std::vector<int>> getC22();
	public:
		SimpleSubmatrices(
			const std::vector<std::vector<int>>& matrixA,
			const std::vector<std::vector<int>>& matrixB,
			std::size_t size);
	};
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

	/*bool checkSizesOfMatrices(const std::vector<std::vector<int>>& matrixA,
		const std::vector<std::vector<int>>& matrixB);
	void addZerosToMatrices(std::vector<std::vector<int>>& matrixA,
		std::vector<std::vector<int>>& matrixB);
	void addZeros(std::vector<std::vector<int>>& matrix, std::size_t newSize);
	void removeExtraZeros(std::vector<std::vector<int>>& matrix, std::size_t oldSize);
	std::vector<std::vector<int>> simpleRecursiveMultiplication(
		const std::vector<std::vector<int>>& matrixA,
		const std::vector<std::vector<int>>& matrixB);
	std::vector<std::vector<int>> recursiveStrassenMultiplication(
		const std::vector<std::vector<int>>& matrixA,
		const std::vector<std::vector<int>>& matrixB);
	std::vector<std::vector<int>> simpleMultiplication(
		const std::vector<std::vector<int>>& matrix1,
		const std::vector<std::vector<int>>& matrix2);
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
	/*PartOfMatrices::PartOfMatrices()
		:matrix{ std::vector<std::vector<int>>() }, size{ 0 } {}
	PartOfMatrices::PartOfMatrices(
		const std::vector<std::vector<int>>& matrix,
		std::size_t size) : matrix(matrix), size(size)
	{
		matrix11 = createPartOfMatrix(0, 0, size / 2, size / 2);
		matrix12 = createPartOfMatrix(0, size / 2, size / 2, size);
		matrix21 = createPartOfMatrix(size / 2, 0, size, size / 2);
		matrix22 = createPartOfMatrix(size / 2, size / 2, size, size);
	}
	std::vector<std::vector<int>> PartOfMatrices::createPartOfMatrix(
		std::size_t beginRow, std::size_t beginColumn,
		std::size_t endRow, std::size_t endColumn)
	{
		std::vector<std::vector<int>> part(endRow - beginRow, std::vector<int>(endColumn - beginColumn));
		for (std::size_t i = beginRow; i < endRow; i++)
		{
			for (std::size_t j = beginColumn; j < endColumn; j++)
			{
				part[i - beginRow][j - beginColumn] = matrix[i][j];
			}
		}

		return part;
	}
	std::vector<std::vector<int>> PartOfMatrices::get11()
	{
		return matrix11;
	}
	std::vector<std::vector<int>> PartOfMatrices::get12()
	{
		return matrix12;
	}
	std::vector<std::vector<int>> PartOfMatrices::get21()
	{
		return matrix21;
	}
	std::vector<std::vector<int>> PartOfMatrices::get22()
	{
		return matrix22;
	}
	//Submatrices
	Submatrices::Submatrices(
		const std::vector<std::vector<int>>& matrixA,
		const std::vector<std::vector<int>>& matrixB,
		std::size_t size)
		: matrixA(matrixA), matrixB(matrixB), size(size),
		partA(PartOfMatrices(matrixA, size)),
		partB(PartOfMatrices(matrixB, size)) {}
	std::vector<std::vector<int>> Submatrices::getC11() { return { }; }
	std::vector<std::vector<int>> Submatrices::getC12() { return { }; }
	std::vector<std::vector<int>> Submatrices::getC21() { return { }; }
	std::vector<std::vector<int>> Submatrices::getC22() { return { }; }
	std::vector<std::vector<int>> Submatrices::mergeMatrices()
	{
		std::vector<std::vector<int>> matrixC(size, std::vector<int>(size));
		copyPartToMatrix(matrixC, getC11(), 0, 0, size / 2, size / 2);
		copyPartToMatrix(matrixC, getC12(), 0, size / 2, size / 2, size);
		copyPartToMatrix(matrixC, getC21(), size / 2, 0, size, size / 2);
		copyPartToMatrix(matrixC, getC22(), size / 2, size / 2, size, size);

		return matrixC;
	}
	void  Submatrices::copyPartToMatrix(std::vector<std::vector<int>>& matrix,
		const std::vector<std::vector<int>>& part,
		std::size_t beginRow, std::size_t beginColumn,
		std::size_t endRow, std::size_t endColumn)
	{
		for (std::size_t i = beginRow; i < endRow; i++)
		{
			for (std::size_t j = beginColumn; j < endColumn; j++)
			{
				matrix[i][j] = part[i - beginRow][j - beginColumn];
			}
		}
	}
	//SimpleSubmatrices
	SimpleSubmatrices::SimpleSubmatrices(
		const std::vector<std::vector<int>>& matrixA,
		const std::vector<std::vector<int>>& matrixB,
		std::size_t size) : Submatrices(matrixA, matrixB, size) {}
	std::vector<std::vector<int>> SimpleSubmatrices::getC11()
	{
		return (simpleRecursiveMultiplication(partA.get11(), partB.get11())
			+
			simpleRecursiveMultiplication(partA.get12(), partB.get21()));
	}
	std::vector<std::vector<int>> SimpleSubmatrices::getC12()
	{
		return (simpleRecursiveMultiplication(partA.get11(), partB.get12())
			+
			simpleRecursiveMultiplication(partA.get12(), partB.get22()));
	}
	std::vector<std::vector<int>> SimpleSubmatrices::getC21()
	{
		return (simpleRecursiveMultiplication(partA.get21(), partB.get11())
			+
			simpleRecursiveMultiplication(partA.get22(), partB.get21()));
	}
	std::vector<std::vector<int>> SimpleSubmatrices::getC22()
	{
		return (simpleRecursiveMultiplication(partA.get21(), partB.get12())
			+
			simpleRecursiveMultiplication(partA.get22(), partB.get22()));
	}
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
	bool checkSizesOfMatrices(const std::vector<std::vector<int>>& matrixA,
		const std::vector<std::vector<int>>& matrixB)
	{
		std::size_t sizeA = matrixA.size();
		std::size_t sizeB = matrixB.size();
		for (std::size_t i = 0; i < sizeA; i++)
		{
			if (sizeA != sizeB || sizeA == 0 ||
				matrixA[i].size() != sizeA || matrixB[i].size() != sizeB)
			{
				std::cerr << "Error: incorrect size of matrices!" << std::endl;
				exit(-1);
				return false;
			}
		}

		return true;
	}
	std::vector<std::vector<int>> simpleMultiplication(
		const std::vector<std::vector<int>>& matrix1,
		const std::vector<std::vector<int>>& matrix2)
	{
		if (!checkSizesOfMatrices(matrix1, matrix2)) return { };
		std::vector<std::vector<int>> matrixA = matrix1, matrixB = matrix2;
		addZerosToMatrices(matrixA, matrixB);
		std::vector<std::vector<int>> matrixC = simpleRecursiveMultiplication(matrixA, matrixB);
		removeExtraZeros(matrixC, matrix1.size());
		return matrixC;
	}
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
	std::vector<std::vector<int>> simpleRecursiveMultiplication(
		const std::vector<std::vector<int>>& matrixA,
		const std::vector<std::vector<int>>& matrixB)
	{
		std::size_t size = matrixA.size();
		if (size == 1)
		{
			return { {matrixA[0][0] * matrixB[0][0]} };
		}
		SimpleSubmatrices submatrices(matrixA, matrixB, size);
		return submatrices.mergeMatrices();
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
	void addZeros(std::vector<std::vector<int>>& matrix, std::size_t newSize)
	{
		std::size_t size = matrix.size();
		std::size_t addZero = newSize - size;
		for (std::size_t i = 0; i < size; i++)
		{
			for (std::size_t k = 0; k < addZero; k++)
			{
				matrix[i].push_back(0);
			}
		}
		for (std::size_t j = 0; j < addZero; j++)
		{
			matrix.push_back(std::vector<int>(newSize));
		}
	}
	void addZerosToMatrices(std::vector<std::vector<int>>& matrixA,
		std::vector<std::vector<int>>& matrixB)
	{
		std::size_t newSize = (std::size_t)pow(2, ceil(log2(matrixA.size())));
		addZeros(matrixA, newSize);
		addZeros(matrixB, newSize);
	}
	void removeExtraZeros(std::vector<std::vector<int>>& matrix, std::size_t oldSize)
	{
		std::size_t size = matrix.size();
		std::size_t removeZero = size - oldSize;
		for (std::size_t i = 0; i < size; i++)
		{
			for (std::size_t k = 0; k < removeZero; k++)
			{
				matrix[i].erase(matrix[i].end() - 1);
			}
		}
		for (std::size_t j = 0; j < removeZero; j++)
		{
			matrix.erase(matrix.end() - 1);
		}
	}
}*/
