// Roni Naftalovich 319049060, roni100400100400@gmail.com

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

namespace ariel
{
    class Graph
    {
    private:
        vector<vector<int>> adjMatrix;
        size_t numVertices;
        bool isDirected;
        bool isWeighted;

    public:
        // Constructor that getting  if the graph is directed or not
        Graph(bool isDirected); // default constructor is not directed

        size_t getNumVertices() const;
        
        //getter to adjMatrix
        vector<vector<int>> getAdjMatrix() const;
        
        //getter to isDirected
        bool getisDirected() const;


        // Function to load graph from an adjacency matrix, like a set function
        void loadGraph(vector<vector<int>> &matrix); // passing it not by reference because we don't want to change it the orginal matrix

        // Function to print the adjacency matrix
        void printGraph();

        //getter to isWeighted
        bool getisWeighted();

        void isDirectedAndWeighted(vector<vector<int>> &matrix); 

        // Arithmetic operators
        vector<vector<int>> operator+(const Graph& other) const;
        void operator+();
        void operator+=(const Graph& other);
        void operator-();
        vector<vector<int>> operator-(const Graph& other) const;
        void operator-=(const Graph& other);

        // Comparison operators
        bool operator==(const Graph& other) const;
        bool operator!=(const Graph& other) const;
        bool operator<(const Graph& other) const;
        bool operator<=(const Graph& other) const;
        bool operator>(const Graph& other) const;
        bool operator>=(const Graph& other) const;

        // Increasing/decreasing 1 operators
        
        void operator++ ();
        void operator-- ();

        //Mul weights in integer
        void operator*=(int a);

        // Multiplication operator
        vector<vector<int>> operator*(const Graph& other);

        bool isContainedIn(const Graph& other) const; // Helper function
        
        //void printingGraph() const;

        size_t numEdges() const; // Helper function
    

        // Friend function for printing
        friend std::ostream &operator<<(ostream& os, const Graph& graph);
        };

        

    };

#endif // GRAPH_HPP