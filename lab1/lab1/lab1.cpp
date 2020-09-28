#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "my_graph_matrix.h"
#include "my_graph_structure.h"
 
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
        SUBCASE("adding edge between added vertices")
        {
            graph.addEdge(0, 1, 100);
            graph.addEdge(1, 0, 6);
            graph.addEdge(0, 2, 48);
            CHECK(graph.getNumberOfVertices() == 3);
            CHECK(graph.getNumberOfEdges() == 3);
            CHECK(graph.getTotalValue() == 154);
        }
        SUBCASE("adding edge between non-existent vertices")
        {
            graph.addEdge(5, 7, 45);
            graph.addEdge(154, 362, 100);
            graph.addEdge(4, 44, 11);
            CHECK(graph.getNumberOfVertices() == 3);
            CHECK(graph.getNumberOfEdges() == 0);
            CHECK(graph.getTotalValue() == 0);
        }
        SUBCASE("adding already added edge")
        {
            graph.addEdge(0, 1, 100);
            graph.addEdge(0, 1, 6);
            graph.addEdge(1, 0, 48);
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
        SUBCASE("adding edge between added vertices")
        {
            graph.addEdge(0, 1, 100);
            graph.addEdge(1, 1, 6);
            graph.addEdge(0, 2, 48);
            CHECK(graph.getNumberOfVertices() == 3);
            CHECK(graph.getNumberOfEdges() == 3);
            CHECK(graph.getTotalValue() == 154);
        }
        SUBCASE("adding edge between non-existent vertices")
        {
            graph.addEdge(5, 7, 45);
            graph.addEdge(154, 362, 100);
            graph.addEdge(4, 44, 11);
            CHECK(graph.getNumberOfVertices() == 3);
            CHECK(graph.getNumberOfEdges() == 0);
            CHECK(graph.getTotalValue() == 0);
        }
        SUBCASE("adding already added edge")
        {
            graph.addEdge(0, 1, 100);
            graph.addEdge(0, 1, 6);
            graph.addEdge(1, 0, 48);
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
        graph.addEdge(1, 3, 100);
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
        graph.addEdge(1, 3, 100);
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
int main(int argc, char** argv) 
{
    doctest::Context context;



    // defaults
//    context.addFilter("test-case-exclude", "*math*"); // exclude test cases with "math" in their name
//    context.setOption("abort-after", 5);              // stop test execution after 5 failed assertions
//    context.setOption("order-by", "name");            // sort the test cases by their name

    context.applyCommandLine(argc, argv);

    // overrides
//    context.setOption("no-breaks", true);             // don't break in the debugger when assertions fail

    int res = context.run(); // run

    if (context.shouldExit()) // important - query flags (and --exit) rely on the user doing this
        return res;          // propagate the result of the tests

    int client_stuff_return_code = 0;
    // your program - if the testing framework is integrated in your production code

    return res + client_stuff_return_code; // the result from doctest is propagated here as well
}

