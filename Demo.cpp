// Roni Naftalovich 319049060, roni100400100400@gmail.com

#include "Graph.hpp"
#include "Algorithms.hpp"
using ariel::Algorithms;

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <climits>
#include <queue>
#include <stack>
#include <algorithm>
#include "Graph.hpp"
#include "Algorithms.hpp"

using namespace std;


int main()
{
    ariel::Graph g(false);
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph); // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 3 vertices and 2 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    cout << Algorithms::shortestPath(g, 0, 2) << endl; // Should print: 0->1->2.
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
    Algorithms::isBipartite(g);        // Should print: "The graph is bipartite: A={0, 2}, B={1}."

    // 5x5 matrix that represents a non-connected graph with a cycle.
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph2); // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 5 vertices and 4 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
    cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: "-1" (there is no path between 0 and 4).
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "The cycle is: 0->1->2->0".
    Algorithms::isBipartite(g);        // Should print: "0" (false).

    ariel::Graph g2(false);
    // 5x5 matrix that reprsents a connected weighted graph.
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g2.loadGraph(graph3); // Load the graph to the object.

    g2.printGraph();                                    // Should print: "Graph with 5 vertices and 4 edges."
    cout << Algorithms::isConnected(g2) << endl;        // Should print: "1" (true).
    cout << Algorithms::shortestPath(g2, 0, 4) << endl; // Should print: 0->1->2->3->4.
    cout << Algorithms::isContainsCycle(g2) << endl;    // Should print: "0" (false). should print 1
    Algorithms::isBipartite(g2);        // Should print: "The graph is biparpite: A={0, 2, 4}, B={1, 3}."

    // 5x4 matrix that reprsents invalid graph.
    vector<vector<int>> graph4 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    try
    {
        g2.loadGraph(graph4); // Load the graph to the object.
    }
    catch (const std::invalid_argument &e)
    {
        // beacuse we it to be undirected but the matrix is not symmetric (more it is not square, it will fall in the beggining)
        cout << e.what() << endl; // Should print: "The graph is not directed."
    }

    ariel::Graph g3(true);
    vector<vector<int>> graph5= {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    try
    {
        g3.loadGraph(graph5); // Load the graph to the object.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print: "Invalid graph: The graph is not a square matrix."
    }

    ariel::Graph g4(true);
    std::vector<std::vector<int>> graph6 = {
    {0, 4, -1, 0, 0},
    {0, 0, 0, 3, 0},
    {0, -1, 0, -2, 0},
    {-2, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
};
g4.loadGraph(graph6);
g4.printGraph();

    cout << Algorithms::isConnected(g4) << endl;        // Should print: "1" (true).
    cout << Algorithms::shortestPath(g4, 0, 4) << endl; // Should print: 0->1->2->3->4.
    cout << Algorithms::isContainsCycle(g4) << endl; 
    Algorithms::negativeCycle(g4);

ariel::Graph g5(true);
ariel::Graph g6(true);
std::vector<std::vector<int>> graph7 = {
    {0, 2, 3, 0, 0},
    {0, 0, 0, 3, 0},
    {0, 3, 0, 1, 0},
    {2, 0, 0, 0, 0},
    {0, 0, 1, 6, 0}
};
std::vector<std::vector<int>> graph9 = {
    {0, 4, 1, 0, 0},
    {0, 0, 0, 3, 0},
    {0, 1, 0, 2, 0},
    {2, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
};
g6.loadGraph(graph9);
g5.loadGraph(graph7);
cout << "" << endl;


cout << "Testing assignment 2 operators: " << endl;
cout << "" << endl;
cout<< "Original Graph g5:" << endl;
g5.printGraph();
g5.printingGraph();
cout<< "Original Graph g6:" << endl;
g6.printGraph();
g6.printingGraph();
cout << "Graph g6 > Graph g5: " << (g6.operator>(g5)) << endl;
cout << "Graph g5 > Graph g6: " << (g5.operator>(g6)) << endl;
cout << "Graph g6 == Graph g5: " << (g6.operator==(g5)) << endl;
ariel::Graph operatorResult(g6.getisDirected());
vector<vector<int>> graph8 = g6.operator*(g5);
operatorResult.loadGraph(graph8);
cout<< "The graph created by multiplying Graph g6 and Graph g5 is:" << endl;
operatorResult.printGraph();
operatorResult.printingGraph();
cout<< "The graph created by adding Graph g6 and Graph g5 is:" << endl;
graph8 = g6.operator+(g5);
operatorResult.loadGraph(graph8);
operatorResult.printingGraph();
cout << "Graph g5 += Graph g6:" << endl;
g5.operator+=(g6);
g5.printingGraph();
cout << "Graph g6 ++ : " << endl;
g6.operator++();
g6.printingGraph();
}