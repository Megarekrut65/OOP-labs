#pragma once
#include <vector>
#include <string>

/*
*   \brief Namespace for sort algorithm and addition functions
*/
namespace sorts
{
    /*
    *   \brief Copies part of arr to copy_arr
    *
    *   Addition function for merge_sort().
    *   \param arr - array of items
    *   \param copy_arr - empty array
    *   \param begin - begin index of part to copy
    *   \param size - size of part to copy
    */
    template<typename T>
    void copy_to_array(std::vector<T>& arr, std::vector<T>& copy_arr, std::size_t begin, std::size_t size);
    /*
    *   \brief Spaws two items
    *
    *   Addition function for bubble_sort(), selection_sort() and quick_sort().
    */
    template<typename T>
    void swap(T& first, T& second);
    /*
    *   \brief Translates array to line
    *
    *   Addition function.
    */
    template<typename T>
    std::string array_to_string(std::vector<T>& arr);
    /*
    *   \brief Returns maximum item in arr
    *
    *   Addition function.
    */
    template<typename T>
    T get_max(std::vector<T>& arr);
    /*
    *   \brief Returns minimum item in arr
    *
    *   Addition function.
    */
    template<typename T>
    T get_min(std::vector<T>& arr);
    /*
    *   \brief Creates array with random items
    *   \param size - size of array
    */
    template<typename T>
    std::vector<T> create_random_array(std::size_t size);
    /*
    *   \brief Creates array with almost ordered items
    *   \param size - size of array
    *   \param random_start - index of firts not ordered item
    */
    template<typename T>
    std::vector<T> create_ordered_array(std::size_t size, std::size_t random_start);
    /*
    *   \brief Creates array with almost reverse ordered items
    *   \param size - size of array
    *   \param random_start - index of firts not inordered item
    */
    template<typename T>
    std::vector<T> create_reverse_ordered_array(std::size_t size, std::size_t random_start);
    /*
    *   \brief Compares two arrays by values
    */
    template<typename T>
    bool operator ==(const std::vector<T>& arr1, const std::vector<T>& arr2);
}
namespace sorts
{
    template<typename T>
    bool operator ==(const std::vector<T>& arr1, const std::vector<T>& arr2)
    {
        if(arr1.size() != arr2.size()) return false;
        for(std::size_t i = 0; i < arr1.size();i++)
            if(arr1[i] != arr2[i]) return false;
        return true;
    }
    template<typename T>
    std::vector<T> create_random_array(std::size_t size)
    {
        std::vector<T> arr;
        for(std::size_t i = 0; i < size; i++)
            arr.push_back(rand()%30000);
        return arr;

    }
    template<typename T>
    std::vector<T> create_ordered_array(std::size_t size, std::size_t random_start)
    {
        if(size == 0) return {};
        if(size < random_start) swap(size, random_start);
        std::vector<T> arr;
        for(std::size_t i = 0; i < size; i++)
            arr.push_back(i);
        if(size == 1) return arr;
        for(std::size_t i = random_start; i < size;i++)
        {
            auto item = arr[i];
            arr.erase(arr.begin() + i);
            arr.insert(arr.begin() + (size - random_start - 1 > 0? rand()%(size - random_start - 1) + random_start: (size - 1)), item);
        }
        return arr;
    }
    template<typename T>
    std::vector<T> create_reverse_ordered_array(std::size_t size, std::size_t random_start)
    {
        if(size == 0) return {};
        if(size < random_start) swap(size, random_start);
        std::vector<T> arr;
        for(std::size_t i = 0; i < size; i++)
            arr.push_back(size - i - 1);
        if(size == 1) return arr;
        for(std::size_t i = random_start; i < size;i++)
        {
            auto item = arr[i];
            arr.erase(arr.begin() + i);
                        arr.insert(arr.begin() + (size - random_start - 1 > 0? rand()%(size - random_start - 1) + random_start: (size - 1)), item);
        }
        return arr;
    }
    template<typename T>
    void copy_to_array(std::vector<T>& arr, std::vector<T>& copy_arr, std::size_t begin, std::size_t size)
    {
        copy_arr.clear();
        for (std::size_t i = 0; i < size; i++)
        {
            copy_arr.push_back(arr[begin + i]);
        }
    }
    template<typename T>
    T get_max(std::vector<T>& arr)
    {
        if(arr.size() < 1) return T();
        T max = arr[0];
        for(std::size_t i = 1; i < arr.size(); i++)
            if(arr[i] > max) max = arr[i];
        return max;
    }
    template<typename T>
    T get_min(std::vector<T>& arr)
    {
        if(arr.size() < 1) return T();
        T min = arr[0];
        for(std::size_t i = 1; i < arr.size(); i++)
            if(arr[i] < min) min = arr[i];
        return min;
    }
    template<typename T>
    void swap(T& first, T& second)
    {
        T temp = first;
        first = second;
        second = temp;
    }
    template<typename T>
    std::string array_to_string(std::vector<T>& arr)
    {
        std::string res = "";
        for(std::size_t i = 0; i < arr.size();i++)
            res += std::to_string(arr[i]) + " ";
        return res;
    }
}
