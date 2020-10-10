#pragma once
#include "my_override_functions_and_operators.h"
#include "my_paths_between_vertices.h"

using namespace ofo;
using namespace pbv;

/**
* Namespace for GraphStructure
*/
namespace gs//graph structure
{
    /**
    * \brief Vertex in graph (GraphStructure)
    *
    * This struct is used as node in the linked list that stores the vertices or the edges of the graph
    */
    template<typename T>
    struct VertexNode
    {
        std::size_t index;/**<The index of vertex in the graph*/
        VertexNode* next;/**<The pointer to adjacent vertex of header vertex*/
        T value; /**< Eigenvalue, which is stored in the vertex or in the edge*/
        /**
        * Default constructor
        */
        VertexNode();
        /**
        * \brief Parameterized constructor
        *
        * Creates vertex in the graph or edge between header vertex and adjacent vertex
        */
        VertexNode(std::size_t index, VertexNode* next, T value);
    };   
    /**
    * \brief Class for representing a graph in the form of a adjacency list
    * (I use the name "adjacency structure")
    *
    * See [Adjacency list](https://en.wikipedia.org/wiki/Adjacency_list "Information about adjacency list in Wikipedia")
    *
    * The vertices are stored in 'std::vector<VertexNode<T>*> list'
    * and the edges are stored in linked lists that are in 'std::vector<VertexNode<T>*> list'
    * 
    * All vertices are associated with adjacent vertices in the linked list
    * (VertexNode is node of this linked list). Value of vertex is stored in 'list[index of vertex]'
    * and value of edge between vertices with 'beginIndex' and 'endIndex' is stored in linked list 'list[beginIndex]'
    *
    * This class also stores information about the number of edges and vertices,
    * the weight of the graph, and information about the orientation of the graph
    *
    * \see gm::GraphMatrix
    */
    template<typename T>
    class GraphStructure
    {
    private:
        std::vector<VertexNode<T>*> list;//the one-dimensional array in which linked lists of vertices are stored
        std::size_t numberOfVertices;
        std::size_t numberOfEdges;
        bool orientation;//if orientation is true then Graph is oriented, else it is no-oriented
        T totalValue;//there is the sum of all values of Edges

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
        void createRandomVertices(std::size_t numberOfVertices, const T& maxValue);//adds vertices to new graph
        void createRandomEdges(std::size_t numberOfEdges, const T& maxValue);//adds edges to new graph
        void createGraph(std::size_t numberOfVertices, std::size_t numberOfEdges, bool orientation, const T& maxValue);//create graph with numberOfVertices vertices and numberOfEdges edges
        void deleteEdges(std::size_t index);//when removes vertex need delete its edges
        void clearNode(std::size_t index);//clear all edges of list[index]
        bool addNode(std::size_t beginIndex, std::size_t endIndex, T value);//add node(edge from beginIndex to endIndex) to list[beginIndex]
        bool isEdge(std::size_t beginIndex, std::size_t endIndex);//returns true if is edge from beginIndex to endIndex else returns false
        T findAndRemoveEdge(std::size_t beginIndex, std::size_t endIndex, bool& isFound);//removes edge(node) from list[beginIndex] and returns value of edge
        void editIndexesOfVertices(std::size_t removedIndex);//after removing vertex need to edit vertices with index > removedIndex
    public:
        /**
        * \brief Default constructor
        *
        * Creates a empty no-oriented graph without vertices and edges
        */
        GraphStructure();
        /**
       * \brief Edited default constructor
       *
       * Creates a empty no-oriented graph if orientation is false or
       * creates a empty oriented graph if orientation is true.
       * In two cases graph will be without vertices and edges
       */
        GraphStructure(bool orientation);
        /**
        * \brief Random Constructor
        *
        * Creates no-oriented or oriented graph with the specified number of vertices and edges.
        * The value of the vertices and edges will not be greater than the maxValue
        */
        GraphStructure(std::size_t numberOfVertices, std::size_t numberOfEdges, bool orientation, const T& maxValue);//create random graph
        /**
        * \brief Copy Constructor
        * 
        * Default copy constructor copies the pointers to nodes, 
        * so I added own copy constructor to copy the nodes
        */
        GraphStructure(const GraphStructure<T>& graph);                                                                                                                /**
        /**
        * \brief Destructor
        *
        * Deltes all nodes in graph and clears 'list'
        */
        ~GraphStructure();
        /**
        * \brief Adding the vertex to graph
        *
        * Creates new node (VertexNode) with 'value' and Index of vertex and Adds it to the end of 'list'.
        *
        * Index of vertex will be equal to 'numberOfVertices'
        * and 'numberOfVertices' will increase by one.
        *
        * \param value that be stored in the new vertex
        * \param show can will be true to show message of the result of the function call
        */
        void addVertex(const T& value, bool show = false);
        /**
        * \brief Adding the edge to graph
        *
        * If the graph has vertices with indexes 'beginIndex' and 'endIndex' then
        * creates new edge with value between these vertices. 
        * If this edge already exists, then nothing will happen
        *
        * Creates new node (VertexNode) with 'value' and 'endIndex' and insert it to 'list[beginIndex]'. 
        * If the graph is no-oriented then also insert the node with 'value' 
        * and 'beginIndex' to 'list[endIndex]'. 
        *
        * The 'numberOfEdges' will increase by one
        *
        * Adds to the 'totalValue' its value
        * \param beginIndex is index of first vertex
        * \param endIndex is index of second vertex
        * \param value that be stored in the new edge
        * \param show can will be true to show message of the result of the function call
        */
        void addEdge(std::size_t beginIndex, std::size_t endIndex, const T& value, bool show = false);
        /**
        * \brief Removing vertex from graph
        *
        * If the graph has vertex with 'index' then
        * removes all nodes from 'list[index]' and removes 'list[index]' from 'list'
        * 
        * Also subtracts all the values of the edges that pass through
        * this vertex from the 'totalValue'
        *
        * Reduces the 'numberOfVertices' by one and reduces the 'numberOfEdges' by number of edges
        * that pass through this vertex
        * \param index is index of this vertex
        * \param show can will be true to show message of the result of the function call
        */
        void removeVertex(std::size_t index, bool show = false);
        /**
        * \brief Removing edge from graph
        *
        * If the graph has vertices with indexes 'beginIndex' and 'endIndex' then
        * removes node with 'endIndex' from 'list[beginIndex]'. 
        * If the graph is non-oriented then removes node with 'beginIndex' from 'list[endIndex]'. 
        *
        * Reduces the 'numberOfEdges' by one
        * and subtracts the value of the edge from the 'totalValue'
        * \param beginIndex is index of first vertex
        * \param endIndex is index of second vertex
        * \param show can will be true to show message of the result of the function call
        */
        void removeEdge(std::size_t beginIndex, std::size_t endIndex, bool show = false);
        /**
        * \return - number of vertices in the graph
        */
        std::size_t getNumberOfVertices();
        /**
        * \return - number of edges in the graph
        */
        std::size_t getNumberOfEdges();
        /**
        * \return - totalValue of the graph
        */
        T getTotalValue();
        /**
        * \param index is index of the vertex
        * \return - value of vertex with 'index' if the graph have it
        * \return - default value if the graph haven't this vertex
        */
        T getVertexValue(std::size_t index);
        /**
        * \param beginIndex is index of first vertex
        * \param endIndex is index of second vertex
        * \return - value of edge between vertices with indexes 'beginIndex' and 'endIndex'
        * if the graph have their
        * \return - default value if the graph haven't this edge
        */
        T getEdgeValue(std::size_t beginIndex, std::size_t endIndex);
        /**
        * \brief This method like function std::to_string
        *
        * Converts a graph to a string(for example to output to the console)
        * \return - text representation of the graph
        */
        std::string getTextRepresentation();
        /**
        * \brief Checking whether the graph is connected
        *
        * See [Connectivity of graph]( https://en.wikipedia.org/w/index.php?search=Connectivity+graph+theory&title=Special%3ASearch&fulltext=1&ns0=1 "Graph theory in Wikipedia")
        * \param show can will be true to show message of the result of the function call
        * \return - true if the graph is connected
        * \return - false if the graph isn't connected
        */
        bool checkingTheConnectivity(bool show = false);
        /**
        * \brief Algorithm for traversing graph
        *
        * See [Depth-first search for graph](https://en.wikipedia.org/wiki/Depth-first_search "Graph theory in Wikipedia")
        *
        * Indexes are added to the array taking into account the order of traversal of the graph
        * If the graph isn't connected then the function cannot perform a search
        * and array will be empty
        * \param show can will be true to show message of the result of the function call
        * \return - array of indexes of vertices
        */
        std::vector<std::size_t> depthFirstSearch(bool show = false);
        /**
        * \brief Finding the smallest path
        *
        * Finds the path from 'beginIndex' to 'endIndex'. Uses dijkstra algorithm
        *
        * If the graph isn't connected then the function cannot find the path
        *
        * \param beginIndex is index of first vertex
        * \param endIndex is index of second vertex
        * \param show can will be true to show message of the result of the function call
        * \return - the smallest path between two vertices
        * \return - default value if the graph haven't these vertices or graph isn't connected
        */
        T getPathBetweenTwoVertices(std::size_t beginIndex, std::size_t endIndex, bool show = false);
        /**
        * \brief Finding the smallest paths
        *
        * Finds the paths from beginIndex to everyone else. Uses dijkstra algorithm
        *
        * If the graph isn't connected then the function cannot find the paths
        *
        * \param beginIndex is index of the vertex
        * \param show can will be true to show message of the result of the function call
        * \return - 'struct pbv::PathsBetweenVertices' that has the smallest paths between vertices
        * \return - empty 'struct pbv::PathsBetweenVertices' if the graph haven't this vertex or graph isn't connected
        */
        PathsBetweenVertices<T> getPathsFromTheVertexToEveryoneElse(std::size_t beginIndex, bool show = false);
        /**
        * \brief Algorithm topological sorting of oriented graph only
        *
        * The function linearly arranges the vertices of the graph.
        * If graph is non-oriented or isn't connected then array will be empty
        *
        * See [Topological sorting](https://en.wikipedia.org/wiki/Topological_sorting "Graph theory in Wikipedia")
        * \param show can will be true to show message of the result of the function call
        * \return - array with the result of topological sorting
        */
        std::vector<std::size_t> topologicalSorting(bool show = false);
        /**
        * \brief Creating spanning tree
        *
        * Creates spannig tree from non-oriented graph only.
        * Uses the Depth-first search algorithm
        *
        * The resulting graph will have all vertices, but the number of edges may be smaller,
        * resulting in less weight of the graph
        *
        * See [Spannig tree](https://en.wikipedia.org/wiki/Spanning_tree "Graph theory in Wikipedia")
        *
        * In fact, the spanning tree will consist of the path obtained by searching
        *
        * If graph isn't connected then spanning tree will be empty
        * \param show can will be true to show message of the result of the function call
        * \return - created graph
        */
        GraphStructure<T> getSpanningTree(bool show = false);
        /**
        * \brief Creating the smallest spanning tree
        *
        * Creates minimum spanning tree from non-oriented graph only.
        * Uses Kruskal's algorithm
        *
        * The resulting graph will have all vertices, but the number of edges may be smaller,
        * resulting in the smallest weight of the graph
        *
        * See [Kruskal's algorithm](https://en.wikipedia.org/wiki/Kruskal%27s_algorithm "Graph theory in Wikipedia")
        *
        * If graph isn't connected then spanning tree will be empty
        * \param show can will be true to show message of the result of the function call
        * \return - created graph
        */
        GraphStructure<T> getTheSmallestSpanningTree(bool show = false);
    };
}
namespace gs
{
    //VertexNode
    template<typename T>
    VertexNode<T>::VertexNode() : index(0), next(nullptr), value(T()) {}
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
    void GraphStructure<T>::createRandomVertices(std::size_t numberOfVertices, const T& maxValue)
    {
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            addVertex(randomValue(maxValue));
        }
    }
    template<typename T>
    void GraphStructure<T>::createRandomEdges(std::size_t numberOfEdges, const T& maxValue)
    {
        if (orientation && (numberOfEdges <= numberOfVertices * numberOfVertices) || numberOfEdges <= (numberOfVertices * (numberOfVertices + 1)) / 2)
        {
            while (this->numberOfEdges < numberOfEdges)
            {
                std::size_t i = rand() % numberOfVertices, j = rand() % numberOfVertices;
                if (!isEdge(i, j))
                {
                    addEdge(i, j, randomValue(maxValue));
                }
            }
            return;
        }
        std::cout << "\nThere are too many edges!" << std::endl;
    }
    template<typename T>
    void GraphStructure<T>::createGraph(std::size_t numberOfVertices, std::size_t numberOfEdges, bool orientation, const T& maxValue)
    {
        srand(unsigned(time(0)));
        this->orientation = orientation;
        totalValue = T();
        this->numberOfVertices = 0;
        this->numberOfEdges = 0;
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
    template<typename T>
    void GraphStructure<T>::editIndexesOfVertices(std::size_t removedIndex)
    {
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            for (VertexNode<T>* current = list[i]->next; current; current = current->next)
            {
                if (current->index > removedIndex) current->index--;
            }
            if (list[i]->index > removedIndex) list[i]->index--;
        }
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
    GraphStructure<T>::GraphStructure(std::size_t numberOfVertices, std::size_t numberOfEdges, bool orientation, const T& maxValue)
    {
        createGraph(numberOfVertices, numberOfEdges, orientation, maxValue);
    }  
    template<typename T>
    GraphStructure<T>::GraphStructure(const GraphStructure<T>& graph)
    {
        orientation = graph.orientation;
        totalValue = T();
        numberOfVertices = 0;
        numberOfEdges = 0;
        for (std::size_t i = 0; i < graph.numberOfVertices; i++)
        {
            addVertex(graph.list[i]->value);
        }
        for (std::size_t i = 0; i < graph.numberOfVertices; i++)
        {
            for (VertexNode<T>* current = graph.list[i]->next; current; current = current->next)
            {
                addEdge(i, current->index, current->value);
            }
        }
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
    void GraphStructure<T>::addVertex(const T& value, bool show) 
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
    void GraphStructure<T>::addEdge(std::size_t beginIndex, std::size_t endIndex, const T& value, bool show)
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
        editIndexesOfVertices(index);
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
            if (!isFound) numberOfEdges--;
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
        result += "\nNumber of vertices: " + toTheString(numberOfVertices) + "\n";
        result += "Number of edges: " + toTheString(numberOfEdges) + "\n";
        result += "Total value: {" + toTheString(totalValue) + "}\n\n";
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            result += "Index: " + toTheString(list[i]->index) + ", value: {"
                + toTheString(list[i]->value) + "} => [ ";
            for (VertexNode<T>* current = list[i]->next; current; current = current->next)
            {
                result += "{i: " +  toTheString(current->index) + ", v: " + toTheString(current->value) + "} -> ";
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
