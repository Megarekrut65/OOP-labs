#pragma once
#include "my_override_functions_and_operators.h"

using namespace ofo;

namespace gs//graph structure
{
    template<typename T>
    struct VertexNode
    {
        std::size_t index;
        VertexNode* next;
        int value;

        VertexNode();
        VertexNode(std::size_t index, VertexNode* next, T value);
    };
    template<typename T>
    struct PathsBetweenVertices
    {
        T* distance;
        bool* isMax;
        std::size_t size;
        std::size_t beginIndex;

        PathsBetweenVertices();
        PathsBetweenVertices(std::size_t size, std::size_t beginIndex);
        PathsBetweenVertices(PathsBetweenVertices&& paths)
            noexcept;
        ~PathsBetweenVertices();
        void print(bool show = true);//print the distance from vertex with beginIndex to all vertices in graph
    };
    template<typename T>
    class GraphStructure
    {
    private:
        std::vector<VertexNode<T>*> list;
        std::size_t numberOfVertices;
        std::size_t numberOfEdges;
        bool orientation;
        T totalValue;

        bool isIndex(std::size_t index);//if vectex with index is in graph then return true, else - false
        bool doAddIndex(std::vector<std::size_t>& indexes, std::size_t index);// if index is not in indexes then function adds index to indexes
        void isConnectedRelativeToTheVertex(std::vector<std::size_t>& indexes, std::size_t index);//the function checks whether the graph is connected starting from a given index of vertex
        bool isConnected(std::vector<std::size_t>& indexes);//the function checks whether the graph is connected with respect to all vertices
        std::size_t minDistance(PathsBetweenVertices<T>& paths, bool* isChecked);//find min distance 
        void dijkstra(PathsBetweenVertices<T>& paths);// algorithm for finding the shortest paths between vertices in a graph
        bool connectedGraph(bool show);//if the graph isn't connected the function messeges about it
        std::vector<std::vector<std::size_t>> createSet();//creates a set consisting only of connected vertices
        void editSet(std::vector<std::vector<std::size_t>>& set, std::size_t index);//remove index from set
        bool isInIndexes(std::vector<std::size_t> indexes, std::size_t index);//checks if there is an index in the array 
        void createSpanningTree(GraphStructure<T>& spanningTree, std::vector<std::size_t>& indexes, std::size_t index);//algorithm for create spanning tree from graph
        GraphStructure<T> kruskal();//algorithm for create minimum spanning tree from graph
        void createRandomVertices(std::size_t numberOfVertices, T maxValue);//adds vertices to new graph
        bool createRandomEdges(std::size_t numberOfEdges, T maxValue);//adds edges to new graph
        bool createGraph(std::size_t numberOfVertices, std::size_t numberOfEdges, bool orientation, T maxValue);//create graph with numberOfVertices vertices and numberOfEdges edges
        void deleteEdges(std::size_t index);//when removes vertex need delete its edges
        void clearNode(std::size_t index);
        bool addNode(std::size_t beginIndex, std::size_t endIndex, T value);
        bool isEdge(std::size_t beginIndex, std::size_t endIndex);
        T findAndRemoveEdge(std::size_t beginIndex, std::size_t endIndex, bool& isFound);
    public:
        GraphStructure();
        GraphStructure(bool orientation);
        GraphStructure(std::size_t numberOfVertices, std::size_t numberOfEdges, bool orientation, T maxValue);//create random graph
        ~GraphStructure();
        void addVertex(T value, bool show = true);//adds a vertex with the value to vertices
        void addEdge(std::size_t beginIndex, std::size_t endIndex, T value, bool show = true);//adds edge from beginIndex to endIndex in graph
        void removeVertex(std::size_t index, bool show = true);//remove the vertex with index from graph
        void removeEdge(std::size_t beginIndex, std::size_t endIndex, bool show = true);//remove the edge from beginIndex to endIndex from graph
        std::string getTextRepresentation();//converts a graph to a string for example to output to the console
        bool checkingTheConnectivity(bool show = true);//returns true if the graph is connected else return false
        std::vector<std::size_t> depthFirstSearch(bool show = true);// algorithm for traversing or searching graph
        T getPathBetweenTwoVertices(std::size_t beginIndex, std::size_t endIndex, bool show = true);//finds the smallest way from beginIndex to endIndex
        PathsBetweenVertices<T> getPathsFromTheVertexToEveryoneElse(std::size_t beginIndex, bool show = true);//finds the smallest way from beginIndex to endIndex to everyone else
        std::vector<std::size_t> topologicalSorting(bool show = true);// the function linearly arranges the vertices of the graph
        GraphStructure<T> getSpanningTree(bool show = true);//creates spanning tree from the graph
        GraphStructure<T> getTheSmallestSpanningTree(bool show = true);//creates minimum spanning tree from the graph

    };
}
namespace gs
{
    //VertexNode
    template<typename T>
    VertexNode<T>::VertexNode() : index(0), next(nullptr), value(0) {}
    template<typename T>
    VertexNode<T>::VertexNode(std::size_t index, VertexNode* next, T value) : index(index), next(next), value(value) {}
    //PathsBetweenVertices
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
        if (distance) delete[]distance;
        if (isMax) delete[]isMax;
        distance = nullptr;
        isMax = nullptr;
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
    //GraphStructure
    //private
    template<typename T>
    bool GraphStructure<T>:: isIndex(std::size_t index)
    {
        if (index >= numberOfVertices)
        {
            std::cout << "\nVertex with index: " << index << " isn't in Graph!" << std::endl;
            return false;
        }

        return true;
    }
    template<typename T>
    bool GraphStructure<T>::doAddIndex(std::vector<std::size_t>& indexes, std::size_t index)
    {
        for (std::size_t i = 0; i < indexes.size(); i++)
        {
            if (indexes[i] == index) return false;
        }
        indexes.push_back(index);

        return true;
    }
    template<typename T>
    void GraphStructure<T>:: isConnectedRelativeToTheVertex(std::vector<std::size_t>& indexes, std::size_t index)
    {
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            if (isEdge(index, i))
            {
                doAddIndex(indexes, index);
                if (index == i) continue;
                if (doAddIndex(indexes, i))
                {
                    isConnectedRelativeToTheVertex(indexes, i);
                }
            }
        }
    }
    template<typename T>
    bool GraphStructure<T>::isConnected(std::vector<std::size_t>& indexes)
    {
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            isConnectedRelativeToTheVertex(indexes, i);
            if (indexes.size() == numberOfVertices)
            {
                return true;
            }
            indexes.clear();
        }

        return false;
    }
    template<typename T>
    std::size_t GraphStructure<T>::minDistance(PathsBetweenVertices<T>& paths, bool* isChecked)
    {
        T min = T();
        bool max = true;
        std::size_t index = 0;
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            if (!isChecked[i] && !paths.isMax[i] && (max || paths.distance[i] <= min))
            {
                max = false;
                min = paths.distance[i];
                index = i;
            }
        }

        return index;
    }
    template<typename T>
    void GraphStructure<T>::dijkstra(PathsBetweenVertices<T>& paths)
    {
        bool* isChecked = new bool[numberOfVertices];
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            paths.isMax[i] = true;
            isChecked[i] = false;
        }
        paths.distance[paths.beginIndex] = T();
        paths.isMax[paths.beginIndex] = false;
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            std::size_t index = minDistance(paths, isChecked);
            isChecked[index] = true;
            for (VertexNode<T>* current = list[index]->next; current; current = current->next)
            {
                std::size_t j = current->index;
                if (!isChecked[j] && !paths.isMax[index] && (paths.isMax[j] 
                    || (paths.distance[index] + current->value < paths.distance[j])))
                {
                    paths.distance[j] = paths.distance[index] + current->value;
                    paths.isMax[j] = false;
                }
            }
        }
        delete[] isChecked;
    }
    template<typename T>
    bool GraphStructure<T>::connectedGraph(bool show)
    {
        std::vector<std::size_t> indexes;
        if (!isConnected(indexes))
        {
            if (show) std::cout << "\nThe graph isn't connected!" << std::endl;
            return false;
        }
        return true;
    }
    template<typename T>
    std::vector<std::vector<std::size_t>> GraphStructure<T>::createSet()
    {
        std::vector<std::vector<std::size_t>> set(numberOfVertices);
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            for (VertexNode<T>* current = list[i]->next; current; current = current->next)
            {
                set[current->index].push_back(i);
            }
        }
        return set;
    }
    template<typename T>
    void GraphStructure<T>::editSet(std::vector<std::vector<std::size_t>>& set, std::size_t index)
    {
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            for (std::size_t j = 0; j < set[i].size(); j++)
            {
                if (set[i][j] == index)
                {
                    set[i].erase(set[i].begin() + j);
                    j--;
                }
            }
        }
    }
    template<typename T>
    bool GraphStructure<T>::isInIndexes(std::vector<std::size_t> indexes, std::size_t index)
    {
        for (std::size_t i = 0; i < indexes.size(); i++)
        {
            if (indexes[i] == index) return true;
        }
        return false;
    }
    template<typename T>
    void GraphStructure<T>::createSpanningTree(GraphStructure<T>& spanningTree, std::vector<std::size_t>& indexes, std::size_t index)
    {
        if (indexes.size() == numberOfVertices) return;
        for (VertexNode<T>* current = list[index]->next; current; current = current->next)
        {
            std::size_t i = current->index;
            doAddIndex(indexes, index);
            if (index == i) continue;
            if (doAddIndex(indexes, i))
            {
                spanningTree.addEdge(index, i, current->value, false);
                createSpanningTree(spanningTree, indexes, i);
            }
        }
    }
    template<typename T>
    GraphStructure<T> GraphStructure<T>::kruskal()
    {
        GraphStructure<T> spanningTree(false);
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            spanningTree.addVertex(list[i]->value, false);
        }
        std::vector<std::size_t> belongs(numberOfVertices);
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            belongs[i] = i;
        }
        std::size_t firstIndex;
        std::size_t secondIndex;
        for (std::size_t vertexIndex = 1; vertexIndex < numberOfVertices; vertexIndex++)
        {
            T min = T();
            bool isMax = true;
            for (std::size_t i = 0; i < numberOfVertices; i++)
            {
                for (VertexNode<T>* current = list[i]->next; current; current = current->next)
                {
                    std::size_t j = current->index;
                    if ((isMax || min > current->value)
                        && (belongs[i] != belongs[j]))
                    {
                        min = current->value;
                        isMax = false;
                        firstIndex = i;
                        secondIndex = j;
                    }
                }
            }
            if (belongs[firstIndex] != belongs[secondIndex])
            {
                spanningTree.addEdge(firstIndex, secondIndex, min, false);
                std::size_t tempIndex = belongs[secondIndex];
                belongs[secondIndex] = belongs[firstIndex];
                for (std::size_t i = 0; i < numberOfVertices; i++)
                {
                    if (belongs[i] == tempIndex)
                    {
                        belongs[i] = belongs[firstIndex];
                    }
                }
            }
        }

        return spanningTree;
    }
    template<typename T>
    void GraphStructure<T>::createRandomVertices(std::size_t numberOfVertices, T maxValue)
    {
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            addVertex(rand() % maxValue, false);
        }
    }
    template<typename T>
    bool GraphStructure<T>::createRandomEdges(std::size_t numberOfEdges, T maxValue)
    {
        if (numberOfEdges <= (numberOfVertices * (numberOfVertices + 1)) / 2)
        {
            while (this->numberOfEdges < numberOfEdges)
            {
                std::size_t i = rand() % numberOfVertices, j = rand() % numberOfVertices;
                if (!isEdge(i, j))
                {
                    addEdge(i, j, rand() % maxValue, false);
                }
            }
        }
        std::cout << "\nThere are too many edges!" << std::endl;

        return false;
    }
    template<typename T>
    bool GraphStructure<T>::createGraph(std::size_t numberOfVertices, std::size_t numberOfEdges, bool orientation, T maxValue)
    {
        srand(unsigned(time(0)));
        this->orientation = orientation;
        totalValue = T();
        createRandomVertices(numberOfVertices, maxValue);
        return createRandomEdges(numberOfEdges, maxValue);
    }
    template<typename T>
    void GraphStructure<T>::deleteEdges(std::size_t index)
    {
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            removeEdge(i, index);
        }
        if (orientation)
        {
            VertexNode<T>* current = list[index];
            while(current->next)
            {
                totalValue = totalValue - current->next->value;
                VertexNode<T>* tempNode = current->next;
                current->next = current->next->next;
                delete tempNode;
                numberOfEdges--;
            }
        }
    }
    template<typename T>
    void GraphStructure<T>::clearNode(std::size_t index)
    {
        VertexNode<T>* current = list[index];
        list[index] = nullptr;
        while (current)
        {
            VertexNode<T>* tempNode = current;
            current = current->next;
            delete tempNode;
            tempNode = nullptr;
        }
    }   
    template<typename T>
    bool GraphStructure<T>::addNode(std::size_t beginIndex, std::size_t endIndex, T value)
    {
        if (isEdge(beginIndex, endIndex)) return false;
        VertexNode<T>* current = list[beginIndex]->next;
        if (!current)
        {
            list[beginIndex]->next = new VertexNode<T>(endIndex, nullptr, value);
            return true;
        }
        VertexNode<T>* tempNode = list[beginIndex];
        for (; current; current = current->next)
        {
            if (current->index > endIndex)
            {
                tempNode->next = new VertexNode<T>(endIndex, current, value);
                return true;
            }
            tempNode = current;
        }
        tempNode->next = new VertexNode<T>(endIndex, nullptr, value);

        return true;
    }
    template<typename T>
    bool GraphStructure<T>::isEdge(std::size_t beginIndex, std::size_t endIndex)
    {
        for (VertexNode<T>* current = list[beginIndex]->next; current; current = current->next)
        {
            if (current->index == endIndex) return true;
        }
        return false;
    }
    template<typename T>
    T GraphStructure<T>::findAndRemoveEdge(std::size_t beginIndex, std::size_t endIndex, bool& isFound)
    {
        for (VertexNode<T>* current = list[beginIndex]; current->next; current = current->next)
        {
            if (current->next->index == endIndex)
            {
                T value = current->next->value;
                VertexNode<T>* tempNode = current->next;
                current->next = current->next->next;
                delete tempNode;
                numberOfEdges--;
                isFound = true;
                return value;
            }
        }
        isFound = false;
        return T();
    }
    //public
    template<typename T>
    GraphStructure<T>::GraphStructure()
    {
        numberOfVertices = 0;
        numberOfEdges = 0;
        orientation = false;
        totalValue = T();
    }
    template<typename T>
    GraphStructure<T>::GraphStructure(bool orientation)
    {
        numberOfVertices = 0;
        numberOfEdges = 0;
        this->orientation = orientation;
        totalValue = T();
    }
    template<typename T>
    GraphStructure<T>::GraphStructure(std::size_t numberOfVertices, std::size_t numberOfEdges, bool orientation, T maxValue)
    {
        if (!createGraph(numberOfVertices, numberOfEdges, orientation, maxValue))
            delete this;
    }  
    template<typename T>
    GraphStructure<T>::~GraphStructure()
    {
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            clearNode(i);
        }
        list.clear();
        numberOfVertices = 0;
        numberOfEdges = 0;
        orientation = false;
        totalValue = T();
    }
    template<typename T>
    void GraphStructure<T>::addVertex(T value, bool show) 
    {
        list.push_back(new VertexNode<T>(numberOfVertices, nullptr, value));
        numberOfVertices++;
        if (show) std::cout << "\nThe vertex is added!" << std::endl;       
    }
    template<typename T>
    void GraphStructure<T>::addEdge(std::size_t beginIndex, std::size_t endIndex, T value, bool show)
    {
        if (!isIndex(beginIndex) || !isIndex(endIndex)) return;
        std::string message = "\nThe edge already exists between the vertices!";
        if (!addNode(beginIndex, endIndex, value))
        {
            if (show) std::cout << message << std::endl;
            return;
        }
        if (!orientation && (beginIndex != endIndex))
        {
            if (!addNode(endIndex, beginIndex, value))
            {
                if (show) std::cout << message << std::endl;
                return;
            }
        }
        numberOfEdges++;
        totalValue = totalValue + value;
        if (show) std::cout << "\nThe edge added!" << std::endl;
    }
    template<typename T>
    void GraphStructure<T>::removeVertex(std::size_t index, bool show)
    {
        if (!isIndex(index)) return;
        deleteEdges(index);
        clearNode(index);
        list.erase(list.begin() + index);
        numberOfVertices--;
        if (show) std::cout << "\nThe vertex with index " << index << " was removed!" << std::endl;
    }
    template<typename T>
    void GraphStructure<T>::removeEdge(std::size_t beginIndex, std::size_t endIndex, bool show)
    {
        if (!isIndex(beginIndex) || !isIndex(endIndex)) return;
        bool isFound = false;
        totalValue = totalValue - findAndRemoveEdge(beginIndex, endIndex, isFound);
        if (!orientation) findAndRemoveEdge(endIndex, beginIndex, isFound);
        if (show)
        {
            if(isFound) std::cout << "\nThe edge between vertices "
                << beginIndex << " and " << endIndex
                << " was removed!" << std::endl;
            else std::cout << "\nThere isn't the edge between vertices "
                << beginIndex << " and " << endIndex << "!" << std::endl;
        }
    }
    template<typename T>
    std::string GraphStructure<T>::getTextRepresentation()
    {
        std::string result = "";
        if (numberOfVertices == 0)
        {
            return "\nThe graph is empty!\n";
        }
        result += "\nNumber of vertices: " + toString(numberOfVertices) + "\n";
        result += "Number of edges: " + toString(numberOfEdges) + "\n";
        result += "Total value: " + toString(totalValue) + "\n";
        result += "\nGraph:\n\n";
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            result += toString(list[i]->index) + ") value: {" 
                + toString(list[i]->value) + "}-> [ {";
            for (VertexNode<T>* current = list[i]->next; current; current = current->next)
            {
                result += toString(current->index) + "} -> {";
            }
            result += "#} ]\n";
        }       
        result += "\n";

        return result;
    }
    template<typename T>
    bool GraphStructure<T>::checkingTheConnectivity(bool show)
    {
        return connectedGraph(show);
    }
    template<typename T>
    std::vector<std::size_t> GraphStructure<T>::depthFirstSearch(bool show)
    {
        std::vector<std::size_t> indexes;
        if (isConnected(indexes))
        {
            if (show) std::cout << "\nSearch is finished!" << std::endl;
        }
        else
        {
            if (show) std::cout << "\nThe graph isn't connected!" << std::endl;
            indexes.clear();
        }
        return indexes;
    }
    template<typename T>
    T GraphStructure<T>::getPathBetweenTwoVertices(std::size_t beginIndex, std::size_t endIndex, bool show)
    {
        if (!connectedGraph(show)) return T();
        T result;
        PathsBetweenVertices<T> paths(numberOfVertices, beginIndex);
        dijkstra(paths);
        if (paths.isMax[endIndex])
        {
            if (show) std::cout << "\nThe graph is poorly oriented so it cannot be reached from " << beginIndex
                << " to " << endIndex << "." << std::endl;
        }
        else
        {
            result = paths.distance[endIndex];
            if (show) std::cout << "\nThe smallest distance from " << beginIndex
                << " to " << endIndex << " was found!" << std::endl;
        }

        return result;
    }
    template<typename T>
    PathsBetweenVertices<T> GraphStructure<T>::getPathsFromTheVertexToEveryoneElse(std::size_t beginIndex, bool show)
    {
        if (!connectedGraph(show)) return PathsBetweenVertices<T>();
        PathsBetweenVertices<T> paths(numberOfVertices, beginIndex);
        dijkstra(paths);
        if (show) std::cout << "\nThe smallest distance from " << beginIndex
            << " to to everyone else was found!" << std::endl;

        return paths;
    }
    template<typename T>
    std::vector<std::size_t> GraphStructure<T>::topologicalSorting(bool show)
    {
        std::vector<std::size_t> indexes;
        if (!orientation)
        {
            if (show) std::cout << "\nTopological sorting for directed graph only" << std::endl;
            return indexes;
        }
        if (!connectedGraph(show)) return indexes;
        std::vector<std::vector<std::size_t>> set = createSet();
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            if ((set[i].size() == 0) && !isInIndexes(indexes, i))
            {
                indexes.push_back(i);
                editSet(set, i);
                i = -1;
            }
        }
        if (indexes.size() != numberOfVertices)
        {
            if (show) std::cout << "\nThe graph has a cycle!" << std::endl;
            indexes.clear();
        }
        else if (show) std::cout << "\nTopological sorting is finished!" << std::endl;
        return indexes;
    }
    template<typename T>
    GraphStructure<T> GraphStructure<T>::getSpanningTree(bool show)
    {
        if (orientation)
        {
            if (show) std::cout << "\nSpanning tree for undirected graph only" << std::endl;
            return GraphStructure();
        }
        GraphStructure<T> spanningTree(false);
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            spanningTree.addVertex(list[i]->value, false);
        }
        std::vector<std::size_t> indexes;
        createSpanningTree(spanningTree, indexes, 0);
        if (indexes.size() != numberOfVertices)
        {
            if (show) std::cout << "\nThe graph isn't connected!" << std::endl;
            return GraphStructure();
        }
        if (show) std::cout << "\nThe spanning tree is created!" << std::endl;       

        return spanningTree;
    }
    template<typename T>
    GraphStructure<T> GraphStructure<T>::getTheSmallestSpanningTree(bool show)
    {
        if (orientation)
        {
            if (show) std::cout << "\nSpanning tree for undirected graph only" << std::endl;
            return GraphStructure<T>();
        }
        if (!connectedGraph(show)) return GraphStructure<T>();
        GraphStructure<T> spanningTree = kruskal();
        if (show) std::cout << "\nThe smallest spanning tree is created!" << std::endl;

        return spanningTree;
    }   
    
}