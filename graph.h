#ifndef GRAPH_H
#define GRAPH_H

#include "doubly_linked_list.h"
#include <vector>

using namespace std;

class Graph{
private:
  int num_vertex, num_edge;
  vector<DoublyLinkedList<int> > adjList;

public:
  // Constructor: initalize an empty graph with n vertices
  Graph(int n);
  // Destructor
  ~Graph();
  // Check whether vertex u is in graph
  bool is_member(int u);
  // Check if edge between vertex u and v is valid
  bool is_edge(int u, int v);
  // Print graph
  void print();
  // Add a new edge
  void add_edge(int u, int v);
  // Remove edge between vertex u and v
  void remove_edge(int u, int v);
  // Add a new vertex
  void add_vertex();
  // Remove vertex u
  void remove_vertex(int u);
  // Print all adjacent vertices of vertex u
  
};

#endif
