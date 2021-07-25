#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
 * Edge struct
 *   contains source vertex, destination vertex, and its weight
 */
struct Edge{
  int src, dst;
  int weight;
  Edge(int s, int d, int w) : src(s), dst(d), weight(w){}
  bool operator<(const Edge& e) const{
    if (this->src == e.src)
      return this->weight < e.weight;
    return this->src < e.src;
  }
  bool operator>(const Edge& e) const{ return this->weight > e.weight; }
};

class Graph{
public:
  // Constructor
  Graph(int n) : num_vertex(n){}
  // Return the number of vertices
  int vertices() const;
  // Return edge list
  vector<Edge> edges() const;
  // Check if vertex u is valid and in graph
  bool is_vertex(int u);
  // Add a new Edge into graph
  void add_edge(const Edge e);
  // Print all vertices with edges
  void print();
private:
  int num_vertex;
  vector<Edge> edgeList;
};
// Return the number of vertices
int Graph::vertices() const{ return num_vertex; }
// Return edge list
vector<Edge> Graph::edges() const{ return edgeList; }
// Check if vertex u is valid and in graph
bool Graph::is_vertex(int u){
  if (u < 1 || u > num_vertex)
    return false;

  for (auto e: edgeList){
    if (u != e.src || u != e.dst)
      return true;
  }
  
  return true;
}
// Add a new Edge into graph
void Graph::add_edge(const Edge e){
  if (is_vertex(e.src) && is_vertex(e.dst))
    edgeList.push_back(e);
}
// Print all vertices with edges
void Graph::print(){
  vector<Edge> tmp = edgeList;
  sort(tmp.begin(), tmp.end());

  for (auto it = tmp.begin(); it != tmp.end(); it++)
    cout << "(" << it->src << ")--" << it->weight << "--(" << it->dst << ")\n";
}

Graph minimum_spanning_tree(Graph g){
  Graph mst(g.vertices());
  priority_queue<Edge, vector<Edge>, greater<Edge> > edge_min_heap;
  
  for (auto e: g.edges())
    edge_min_heap.push(e);

  for (int i = 0; i < g.edges().size(); i++){
    Edge e = edge_min_heap.top();
    
    if (mst.is_vertex(e.src) && mst.is_vertex(e.dst)){
      cout << "skip: " << e.src << " " << e.dst << endl;
    }
    else{
      cout << "add" << endl;
      mst.add_edge(e);
    }

    edge_min_heap.pop();
  }

  return mst;
}

int main(){
  Graph g(8);
  //         Edge(s, d, w)
  g.add_edge(Edge(1, 2, 2));
  g.add_edge(Edge(1, 5, 3));
  g.add_edge(Edge(5, 8, 3));
  g.add_edge(Edge(5, 4, 2));
  g.add_edge(Edge(2, 4, 1));
  g.add_edge(Edge(8, 4, 5));
  g.add_edge(Edge(8, 6, 1));
  g.add_edge(Edge(4, 6, 4));
  g.add_edge(Edge(3, 4, 2));
  g.add_edge(Edge(3, 7, 3));
  g.add_edge(Edge(6, 7, 4));

  g.print();

  cout << "MST" << endl;
  Graph mst = minimum_spanning_tree(g);
  mst.print();
  
  return 0;
}
