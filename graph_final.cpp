#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct Edge{
  int src, dst;
  T weight;
};

template <typename T>
class Graph{
public:
  // Constructor
  Graph(int n);
  // Return number of vertices
  int vertices();
  // Add a new edge
  void add_edge(Edge<T> e);
  // Return edges from vertex u
  vector<Edge<T> > get_edges_of(int u);
private:
  int num_vertex;
  vector<Edge<T> > edgeList;
};

// Constructor
template <typename T>
Graph<T>::Graph(int n) : num_vertex(n){}
// Return number of vertices
template <typename T>
int Graph<T>::vertices(){ return num_vertex; }
// Add a new edge
template <typename T>
void Graph<T>::add_edge(Edge<T> e){
  if (e.src >= 1 && e.dst >= 1 && e.src <= num_vertex && e.dst <= num_vertex)
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
