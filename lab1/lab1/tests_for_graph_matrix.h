#pragma once
#include "doctest.h"
#include "my_graph_matrix.h"
#include "my_graph_structure.h"
//tests for int
TEST_CASE("testing the adding vertices and edges to GraphMatrix<int>")
{
    SUBCASE("oriented graph")
    {
        gm::GraphMatrix<int> graph(true);
        graph.addVertex(10);
        graph.addVertex(5);
        graph.addVertex(447);
        REQUIRE(graph.getNumberOfVertices() == 3);
        REQUIRE(graph.getNumberOfEdges() == 0);
        REQUIRE(graph.getTotalValue() == 0);
        CHECK(graph.getVertexValue(0) == 10);
        CHECK(graph.getVertexValue(1) == 5);
        CHECK(graph.getVertexValue(2) == 447);
        SUBCASE("adding edge between added vertices")
        {
            graph.addEdge(0, 1, 100);
            graph.addEdge(1, 0, 6);
            graph.addEdge(0, 2, 48);
            CHECK(graph.getNumberOfVertices() == 3);
            CHECK(graph.getNumberOfEdges() == 3);
            CHECK(graph.getTotalValue() == 154);
            CHECK(graph.getEdgeValue(0, 1) == 100);
            CHECK(graph.getEdgeValue(1, 0) == 6);
            CHECK(graph.getEdgeValue(0, 2) == 48);
        }
        SUBCASE("adding edge between non-existent vertices")
        {
            graph.addEdge(5, 7, 45);
            graph.addEdge(154, 362, 100);
            graph.addEdge(4, 44, 11);
            CHECK(graph.getNumberOfVertices() == 3);
            CHECK(graph.getNumberOfEdges() == 0);
            CHECK(graph.getTotalValue() == 0);
            CHECK(graph.getEdgeValue(5, 7) == 0);
            CHECK(graph.getEdgeValue(154, 362) == 0);
            CHECK(graph.getEdgeValue(4, 44) == 0);
        }
        SUBCASE("adding already added edge")
        {
            graph.addEdge(0, 1, 100);
            CHECK(graph.getEdgeValue(0, 1) == 100);
            graph.addEdge(0, 1, 6);
            CHECK(graph.getEdgeValue(0, 1) == 100);
            graph.addEdge(1, 0, 48);
            CHECK(graph.getEdgeValue(1, 0) == 48);
            CHECK(graph.getNumberOfVertices() == 3);
            CHECK(graph.getNumberOfEdges() == 2);
            CHECK(graph.getTotalValue() == 148);
        }
    }
    SUBCASE("non-oriented graph")
    {
        gm::GraphMatrix<int> graph(false);
        graph.addVertex(10);
        graph.addVertex(5);
        graph.addVertex(447);
        REQUIRE(graph.getNumberOfVertices() == 3);
        REQUIRE(graph.getNumberOfEdges() == 0);
        REQUIRE(graph.getTotalValue() == 0);
        CHECK(graph.getVertexValue(0) == 10);
        CHECK(graph.getVertexValue(1) == 5);
        CHECK(graph.getVertexValue(2) == 447);
        SUBCASE("adding edge between added vertices")
        {
            graph.addEdge(0, 1, 100);
            graph.addEdge(1, 1, 6);
            graph.addEdge(0, 2, 48);
            CHECK(graph.getNumberOfVertices() == 3);
            CHECK(graph.getNumberOfEdges() == 3);
            CHECK(graph.getTotalValue() == 154);
            CHECK(graph.getEdgeValue(0, 1) == 100);
            CHECK(graph.getEdgeValue(1, 1) == 6);
            CHECK(graph.getEdgeValue(0, 2) == 48);
        }
        SUBCASE("adding edge between non-existent vertices")
        {
            graph.addEdge(5, 7, 45);
            graph.addEdge(154, 362, 100);
            graph.addEdge(4, 44, 11);
            CHECK(graph.getNumberOfVertices() == 3);
            CHECK(graph.getNumberOfEdges() == 0);
            CHECK(graph.getTotalValue() == 0);
            CHECK(graph.getEdgeValue(5, 7) == 0);
            CHECK(graph.getEdgeValue(154, 362) == 0);
            CHECK(graph.getEdgeValue(4, 44) == 0);
        }
        SUBCASE("adding already added edge")
        {
            graph.addEdge(0, 1, 100);
            CHECK(graph.getEdgeValue(0, 1) == 100);
            graph.addEdge(0, 1, 6);
            CHECK(graph.getEdgeValue(0, 1) == 100);
            graph.addEdge(1, 0, 48);
            CHECK(graph.getEdgeValue(1, 0) == 100);
            CHECK(graph.getNumberOfVertices() == 3);
            CHECK(graph.getNumberOfEdges() == 1);
            CHECK(graph.getTotalValue() == 100);
        }
    }

}
TEST_CASE("testing the removing vertices and edges from GraphMatrix<int>")
{
    SUBCASE("oriented graph")
    {
        gm::GraphMatrix<int> graph(true);
        graph.addVertex(10);
        graph.addVertex(5);
        graph.addVertex(447);
        graph.addVertex(41);
        graph.addEdge(0, 1, 10);
        graph.addEdge(1, 2, 6);
        graph.addEdge(0, 3, 44);
        REQUIRE(graph.getNumberOfVertices() == 4);
        REQUIRE(graph.getNumberOfEdges() == 3);
        REQUIRE(graph.getTotalValue() == 60);
        SUBCASE("removing existent vertices")//after removing vertex indexes of all vertices edited(example: vertices: 0, 1, 2; remove(0); vertices: 0, 1;)
        {
            graph.removeVertex(0);
            graph.removeVertex(0);
            CHECK(graph.getNumberOfVertices() == 2);
            CHECK(graph.getNumberOfEdges() == 0);
            CHECK(graph.getTotalValue() == 0);
        }
        SUBCASE("removing non-existent vertices")
        {
            graph.removeVertex(56);
            graph.removeVertex(18);
            graph.removeVertex(4);
            CHECK(graph.getNumberOfVertices() == 4);
            CHECK(graph.getNumberOfEdges() == 3);
            CHECK(graph.getTotalValue() == 60);
        }
        SUBCASE("removing existent edges")
        {
            graph.removeEdge(0, 3);
            graph.removeEdge(1, 2);
            CHECK(graph.getNumberOfVertices() == 4);
            CHECK(graph.getNumberOfEdges() == 1);
            CHECK(graph.getTotalValue() == 10);
        }
        SUBCASE("removing non-existent edges")
        {
            graph.removeEdge(0, 2);
            graph.removeEdge(15, 22);
            CHECK(graph.getNumberOfVertices() == 4);
            CHECK(graph.getNumberOfEdges() == 3);
            CHECK(graph.getTotalValue() == 60);
        }
    }
    SUBCASE("non-oriented graph")
    {
        gm::GraphMatrix<int> graph(false);
        graph.addVertex(10);
        graph.addVertex(5);
        graph.addVertex(447);
        graph.addVertex(41);
        graph.addEdge(0, 1, 10);
        graph.addEdge(1, 2, 6);
        graph.addEdge(0, 3, 44);
        REQUIRE(graph.getNumberOfVertices() == 4);
        REQUIRE(graph.getNumberOfEdges() == 3);
        REQUIRE(graph.getTotalValue() == 60);
        SUBCASE("removing existent vertices")//after removing vertex indexes of all vertices edited(example: vertices: 0, 1, 2; remove(0); vertices: 0, 1;)
        {
            graph.removeVertex(0);
            graph.removeVertex(0);
            CHECK(graph.getNumberOfVertices() == 2);
            CHECK(graph.getNumberOfEdges() == 0);
            CHECK(graph.getTotalValue() == 0);
        }
        SUBCASE("removing non-existent vertices")
        {
            graph.removeVertex(56);
            graph.removeVertex(18);
            graph.removeVertex(4);
            CHECK(graph.getNumberOfVertices() == 4);
            CHECK(graph.getNumberOfEdges() == 3);
            CHECK(graph.getTotalValue() == 60);
        }
        SUBCASE("removing existent edges")
        {
            graph.removeEdge(0, 3);
            graph.removeEdge(1, 2);
            CHECK(graph.getNumberOfVertices() == 4);
            CHECK(graph.getNumberOfEdges() == 1);
            CHECK(graph.getTotalValue() == 10);
        }
        SUBCASE("removing non-existent edges")
        {
            graph.removeEdge(0, 2);
            graph.removeEdge(15, 22);
            CHECK(graph.getNumberOfVertices() == 4);
            CHECK(graph.getNumberOfEdges() == 3);
            CHECK(graph.getTotalValue() == 60);
        }
    }

}
TEST_CASE("testing the checking the connectivity of GraphMatrix<int>")
{
    SUBCASE("oriented graph")
    {
        gm::GraphMatrix<int> graph(true);
        graph.addVertex(10);
        graph.addVertex(5);
        graph.addVertex(447);
        graph.addVertex(132);
        graph.addEdge(0, 1, 100);
        graph.addEdge(1, 2, 6);
        REQUIRE(graph.getNumberOfVertices() == 4);
        REQUIRE(graph.getNumberOfEdges() == 2);
        REQUIRE(graph.getTotalValue() == 106);
        SUBCASE("graph is connected")
        {
            graph.addEdge(2, 3, 20);
            CHECK(graph.getNumberOfVertices() == 4);
            CHECK(graph.getNumberOfEdges() == 3);
            CHECK(graph.getTotalValue() == 126);
            CHECK(graph.checkingTheConnectivity());
        }
        SUBCASE("graph isn't connected")
        {
            graph.addEdge(3, 2, 20);
            CHECK(graph.getNumberOfVertices() == 4);
            CHECK(graph.getNumberOfEdges() == 3);
            CHECK(graph.getTotalValue() == 126);
            CHECK(!graph.checkingTheConnectivity());
        }
    }
    SUBCASE("non-oriented graph")
    {
        gm::GraphMatrix<int> graph(false);
        graph.addVertex(10);
        graph.addVertex(5);
        graph.addVertex(447);
        graph.addVertex(132);
        graph.addEdge(0, 1, 100);
        graph.addEdge(1, 2, 6);
        REQUIRE(graph.getNumberOfVertices() == 4);
        REQUIRE(graph.getNumberOfEdges() == 2);
        REQUIRE(graph.getTotalValue() == 106);
        SUBCASE("graph is connected")
        {
            graph.addEdge(0, 3, 20);
            CHECK(graph.getNumberOfVertices() == 4);
            CHECK(graph.getNumberOfEdges() == 3);
            CHECK(graph.getTotalValue() == 126);
            CHECK(graph.checkingTheConnectivity());
        }
        SUBCASE("graph isn't connected")
        {
            CHECK(graph.getNumberOfVertices() == 4);
            CHECK(graph.getNumberOfEdges() == 2);
            CHECK(graph.getTotalValue() == 106);
            CHECK(!graph.checkingTheConnectivity());
        }
    }

}
TEST_CASE("testing the depth First Search for GraphMatrix<int>")
{
    SUBCASE("oriented graph")
    {
        gm::GraphMatrix<int> graph(true);
        graph.addVertex(10);
        graph.addVertex(5);
        graph.addVertex(447);
        graph.addVertex(132);
        graph.addVertex(2);
        graph.addEdge(0, 2, 12);
        graph.addEdge(4, 1, 6);
        graph.addEdge(0, 3, 68);
        graph.addEdge(1, 0, 100);
        graph.addEdge(2, 4, 33);
        REQUIRE(graph.getNumberOfVertices() == 5);
        REQUIRE(graph.getNumberOfEdges() == 5);
        REQUIRE(graph.getTotalValue() == 219);
        std::vector<std::size_t> search = graph.depthFirstSearch(), array = { 0, 2, 4, 1, 3 };
        REQUIRE(search.size() == 5);
        for (std::size_t i = 0; i < search.size(); i++)
        {
            CHECK(search[i] == array[i]);
        }
    }
    SUBCASE("non-oriented graph")
    {
        gm::GraphMatrix<int> graph(false);
        graph.addVertex(10);
        graph.addVertex(5);
        graph.addVertex(447);
        graph.addVertex(132);
        graph.addVertex(2);
        graph.addEdge(0, 2, 12);
        graph.addEdge(4, 1, 6);
        graph.addEdge(0, 3, 68);
        graph.addEdge(1, 0, 100);
        graph.addEdge(2, 4, 33);
        REQUIRE(graph.getNumberOfVertices() == 5);
        REQUIRE(graph.getNumberOfEdges() == 5);
        REQUIRE(graph.getTotalValue() == 219);
        std::vector<std::size_t> search = graph.depthFirstSearch(), array = { 0, 1, 4, 2, 3 };
        REQUIRE(search.size() == 5);
        for (std::size_t i = 0; i < search.size(); i++)
        {
            CHECK(search[i] == array[i]);
        }
    }

}
TEST_CASE("testing the getting path between two vertices for GraphMatrix<int>")
{
    SUBCASE("oriented graph")
    {
        gm::GraphMatrix<int> graph(true);
        graph.addVertex(10);
        graph.addVertex(5);
        graph.addVertex(44);
        graph.addVertex(13);
        graph.addVertex(2);
        graph.addEdge(0, 1, 12);
        graph.addEdge(0, 3, 17);
        graph.addEdge(2, 1, 6);
        graph.addEdge(4, 0, 68);
        REQUIRE(graph.getNumberOfVertices() == 5);
        REQUIRE(graph.getNumberOfEdges() == 4);
        REQUIRE(graph.getTotalValue() == 103);
        SUBCASE("the direct path is the shortest")
        {
            graph.addEdge(4, 2, 50);
            graph.addEdge(0, 2, 10);
            CHECK(graph.getPathBetweenTwoVertices(4, 2) == 50);
        }
        SUBCASE("bypass through other vertices is the shortest")
        {
            graph.addEdge(4, 2, 100);
            graph.addEdge(0, 2, 10);
            CHECK(graph.getPathBetweenTwoVertices(4, 2) == 78);
        }
        SUBCASE("features in the oriented graph")
        {
            graph.addEdge(4, 2, 100);
            CHECK(graph.getPathBetweenTwoVertices(4, 2) == 100);
        }
    }
    SUBCASE("non-oriented graph")
    {
        gm::GraphMatrix<int> graph(false);
        graph.addVertex(10);
        graph.addVertex(5);
        graph.addVertex(44);
        graph.addVertex(13);
        graph.addVertex(2);
        graph.addEdge(0, 1, 12);
        graph.addEdge(0, 3, 17);
        graph.addEdge(2, 1, 6);
        graph.addEdge(4, 0, 68);
        REQUIRE(graph.getNumberOfVertices() == 5);
        REQUIRE(graph.getNumberOfEdges() == 4);
        REQUIRE(graph.getTotalValue() == 103);
        SUBCASE("the direct path is the shortest")
        {
            graph.addEdge(4, 2, 50);
            CHECK(graph.getPathBetweenTwoVertices(4, 2) == 50);
        }
        SUBCASE("bypass through other vertices is the shortest")
        {
            graph.addEdge(4, 2, 100);
            CHECK(graph.getPathBetweenTwoVertices(4, 2) == 86);
        }
    }
}
TEST_CASE("testing the getting paths from the vertex to everyone else for GraphMatrix<int>")
{
    SUBCASE("oriented graph")
    {
        gm::GraphMatrix<int> graph(true);
        graph.addVertex(10);
        graph.addVertex(5);
        graph.addVertex(44);
        graph.addVertex(13);
        graph.addVertex(2);
        graph.addEdge(1, 0, 17);
        graph.addEdge(3, 2, 10);
        graph.addEdge(2, 1, 19);
        graph.addEdge(3, 4, 42);
        graph.addEdge(2, 4, 7);
        graph.addEdge(2, 0, 50);
        REQUIRE(graph.getNumberOfVertices() == 5);
        REQUIRE(graph.getNumberOfEdges() == 6);
        REQUIRE(graph.getTotalValue() == 145);
        int* distance = new int[5]{ 46, 29, 10, 0 , 17 };
        bool* isMax = new bool[5]{ false, false, false, false, false };//if from the vertex can't get to other vertex then isMax[other vertex] = true
        pbv::PathsBetweenVertices<int> paths(distance, isMax, 5, 3), getPaths(graph.getPathsFromTheVertexToEveryoneElse(3));
        REQUIRE(getPaths.size == paths.size);
        REQUIRE(getPaths.beginIndex == paths.beginIndex);
        for (std::size_t i = 0; i < 5; i++)
        {
            CHECK(getPaths.distance[i] == paths.distance[i]);
            CHECK(getPaths.isMax[i] == paths.isMax[i]);
        }
    }
    SUBCASE("non-oriented graph")
    {
        gm::GraphMatrix<int> graph(false);
        graph.addVertex(10);
        graph.addVertex(5);
        graph.addVertex(44);
        graph.addVertex(13);
        graph.addVertex(2);
        graph.addEdge(1, 0, 17);
        graph.addEdge(3, 2, 10);
        graph.addEdge(2, 1, 19);
        graph.addEdge(3, 4, 42);
        graph.addEdge(2, 4, 7);
        graph.addEdge(2, 0, 50);
        REQUIRE(graph.getNumberOfVertices() == 5);
        REQUIRE(graph.getNumberOfEdges() == 6);
        REQUIRE(graph.getTotalValue() == 145);
        int* distance = new int[5]{ 46, 29, 10, 0 , 17 };
        bool* isMax = new bool[5]{ false, false, false, false, false };//if from the vertex can't get to other vertex then isMax[other vertex] = true
        pbv::PathsBetweenVertices<int> paths(distance, isMax, 5, 3), getPaths(graph.getPathsFromTheVertexToEveryoneElse(3));
        REQUIRE(getPaths.size == paths.size);
        REQUIRE(getPaths.beginIndex == paths.beginIndex);
        for (std::size_t i = 0; i < 5; i++)
        {
            CHECK(getPaths.distance[i] == paths.distance[i]);
            CHECK(getPaths.isMax[i] == paths.isMax[i]);
        }
    }
}
TEST_CASE("testing the topological sorting for oriented GraphMatrix<int> only")
{
    gm::GraphMatrix<int> graph(true);
    graph.addVertex(10);
    graph.addVertex(5);
    graph.addVertex(44);
    graph.addVertex(13);
    graph.addVertex(2);
    graph.addEdge(1, 0, 17);
    graph.addEdge(3, 2, 10);
    graph.addEdge(2, 1, 19);
    graph.addEdge(3, 4, 42);
    graph.addEdge(2, 4, 7);
    graph.addEdge(2, 0, 50);
    REQUIRE(graph.getNumberOfVertices() == 5);
    REQUIRE(graph.getNumberOfEdges() == 6);
    REQUIRE(graph.getTotalValue() == 145);
    std::vector<std::size_t> array = { 3, 2, 1, 0, 4 }, getArray = graph.topologicalSorting();
    CHECK(array.size() == getArray.size());
    for (std::size_t i = 0; i < 5; i++)
    {
        CHECK(array[i] == getArray[i]);
    }
}
TEST_CASE("testing the getting spanning Tree for non-oriented GraphMatrix<int> only")
{
    gm::GraphMatrix<int> graph(false);
    graph.addVertex(10);
    graph.addVertex(5);
    graph.addVertex(44);
    graph.addVertex(13);
    graph.addVertex(2);
    graph.addEdge(1, 0, 17);
    graph.addEdge(3, 2, 10);
    graph.addEdge(2, 1, 19);
    graph.addEdge(3, 4, 42);
    graph.addEdge(2, 4, 7);
    graph.addEdge(2, 0, 50);
    REQUIRE(graph.getNumberOfVertices() == 5);
    REQUIRE(graph.getNumberOfEdges() == 6);
    REQUIRE(graph.getTotalValue() == 145);
    SUBCASE("normal spanning tree")//using depth First Search
    {
        gm::GraphMatrix<int> spanningTree(graph.getSpanningTree());
        CHECK(spanningTree.getNumberOfVertices() == 5);
        CHECK(spanningTree.getNumberOfEdges() == 4);
        CHECK(spanningTree.getTotalValue() == 88);
    }
    SUBCASE("the smallest spanning tree")
    {
        gm::GraphMatrix<int> spanningTree(graph.getTheSmallestSpanningTree());
        CHECK(spanningTree.getNumberOfVertices() == 5);
        CHECK(spanningTree.getNumberOfEdges() == 4);
        CHECK(spanningTree.getTotalValue() == 53);
    }

}

//tests for double
//tests for std::vector
//tests for std::string