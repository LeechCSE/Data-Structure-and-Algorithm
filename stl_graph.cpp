#include "stl_graph.h"
#include <iostream>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

// Constructor: initialize graph with n vertices
Graph::Graph(int n){
  num_vertex = n;
  num_edge = 0;
  for (int i = 0; i < n; i++){
    adjList.push_back(list<int>());
    visited.push_back(false);
  }
}
// Destructor
Graph::~Graph(){}
// Print adjacency list
void Graph::print(){
  for (int i = 0; i < num_vertex; i++){
    cout << "Node " << i << ": ";
    for (list<int>::iterator it = adjList[i].begin(); it != adjList[i].end(); it++){
      cout << *it << " ";
    }
    cout << endl;
  }
}
// Check if vertex u is graph
bool Graph::is_vertex(int u){
  if (u < 0 || u > (num_vertex - 1))
    return false;
  else
    return true;
}
// Check if edge between vertex u and v is in graph
bool Graph::is_edge(int u, int v){
  
  list<int>::iterator it = find(adjList[u].begin(), adjList[u].end(), v);
  if (it != adjList[u].end())
    return true;
  else
    return false;
}
// Add a new edge between vertex u and v
void Graph::add_edge(int u, int v){
  if (!is_vertex(u) || !is_vertex(v))
    return;
  if (is_edge(u, v))
    return;
  
  adjList[u].push_back(v);
  adjList[v].push_back(u);
  num_edge++;
}
// Add a new vertex
void Graph::add_vertex(int u){
  if (is_vertex(u))
    return;

  adjList.push_back(list<int>());
  num_vertex++;
}

int main(){
  Graph g(5);
  g.add_edge(0, 2);
  g.add_edge(0, 3);
  g.add_edge(3, 1);
  g.add_vertex(5);
  //  g.remove_edge(1, 3);
  g.add_edge(5, 1);
  g.add_edge(5, 4);
  g.add_edge(3, 5);
  g.print();
    
  return 0;
}
