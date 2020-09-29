#pragma once
#include <vector>
#include <string>
#include <iostream>

namespace ofo//override functions and operators
{
	template<typename T>
	std::string toString(const std::vector<T>& array);//to_string for std::vector<T>
    std::string toString(const std::string& line);//to_string for std::string
	template<typename T>
	std::string toString(const T& value);//edit name of function std::to_sting 
	template<typename T>
	std::ostream& operator<< (std::ostream& out, const std::vector<T>& array);
	template<typename T>
	void vectorCopy(std::vector<T>& array1, const std::vector<T>& array2);//array2 append to array1
	template<typename T>
	std::vector<T> operator + (const std::vector<T>& array1, const std::vector<T>& array2);
    template<typename T>
    std::vector<T> operator - (const std::vector<T>& array1, const std::vector<T>& array2);
	template<typename T>
	std::vector<T> operator % (const int& random, const std::vector<T>& array1);// use for rand() % std::vector<T>
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
    template<typename T>
    bool operator != (const std::vector<T>& array1, const std::vector<T>& array2);
    std::string operator - (const std::string& line1, const std::string& line2);
    std::string operator % (const int& random, const std::string& line1);// use for rand() % std::string
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
    std::string toString(const std::string& line)
    {
        return line;
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
    std::vector<T> operator - (const std::vector<T>& array1, const std::vector<T>& array2)
    {
        std::vector<T> array3;
        std::size_t size1 = array1.size(), size2 = array2.size();
        if (size2 >= size1) return array3;
        std::size_t newSize = size1 - size2;
        vectorCopy(array3, array1);
        array3.erase(array3.begin() + newSize, array3.end());

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
        if (array1.size() != array2.size()) return false;
        for (std::size_t i = 0; i < array1.size(); i++)
        {
            if (array1[i] != array2[i]) return false;
        }

        return true;
    }
    template<typename T>
    bool operator != (const std::vector<T>& array1, const std::vector<T>& array2)
    {
        if (array1.size() != array2.size()) return true;
        for (std::size_t i = 0; i < array1.size(); i++)
        {
            if (array1[i] != array2[i]) return true;
        }

        return false;
    }
    std::string operator - (const std::string& line1, const std::string& line2)
    {
        std::string line3;     
        std::size_t index = line1.find(line2, 0);
        if (index + 1 == 0) return line3;
        line3 = line1;
        line3.erase(line3.begin() + index, line3.begin() + index + line2.size() - 1);

        return line3;
    }
    std::string operator % (const int& random, const std::string& line1)
    {
        std::string line2;
        std::size_t size = random % (line1.size() + 1);
        for (std::size_t i = 0; i < size; i++)
        {
            line2.push_back(rand() % 'Z');
        }

        return line2;
    }    
}
