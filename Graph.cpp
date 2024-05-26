// Roni Naftalovich 319049060, roni100400100400@gmail.com

#include <iostream>
#include <vector>
#include "Graph.hpp"

using namespace std;
using namespace ariel;


Graph::Graph(bool isDirected)
{
    this->isDirected = isDirected;
    this->isWeighted = false; //temporarly
    this->numVertices = 0;
}

size_t Graph::getNumVertices() const
{
    return this->numVertices;
}

vector<vector<int>> Graph::getAdjMatrix() const
{
    return this->adjMatrix;
}

bool Graph::getisDirected() const
{
    return this->isDirected;
}


void Graph::loadGraph(vector<vector<int>> &matrix)
{
    if (matrix.size() !=  matrix[0].size() || matrix.size()==0) {
            cerr << "Invalid adjacency matrix - not square" << endl;
            return;
        }

    this->numVertices = matrix.size();
    this->adjMatrix = matrix;
    for (size_t i = 0; i < adjMatrix.size(); i++)
    {
        for (size_t j = 0; j < adjMatrix[i].size(); j++)
        {
            if (i == j && adjMatrix[i][j] != 0)
            {
               cerr << "Invalid adjacency matrix - diagonal must be zero "<< endl;
               return;
            }
        }
    }
    this->isDirectedAndWeighted(matrix);
}

void Graph::printGraph()
{
    if (this->isDirected==true)
    {
        cout << "The graph is directed, containing " << this->numVertices << " vertices" << endl;
    }
    else
    {
        cout << "The graph is undirected, containing " << this->numVertices << " vertices" << endl;
    }
}

bool Graph::getisWeighted(){
    return this->isWeighted;
}

void Graph::isDirectedAndWeighted(vector<vector<int>> &matrix) // for graph being undirected it first need to be symmetric
{
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            if (this->isDirected== false && matrix[i][j] != matrix[j][i])
            {
                this->isDirected= true;
            }
            if(this->isWeighted == false && matrix[i][j] !=0 && matrix[i][j]!=1)
            {
                this->isWeighted=true;
            }
        }
    }
    return;
}

// Arithmetic operators
 vector<vector<int>> Graph::operator+(const Graph& other) const {
    if (this->numVertices != other.numVertices) {
        throw invalid_argument("Graphs must be of the same size.");
    }
    vector<vector<int>> resultMatrix(this->numVertices, vector<int>(this->numVertices, 0));
    for (size_t i = 0; i < resultMatrix.size(); i++) {
        for (size_t j = 0; j < resultMatrix[i].size(); j++) {
            resultMatrix[i][j] = this->adjMatrix[i][j]+ other.adjMatrix[i][j];
        }
    }
    return resultMatrix;
}

void Graph::operator+() {
    return;
}

void Graph::operator+=(const Graph& other) {
    if (this->numVertices != other.numVertices) {
        throw invalid_argument("Graphs must be of the same size.");
    }
    for (size_t i = 0; i < this->adjMatrix.size(); i++) {
        for (size_t j = 0; j < this->adjMatrix[i].size(); j++) {
            this->adjMatrix[i][j] += other.adjMatrix[i][j];
        }
    }
}

void Graph::operator-() {
    for (size_t i = 0; i < this->numVertices; i++) {
        for (size_t j = 0; j < this->numVertices; j++) {
            this->adjMatrix[i][j] = - this->adjMatrix[i][j];
        }
    }
    
}

vector<vector<int>> Graph::operator-(const Graph& other) const {
    if (this->numVertices != other.numVertices) {
        throw invalid_argument("Graphs must be of the same size.");
    }
    vector<vector<int>> resultMatrix(this->numVertices, vector<int>(this->numVertices, 0));
    for (size_t i = 0; i < resultMatrix.size(); i++) {
        for (size_t j = 0; j < resultMatrix[i].size(); j++) {
            resultMatrix[i][j] -= other.adjMatrix[i][j];
        }
    }
    return resultMatrix;
}

void Graph::operator-=(const Graph& other) {
    if (this->numVertices != other.numVertices) {
        throw invalid_argument("Graphs must be of the same size.");
    }
    for (size_t i = 0; i < this->adjMatrix.size(); i++) {
        for (size_t j = 0; j < this->adjMatrix[i].size(); j++) {
            this->adjMatrix[i][j] -= other.adjMatrix[i][j];
        }
    }
}

// Comparison operators
bool Graph::operator==(const Graph& other) const {
    if(this->numVertices != other.numVertices) {
        return false;
        }
    for (size_t i = 0; i < this->numVertices; i++)
    {
        for (size_t j = 0; j < this->numVertices; j++)
        {
            if(this->adjMatrix[i][j] != other.adjMatrix[i][j]){
                return false;
            }
        }
        
    }
    return true;
}

bool Graph::operator!=(const Graph& other) const {
    bool flag = this->operator==(other);
    return !flag;
}


bool Graph::operator<(const Graph& other) const {
    if (this->isContainedIn(other)) return true;
    if (other.isContainedIn(*this)) return false;
    if (this->numEdges() < other.numEdges()) return true;
    if (this->numEdges() > other.numEdges()) return false;
    return this->numVertices < other.numVertices;
}

bool Graph::operator<=(const Graph& other) const {
    return (this->operator<(other) || this->operator==(other));
}

bool Graph::operator>(const Graph& other) const {
    if (other.isContainedIn(*this)) return true;
    if (this->isContainedIn(other)) return false;
    if (this->numEdges() > other.numEdges()) return true;
    if (this->numEdges() < other.numEdges()) return false;
    return this->numVertices > other.numVertices;
}
bool Graph::operator>=(const Graph& other) const {
    return (this->operator>(other) || this->operator==(other));
}

void Graph::operator++(){
    for (size_t i = 0; i < this->numVertices; i++)
    {
        for (size_t j = 0; j < this->numVertices; j++)
        {
            if (j!=i)
            {
                this->adjMatrix[i][j]+=1;
            }
            
        }
        
    } 
}
void Graph::operator-- (){
       for (size_t i = 0; i < this->numVertices; i++)
    {
        for (size_t j = 0; j < this->numVertices; j++)
        {
            if (j!=i)
            {
                this->adjMatrix[i][j]-=1;
            }
            
        }
        
    } 
}

void Graph::operator*=(int a){
    for (size_t i = 0; i < this->numVertices; i++)
    {
        for (size_t j = 0; j < this->numVertices; j++)
        {
            this->adjMatrix[i][j]*= a;
        }
        
    }
    
}

// Multiplication operator
vector<vector<int>> Graph::operator*(const Graph& other) {
    if (this->numVertices != other.numVertices) {
        throw std::invalid_argument("Graphs must be of the same size.");
    }

    vector<vector<int>> resultMatrix(this->numVertices, vector<int>(this->numVertices, 0));

    for (size_t i = 0; i < this->numVertices; i++) {
        for (size_t j = 0; j < this->numVertices; j++) {
             if(i==j){
                    continue;
                }
            for (size_t k = 0; k < this->numVertices; k++) {
               
                resultMatrix[i][j] += this->adjMatrix[i][k] * other.adjMatrix[k][j];
            }
        }
    }

    return resultMatrix;
}

bool Graph::isContainedIn(const Graph& other) const {
    if (this->numVertices > other.numVertices) return false;

    for (size_t i = 0; i <= other.numVertices - this->numVertices; i++) {
        for (size_t j = 0; j <= other.numVertices - this->numVertices; j++) {
            bool isContained = true;
            for (size_t x = 0; x < this->numVertices && isContained; x++) {
                for (size_t y = 0; y < this->numVertices && isContained; y++) {
                    if (this->adjMatrix[x][y] != other.adjMatrix[i + x][j + y]) {
                        isContained = false;
                    }
                }
            }
            if (isContained) return true;
        }
    }
    return false;
}

// Function to count the number of edges
size_t Graph::numEdges() const {
    size_t count = 0;
    for (const auto& row : this->adjMatrix) {
        for (int val : row) {
            if (val != 0) count++;
        }
    }
    return count;
}

// Print graph as a table with vertices and weights
// void Graph::printingGraph() const {
//     std::cout << "  |";
//     for (size_t i = 0; i < this->numVertices; ++i) {
//         std::cout <<i << "| ";
//     }
//     std::cout << std::endl;

//     for (size_t i = 0; i < this->numVertices; ++i) {
//         std::cout << i << "| ";
//         for (size_t j = 0; j < this->numVertices; ++j) {
//             if (this->adjMatrix[i][j]<0)
//             {
//                 std::cout << this->adjMatrix[i][j] << " ";
//             }else{
            
//             std::cout << this->adjMatrix[i][j] << "  ";
//         }}
//         std::cout << std::endl;
//     }
// }
// Friend function for printing
std::ostream &ariel::operator<<(ostream& os, const Graph& graph) {
    os << "Number of vertices: " << graph.numVertices << std::endl;
    os << "Graph is " << (graph.isDirected ? "directed" : "undirected") << std::endl;
    os << "Graph is " << (graph.isWeighted ? "weighted" : "unweighted") << std::endl;
    for (const auto& row : graph.adjMatrix) {
        for (int val : row) {
            if (val>9 || val <0){
                os << val << " ";
            }else{
            os << val << "  ";
        }}
        os << endl;
    }
    return os;
}


