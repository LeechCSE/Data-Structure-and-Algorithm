#ifndef STL_GRAPH_H
#define STL_GRAPH_H

#include <vector>
#include <list>

using namespace std;

class Graph{
 private:
  int num_vertex, num_edge;
  vector<list<int> > adjList;
  vector<bool> visited;
 public:
  // Constructor: initialize graph with n vertices
  Graph(int n);
  // Destructor
  ~Graph();
  // Print adjacency list
  void print();
  // Check if vertex u is in graph
  bool is_vertex(int u);
  // Check if edge between vertex u and v is in graph
  bool is_edge(int u, int v);
  // Add a new edge between vertex u and v
  void add_edge(int u, int v);
  // Add a vertex u
  void add_vertex(int u);
  // Remove edge between vertex u and v
  void remove_edge(int u, int v);
  // Breath-First-Search(BFS)
  void bfs(int u);
  // Depth-First-Search(DFS) recursive version
  void dfs_rec(int u);
  // Depth-First-Search(DFS) iterative version
  void dfs_itr(int u);
};

#endif
