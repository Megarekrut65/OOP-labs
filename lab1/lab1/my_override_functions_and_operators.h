#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <math.h>

namespace ofo//override functions and operators
{
	template<typename T>
	std::string toTheString(const std::vector<T>& array);//to_string for std::vector<T>
	template<typename T>
	std::string toTheString(const T& value);//edit name of function std::to_sting 
    template<>
    std::string toTheString(const std::string& line);//to_string for std::string
    template<>
    std::string toTheString(const double& value);//to_string for double
	template<typename T>
	std::ostream& operator<< (std::ostream& out, const std::vector<T>& array);
	template<typename T>
	void vectorCopy(std::vector<T>& array1, const std::vector<T>& array2);//array2 append to array1
	template<typename T>
	std::vector<T> operator + (const std::vector<T>& array1, const std::vector<T>& array2);
    template<typename T>
    std::vector<T> operator - (const std::vector<T>& array1, const std::vector<T>& array2);
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
    template<typename T>
    T randomValue(const T& maxValue);
    template<>
    double randomValue(const double& maxValue);
    template<>
    std::string randomValue(const std::string& maxValue);
    template<typename T>
    std::vector<T> randomValue(const std::vector<T>& maxValue);
 }
namespace ofo
{
    template<typename T>
    std::string toTheString(const std::vector<T>& array)
    {
        std::string result = "";
        result += "Size: " + std::to_string(array.size()) + ", array: ";
        for (std::size_t i = 0; i < array.size(); i++) result += std::to_string(array[i]) + " ";

        return result;
    }
    template<>
    std::string toTheString(const std::string& line)
    {
        return line;
    }
    template<>
    std::string toTheString(const double& value)
    {
        std::string line = std::to_string(value);
        while(true)
        {
            if (line.size() == 1) break;
            if (line[line.size() - 1] == '0') line.erase(line.size() - 1, 1);
            else if (line[line.size() - 1] == '.') line.erase(line.size() - 1, 1);
            else break;
        }

        return line;
    }
    template<typename T>
    std::string toTheString(const T& value)
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
        if (index + 1 == 0) return line1;
        line3 = line1;
        line3.erase(index, line2.size());

        return line3;
    } 
    template<typename T>
    T randomValue(const T& maxValue)
    {
        return rand() % (maxValue + 1);
    }
    template<>
    double randomValue(const double& maxValue)
    {
        return (double)(rand())/RAND_MAX * maxValue;
    }
    template<>
    std::string randomValue(const std::string& maxValue)
    {
        std::size_t size = rand() % (maxValue.size() + 1);
        std::string line = "";
        for (std::size_t i = 0; i < size; i++)
        {
            line+= 'a' + (rand() % 26);
        }
        return line;
    }
    template<typename T>
    std::vector<T> randomValue(const std::vector<T>& maxValue)
    {
        std::vector<T> array;
        std::size_t size = rand() % (maxValue.size() + 1);
        for (std::size_t i = 0; i < size; i++)
        {
            array.push_back(rand() % (abs(maxValue[i]) + 1));
        }

        return array;
    }
}
