#pragma once
#include <vector>
#include <string>
#include <iostream>

namespace ofo//override functions and operators
{
	template<typename T>
	std::string toString(const std::vector<T>& array);//to_string for a vector
	template<typename T>
	std::string toString(const T& value);//edit name of function std::to_sting 
	template<typename T>
	std::ostream& operator<< (std::ostream& out, const std::vector<T>& array);
	template<typename T>
	void vectorCopy(std::vector<T>& array1, const std::vector<T>& array2);//array2 append to array1
	template<typename T>
	std::vector<T> operator + (const std::vector<T>& array1, const std::vector<T>& array2);
	template<typename T>
	std::vector<T> operator % (const int& random, const std::vector<T>& array1);// use for rand()%std::vector<T>
	template<typename T>
	bool operator < (const std::vector<T>& array1, const std::vector<T>& array2);
	template<typename T>
	bool operator <= (const std::vector<T>& array1, const std::vector<T>& array2);
	template<typename T>
	bool operator > (const std::vector<T>& array1, const std::vector<T>& array2);
	template<typename T>
	bool operator >= (const std::vector<T>& array1, const std::vector<T>& array2);
	template<typename T>
	bool operator == (const std::vector<T>& array1, const std::vector<T>& array2);
}
namespace ofo
{
    template<typename T>
    std::string toString(const std::vector<T>& array)
    {
        std::string result = "";
        result += "Size: " + std::to_string(array.size()) + ", array: ";
        for (std::size_t i = 0; i < array.size(); i++) result += std::to_string(array[i]) + " ";

        return result;
    }
    template<typename T>
    std::string toString(const T& value)
    {
        return std::to_string(value);
    }
    template<typename T>
    std::ostream& operator<< (std::ostream& out, const std::vector<T>& array)
    {
        out << "Size: " << array.size() << ", array: ";
        for (std::size_t i = 0; i < array.size(); i++) out << array[i] << " ";

        return out;
    }
    template<typename T>
    void vectorCopy(std::vector<T>& array1, const std::vector<T>& array2)
    {
        for (std::size_t i = 0; i < array2.size(); i++) array1.push_back(array2[i]);
    }
    template<typename T>
    std::vector<T> operator + (const std::vector<T>& array1, const std::vector<T>& array2)
    {
        std::vector<T> array3;
        vectorCopy(array3, array1);
        vectorCopy(array3, array2);
        return array3;
    }
    template<typename T>
    std::vector<T> operator % (const int& random, const std::vector<T>& array1)
    {
        std::vector<T> array2;
        std::size_t size = random % (array1.size() + 1);
        for (std::size_t i = 0; i < size; i++)
        {
            array2.push_back(rand() % (array1[i] + 1));
        }

        return array2;
    }
    template<typename T>
    bool operator < (const std::vector<T>& array1, const std::vector<T>& array2)
    {
        return (array1.size() < array2.size());
    }
    template<typename T>
    bool operator <= (const std::vector<T>& array1, const std::vector<T>& array2)
    {
        return (array1.size() <= array2.size());
    }
    template<typename T>
    bool operator > (const std::vector<T>& array1, const std::vector<T>& array2)
    {
        return (array1.size() > array2.size());
    }
    template<typename T>
    bool operator >= (const std::vector<T>& array1, const std::vector<T>& array2)
    {
        return (array1.size() >= array2.size());
    }
    template<typename T>
    bool operator == (const std::vector<T>& array1, const std::vector<T>& array2)
    {
        return (array1.size() == array2.size());
    }
}
