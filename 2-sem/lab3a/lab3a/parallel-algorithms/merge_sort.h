#pragma once
#include "../libraries_and_namespaces.h"
#include "thread_number.h"

using namespace sorts;
namespace parsorts
{
    /**
    *   \brief Sorts array
    *
    *   Top-down implementation.
    *   See [Merge sort.](https://en.wikipedia.org/wiki/Merge_sort "Information about this algorithm in Wikipedia")
    */
    template<typename T>
    void merge_sort(std::vector<T>& arr);
    /**
    *   \brief Merges two arrays to one
    *
    *   \param arr - array of numbers
    *   \param begin - begin index of firts array
    *   \param middle - end index of firts and begin index of second arrays
    *   \param end - end index of second array
    */
    template<typename T>
    void merge(std::vector<T>& arr, std::size_t begin, std::size_t middle, std::size_t end);
    /**
    *   \brief Sorts part of array
    *
    *   \param arr - array of numbers
    *   \param begin - index of begin item
    *   \param end - index of end item
    */
    template<typename T>
    void merge_sorting(std::vector<T>& arr, std::size_t begin, std::size_t end, thnum::ThreadNumber& th_number);
}
namespace parsorts
{
    template<typename T>
    void merge(std::vector<T>& arr, std::size_t begin, std::size_t middle, std::size_t end)
    {
        std::size_t left_size = middle - begin, right_size = end - middle;
        std::size_t i = 0, j = 0, k = begin;
        std::vector<T> left_arr, right_arr;
        copy_to_array(arr, left_arr, begin, left_size);
        copy_to_array(arr, right_arr, middle, right_size);
        while (i < left_size && j < right_size)
        {
            if (left_arr[i] <= right_arr[j])
            {
                arr[k] = left_arr[i];
                i++;
            }
            else
            {
                arr[k] = right_arr[j];
                j++;
            }
            k++;
        }
        for (; i < left_size; i++, k++) arr[k] = left_arr[i];
        for (; j < right_size; j++, k++) arr[k] = right_arr[j];
    }
    template<typename T>
    void merge_sorting(std::vector<T>& arr, std::size_t begin, std::size_t end, thnum::ThreadNumber& th_number)
    {
        if (end - begin < 2) return;
        std::size_t middle = (end + begin) / 2;
        std::thread th;
        if (th_number.add_new_thread())
            th = std::thread([=, &arr, &th_number](){merge_sorting(arr, begin, middle, th_number);});
        else merge_sorting(arr, begin, middle, th_number);
        merge_sorting(arr, middle, end, th_number);
        if(th.joinable()) th.join();
        merge(arr, begin, middle, end);
    }
    template<typename T>
    void merge_sort(std::vector<T>& arr)
    {
        thnum::ThreadNumber th_number;
        merge_sorting(arr, 0, arr.size(), th_number);
    }
}
