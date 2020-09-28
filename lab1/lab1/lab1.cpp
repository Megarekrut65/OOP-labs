#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include "my_graph_matrix.h"
#include "my_graph_structure.h"

using namespace gs;
       
int main()
{
    srand(unsigned(time(0)));
    //std::vector<int> arr1 = {10, 14, 15, 5, 2 ,5, 1, 3, 9, 6}, arr2 = rand() % arr1, arr3 = rand() % arr1, arr4 = rand() % arr1, arr5 = rand() % arr1, arr6 = rand() % arr1;
    GraphStructure< int> graph(false);
    graph.addVertex(40);
    graph.addVertex(60);
    graph.addVertex(40);
    graph.addVertex(10);
    graph.addVertex(20);
    graph.addEdge(0, 1, 30);
    graph.addEdge(1, 2, 60);
    graph.addEdge(2, 3, 20);
    graph.addEdge(0, 4, 30);
    graph.addEdge(4, 2, 40);
    graph.addEdge(3, 1, 80);
    std::cout << graph.getTextRepresentation();
    graph.removeEdge(3, 1);
    graph.removeVertex(2);
    graph.addVertex(15);
   // graph.addEdge(4, 2, 40);
   // graph.addEdge(3, 1, 80);
   /*
    std::cout << graph.getTextRepresentation();
    graph.addVertex(arr1, false);
    graph.addVertex(arr1, false);
    graph.addEdge(4, 5, arr4, false);
    graph.addEdge(1, 5, arr6, false);
    std::cout << graph.getTextRepresentation();
    //graph.getPathsFromTheVertexToEveryoneElse(2).print();
    //std::cout << graph.depthFirstSearch();
    //std::cout << graph.topologicalSorting();*/
    //std::cout << graph.getSpanningTree().getTextRepresentation();
    //std::cout << graph.getTheSmallestSpanningTree().getTextRepresentation();
    std::cout << graph.getTextRepresentation();
    std::cout << "Hello World!\n";

    return 0;
}
