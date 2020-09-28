#pragma once
#include "my_override_functions_and_operators.h"
#include "my_paths_between_vertices.h"

using namespace ofo;
using namespace pbv;

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
    class GraphStructure
    {
    private:
        std::vector<VertexNode<T>*> list;
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
        void createSpanningTree(GraphStructure<T>& spanningTree, std::vector<std::size_t>& indexes, std::size_t index);//algorithm for create spanning tree from graph
        GraphStructure<T> kruskal();//algorithm for create minimum spanning tree from graph
        void createRandomVertices(std::size_t numberOfVertices, T maxValue);//adds vertices to new graph
        void createRandomEdges(std::size_t numberOfEdges, T maxValue);//adds edges to new graph
        void createGraph(std::size_t numberOfVertices, std::size_t numberOfEdges, bool orientation, T maxValue);//create graph with numberOfVertices vertices and numberOfEdges edges
        void deleteEdges(std::size_t index);//when removes vertex need delete its edges
        void clearNode(std::size_t index);//clear all edges of list[index]
        bool addNode(std::size_t beginIndex, std::size_t endIndex, T value);//add node(edge from beginIndex to endIndex) to list[beginIndex]
        bool isEdge(std::size_t beginIndex, std::size_t endIndex);//returns true if is edge from beginIndex to endIndex else returns false
        T findAndRemoveEdge(std::size_t beginIndex, std::size_t endIndex, bool& isFound);//removes edge(node) from list[beginIndex] and returns value of edge
    public:
        GraphStructure();
        GraphStructure(bool orientation);
        GraphStructure(std::size_t numberOfVertices, std::size_t numberOfEdges, bool orientation, T maxValue);//create random graph
        GraphStructure(GraphStructure&& graph);
        ~GraphStructure();
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
        GraphStructure<T> getSpanningTree(bool show = false);//creates spanning tree from the graph
        GraphStructure<T> getTheSmallestSpanningTree(bool show = false);//creates minimum spanning tree from the graph

    };
}
namespace gs
{
    //VertexNode
    template<typename T>
    VertexNode<T>::VertexNode() : index(0), next(nullptr), value(0) {}
    template<typename T>
    VertexNode<T>::VertexNode(std::size_t index, VertexNode* next, T value) : index(index), next(next), value(value) {}    
    //GraphStructure
    //private
    template<typename T>
    bool GraphStructure<T>:: isIndex(std::size_t index, bool show)
    {
        if (index >= numberOfVertices)
        {
            if(show) std::cout << "\nVertex with index: " << index << " isn't in Graph!" << std::endl;
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
        std::size_t firstIndex = 0;
        std::size_t secondIndex = 0;
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
    void GraphStructure<T>::createRandomEdges(std::size_t numberOfEdges, T maxValue)
    {
        if (orientation && (numberOfEdges <= numberOfVertices * numberOfVertices) || numberOfEdges <= (numberOfVertices * (numberOfVertices + 1)) / 2)
        {
            while (this->numberOfEdges < numberOfEdges)
            {
                std::size_t i = rand() % numberOfVertices, j = rand() % numberOfVertices;
                if (!isEdge(i, j))
                {
                    addEdge(i, j, rand() % maxValue, false);
                }
            }
            return;
        }
        std::cout << "\nThere are too many edges!" << std::endl;
    }
    template<typename T>
    void GraphStructure<T>::createGraph(std::size_t numberOfVertices, std::size_t numberOfEdges, bool orientation, T maxValue)
    {
        srand(unsigned(time(0)));
        this->orientation = orientation;
        totalValue = T();
        createRandomVertices(numberOfVertices, maxValue);
        createRandomEdges(numberOfEdges, maxValue);
    }
    template<typename T>
    void GraphStructure<T>::deleteEdges(std::size_t index)
    {
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            removeEdge(i, index, false);
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
        createGraph(numberOfVertices, numberOfEdges, orientation, maxValue);
    }  
    template<typename T>
    GraphStructure<T>::GraphStructure(GraphStructure&& graph)
    {
        for (std::size_t i = 0; i < graph.numberOfVertices; i++)
        {
            list.push_back(graph.list[i]);
            graph.list[i] = nullptr;
        }
        orientation = graph.orientation;
        totalValue = graph.totalValue;
        numberOfVertices = graph.numberOfVertices;
        numberOfEdges = graph.numberOfEdges;
        graph.numberOfVertices = 0;
        graph.numberOfEdges = 0;
        graph.totalValue = T();
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
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            if (list[i]->index != i)
            {
                list.push_back(new VertexNode<T>());
                for (std::size_t j = numberOfVertices; j > i; j--)
                {
                    list[j] = list[j - 1];
                }
                list[i] = new VertexNode<T>(i, nullptr, value);
                numberOfVertices++;
                return;
            }
        }
        list.push_back(new VertexNode<T>(numberOfVertices, nullptr, value));
        numberOfVertices++;
        if (show) std::cout << "\nThe vertex is added!" << std::endl;       
    }
    template<typename T>
    void GraphStructure<T>::addEdge(std::size_t beginIndex, std::size_t endIndex, T value, bool show)
    {
        if (!isIndex(beginIndex, show) || !isIndex(endIndex, show)) return;
        std::string message = "\nThe edge already exists between the vertices!";
        if (!addNode(beginIndex, endIndex, value))
        {
            if (show) std::cout << message << std::endl;
            return;
        }
        if (!orientation && (beginIndex != endIndex))
        {
            addNode(endIndex, beginIndex, value);
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
        if (!orientation)
        {
            numberOfEdges++;
            findAndRemoveEdge(endIndex, beginIndex, isFound);
        }
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
    std::size_t GraphStructure<T>::getNumberOfVertices()
    {
        return numberOfVertices;
    }
    template<typename T>
    std::size_t GraphStructure<T>::getNumberOfEdges()
    {
        return numberOfEdges;
    }
    template<typename T>
    T GraphStructure<T>::getTotalValue()
    {
        return totalValue;
    }
    template<typename T>
    T GraphStructure<T>::getVertexValue(std::size_t index)
    {
        if (!isIndex(index)) return T();
        return list[index]->value;
    }
    template<typename T>
    T GraphStructure<T>::getEdgeValue(std::size_t beginIndex, std::size_t endIndex)
    {
        if (!isIndex(beginIndex) || !isIndex(endIndex)) return T();
        for (VertexNode<T>* current = list[beginIndex]->next; current; current = current->next)
        {
            if (current->index == endIndex)
            {
                return current->value;
            }
        }
        return T();
    }
    template<typename T>
    std::string GraphStructure<T>::getTextRepresentation()
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
            result += "Index: " + toString(list[i]->index) + ", value: {" 
                + toString(list[i]->value) + "} => [ ";
            for (VertexNode<T>* current = list[i]->next; current; current = current->next)
            {
                result += "{i: " +  toString(current->index) + ", v: " + toString(current->value) + "} -> ";
            }
            result += "# ].\n";
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
