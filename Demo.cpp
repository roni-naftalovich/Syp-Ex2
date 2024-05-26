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

ariel::Graph g1(true);
ariel::Graph g2(true);
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
g2.loadGraph(graph9);
g1.loadGraph(graph7);


cout << "Testing assignment 2 operators: " << endl;
cout<< "" <<endl;
cout<< "Original Graph g:" << endl;
cout << g << endl;
cout<< "Original Graph g1:" << endl;
cout << g1 << endl;
cout<< "Original Graph g2:" << endl;
cout << g2 << endl;
cout << "Graph g2 > Graph g1: " << (g2>g1) << endl;
cout << "Graph g1 > Graph g2: " << (g1>g2) << endl;
cout << "Graph g2 == Graph g1: " << (g2==(g1)) << endl;
cout << "Graph g >= Graph g1: " << (g>=g1) << endl;
cout << "Graph g <= Graph g1: " << (g<=g1) << endl;
cout << "Graph g != Graph g1: " << (g!=g1) << endl;
ariel::Graph operatorResult(g2.getisDirected());
vector<vector<int>> graph8 = g2 *g1;
operatorResult.loadGraph(graph8);
cout<< "The graph created by multiplying Graph g2 and Graph g1 is:" << endl;
cout<< operatorResult << endl;
cout <<"Trying to multiply g (3X3) and g1 (5X5): " << endl;
try{
graph8= g * g1;
}
catch(invalid_argument &e){
    cout << e.what() << endl;
}
cout<< "The graph created by adding Graph g2 and Graph g1 is:" << endl;
graph8 = g2+(g1);
operatorResult.loadGraph(graph8);
cout<< operatorResult << endl;
cout << "Graph g1 += Graph g2:" << endl;
g1+=(g2);
cout << g1 << endl;
cout << "Graph g2 ++ : " << endl;
++g2;
cout<< g2 <<endl;
--g2;
cout << "Graph g2 -- : " << endl;
--g2;
cout<<g2<<endl;
++g2;
cout<< "Graph g2*=2:" <<endl;
g2*= 2;
cout<<g2<< endl;

}