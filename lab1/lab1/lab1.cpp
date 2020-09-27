#include <iostream>
#include <vector>
#include <ctime>
/*template<typename T>
std::size_t operator + (const std::size_t& value, const std::vector<T>& array1)
{
    return (value + array1.size());
}*/
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
    std::size_t size = random % array1.size();
    for (std::size_t i = 0; i < size; i++)
    {
        array2.push_back(array1[i]);
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
template<typename T>
struct Edge
{
    bool contiguity;
    T value;
    Edge() : contiguity(false), value(T()) {}
    Edge(bool contiguity, T value): contiguity(contiguity), value(value) {}
};
/*template<typename T>
struct Vertex
{
    std::size_t index;
    T value;
    Vertex(): index(0), value(T()) {}
    Vertex(std::size_t index, T value): index(index), value(value) {}

};*/
template<typename T>
struct PathsBetweenVertices
{
    T* distance;
    bool* isMax;
    std::size_t size;
    std::size_t beginIndex;
    PathsBetweenVertices() : distance(nullptr), isMax(nullptr), size(0), beginIndex(0) {}
    PathsBetweenVertices(std::size_t size, std::size_t beginIndex)
    {
        this->size = size;
        this->beginIndex = beginIndex;
        distance = new T[size];
        isMax = new bool[size];
    }
    PathsBetweenVertices(PathsBetweenVertices&& paths)
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
   ~PathsBetweenVertices()
    {
        if (distance) delete[]distance;
        if (isMax) delete[]isMax;
        distance = nullptr;
        isMax = nullptr;
        size = 0;
        beginIndex = 0;
    }
    void print(bool show = true)
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
};
template<typename T>
class GraphMatrix
{
    std::vector<std::vector<Edge<T>>> matrix;
    std::vector<T> vertices;
    std::size_t numberOfVertices;
    std::size_t numberOfEdges;
    bool orientation;

    bool isIndex(std::size_t index)//if vectex with index is in graph then return true, else - false
    {
        if (index >= numberOfVertices)
        {
            std::cout << "\nVertex with index: " << index << " isn't in Graph!" << std::endl;
            return false;
        }
        /*for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            if(index == vertices[i].index)  return true;
        }*/
       
        return true;
    }
    bool doAddIndex(std::vector<std::size_t>& indexes, std::size_t index)// if index is not in indexes then function adds index to indexes
    {
        for (std::size_t i = 0; i < indexes.size(); i++)
        {
            if (indexes[i] == index) return false;
        }
        indexes.push_back(index);

        return true;
    }
    /*void swap(T& value1, T& value2)
    {
        T value3 = value1;
        value1 = value2;
        value2 = value3;
    }*/
    void isConnectedRelativeToTheVertex(std::vector<std::size_t>& indexes, std::size_t index)//the function checks whether the graph is connected starting from a given index of vertex
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
    bool isConnected(std::vector<std::size_t>& indexes)//the function checks whether the graph is connected with respect to all vertices
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
    std::size_t minDistance(PathsBetweenVertices<T>& paths, bool* isChecked)//find min distance 
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
    void dijkstra(PathsBetweenVertices<T>& paths)
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
    bool connectedGraph(bool show)//checks if the graph is connected
    {
        std::vector<std::size_t> indexes;
        if (!isConnected(indexes))
        {
            if (show) std::cout << "\nThe graph isn't connected!" << std::endl;
            return false;
        }
        return true;
    }
    std::vector<std::vector<std::size_t>> createSet()//creates a set consisting only of connected vertices
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
    void editSet(std::vector<std::vector<std::size_t>>& set, std::size_t index)//remove index from set
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
    bool isInIndexes(std::vector<std::size_t> indexes, std::size_t index)//checks if there is an index in the array 
    {
        for (std::size_t i = 0; i < indexes.size(); i++)
        {
            if (indexes[i] == index) return true;
        }
        return false;
    }
    void createSpanningTree(GraphMatrix<T>& spanningTree, std::vector<std::size_t>& indexes, std::size_t index)
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
    void createRandomVertices(std::size_t numberOfVertices, T maxValue)//adds vertices to new graph
    {
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            addVertex(rand() % maxValue, false);
        }
    }
    bool createRandomEdges(std::size_t numberOfEdges, T maxValue)//adds edges to new graph
    {
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            for (std::size_t j = 0; j < numberOfVertices; j++)
            {
                if (this->numberOfEdges >= numberOfEdges) return true;
                if (!matrix[i][j].contiguity)
                {
                    addEdge(rand()% numberOfVertices, rand() % numberOfVertices, rand() % maxValue, false);
                }
            }
        }
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            for (std::size_t j = 0; j < numberOfVertices; j++)
            {
                if (this->numberOfEdges >= numberOfEdges) return true;
                if ((i != j) && !matrix[i][j].contiguity)
                {
                    addEdge(i, j, rand() % maxValue, false);
                }
            }
        }
        if (this->numberOfEdges < numberOfEdges)
        {
            for (std::size_t i = 0; i < numberOfVertices; i++)
            {
                if (this->numberOfEdges >= numberOfEdges) return true;
                if (!matrix[i][i].contiguity)
                {
                    addEdge(i, i, rand() % maxValue, false);
                }
            }
        }
        std::cout << "\nThere are too many edges!" << std::endl;
        
        return false;
    }
    bool createGraph(std::size_t numberOfVertices, std::size_t numberOfEdges, bool orientation, T maxValue)
    {    
        srand(unsigned(time(0)));
        this->orientation = orientation;
        createRandomVertices(numberOfVertices, maxValue);
        return createRandomEdges(numberOfEdges, maxValue);
    }
    void deleteEdges(std::size_t index)//when removes vertex need delete its edges
    {
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            if (matrix[i][index].contiguity) numberOfEdges--;
            if (orientation && i != index && matrix[index][i].contiguity) numberOfEdges--;
        }
    }
    /* void insertVertexToVertices(std::size_t index, T value)//insert a vertex in vertices by index
    {
        vertices.push_back(Vertex<T>());
        for (std::size_t i = numberOfVertices; i > index; i--)
        {
            vertices[i] = vertices[i - 1];
        }
        vertices[index] = Vertex<T>(index, value);
    }
    void addVertexToVertices(T value)//add vertex in vertices by index or to end
    {
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            if (vertices[i].index != i)
            {
                insertVertexToVertices(i, value);
                return;
            }
        }
        vertices.push_back(Vertex<T>(numberOfVertices, value));
    }*/
public:
    GraphMatrix()
    {
        numberOfVertices = 0;
        numberOfEdges = 0;
        orientation = false;
    }
    GraphMatrix(bool orientation)
    {
        numberOfVertices = 0;
        numberOfEdges = 0;
        this->orientation = orientation;
    }
    GraphMatrix(std::size_t numberOfVertices, std::size_t numberOfEdges, bool orientation, T maxValue)//create random graph
    {
        if (!createGraph(numberOfVertices, numberOfEdges, orientation, maxValue)) delete this;
    }
    ~GraphMatrix()
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
    }
    void addVertex(T value, bool show = true)//adds a vertex with the value to vertices
    {
        //addVertexToVertices(value);
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
    void addEdge(std::size_t beginIndex, std::size_t endIndex, T value, bool show = true)
    {
        if (!isIndex(beginIndex) || !isIndex(endIndex)) return;
        if (matrix[beginIndex][endIndex].contiguity)
        {
            if (show) std::cout << "\nThe edge already exists between the vertices!" << std::endl;
            return;
        }
        Edge<T> node = Edge<T>(true, value);
        matrix[beginIndex][endIndex] = node;
        if (!orientation) matrix[endIndex][beginIndex] = node;
        numberOfEdges++;
        if (show) std::cout << "\nThe edge added!" << std::endl;
    }
    void removeVertex(std::size_t index, bool show = true)
    {
        if(!isIndex(index)) return;
        deleteEdges(index);
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            matrix[i].erase(matrix[i].begin() + index);
        }
        matrix.erase(matrix.begin() + index);
        numberOfVertices--;
        if (show) std::cout << "\nThe vertex with index " << index << " was removed!" << std::endl;
    }
    void removeEdge(std::size_t beginIndex, std::size_t endIndex, bool show = true)
    {
        if (!isIndex(beginIndex) || !isIndex(endIndex)) return;
        if (matrix[beginIndex][endIndex].contiguity)
        {
            matrix[beginIndex][endIndex].contiguity = false;
            numberOfEdges--;
            if(!orientation) matrix[endIndex][beginIndex].contiguity = false;
            if (show) std::cout << "\nThe edge between vertices "
                << beginIndex << " and " << endIndex 
                << " was removed!" <<  std::endl;
        }
        else if (show) std::cout << "\nThere isn't the edge between vertices " 
                << beginIndex << " and " << endIndex << "!" << std::endl;       
    }
    void print()
    {
        if (numberOfVertices == 0)
        {
            std::cout << "\nThe graph is empty!" << std::endl;
            return;
        }
        std::cout << "\nVertices: " << numberOfVertices << std::endl;
        std::cout << "Edges: " << numberOfEdges << std::endl;
        std::cout << "\nGraph:\n" << std::endl;
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            std::cout << "| ";
            for (std::size_t j = 0; j < numberOfVertices; j++)
            {
                if (matrix[i][j].contiguity) std::cout << "1 ";
                else std::cout << "0 ";
            }
            std::cout << "|" << std::endl;
        }
        std::cout << "Vertices:" << std::endl;
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            std::cout << i << ")value: {" << vertices[i]<< "}." <<  std::endl;
        }
        std::cout << std::endl;
    }
    bool checkingTheConnectivity(bool show = true)
    {
        return connectedGraph(show);
    }
    std::vector<std::size_t> depthFirstSearch(bool show = true)
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
    T getPathBetweenTwoVertices(std::size_t beginIndex, std::size_t endIndex, bool show = true)
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
    PathsBetweenVertices<T> getPathsFromTheVertexToEveryoneElse(std::size_t beginIndex, bool show = true)
    {
        if (!connectedGraph(show)) return PathsBetweenVertices<T>();
        PathsBetweenVertices<T> paths(numberOfVertices, beginIndex);
        dijkstra(paths);
        if (show) std::cout << "\nThe smallest distance from " << beginIndex
            << " to to everyone else was found!" << std::endl;

        return paths;
    }
    std::vector<std::size_t> topologicalSorting(bool show = true)
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
    GraphMatrix<T> getSpanningTree(bool show = true)
    {
        if (orientation)
        {
            if (show) std::cout << "\nSpanning tree for undirected graph only" << std::endl;
            return GraphMatrix();
        }
        GraphMatrix<T> spanningTree(numberOfVertices, false);
        std::vector<std::size_t> indexes;
        createSpanningTree(spanningTree, indexes, 0);
        if (indexes.size() != numberOfVertices)
        {
            if (show) std::cout << "\nThe graph isn't connected!" << std::endl;
            return GraphMatrix();
        }
        if (show)
        {
            std::cout << "\nThe spanning tree is created!" << std::endl;
        }

        return spanningTree;
    }
   /* void createTheSmallestSpanningTree(bool show = true)
    {
        if (orientation)
        {
            if (show) std::cout << "\nSpanning tree for undirected graph only" << std::endl;
            return;
        }
        if (!connectedGraph(show)) return;
        GraphMatrix<T> spanning_tree = kruskal();
        if (show)
        {
            std::cout << "\nThe spanning tree is created!" << std::endl;
            spanning_tree.printGraph();
        }
    }   */
};
/*struct Vertex_node
{
    std::size_t index;
    Vertex_node* next;
    int weight_coefficient;

    Vertex_node()
    {
        index = 0;
        next = nullptr;
        weight_coefficient = 0;
    }
    Vertex_node(std::size_t index, Vertex_node* next)
    {
        this->index = index;
        this->next = next;
        weight_coefficient = 0;
    }
    Vertex_node(std::size_t index, Vertex_node* next, int weight_coefficient)
    {
        this->index = index;
        this->next = next;
        this->weight_coefficient = weight_coefficient;
    }
};
struct Graph_structure
{
    std::vector<Vertex_node*> list;
    std::size_t numberOfVertices;
    std::size_t number_of_edges;
    bool orientation;
    int total_weight;
private:
    bool is_index(std::size_t index)
    {
        if (index >= numberOfVertices)
        {
            std::cout << "\nVertex with index: " << index << " isn't in Graph!" << std::endl;
            return false;
        }
        return true;
    }
    bool do_add_index(std::vector<std::size_t>& indexes, std::size_t index)
    {
        for (std::size_t i = 0; i < indexes.size(); i++)
        {
            if (indexes[i] == index) return false;
        }
        indexes.push_back(index);

        return true;
    }
    bool add_node(std::size_t begin_index, std::size_t end_index, int weight_coefficient)
    {
        if (is_edge(begin_index, end_index)) return false;
        Vertex_node* current = list[begin_index]->next;
        if (!current)
        {
            list[begin_index]->next = new Vertex_node(end_index, nullptr, weight_coefficient);
            return true;
        }
        Vertex_node* temp_node = list[begin_index];
        for (; current; current = current->next)
        {
            if (current->index > end_index)
            {
                temp_node->next = new Vertex_node(end_index, current, weight_coefficient);
                return true;
            }
            temp_node = current;
        }
        temp_node->next = new Vertex_node(end_index, nullptr, weight_coefficient);

        return true;
    }
    template<class T>
    void swap(T& a, T& b)
    {
        T temp = a;
        a = b;
        b = temp;
    }
    std::vector<std::size_t> create_numbers(std::size_t index, bool mode)
    {
        std::vector<std::size_t> numbers;
        std::vector<int> line;
        for (Vertex_node* current = list[index]->next; current; current = current->next)
        {
            line.push_back(current->weight_coefficient);
            numbers.push_back(current->index);
        }
        if (!mode) return numbers;
        for (std::size_t i = 0; i < line.size(); i++)
        {
            for (std::size_t j = 0; j < (line.size() - 1 - i); j++)
            {
                if (line[j] > line[j + 1])
                {
                    swap(line[j], line[j + 1]);
                    swap(numbers[j], numbers[j + 1]);
                }
            }
        }
        return numbers;
    }
    void is_connected_current(std::vector<std::size_t>& indexes, std::size_t index, bool mode)
    {
        std::vector<std::size_t> numbers = create_numbers(index, mode);
        for (std::size_t j = 0; j < numbers.size(); j++)
        {
            if (is_edge(index, numbers[j]))
            {
                do_add_index(indexes, index);
                if (index == numbers[j]) continue;
                if (do_add_index(indexes, numbers[j]))
                {
                    is_connected_current(indexes, numbers[j], mode);
                }
            }
        }
    }
    bool is_connected(std::vector<std::size_t>& indexes, bool mode)
    {
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            is_connected_current(indexes, i, mode);
            if (indexes.size() == numberOfVertices)
            {
                return true;
            }
            indexes.clear();
        }

        return false;
    }
    bool connected_graph(bool show)
    {
        std::vector<std::size_t> indexes;
        if (!is_connected(indexes, false))
        {
            if (show) std::cout << "\nThe graph isn't connected!" << std::endl;
            return false;
        }
        return true;
    }
    std::size_t min_distance(int* distance, bool* is_set)
    {
        int min = INT_MAX;
        std::size_t index = 0;
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            if (!is_set[i] && distance[i] <= min)
            {
                min = distance[i];
                index = i;
            }
        }

        return index;
    }
    int* dijkstra(std::size_t begin_index)
    {
        int* distance = new int[numberOfVertices];
        bool* is_set = new bool[numberOfVertices];
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            distance[i] = INT_MAX;
            is_set[i] = false;
        }
        distance[begin_index] = 0;
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            std::size_t index = min_distance(distance, is_set);
            is_set[index] = true;
            for (std::size_t j = 0; j < numberOfVertices; j++)
            {
                int weight_coefficient = give_weight(index, j);
                if (!is_set[j] && is_edge(index, j)
                    && distance[index] != INT_MAX
                    && distance[index] + weight_coefficient < distance[j])
                    distance[j] = distance[index] + weight_coefficient;
            }
        }
        delete[]is_set;
        return distance;
    }
    std::vector<std::vector<std::size_t>> create_set()
    {
        std::vector<std::vector<std::size_t>> set(numberOfVertices);
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            for (std::size_t j = 0; j < numberOfVertices; j++)
            {
                if (is_edge(i, j)) set[j].push_back(i);
            }
        }
        return set;
    }
    void edit_set(std::vector<std::vector<std::size_t>>& set, std::size_t index)
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
    bool is_in_indexes(std::vector<std::size_t> indexes, std::size_t index)
    {
        for (std::size_t i = 0; i < indexes.size(); i++)
        {
            if (indexes[i] == index) return true;
        }
        return false;
    }
    void create_spanning_tree_current(Graph_structure& spanning_tree, std::vector<std::size_t>& indexes, std::size_t index, bool mode, int& total_weight)
    {
        std::vector<std::size_t> numbers = create_numbers(index, mode);
        for (std::size_t j = 0; j < numbers.size(); j++)
        {
            if (is_edge(index, numbers[j]))
            {
                do_add_index(indexes, index);
                if (index == numbers[j]) continue;
                if (do_add_index(indexes, numbers[j]))
                {
                    int weight_coefficient = give_weight(index, numbers[j]);
                    spanning_tree.add_edge(index, numbers[j], weight_coefficient, false);
                    total_weight += weight_coefficient;
                    create_spanning_tree_current(spanning_tree, indexes, numbers[j], mode, total_weight);
                }
            }
        }
    }
    void clear_node(std::size_t index)
    {
        Vertex_node* current = list[index];
        list[index] = nullptr;
        while (current)
        {
            Vertex_node* temp_node = current;
            current = current->next;
            delete temp_node;
            temp_node = nullptr;
        }
    }
    Graph_structure kruskal()
    {
        Graph_structure spanning_tree(numberOfVertices, false);
        std::vector<std::size_t> belongs(numberOfVertices);
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            belongs[i] = i;
        }
        std::size_t first_index;
        std::size_t second_index;
        for (std::size_t vertices = 1; vertices < numberOfVertices; vertices++)
        {
            int min = INT_MAX;
            for (std::size_t i = 0; i < numberOfVertices; i++)
            {
                for (std::size_t j = 0; j < numberOfVertices; j++)
                {
                    int weight_coefficient = give_weight(i, j);
                    if (is_edge(i, j) && (min > weight_coefficient)
                        && (belongs[i] != belongs[j]))
                    {
                        min = weight_coefficient;
                        first_index = i;
                        second_index = j;
                    }
                }
            }
            if (belongs[first_index] != belongs[second_index])
            {
                spanning_tree.add_edge(first_index, second_index, min, false);
                std::size_t temp = belongs[second_index];
                belongs[second_index] = belongs[first_index];
                for (std::size_t i = 0; i < numberOfVertices; i++)
                {
                    if (belongs[i] == temp)
                    {
                        belongs[i] = belongs[first_index];
                    }
                }
            }
        }
        return spanning_tree;
    }
    void create_graph(std::size_t number_of_vertices, bool orientation)
    {
        number_of_edges = 0;
        this->numberOfVertices = 0;
        this->orientation = orientation;
        total_weight = 0;
        for (std::size_t i = 0; i < number_of_vertices; i++)
        {
            add_vertex(false);
        }
    }
    bool create_random(std::size_t number_of_vertices, std::size_t number_of_edges, bool orientation, int max_weight)
    {
        clear();
        create_graph(number_of_vertices, orientation);
        srand(unsigned(time(0)));
        for (std::size_t i = 0; i < number_of_vertices; i++)
        {
            for (std::size_t j = 0; j < number_of_vertices; j++)
            {
                if (this->number_of_edges >= number_of_edges) return true;
                if ((i != j) && !is_edge(i, j))
                {
                    add_edge(i, j, rand() % max_weight, false);
                }
            }
        }
        if (this->number_of_edges < number_of_edges)
        {
            for (std::size_t i = 0; i < number_of_vertices; i++)
            {
                if (this->number_of_edges >= number_of_edges) return true;
                if (!is_edge(i, i))
                {
                    add_edge(i, i, rand() % max_weight, false);
                }
            }
        }
        if (this->number_of_edges < number_of_edges)
        {
            std::cout << "\nThere are too many edges!" << std::endl;
            clear();
            return false;
        }

        return false;
    }
public:
    Graph_structure(bool orientation)
    {
        numberOfVertices = 0;
        number_of_edges = 0;
        this->orientation = orientation;
        total_weight = 0;
    }
    Graph_structure(std::size_t number_of_vertices, bool orientation)
    {
        create_graph(number_of_vertices, orientation);
    }
    void add_vertex(bool show = true)
    {
        list.push_back(new Vertex_node(numberOfVertices, nullptr));
        numberOfVertices++;
        if (show) std::cout << "\nThe vertex is added!" << std::endl;
    }
    void add_edge(std::size_t begin_index, std::size_t end_index, int weight_coefficient, bool show = true)
    {
        if (!is_index(begin_index) || !is_index(end_index)) return;
        if (!add_node(begin_index, end_index, weight_coefficient))
        {
            if (show) std::cout << "\nThe edge already exists between the vertices!" << std::endl;
            return;
        }
        if (!orientation && (begin_index != end_index))
        {
            if (!add_node(end_index, begin_index, weight_coefficient))
            {
                if (show) std::cout << "\nThe edge already exists between the vertices!" << std::endl;
                return;
            }
        }
        total_weight += weight_coefficient;
        if (show) std::cout << "\nThe edge added!" << std::endl;
        number_of_edges++;
    }
    void write_graph()
    {
        if (numberOfVertices == 0)
        {
            std::cout << "\nThe graph is empty!" << std::endl;
            return;
        }
        std::cout << "\nGraph:\n" << std::endl;
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            std::cout << "Vertex: [" << list[i]->index << "]-> { ";
            for (Vertex_node* current = list[i]->next; current; current = current->next)
            {
                std::cout << current->index << "-> ";
            }
            std::cout << "# }" << std::endl;
        }
        std::cout << "\nVertices: " << numberOfVertices << std::endl;
        std::cout << "Edges: " << number_of_edges << std::endl;
        std::cout << "Total weight: " << total_weight << std::endl;
    }
    void create_random_graph(std::size_t number_of_vertices, std::size_t number_of_edges, bool orientation, int max_weight, bool show = true)
    {
        if (create_random(number_of_vertices, number_of_edges, orientation, max_weight))
        {
            if (!show) return;
            std::cout << "\nThe graph is created!" << std::endl;
            write_graph();
        }
    }
    void checking_the_connectivity_of_graph(bool show = true)
    {
        if (connected_graph(show))
        {
            if (show) std::cout << "\nThe graph is connected!" << std::endl;
        }
    }
    void depth_first_search(bool mode, bool show = true)
    {
        std::vector<std::size_t> indexes;
        if (is_connected(indexes, mode))
        {
            if (!show) return;
            std::cout << "\nSearch is finished!\nVertex: " << std::endl;
            for (std::size_t i = 0; i < numberOfVertices; i++)
            {
                std::cout << indexes[i] << " ";
            }
            std::cout << std::endl;
        }
        else
        {
            if (show) std::cout << "\nThe graph isn't connected!" << std::endl;
        }
    }
    void find_paths_between_two_vertices(std::size_t begin_index, std::size_t end_index, bool show = true)
    {
        if (!connected_graph(show)) return;
        int* distance = dijkstra(begin_index);
        if (distance[end_index] == INT_MAX)
        {
            if (show) std::cout << "\nThe graph is poorly oriented so it cannot be reached from " << begin_index
                << " to " << end_index << "." << std::endl;
        }
        else
        {
            if (show) std::cout << "\nThe smallest distance from " << begin_index
                << " to " << end_index << " = " << distance[end_index] << "." << std::endl;
        }
        delete[]distance;
    }
    void find_path_from_the_vertex_to_everyone_else(std::size_t begin_index, bool show = true)
    {
        if (!connected_graph(show)) return;
        int* distance = dijkstra(begin_index);
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            if (distance[i] == INT_MAX)
            {
                if (show) std::cout << "\nThe graph is poorly oriented so it cannot be reached from " << begin_index
                    << " to " << i << "." << std::endl;
            }
            else
            {
                if (show) std::cout << "\nThe smallest distance from " << begin_index
                    << " to " << i << " = " << distance[i] << "." << std::endl;
            }
        }
        delete[]distance;
    }
    void find_paths_between_all_vertices(bool show = true)
    {
        if (!connected_graph(show)) return;
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            if (show) std::cout << "\nVertex: " << i << "." << std::endl;
            find_path_from_the_vertex_to_everyone_else(i, show);
        }
    }
    void topological_sorting(bool show = true)
    {
        if (!orientation)
        {
            if (show) std::cout << "\nTopological sorting for directed graph only" << std::endl;
            return;
        }
        if (!connected_graph(show)) return;
        std::vector<std::size_t> indexes;
        std::vector<std::vector<std::size_t>> set = create_set();
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            if ((set[i].size() == 0) && (!is_in_indexes(indexes, i)))
            {
                indexes.push_back(i);
                edit_set(set, i);
                i = -1;
            }
        }
        if (indexes.size() != numberOfVertices)
        {
            if (show) std::cout << "\nThe graph has a cycle!" << std::endl;
            return;
        }
        if (!show) return;
        std::cout << "\nResult: ";
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            std::cout << indexes[i] << " ";
        }
        std::cout << std::endl;
    }
    void create_spanning_tree(bool mode, bool show = true)
    {
        if (orientation)
        {
            if (show) std::cout << "\nSpanning tree for undirected graph only" << std::endl;
            return;
        }
        Graph_structure spanning_tree(numberOfVertices, false);
        std::vector<std::size_t> indexes;
        int total_weight = 0;
        create_spanning_tree_current(spanning_tree, indexes, 0, mode, total_weight);
        if (indexes.size() != numberOfVertices)
        {
            if (show) std::cout << "\nThe graph isn't connected!" << std::endl;
            return;
        }
        if (show) std::cout << "\nThe spanning tree is created!" << std::endl;
        if (show) spanning_tree.write_graph();
        spanning_tree.clear();
    }
    void create_the_smallest_spanning_tree(bool show = true)
    {
        if (orientation)
        {
            if (show) std::cout << "\nSpanning tree for undirected graph only" << std::endl;
            return;
        }
        if (!connected_graph(show)) return;
        Graph_structure spanning_tree = kruskal();
        if (show) std::cout << "\nThe spanning tree is created!" << std::endl;
        if (show) spanning_tree.write_graph();
        spanning_tree.clear();
    }
    bool is_edge(std::size_t begin_index, std::size_t end_index)
    {
        for (Vertex_node* current = list[begin_index]->next; current; current = current->next)
        {
            if (current->index == end_index) return true;
        }
        return false;
    }
    int give_weight(std::size_t index_i, std::size_t index_j)
    {
        for (Vertex_node* current = list[index_i]->next; current; current = current->next)
        {
            if (current->index == index_j) return current->weight_coefficient;
        }

        return INT_MAX;
    }
    std::size_t get_size()
    {
        std::size_t size = 0;
        std::size_t number_of_node = 0;
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            for (Vertex_node* current = list[i]; current; current = current->next)
            {
                number_of_node++;
            }
        }
        size += number_of_node * sizeof(Vertex_node*) + sizeof(numberOfVertices)
            + sizeof(number_of_edges) + sizeof(orientation) + sizeof(total_weight);

        return size;
    }
    void clear()
    {
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            clear_node(i);
        }
        list.clear();
        numberOfVertices = 0;
        number_of_edges = 0;
        orientation = false;
        total_weight = 0;
    }
};*/

int main()
{
    std::vector<int> arr1(7), arr2(4), arr3(7), arr4(1), arr5(16), arr6(2);
    GraphMatrix< std::vector<int>> graph(true);
    graph.addVertex(arr4, false);
    graph.addVertex(arr1, false);
    graph.addVertex(arr2, false);
    graph.addVertex(arr1, false);
    graph.addVertex(arr1, false);
    graph.addEdge(0, 1, arr5, false);
    graph.addEdge(1, 2, arr1, false);
    graph.addEdge(2, 3, arr2, false);
    graph.addEdge(0, 4, arr3, false);
    graph.addEdge(4, 2, arr4, false);
    graph.addEdge(3, 1, arr6, false);
    graph.print();
    graph.removeEdge(3, 1);
    graph.removeVertex(2);
    graph.print();
    graph.addVertex(arr1, false);
    graph.addVertex(arr1, false);
    graph.addEdge(4, 5, arr4, false);
    graph.addEdge(1, 5, arr6, false);
    graph.print();
    //graph.getPathsFromTheVertexToEveryoneElse(2).print();
    //std::cout << graph.depthFirstSearch();
    //std::cout << graph.topologicalSorting();
    std::cout << "Hello World!\n";

    return 0;
}
