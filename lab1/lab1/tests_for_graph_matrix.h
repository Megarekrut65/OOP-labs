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
TEST_CASE("testing the adding vertices and edges to GraphMatrix<double>")
{
    SUBCASE("oriented graph")
    {
        gm::GraphMatrix<double> graph(true);
        graph.addVertex(10.5);
        graph.addVertex(5.1);
        graph.addVertex(44.7);
        REQUIRE(graph.getNumberOfVertices() == 3);
        REQUIRE(graph.getNumberOfEdges() == 0);
        REQUIRE(graph.getTotalValue() == doctest::Approx(0));
        CHECK(graph.getVertexValue(0) == doctest::Approx(10.5));
        CHECK(graph.getVertexValue(1) == doctest::Approx(5.1));
        CHECK(graph.getVertexValue(2) == doctest::Approx(44.7));
        SUBCASE("adding edge between added vertices")
        {
            graph.addEdge(0, 1, 100.88);
            graph.addEdge(1, 0, 6.9);
            graph.addEdge(0, 2, 4.8);
            CHECK(graph.getNumberOfVertices() == 3);
            CHECK(graph.getNumberOfEdges() == 3);
            CHECK(graph.getTotalValue() == doctest::Approx(112.58));
            CHECK(graph.getEdgeValue(0, 1) == doctest::Approx(100.88));
            CHECK(graph.getEdgeValue(1, 0) == doctest::Approx(6.9));
            CHECK(graph.getEdgeValue(0, 2) == doctest::Approx(4.8));
        }
        SUBCASE("adding edge between non-existent vertices")
        {
            graph.addEdge(5, 7, 4.5);
            graph.addEdge(154, 362, 100);
            graph.addEdge(4, 44, 11);
            CHECK(graph.getNumberOfVertices() == 3);
            CHECK(graph.getNumberOfEdges() == 0);
            CHECK(graph.getTotalValue() == doctest::Approx(0));
            CHECK(graph.getEdgeValue(5, 7) == doctest::Approx(0));
            CHECK(graph.getEdgeValue(154, 362) == doctest::Approx(0));
            CHECK(graph.getEdgeValue(4, 44) == doctest::Approx(0));
        }
        SUBCASE("adding already added edge")
        {
            graph.addEdge(0, 1, 10.7);
            CHECK(graph.getEdgeValue(0, 1) == doctest::Approx(10.7));
            graph.addEdge(0, 1, 6);
            CHECK(graph.getEdgeValue(0, 1) == doctest::Approx(10.7));
            graph.addEdge(1, 0, 4.8);
            CHECK(graph.getEdgeValue(1, 0) == doctest::Approx(4.8));
            CHECK(graph.getNumberOfVertices() == 3);
            CHECK(graph.getNumberOfEdges() == 2);
            CHECK(graph.getTotalValue() == doctest::Approx(15.5));
        }
    }
    SUBCASE("non-oriented graph")
    {
        gm::GraphMatrix<double> graph(false);
        graph.addVertex(10.5);
        graph.addVertex(5.1);
        graph.addVertex(44.7);
        REQUIRE(graph.getNumberOfVertices() == 3);
        REQUIRE(graph.getNumberOfEdges() == 0);
        REQUIRE(graph.getTotalValue() == doctest::Approx(0));
        CHECK(graph.getVertexValue(0) == doctest::Approx(10.5));
        CHECK(graph.getVertexValue(1) == doctest::Approx(5.1));
        CHECK(graph.getVertexValue(2) == doctest::Approx(44.7));
        SUBCASE("adding edge between added vertices")
        {
            graph.addEdge(0, 1, 100);
            graph.addEdge(1, 1, 6.7);
            graph.addEdge(0, 2, 48.3);
            CHECK(graph.getNumberOfVertices() == 3);
            CHECK(graph.getNumberOfEdges() == 3);
            CHECK(graph.getTotalValue() == doctest::Approx(155.0));
            CHECK(graph.getEdgeValue(0, 1) == doctest::Approx(100.0));
            CHECK(graph.getEdgeValue(1, 1) == doctest::Approx(6.7));
            CHECK(graph.getEdgeValue(0, 2) == doctest::Approx(48.3));
        }
        SUBCASE("adding edge between non-existent vertices")
        {
            graph.addEdge(5, 7, 45);
            graph.addEdge(154, 362, 100);
            graph.addEdge(4, 44, 11);
            CHECK(graph.getNumberOfVertices() == 3);
            CHECK(graph.getNumberOfEdges() == 0);
            CHECK(graph.getTotalValue() == doctest::Approx(0));
            CHECK(graph.getEdgeValue(5, 7) == doctest::Approx(0));
            CHECK(graph.getEdgeValue(154, 362) == doctest::Approx(0));
            CHECK(graph.getEdgeValue(4, 44) == doctest::Approx(0));
        }
        SUBCASE("adding already added edge")
        {
            graph.addEdge(0, 1, 100.9);
            CHECK(graph.getEdgeValue(0, 1) == doctest::Approx(100.9));
            graph.addEdge(0, 1, 6.7);
            CHECK(graph.getEdgeValue(0, 1) == doctest::Approx(100.9));
            graph.addEdge(1, 0, 4.8);
            CHECK(graph.getEdgeValue(1, 0) == doctest::Approx(100.9));
            CHECK(graph.getNumberOfVertices() == 3);
            CHECK(graph.getNumberOfEdges() == 1);
            CHECK(graph.getTotalValue() == doctest::Approx(100.9));
        }
    }

}
TEST_CASE("testing the removing vertices and edges from GraphMatrix<double>")
{
    SUBCASE("oriented graph")
    {
        gm::GraphMatrix<double> graph(true);
        graph.addVertex(10.7);
        graph.addVertex(5.3);
        graph.addVertex(447.9);
        graph.addVertex(41.2);
        graph.addEdge(0, 1, 10.8);
        graph.addEdge(1, 2, 6.1);
        graph.addEdge(0, 3, 4.4);
        REQUIRE(graph.getNumberOfVertices() == 4);
        REQUIRE(graph.getNumberOfEdges() == 3);
        REQUIRE(graph.getTotalValue() == doctest::Approx(21.3));
        SUBCASE("removing existent vertices")//after removing vertex indexes of all vertices edited(example: vertices: 0, 1, 2; remove(0); vertices: 0, 1;)
        {
            graph.removeVertex(0);
            graph.removeVertex(0);
            CHECK(graph.getNumberOfVertices() == 2);
            CHECK(graph.getNumberOfEdges() == 0);
            CHECK(graph.getTotalValue() == doctest::Approx(0));
        }
        SUBCASE("removing non-existent vertices")
        {
            graph.removeVertex(56);
            graph.removeVertex(18);
            graph.removeVertex(4);
            CHECK(graph.getNumberOfVertices() == 4);
            CHECK(graph.getNumberOfEdges() == 3);
            CHECK(graph.getTotalValue() == doctest::Approx(21.3));
        }
        SUBCASE("removing existent edges")
        {
            graph.removeEdge(0, 3);
            graph.removeEdge(1, 2);
            CHECK(graph.getNumberOfVertices() == 4);
            CHECK(graph.getNumberOfEdges() == 1);
            CHECK(graph.getTotalValue() == doctest::Approx(10.8));
        }
        SUBCASE("removing non-existent edges")
        {
            graph.removeEdge(0, 2);
            graph.removeEdge(15, 22);
            CHECK(graph.getNumberOfVertices() == 4);
            CHECK(graph.getNumberOfEdges() == 3);
            CHECK(graph.getTotalValue() == doctest::Approx(21.3));
        }
    }
    SUBCASE("non-oriented graph")
    {
        gm::GraphMatrix<double> graph(false);
        graph.addVertex(10.8);
        graph.addVertex(5.2);
        graph.addVertex(4.47);
        graph.addVertex(4.1);
        graph.addEdge(0, 1, 10.8);
        graph.addEdge(1, 2, 6.4);
        graph.addEdge(0, 3, 4.4);
        REQUIRE(graph.getNumberOfVertices() == 4);
        REQUIRE(graph.getNumberOfEdges() == 3);
        REQUIRE(graph.getTotalValue() == doctest::Approx(21.6));
        SUBCASE("removing existent vertices")//after removing vertex indexes of all vertices edited(example: vertices: 0, 1, 2; remove(0); vertices: 0, 1;)
        {
            graph.removeVertex(0);
            graph.removeVertex(0);
            CHECK(graph.getNumberOfVertices() == 2);
            CHECK(graph.getNumberOfEdges() == 0);
            CHECK(graph.getTotalValue() == doctest::Approx(0));
        }
        SUBCASE("removing non-existent vertices")
        {
            graph.removeVertex(56);
            graph.removeVertex(18);
            graph.removeVertex(4);
            CHECK(graph.getNumberOfVertices() == 4);
            CHECK(graph.getNumberOfEdges() == 3);
            CHECK(graph.getTotalValue() == doctest::Approx(21.6));
        }
        SUBCASE("removing existent edges")
        {
            graph.removeEdge(0, 3);
            graph.removeEdge(1, 2);
            CHECK(graph.getNumberOfVertices() == 4);
            CHECK(graph.getNumberOfEdges() == 1);
            CHECK(graph.getTotalValue() == doctest::Approx(10.8));
        }
        SUBCASE("removing non-existent edges")
        {
            graph.removeEdge(0, 2);
            graph.removeEdge(15, 22);
            CHECK(graph.getNumberOfVertices() == 4);
            CHECK(graph.getNumberOfEdges() == 3);
            CHECK(graph.getTotalValue() == doctest::Approx(21.6));
        }
    }

}
TEST_CASE("testing the checking the connectivity of GraphMatrix<double>")
{
    SUBCASE("oriented graph")
    {
        gm::GraphMatrix<double> graph(true);
        graph.addVertex(10.3);
        graph.addVertex(5.9);
        graph.addVertex(44.7);
        graph.addVertex(13.2);
        graph.addEdge(0, 1, 100.7);
        graph.addEdge(1, 2, 6.4);
        REQUIRE(graph.getNumberOfVertices() == 4);
        REQUIRE(graph.getNumberOfEdges() == 2);
        REQUIRE(graph.getTotalValue() == doctest::Approx(107.1));
        SUBCASE("graph is connected")
        {
            graph.addEdge(2, 3, 20.2);
            CHECK(graph.getNumberOfVertices() == 4);
            CHECK(graph.getNumberOfEdges() == 3);
            CHECK(graph.getTotalValue() == doctest::Approx(127.3));
            CHECK(graph.checkingTheConnectivity());
        }
        SUBCASE("graph isn't connected")
        {
            graph.addEdge(3, 2, 20.2);
            CHECK(graph.getNumberOfVertices() == 4);
            CHECK(graph.getNumberOfEdges() == 3);
            CHECK(graph.getTotalValue() == doctest::Approx(127.3));
            CHECK(!graph.checkingTheConnectivity());
        }
    }
    SUBCASE("non-oriented graph")
    {
        gm::GraphMatrix<double> graph(false);
        graph.addVertex(10.8);
        graph.addVertex(5.3);
        graph.addVertex(44.7);
        graph.addVertex(13.2);
        graph.addEdge(0, 1, 100.8);
        graph.addEdge(1, 2, 6.5);
        REQUIRE(graph.getNumberOfVertices() == 4);
        REQUIRE(graph.getNumberOfEdges() == 2);
        REQUIRE(graph.getTotalValue() == doctest::Approx(107.3));
        SUBCASE("graph is connected")
        {
            graph.addEdge(0, 3, 20.8);
            CHECK(graph.getNumberOfVertices() == 4);
            CHECK(graph.getNumberOfEdges() == 3);
            CHECK(graph.getTotalValue() == doctest::Approx(128.1));
            CHECK(graph.checkingTheConnectivity());
        }
        SUBCASE("graph isn't connected")
        {
            CHECK(graph.getNumberOfVertices() == 4);
            CHECK(graph.getNumberOfEdges() == 2);
            CHECK(graph.getTotalValue() == doctest::Approx(107.3));
            CHECK(!graph.checkingTheConnectivity());
        }
    }

}
TEST_CASE("testing the depth First Search for GraphMatrix<double>")
{
    SUBCASE("oriented graph")
    {
        gm::GraphMatrix<double> graph(true);
        graph.addVertex(10.8);
        graph.addVertex(5.5);
        graph.addVertex(4.47);
        graph.addVertex(1.32);
        graph.addVertex(2.5);
        graph.addEdge(0, 2, 1.2);
        graph.addEdge(4, 1, 6.5);
        graph.addEdge(0, 3, 6.8);
        graph.addEdge(1, 0, 100.67);
        graph.addEdge(2, 4, 3.3);
        REQUIRE(graph.getNumberOfVertices() == 5);
        REQUIRE(graph.getNumberOfEdges() == 5);
        REQUIRE(graph.getTotalValue() == doctest::Approx(118.47));
        std::vector<std::size_t> search = graph.depthFirstSearch(), array = { 0, 2, 4, 1, 3 };
        REQUIRE(search.size() == 5);
        for (std::size_t i = 0; i < search.size(); i++)
        {
            CHECK(search[i] == array[i]);
        }
    }
    SUBCASE("non-oriented graph")
    {
        gm::GraphMatrix<double> graph(false);
        graph.addVertex(10.8);
        graph.addVertex(5.5);
        graph.addVertex(4.47);
        graph.addVertex(1.32);
        graph.addVertex(2.5);
        graph.addEdge(0, 2, 1.2);
        graph.addEdge(4, 1, 6.5);
        graph.addEdge(0, 3, 6.8);
        graph.addEdge(1, 0, 100.67);
        graph.addEdge(2, 4, 3.3);
        REQUIRE(graph.getNumberOfVertices() == 5);
        REQUIRE(graph.getNumberOfEdges() == 5);
        REQUIRE(graph.getTotalValue() == doctest::Approx(118.47));
        std::vector<std::size_t> search = graph.depthFirstSearch(), array = { 0, 1, 4, 2, 3 };
        REQUIRE(search.size() == 5);
        for (std::size_t i = 0; i < search.size(); i++)
        {
            CHECK(search[i] == array[i]);
        }
    }
}
TEST_CASE("testing the getting path between two vertices for GraphMatrix<double>")
{
    SUBCASE("oriented graph")
    {
        gm::GraphMatrix<double> graph(true);
        graph.addVertex(10.8);
        graph.addVertex(5.9);
        graph.addVertex(4.4);
        graph.addVertex(1.3);
        graph.addVertex(2.6);
        graph.addEdge(0, 1, 1.2);
        graph.addEdge(0, 3, 1.7);
        graph.addEdge(2, 1, 0.6);
        graph.addEdge(4, 0, 4.1);
        REQUIRE(graph.getNumberOfVertices() == 5);
        REQUIRE(graph.getNumberOfEdges() == 4);
        REQUIRE(graph.getTotalValue() == doctest::Approx(7.6));
        SUBCASE("the direct path is the shortest")
        {
            graph.addEdge(4, 2, 5.1);
            graph.addEdge(0, 2, 1.1);
            CHECK(graph.getPathBetweenTwoVertices(4, 2) == doctest::Approx(5.1));
        }
        SUBCASE("bypass through other vertices is the shortest")
        {
            graph.addEdge(4, 2, 10.2);
            graph.addEdge(0, 2, 6.01);
            CHECK(graph.getPathBetweenTwoVertices(4, 2) == doctest::Approx(10.11));
        }
        SUBCASE("features in the oriented graph")
        {
            graph.addEdge(4, 2, 100.8);
            CHECK(graph.getPathBetweenTwoVertices(4, 2) == doctest::Approx(100.8));
        }
    }
    SUBCASE("non-oriented graph")
    {
        gm::GraphMatrix<double> graph(false);
        graph.addVertex(10.8);
        graph.addVertex(5.9);
        graph.addVertex(4.4);
        graph.addVertex(1.3);
        graph.addVertex(2.6);
        graph.addEdge(0, 1, 1.2);
        graph.addEdge(0, 3, 1.7);
        graph.addEdge(2, 1, 0.6);
        graph.addEdge(4, 0, 3.4);
        REQUIRE(graph.getNumberOfVertices() == 5);
        REQUIRE(graph.getNumberOfEdges() == 4);
        REQUIRE(graph.getTotalValue() == doctest::Approx(6.9));
        SUBCASE("the direct path is the shortest")
        {
            graph.addEdge(4, 2, 5.1);
            CHECK(graph.getPathBetweenTwoVertices(4, 2) == doctest::Approx(5.1));
        }
        SUBCASE("bypass through other vertices is the shortest")
        {
            graph.addEdge(4, 2, 5.3);
            CHECK(graph.getPathBetweenTwoVertices(4, 2) == doctest::Approx(5.2));
        }
    }
}
TEST_CASE("testing the getting paths from the vertex to everyone else for GraphMatrix<double>")
{
    SUBCASE("oriented graph")
    {
        gm::GraphMatrix<double> graph(true);
        graph.addVertex(10.9);
        graph.addVertex(5.2);
        graph.addVertex(4.4);
        graph.addVertex(1.3);
        graph.addVertex(0.2);
        graph.addEdge(1, 0, 1.7);
        graph.addEdge(3, 2, 10.8);
        graph.addEdge(2, 1, 1.9);
        graph.addEdge(3, 4, 4.2);
        graph.addEdge(2, 4, 7.3);
        graph.addEdge(2, 0, 5.8);
        REQUIRE(graph.getNumberOfVertices() == 5);
        REQUIRE(graph.getNumberOfEdges() == 6);
        REQUIRE(graph.getTotalValue() == doctest::Approx(31.7));
        double* distance = new double[5]{ 14.4, 12.7, 10.8, 0 , 4.2 };
        bool* isMax = new bool[5]{ false, false, false, false, false };//if from the vertex can't get to other vertex then isMax[other vertex] = true
        pbv::PathsBetweenVertices<double> paths(distance, isMax, 5, 3), getPaths(graph.getPathsFromTheVertexToEveryoneElse(3));
        REQUIRE(getPaths.size == paths.size);
        REQUIRE(getPaths.beginIndex == paths.beginIndex);
        for (std::size_t i = 0; i < 5; i++)
        {
            CHECK(getPaths.distance[i] == doctest::Approx(paths.distance[i]));
            CHECK(getPaths.isMax[i] == paths.isMax[i]);
        }
    }
    SUBCASE("non-oriented graph")
    {
        gm::GraphMatrix<double> graph(false);
        graph.addVertex(10.9);
        graph.addVertex(5.2);
        graph.addVertex(4.4);
        graph.addVertex(1.3);
        graph.addVertex(0.2);
        graph.addEdge(1, 0, 1.7);
        graph.addEdge(3, 2, 10.8);
        graph.addEdge(2, 1, 1.9);
        graph.addEdge(3, 4, 4.2);
        graph.addEdge(2, 4, 7.3);
        graph.addEdge(2, 0, 5.8);
        REQUIRE(graph.getNumberOfVertices() == 5);
        REQUIRE(graph.getNumberOfEdges() == 6);
        REQUIRE(graph.getTotalValue() == doctest::Approx(31.7));
        double* distance = new double[5]{ 14.4, 12.7, 10.8, 0 , 4.2 };
        bool* isMax = new bool[5]{ false, false, false, false, false };//if from the vertex can't get to other vertex then isMax[other vertex] = true
        pbv::PathsBetweenVertices<double> paths(distance, isMax, 5, 3), getPaths(graph.getPathsFromTheVertexToEveryoneElse(3));
        REQUIRE(getPaths.size == paths.size);
        REQUIRE(getPaths.beginIndex == paths.beginIndex);
        for (std::size_t i = 0; i < 5; i++)
        {
            CHECK(getPaths.distance[i] == doctest::Approx(paths.distance[i]));
            CHECK(getPaths.isMax[i] == paths.isMax[i]);
        }
    }
}
TEST_CASE("testing the topological sorting for oriented GraphMatrix<int> only")
{
    gm::GraphMatrix<double> graph(true);
    graph.addVertex(10.7);
    graph.addVertex(5.6);
    graph.addVertex(4.4);
    graph.addVertex(1.3);
    graph.addVertex(2.6);
    graph.addEdge(1, 0, 1.7);
    graph.addEdge(3, 2, 10.6);
    graph.addEdge(2, 1, 1.9);
    graph.addEdge(3, 4, 4.2);
    graph.addEdge(2, 4, 7.5);
    graph.addEdge(2, 0, 50.2);
    REQUIRE(graph.getNumberOfVertices() == 5);
    REQUIRE(graph.getNumberOfEdges() == 6);
    REQUIRE(graph.getTotalValue() == doctest::Approx(76.1));
    std::vector<std::size_t> array = { 3, 2, 1, 0, 4 }, getArray = graph.topologicalSorting();
    CHECK(array.size() == getArray.size());
    for (std::size_t i = 0; i < 5; i++)
    {
        CHECK(array[i] == getArray[i]);
    }
}
TEST_CASE("testing the getting spanning Tree for non-oriented GraphMatrix<int> only")
{
    gm::GraphMatrix<double> graph(false);
    graph.addVertex(10.8);
    graph.addVertex(5.1);
    graph.addVertex(42.4);
    graph.addVertex(1.3);
    graph.addVertex(2.4);
    graph.addEdge(1, 0, 1.7);
    graph.addEdge(3, 2, 1.1);
    graph.addEdge(2, 1, 1.9);
    graph.addEdge(3, 4, 4.2);
    graph.addEdge(2, 4, 2.2);
    graph.addEdge(2, 0, 5.6);
    REQUIRE(graph.getNumberOfVertices() == 5);
    REQUIRE(graph.getNumberOfEdges() == 6);
    REQUIRE(graph.getTotalValue() == doctest::Approx(16.7));
    SUBCASE("normal spanning tree")//using depth First Search
    {
        gm::GraphMatrix<double> spanningTree(graph.getSpanningTree());
        CHECK(spanningTree.getNumberOfVertices() == 5);
        CHECK(spanningTree.getNumberOfEdges() == 4);
        CHECK(spanningTree.getTotalValue() == doctest::Approx(8.9));
    }
    SUBCASE("the smallest spanning tree")
    {
        gm::GraphMatrix<double> spanningTree(graph.getTheSmallestSpanningTree());
        CHECK(spanningTree.getNumberOfVertices() == 5);
        CHECK(spanningTree.getNumberOfEdges() == 4);
        CHECK(spanningTree.getTotalValue() == doctest::Approx(6.9));
    }

}
//tests for std::vector<int>. Other types can be used instead of int. Because the methods are defined for std::vector<T>

TEST_CASE("testing the adding vertices and edges to GraphMatrix<std::vector<int>>")
{
    std::vector<int> arr0, arr1 = { 5 }, arr2 = { 9, 2 }, arr3 = { 0, 4, 2 }, arr4 = { 8, 9, 2, 1 }, arrFour = { 1, 5, 2, 2 };

    SUBCASE("oriented graph")
    {
        gm::GraphMatrix< std::vector<int>> graph(true);
        graph.addVertex(arr1);
        graph.addVertex(arr2);
        graph.addVertex(arr3);
        REQUIRE(graph.getNumberOfVertices() == 3);
        REQUIRE(graph.getNumberOfEdges() == 0);
        REQUIRE(graph.getTotalValue() == arr0);
        CHECK(graph.getVertexValue(0) == arr1);
        CHECK(graph.getVertexValue(1) == arr2);
        CHECK(graph.getVertexValue(2) == arr3);
        SUBCASE("adding edge between added vertices")
        {
            graph.addEdge(0, 1, arr0);
            graph.addEdge(1, 0, arr2);
            graph.addEdge(0, 2, arr4);
            CHECK(graph.getNumberOfVertices() == 3);
            CHECK(graph.getNumberOfEdges() == 3);
            CHECK(graph.getTotalValue() == (arr2 + arr4));
            CHECK(graph.getEdgeValue(0, 1) == arr0);
            CHECK(graph.getEdgeValue(1, 0) == arr2);
            CHECK(graph.getEdgeValue(0, 2) != arrFour);
            CHECK(graph.getEdgeValue(0, 2) == arr4);
        }
        SUBCASE("adding edge between non-existent vertices")
        {
            graph.addEdge(5, 7, arr2);
            graph.addEdge(154, 362, arr2);
            graph.addEdge(4, 44, arr2);
            CHECK(graph.getNumberOfVertices() == 3);
            CHECK(graph.getNumberOfEdges() == 0);
            CHECK(graph.getTotalValue() == arr0);
            CHECK(graph.getEdgeValue(5, 7) == arr0);
            CHECK(graph.getEdgeValue(154, 362) == arr0);
            CHECK(graph.getEdgeValue(4, 44) == arr0);
        }
        SUBCASE("adding already added edge")
        {
            graph.addEdge(0, 1, arr3);
            CHECK(graph.getEdgeValue(0, 1) == arr3);
            graph.addEdge(0, 1, arr4);
            CHECK(graph.getEdgeValue(0, 1) == arr3);
            graph.addEdge(1, 0, arr1);
            CHECK(graph.getEdgeValue(1, 0) == arr1);
            CHECK(graph.getNumberOfVertices() == 3);
            CHECK(graph.getNumberOfEdges() == 2);
            CHECK(graph.getTotalValue() == (arr3 + arr1));
        }
    }
    SUBCASE("non-oriented graph")
    {
        gm::GraphMatrix< std::vector<int>> graph(false);
        graph.addVertex(arr1);
        graph.addVertex(arr2);
        graph.addVertex(arr3);
        REQUIRE(graph.getNumberOfVertices() == 3);
        REQUIRE(graph.getNumberOfEdges() == 0);
        REQUIRE(graph.getTotalValue() == arr0);
        CHECK(graph.getVertexValue(0) == arr1);
        CHECK(graph.getVertexValue(1) == arr2);
        CHECK(graph.getVertexValue(2) == arr3);
        SUBCASE("adding edge between added vertices")
        {
            graph.addEdge(0, 1, arr1);
            graph.addEdge(1, 0, arr2);
            graph.addEdge(0, 2, arr4);
            CHECK(graph.getNumberOfVertices() == 3);
            CHECK(graph.getNumberOfEdges() == 2);
            CHECK(graph.getTotalValue() == (arr1 + arr4));
            CHECK(graph.getEdgeValue(0, 1) == arr1);
            CHECK(graph.getEdgeValue(1, 0) == arr1);
            CHECK(graph.getEdgeValue(0, 2) != arrFour);
            CHECK(graph.getEdgeValue(0, 2) == arr4);
        }
        SUBCASE("adding edge between non-existent vertices")
        {
            graph.addEdge(5, 7, arr2);
            graph.addEdge(154, 362, arr2);
            graph.addEdge(4, 44, arr2);
            CHECK(graph.getNumberOfVertices() == 3);
            CHECK(graph.getNumberOfEdges() == 0);
            CHECK(graph.getTotalValue() == arr0);
            CHECK(graph.getEdgeValue(5, 7) == arr0);
            CHECK(graph.getEdgeValue(154, 362) == arr0);
            CHECK(graph.getEdgeValue(4, 44) == arr0);
        }
        SUBCASE("adding already added edge")
        {
            graph.addEdge(0, 1, arr3);
            CHECK(graph.getEdgeValue(0, 1) == arr3);
            graph.addEdge(0, 1, arr4);
            CHECK(graph.getEdgeValue(0, 1) == arr3);
            graph.addEdge(1, 0, arr1);
            CHECK(graph.getEdgeValue(1, 0) == arr3);
            CHECK(graph.getNumberOfVertices() == 3);
            CHECK(graph.getNumberOfEdges() == 1);
            CHECK(graph.getTotalValue() == arr3);
        }
    }
}
TEST_CASE("testing the removing vertices and edges from GraphMatrix<std::vector<int>>")
{
    std::vector<int> arr0, arr1 = { 5 }, arr2 = { 9, 2 }, arr3 = { 0, 4, 2 }, arr4 = { 8, 9, 2, 1 }, arrFour = { 1, 5, 2, 2 };

    SUBCASE("oriented graph")
    {
        gm::GraphMatrix<std::vector<int>> graph(true);
        graph.addVertex(arr1);
        graph.addVertex(arr3);
        graph.addVertex(arr3);
        graph.addVertex(arr2);
        graph.addEdge(0, 1, arr4);
        graph.addEdge(1, 2, arr2);
        graph.addEdge(0, 3, arr1);
        REQUIRE(graph.getNumberOfVertices() == 4);
        REQUIRE(graph.getNumberOfEdges() == 3);
        REQUIRE(graph.getTotalValue() == (arr4 + arr2 + arr1));
        SUBCASE("removing existent vertices")//after removing vertex indexes of all vertices edited(example: vertices: 0, 1, 2; remove(0); vertices: 0, 1;)
        {
            graph.removeVertex(0);
            graph.removeVertex(0);
            CHECK(graph.getNumberOfVertices() == 2);
            CHECK(graph.getNumberOfEdges() == 0);
            CHECK(graph.getTotalValue() == arr0);
        }
        SUBCASE("removing non-existent vertices")
        {
            graph.removeVertex(56);
            graph.removeVertex(18);
            graph.removeVertex(4);
            CHECK(graph.getNumberOfVertices() == 4);
            CHECK(graph.getNumberOfEdges() == 3);
            CHECK(graph.getTotalValue() == (arr4 + arr2 + arr1));
        }
        SUBCASE("removing existent edges")//during removal of an edge totalValue reduces the length, but its elements can differ from those which remained in other edges.
        {
            graph.removeEdge(0, 1);
            graph.removeEdge(1, 2);
            CHECK(graph.getNumberOfVertices() == 4);
            CHECK(graph.getNumberOfEdges() == 1);
            CHECK(graph.getTotalValue() == ((arr4 + arr2 + arr1) - arr4 - arr2));
            CHECK(graph.getTotalValue() != arr1);
        }
        SUBCASE("removing non-existent edges")
        {
            graph.removeEdge(0, 2);
            graph.removeEdge(15, 22);
            CHECK(graph.getNumberOfVertices() == 4);
            CHECK(graph.getNumberOfEdges() == 3);
            CHECK(graph.getTotalValue() == (arr4 + arr2 + arr1));
        }
    }
    SUBCASE("non-oriented graph")
    {
        gm::GraphMatrix<std::vector<int>> graph(false);
        graph.addVertex(arr1);
        graph.addVertex(arr3);
        graph.addVertex(arr3);
        graph.addVertex(arr2);
        graph.addEdge(0, 1, arr4);
        graph.addEdge(1, 2, arr2);
        graph.addEdge(0, 3, arr1);
        REQUIRE(graph.getNumberOfVertices() == 4);
        REQUIRE(graph.getNumberOfEdges() == 3);
        REQUIRE(graph.getTotalValue() == (arr4 + arr2 + arr1));
        SUBCASE("removing existent vertices")//after removing vertex indexes of all vertices edited(example: vertices: 0, 1, 2; remove(0); vertices: 0, 1;)
        {
            graph.removeVertex(0);
            graph.removeVertex(0);
            CHECK(graph.getNumberOfVertices() == 2);
            CHECK(graph.getNumberOfEdges() == 0);
            CHECK(graph.getTotalValue() == arr0);
        }
        SUBCASE("removing non-existent vertices")
        {
            graph.removeVertex(56);
            graph.removeVertex(18);
            graph.removeVertex(4);
            CHECK(graph.getNumberOfVertices() == 4);
            CHECK(graph.getNumberOfEdges() == 3);
            CHECK(graph.getTotalValue() == (arr4 + arr2 + arr1));
        }
        SUBCASE("removing existent edges")//during removal of an edge totalValue reduces the length, but its elements can differ from those which remained in other edges.
        {
            graph.removeEdge(0, 1);
            graph.removeEdge(1, 2);
            CHECK(graph.getNumberOfVertices() == 4);
            CHECK(graph.getNumberOfEdges() == 1);
            CHECK(graph.getTotalValue() == ((arr4 + arr2 + arr1) - arr4 - arr2));
            CHECK(graph.getTotalValue() != arr1);
        }
        SUBCASE("removing non-existent edges")
        {
            graph.removeEdge(0, 2);
            graph.removeEdge(15, 22);
            CHECK(graph.getNumberOfVertices() == 4);
            CHECK(graph.getNumberOfEdges() == 3);
            CHECK(graph.getTotalValue() == (arr4 + arr2 + arr1));
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
//tests for std::string