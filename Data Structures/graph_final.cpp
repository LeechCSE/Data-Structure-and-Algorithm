#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct Edge{
  int src, dst;
  T weight;
  Edge(int s, int d, T w) : src(s), dst(d), weight(w){}
};

template <typename T>
class Graph{
public:
  // Constructor
  Graph();
  Graph(int n);
  // Set the number of vertices and edges
  void reserve(int n, int m);
  // Return number of vertices
  int vertices();
  // Add a new edge
  void add_edge(Edge<T> e);
  // Return edges from vertex u
  vector<Edge<T> > get_edges_of(int u);
  // Return edge list
  vector<Edge<T> > get_edges();
private:
  int num_vertex;
  vector<Edge<T> > edgeList;
};

// Constructor
template <typename T>
Graph<T>::Graph(){}
template <typename T>
Graph<T>::Graph(int n) : num_vertex(n){}
// Set the number of vertices
template <typename T>
void Graph<T>::reserve(int n, int m){ 
	num_vertex = n;
	edgeList.reserve(m);
}
// Return number of vertices
template <typename T>
int Graph<T>::vertices(){ return num_vertex; }
// Add a new edge
template <typename T>
void Graph<T>::add_edge(Edge<T> e){
  if (e.src >= 0 && e.dst >= 0 && e.src <= num_vertex && e.dst <= num_vertex)
    edgeList.emplace_back(e);
}
// Return edges from vertex u
template <typename T>
vector<Edge<T> > Graph<T>::get_edges_of(int u){
  vector<Edge<T> > rtn;
  for (auto e : edgeList)
    if (e.src == u)
      rtn.emplace_back(e);

  return rtn;
}
// Return edge list
template <typename T>
vector<Edge<T> > Graph<T>::get_edges(){ return edgeList; }