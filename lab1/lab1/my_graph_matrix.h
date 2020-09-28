#pragma once
#include "my_override_functions_and_operators.h"
#include "my_paths_between_vertices.h"

using namespace ofo;
using namespace pbv;

namespace gm//graph matrix
{
    template<typename T>
    struct Edge//edge in graph matrix
    {
        bool contiguity;
        T value;

        Edge();
        Edge(bool contiguity, T value);
    };  
    template<typename T>
    class GraphMatrix
    {
    private:
        std::vector<std::vector<Edge<T>>> matrix;
        std::vector<T> vertices;
        std::size_t numberOfVertices;
        std::size_t numberOfEdges;
        bool orientation;
        T totalValue;

        bool isIndex(std::size_t index, bool show = false);//if vectex with index is in graph then return true, else - false
        bool doAddIndex(std::vector<std::size_t>& indexes, std::size_t index);// if index is not in indexes then function adds index to indexes
        void isConnectedRelativeToTheVertex(std::vector<std::size_t>& indexes, std::size_t index);//the function checks whether the graph is connected starting from a given index of vertex
        bool isConnected(std::vector<std::size_t>& indexes);//the function checks whether the graph is connected with respect to all vertices
        std::size_t minDistance(PathsBetweenVertices<T>& paths, bool* isChecked);//find min distance 
        void dijkstra(PathsBetweenVertices<T>& paths);// algorithm for finding the shortest paths between vertices in a graph
        bool connectedGraph(bool show = false);//if the graph isn't connected the function messeges about it
        std::vector<std::vector<std::size_t>> createSet();//creates a set consisting only of connected vertices
        void editSet(std::vector<std::vector<std::size_t>>& set, std::size_t index);//remove index from set
        bool isInIndexes(std::vector<std::size_t> indexes, std::size_t index);//checks if there is an index in the array 
        void createSpanningTree(GraphMatrix<T>& spanningTree, std::vector<std::size_t>& indexes, std::size_t index);//algorithm for create spanning tree from graph
        GraphMatrix<T> kruskal();//algorithm for create minimum spanning tree from graph
        void createRandomVertices(std::size_t numberOfVertices, T maxValue);//adds vertices to new graph
        bool createRandomEdges(std::size_t numberOfEdges, T maxValue);//adds edges to new graph
        bool createGraph(std::size_t numberOfVertices, std::size_t numberOfEdges, bool orientation, T maxValue);//create graph with numberOfVertices vertices and numberOfEdges edges
        void deleteEdges(std::size_t index);//when removes vertex need delete its edges
    public:
        GraphMatrix();
        GraphMatrix(bool orientation);
        GraphMatrix(std::size_t numberOfVertices, std::size_t numberOfEdges, bool orientation, T maxValue);//create random graph
        ~GraphMatrix();
        void addVertex(T value, bool show = false);//adds a vertex with the value to vertices
        void addEdge(std::size_t beginIndex, std::size_t endIndex, T value, bool show = false);//adds edge from beginIndex to endIndex in graph
        void removeVertex(std::size_t index, bool show = false);//remove the vertex with index from graph
        void removeEdge(std::size_t beginIndex, std::size_t endIndex, bool show = false);//remove the edge from beginIndex to endIndex from graph
        std::size_t getNumberOfVertices();
        std::size_t getNumberOfEdges();
        T getTotalValue();
        T getVertexValue(std::size_t index);
        T getEdgeValue(std::size_t beginIndex, std::size_t endIndex);
        std::string getTextRepresentation();//converts a graph to a string for example to output to the console
        bool checkingTheConnectivity(bool show = false);//returns true if the graph is connected else return false
        std::vector<std::size_t> depthFirstSearch(bool show = false);// algorithm for traversing or searching graph
        T getPathBetweenTwoVertices(std::size_t beginIndex, std::size_t endIndex, bool show = false);//finds the smallest way from beginIndex to endIndex
        PathsBetweenVertices<T> getPathsFromTheVertexToEveryoneElse(std::size_t beginIndex, bool show = false);//finds the smallest way from beginIndex to endIndex to everyone else
        std::vector<std::size_t> topologicalSorting(bool show = false);// the function linearly arranges the vertices of the graph
        GraphMatrix<T> getSpanningTree(bool show = false);//creates spanning tree from the graph
        GraphMatrix<T> getTheSmallestSpanningTree(bool show = false);//creates minimum spanning tree from the graph
    };
}
namespace gm
{
    //Edge
    template<typename T>
    Edge<T>::Edge() : contiguity(false), value(T()) {}
    template<typename T>
    Edge<T>::Edge(bool contiguity, T value) : contiguity(contiguity), value(value) {}   
    //GraphMatrix
    //private
    template<typename T>
    bool GraphMatrix<T>:: isIndex(std::size_t index, bool show)
    {
        if (index >= numberOfVertices)
        {
            if(show) std::cout << "\nVertex with index: " << index << " isn't in Graph!" << std::endl;
            return false;
        }

        return true;
    }
    template<typename T>
    bool GraphMatrix<T>::doAddIndex(std::vector<std::size_t>& indexes, std::size_t index)
    {
        for (std::size_t i = 0; i < indexes.size(); i++)
        {
            if (indexes[i] == index) return false;
        }
        indexes.push_back(index);

        return true;
    }
    template<typename T>
    void GraphMatrix<T>:: isConnectedRelativeToTheVertex(std::vector<std::size_t>& indexes, std::size_t index)
    {
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            if (matrix[index][i].contiguity)
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
    bool GraphMatrix<T>::isConnected(std::vector<std::size_t>& indexes)
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
    std::size_t GraphMatrix<T>::minDistance(PathsBetweenVertices<T>& paths, bool* isChecked)
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
    void GraphMatrix<T>::dijkstra(PathsBetweenVertices<T>& paths)
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
            for (std::size_t j = 0; j < numberOfVertices; j++)
            {
                if (!isChecked[j] && matrix[index][j].contiguity && !paths.isMax[index]
                    && (paths.isMax[j] || (paths.distance[index] + matrix[index][j].value < paths.distance[j])))
                {
                    paths.distance[j] = paths.distance[index] + matrix[index][j].value;
                    paths.isMax[j] = false;
                }
            }
        }
        delete[] isChecked;
    }
    template<typename T>
    bool GraphMatrix<T>::connectedGraph(bool show)
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
    std::vector<std::vector<std::size_t>> GraphMatrix<T>::createSet()
    {
        std::vector<std::vector<std::size_t>> set(numberOfVertices);
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            for (std::size_t j = 0; j < numberOfVertices; j++)
            {
                if (matrix[i][j].contiguity) set[j].push_back(i);
            }
        }
        return set;
    }
    template<typename T>
    void GraphMatrix<T>::editSet(std::vector<std::vector<std::size_t>>& set, std::size_t index)
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
    bool GraphMatrix<T>::isInIndexes(std::vector<std::size_t> indexes, std::size_t index)
    {
        for (std::size_t i = 0; i < indexes.size(); i++)
        {
            if (indexes[i] == index) return true;
        }
        return false;
    }
    template<typename T>
    void GraphMatrix<T>::createSpanningTree(GraphMatrix<T>& spanningTree, std::vector<std::size_t>& indexes, std::size_t index)
    {
        if (indexes.size() == numberOfVertices) return;
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            if (matrix[index][i].contiguity)
            {
                doAddIndex(indexes, index);
                if (index == i) continue;
                if (doAddIndex(indexes, i))
                {
                    spanningTree.addEdge(index, i, matrix[index][i].value, false);
                    createSpanningTree(spanningTree, indexes, i);
                }
            }
        }
    }
    template<typename T>
    GraphMatrix<T> GraphMatrix<T>::kruskal()
    {
        GraphMatrix<T> spanningTree(false);
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            spanningTree.addVertex(vertices[i], false);
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
                for (std::size_t j = 0; j < numberOfVertices; j++)
                {
                    if (matrix[i][j].contiguity && (isMax || min > matrix[i][j].value)
                        && (belongs[i] != belongs[j]))
                    {
                        min = matrix[i][j].value;
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
    void GraphMatrix<T>::createRandomVertices(std::size_t numberOfVertices, T maxValue)
    {
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            addVertex(rand() % maxValue, false);
        }
    }
    template<typename T>
    bool GraphMatrix<T>::createRandomEdges(std::size_t numberOfEdges, T maxValue)
    {
        if (numberOfEdges <= (numberOfVertices * (numberOfVertices + 1)) / 2)
        {
            while (this->numberOfEdges < numberOfEdges)
            {
                std::size_t i = rand() % numberOfVertices, j = rand() % numberOfVertices;
                if (!matrix[i][j].contiguity)
                {
                    addEdge(i, j, rand() % maxValue, false);
                }
            }                                                         
        }              
        std::cout << "\nThere are too many edges!" << std::endl;

        return false;
    }
    template<typename T>
    bool GraphMatrix<T>::createGraph(std::size_t numberOfVertices, std::size_t numberOfEdges, bool orientation, T maxValue)
    {
        srand(unsigned(time(0)));
        this->orientation = orientation;
        totalValue = T();
        createRandomVertices(numberOfVertices, maxValue);
        return createRandomEdges(numberOfEdges, maxValue);
    }
    template<typename T>
    void GraphMatrix<T>::deleteEdges(std::size_t index)
    {
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            if (matrix[i][index].contiguity)
            {
                numberOfEdges--;
                totalValue = totalValue - matrix[i][index].value;
            }
            if (orientation && i != index && matrix[index][i].contiguity)
            {
                numberOfEdges--;
                totalValue = totalValue - matrix[index][i].value;
            }
        }
    }
    //public
    template<typename T>
    GraphMatrix<T>::GraphMatrix()
    {
        numberOfVertices = 0;
        numberOfEdges = 0;
        orientation = false;
        totalValue = T();
    }
    template<typename T>
    GraphMatrix<T>::GraphMatrix(bool orientation)
    {
        numberOfVertices = 0;
        numberOfEdges = 0;
        this->orientation = orientation;
        totalValue = T();
    }
    template<typename T>
    GraphMatrix<T>::GraphMatrix(std::size_t numberOfVertices, std::size_t numberOfEdges, bool orientation, T maxValue)
    {
        if (!createGraph(numberOfVertices, numberOfEdges, orientation, maxValue))
            delete this;
    }
    template<typename T>
    GraphMatrix<T>::~GraphMatrix()
    {
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            matrix[i].clear();
        }
        matrix.clear();
        vertices.clear();
        numberOfVertices = 0;
        numberOfEdges = 0;
        orientation = false;
        totalValue = T();
    }
    template<typename T>
    void GraphMatrix<T>::addVertex(T value, bool show) 
    {
        vertices.push_back(value);
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            matrix[i].push_back(Edge<T>());
        }
        numberOfVertices++;
        std::vector<Edge<T>> newLine(numberOfVertices, Edge<T>());
        matrix.push_back(newLine);
        if (show) std::cout << "\nThe vertex is added!" << std::endl;
    }
    template<typename T>
    void GraphMatrix<T>::addEdge(std::size_t beginIndex, std::size_t endIndex, T value, bool show)
    {
        if (!isIndex(beginIndex, show) || !isIndex(endIndex, show)) return;
        if (matrix[beginIndex][endIndex].contiguity)
        {
            if (show) std::cout << "\nThe edge already exists between the vertices!" << std::endl;
            return;
        }
        Edge<T> node = Edge<T>(true, value);
        matrix[beginIndex][endIndex] = node;
        if (!orientation) matrix[endIndex][beginIndex] = node;
        numberOfEdges++;
        totalValue = totalValue + value;
        if (show) std::cout << "\nThe edge added!" << std::endl;
    }
    template<typename T>
    void GraphMatrix<T>::removeVertex(std::size_t index, bool show)
    {
        if (!isIndex(index)) return;
        deleteEdges(index);
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            matrix[i].erase(matrix[i].begin() + index);
        }
        matrix.erase(matrix.begin() + index);
        numberOfVertices--;
        if (show) std::cout << "\nThe vertex with index " << index << " was removed!" << std::endl;
    }
    template<typename T>
    void GraphMatrix<T>::removeEdge(std::size_t beginIndex, std::size_t endIndex, bool show)
    {
        if (!isIndex(beginIndex) || !isIndex(endIndex)) return;
        if (matrix[beginIndex][endIndex].contiguity)
        {
            matrix[beginIndex][endIndex].contiguity = false;
            numberOfEdges--;
            totalValue = totalValue - matrix[beginIndex][endIndex].value;
            if (!orientation) matrix[endIndex][beginIndex].contiguity = false;
            if (show) std::cout << "\nThe edge between vertices "
                << beginIndex << " and " << endIndex
                << " was removed!" << std::endl;
        }
        else if (show) std::cout << "\nThere isn't the edge between vertices "
            << beginIndex << " and " << endIndex << "!" << std::endl;
    }
    template<typename T>
    std::size_t GraphMatrix<T>::getNumberOfVertices()
    {
        return numberOfVertices;
    }
    template<typename T>
    std::size_t GraphMatrix<T>::getNumberOfEdges()
    {
        return numberOfEdges;
    }
    template<typename T>
    T GraphMatrix<T>::getTotalValue()
    {
        return totalValue;
    }
    template<typename T>
    T GraphMatrix<T>::getVertexValue(std::size_t index)
    {
        if (!isIndex(index)) return T();
        return vertices[index];
    }
    template<typename T>
    T GraphMatrix<T>::getEdgeValue(std::size_t beginIndex, std::size_t endIndex)
    {
        if (!isIndex(beginIndex) || !isIndex(endIndex)) return T();
        return matrix[beginIndex][endIndex].value;
    }
    template<typename T>
    std::string GraphMatrix<T>::getTextRepresentation()
    {
        std::string result = "";
        if (numberOfVertices == 0)
        {
            return "\nThe graph is empty!\n";
        }
        result += "\nGraph:\n";
        result += "\nNumber of vertices: " + toString(numberOfVertices) + "\n";
        result += "Number of edges: " + toString(numberOfEdges) + "\n";
        result += "Total value: " + toString(totalValue) + "\n\n";
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            result += "| ";
            for (std::size_t j = 0; j < numberOfVertices; j++)
            {
                if (matrix[i][j].contiguity) result += "1 ";
                else result += "0 ";
            }
            result += "|\n";
        }
        result += "\nVertices:\n";
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            result += toString(i) + ")value: {" + toString(vertices[i]) + "}.\n";
        }
        result += "\n";

        return result;
    }
    template<typename T>
    bool GraphMatrix<T>::checkingTheConnectivity(bool show)
    {
        return connectedGraph(show);
    }
    template<typename T>
    std::vector<std::size_t> GraphMatrix<T>::depthFirstSearch(bool show)
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
    T GraphMatrix<T>::getPathBetweenTwoVertices(std::size_t beginIndex, std::size_t endIndex, bool show)
    {
        if (!connectedGraph(show)) return T();
        T result = T();
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
    PathsBetweenVertices<T> GraphMatrix<T>::getPathsFromTheVertexToEveryoneElse(std::size_t beginIndex, bool show)
    {
        if (!connectedGraph(show)) return PathsBetweenVertices<T>();
        PathsBetweenVertices<T> paths(numberOfVertices, beginIndex);
        dijkstra(paths);
        if (show) std::cout << "\nThe smallest distance from " << beginIndex
            << " to to everyone else was found!" << std::endl;

        return paths;
    }
    template<typename T>
    std::vector<std::size_t> GraphMatrix<T>::topologicalSorting(bool show)
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
    GraphMatrix<T> GraphMatrix<T>::getSpanningTree(bool show)
    {
        if (orientation)
        {
            if (show) std::cout << "\nSpanning tree for undirected graph only" << std::endl;
            return GraphMatrix();
        }
        GraphMatrix<T> spanningTree(false);
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            spanningTree.addVertex(vertices[i], false);
        }
        std::vector<std::size_t> indexes;
        createSpanningTree(spanningTree, indexes, 0);
        if (indexes.size() != numberOfVertices)
        {
            if (show) std::cout << "\nThe graph isn't connected!" << std::endl;
            return GraphMatrix();
        }
        if (show) std::cout << "\nThe spanning tree is created!" << std::endl;       

        return spanningTree;
    }
    template<typename T>
    GraphMatrix<T> GraphMatrix<T>::getTheSmallestSpanningTree(bool show)
    {
        if (orientation)
        {
            if (show) std::cout << "\nSpanning tree for undirected graph only" << std::endl;
            return GraphMatrix<T>();
        }
        if (!connectedGraph(show)) return GraphMatrix<T>();
        GraphMatrix<T> spanningTree = kruskal();
        if (show) std::cout << "\nThe smallest spanning tree is created!" << std::endl;

        return spanningTree;
    }   
}