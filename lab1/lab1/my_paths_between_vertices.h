#pragma once
#include <iostream>
namespace pbv//path between vetices
{
    template<typename T>
    struct PathsBetweenVertices
    {
        T* distance;
        bool* isMax;
        std::size_t size;
        std::size_t beginIndex;

        PathsBetweenVertices();
        PathsBetweenVertices(std::size_t size, std::size_t beginIndex);
        PathsBetweenVertices(T* distance, bool* isMax, std::size_t size, std::size_t beginIndex);
        PathsBetweenVertices(PathsBetweenVertices&& paths)
            noexcept;
        ~PathsBetweenVertices();
        void print(bool show = false);//print the distance from vertex with beginIndex to all vertices in graph
    };
}
namespace pbv
{
    template<typename T>
    PathsBetweenVertices<T>::PathsBetweenVertices() : distance(nullptr), isMax(nullptr), size(0), beginIndex(0) {}
    template<typename T>
    PathsBetweenVertices<T>::PathsBetweenVertices(std::size_t size, std::size_t beginIndex)
    {
        this->size = size;
        this->beginIndex = beginIndex;
        distance = new T[size];
        isMax = new bool[size];
    }
    template<typename T>
    PathsBetweenVertices<T>::PathsBetweenVertices(T* distance, bool* isMax, std::size_t size, std::size_t beginIndex): distance(distance), isMax(isMax), beginIndex(beginIndex), size(size){}
    template<typename T>
    PathsBetweenVertices<T>::PathsBetweenVertices(PathsBetweenVertices&& paths)
        noexcept
    {
        distance = paths.distance;
        paths.distance = nullptr;
        isMax = paths.isMax;
        paths.isMax = nullptr;
        size = paths.size;
        paths.size = 0;
        beginIndex = paths.beginIndex;
        paths.beginIndex = 0;
    }
    template<typename T>
    PathsBetweenVertices<T>::~PathsBetweenVertices()
    {
        if (distance)
        {
            delete[]distance;
            distance = nullptr;
        }
        if (isMax)
        {
            delete[]isMax;
            isMax = nullptr;
        }            
        size = 0;
        beginIndex = 0;
    }
    template<typename T>
    void PathsBetweenVertices<T>::print(bool show)
    {
        if (!distance || !isMax)
        {
            std::cout << "\nThere aren't paths between vertices!" << std::endl;
            return;
        }
        for (std::size_t i = 0; i < size; i++)
        {
            if (isMax[i])
            {
                if (show) std::cout << "\nThe graph is poorly oriented so it cannot be reached from " << beginIndex
                    << " to " << i << "." << std::endl;
            }
            else
            {
                if (show) std::cout << "\nThe smallest distance from " << beginIndex
                    << " to " << i << " = {" << distance[i] << "}." << std::endl;
            }
        }
    }
}