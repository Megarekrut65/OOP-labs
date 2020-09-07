#include <iostream>
#include <vector>
#include <ctime>

template<class T>
struct Edge
{
    bool contiguity;
    T value;

    Edge()
    {
        contiguity = false;
        value = 0;
    }
    Edge(bool contiguity, T value)
    {
        this->contiguity = contiguity;
        this->value = value;
    }
};
template<class T>
struct GraphMatrix
{
    std::vector<std::vector<Edge<T>>> matrix;
    std::size_t numberOfVertices;
    std::size_t numberOfEdges;
    bool orientation;
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
    void swap(T& a, T& b)
    {
        T temp = a;
        a = b;
        b = temp;
    }
    std::vector<std::size_t> create_numbers(std::size_t index, bool mode)
    {
        std::vector<std::size_t> numbers;
        std::vector<Edge<T>> line = matrix[index];
        for (std::size_t i = 0; i < numberOfVertices; i++) numbers.push_back(i);
        if (!mode) return numbers;
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            for (std::size_t j = 0; j < (numberOfVertices - 1 - i); j++)
            {
                if (line[j].value > line[j + 1].value)
                {
                    swap(line[j].value, line[j + 1].value);
                    swap(numbers[j], numbers[j + 1]);
                }
            }
        }
        return numbers;
    }
    void is_connected_current(std::vector<std::size_t>& indexes, std::size_t index, bool mode)
    {
        std::vector<std::size_t> numbers = create_numbers(index, mode);
        for (std::size_t j = 0; j < numberOfVertices; j++)
        {
            if (matrix[index][numbers[j]].contiguity)
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
                if (!is_set[j] && matrix[index][j].contiguity
                    && distance[index] != INT_MAX
                    && distance[index] + matrix[index][j].value < distance[j])
                    distance[j] = distance[index] + matrix[index][j].value;
            }
        }
        delete[]is_set;
        return distance;
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
    std::vector<std::vector<std::size_t>> create_set()
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
    void create_spanning_tree_current(GraphMatrix<T>& spanning_tree, std::vector<std::size_t>& indexes, std::size_t index, bool mode, int& total_weight)
    {
        std::vector<std::size_t> numbers = create_numbers(index, mode);
        for (std::size_t j = 0; j < numberOfVertices; j++)
        {
            if (matrix[index][numbers[j]].contiguity)
            {
                do_add_index(indexes, index);
                if (index == numbers[j]) continue;
                if (do_add_index(indexes, numbers[j]))
                {
                    spanning_tree.add_edge(index, numbers[j], matrix[index][numbers[j]].value, false);
                    total_weight += matrix[index][numbers[j]].value;
                    create_spanning_tree_current(spanning_tree, indexes, numbers[j], mode, total_weight);
                }
            }
        }
    }
    GraphMatrix kruskal()
    {
        GraphMatrix spanning_tree(numberOfVertices, false);
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
                    if (matrix[i][j].contiguity && (min > matrix[i][j].value)
                        && (belongs[i] != belongs[j]))
                    {
                        min = matrix[i][j].value;
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
    void create_graph(std::size_t numberOfVertices, bool orientation)
    {
        this->numberOfVertices = numberOfVertices;
        numberOfEdges = 0;
        this->orientation = orientation;
        std::vector<Edge<T>> new_line(numberOfVertices, Edge<T>());
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            matrix.push_back(new_line);
        }
    }
    bool create_random(std::size_t numberOfVertices, std::size_t numberOfEdges, bool orientation, int max_weight)
    {
        clear();
        create_graph(numberOfVertices, orientation);
        srand(unsigned(time(0)));
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            for (std::size_t j = 0; j < numberOfVertices; j++)
            {
                if (this->numberOfEdges >= numberOfEdges) return true;
                if ((i != j) && !matrix[i][j].contiguity)
                {
                    add_edge(i, j, rand() % max_weight, false);//?
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
                    add_edge(i, i, rand() % max_weight, false);
                }
            }
        }
        if (this->numberOfEdges < numberOfEdges)
        {
            std::cout << "\nThere are too many edges!" << std::endl;
            clear();
            return false;
        }

        return false;
    }
public:
    GraphMatrix(bool orientation)
    {
        numberOfVertices = 0;
        numberOfEdges = 0;
        this->orientation = orientation;
    }
    GraphMatrix(std::size_t numberOfVertices, bool orientation)
    {
        create_graph(numberOfVertices, orientation);
    }
    void add_vertex(bool show = true)
    {
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            matrix[i].push_back(Edge<T>());
        }
        numberOfVertices++;
        std::vector<Edge<T>> new_line(numberOfVertices, Edge<T>());
        matrix.push_back(new_line);
        if (show) std::cout << "\nThe vertex is added!" << std::endl;
    }
    void add_edge(std::size_t beginIndex, std::size_t endIndex, T value, bool show = true)
    {
        if (!is_index(beginIndex) || !is_index(endIndex)) return;
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
            std::cout << "| ";
            for (std::size_t j = 0; j < numberOfVertices; j++)
            {
                if (matrix[i][j].contiguity) std::cout << "1 ";
                else std::cout << "0 ";
            }
            std::cout << "|" << std::endl;
        }
        std::cout << "\nVertices: " << numberOfVertices << std::endl;
        std::cout << "Edges: " << numberOfEdges << std::endl;
    }
    void create_random_graph(std::size_t numberOfVertices, std::size_t numberOfEdges, bool orientation, int max_weight, bool show = true)
    {
        if (create_random(numberOfVertices, numberOfEdges, orientation, max_weight))
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
    void find_paths_between_two_vertices(std::size_t beginIndex, std::size_t endIndex, bool show = true)
    {
        if (!connected_graph(show)) return;
        int* distance = dijkstra(beginIndex);
        if (distance[endIndex] == INT_MAX)
        {
            if (show) std::cout << "\nThe graph is poorly oriented so it cannot be reached from " << beginIndex
                << " to " << endIndex << "." << std::endl;
        }
        else
        {
            if (show) std::cout << "\nThe smallest distance from " << beginIndex
                << " to " << endIndex << " = " << distance[endIndex] << "." << std::endl;
        }
        delete[]distance;
    }
    void find_path_from_the_vertex_to_everyone_else(std::size_t beginIndex, bool show = true)
    {
        if (!connected_graph(show)) return;
        int* distance = dijkstra(beginIndex);
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            if (distance[i] == INT_MAX)
            {
                if (show) std::cout << "\nThe graph is poorly oriented so it cannot be reached from " << beginIndex
                    << " to " << i << "." << std::endl;
            }
            else
            {
                if (show) std::cout << "\nThe smallest distance from " << beginIndex
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
        GraphMatrix<T> spanning_tree(numberOfVertices, false);
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
        GraphMatrix<T> spanning_tree = kruskal();
        if (show) std::cout << "\nThe spanning tree is created!" << std::endl;
        if (show) spanning_tree.write_graph();
        spanning_tree.clear();
    }
    std::size_t get_size()
    {
        std::size_t size = 0;
        size += numberOfVertices * numberOfVertices * sizeof(Edge)
            + sizeof(numberOfVertices) + sizeof(numberOfEdges)
            + sizeof(orientation);

        return size;
    }
    void clear()
    {
        for (std::size_t i = 0; i < numberOfVertices; i++)
        {
            matrix[i].clear();
        }
        matrix.clear();
        numberOfVertices = 0;
        numberOfEdges = 0;
        orientation = false;
    }
};

struct Vertex_node
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
};

void printV(std::vector <int> arr)
{
    for (std::size_t i = 0; i < arr.size(); i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
}
int main()
{
    std::vector <int> a = { 1, 2, 3 ,4 }, b;
    std::cout << "A:\n";
    printV(a);
    b = a;
    std::cout << "B:\n";
    printV(b);
    a[2] = 10;
    a[0] = -99;
    std::cout << "A:\n";
    printV(a);
    std::cout << "B:\n";
    printV(b);
    std::cout << "Hello World!\n";
}
