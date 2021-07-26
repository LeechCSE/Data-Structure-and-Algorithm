#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Disjoint_set{
public:
  // Constructor
  Disjoint_set(int n);
  // Add a new set having id = x into forest
  void make_set(int x);
  // Return root of tree starting node x
  int find(int x);
  // Combine two trees that have node x and y by their rank
  void union_sets(int x, int y);
private:
  struct Node{
    int id, rank, parent;
    Node(int i, int r, int p) : id(i), rank(r), parent(p){}
  };
  vector<Node> forest;
};
// Constructor
Disjoint_set::Disjoint_set(int n){
  forest.reserve(n);
  for (int i = 0; i <= n; i++)
    forest.emplace_back(Node(i, 0, i));
}
// Add a new set having id = x into forest
void Disjoint_set::make_set(int x){
  forest.emplace_back(Node(x, 0, x));
}
// Return root of tree having node x
int Disjoint_set::find(int x){
  auto it = find_if(forest.begin(), forest.end(),
		    [x](Node n){ return n.id == x; });
  int id_found = (*it).id;
  
  while (id_found != forest[id_found].parent)
    id_found = forest[id_found].parent;

  return id_found;
}
// Combine two trees that have node x and y
void Disjoint_set::union_sets(int x, int y){
  int root_x = find(x);
  int root_y = find(y);

  if (root_x == root_y) // same tree
    return;
  
  if (forest[root_x].rank >= forest[root_y].rank){
    forest[root_y].parent = forest[root_x].parent;
    forest[root_x].rank++;
  }
  else{
    forest[root_x].parent = forest[root_y].parent;
    forest[root_y].rank++;
  }
}

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
  // minimum spanning tree for return
  Graph mst(g.vertices());
  // min-heap of weight of edge
  priority_queue<Edge, vector<Edge>, greater<Edge> > edge_min_heap;
  for (auto e: g.edges())
    edge_min_heap.push(e);
  // disjoint set for checking being cyclic
  Disjoint_set ds(g.vertices());
  for (int i = 1; i <= g.vertices(); i++)
    ds.make_set(i);
  
  for (int i = 0; i < g.edges().size(); i++){
    Edge e = edge_min_heap.top();
    edge_min_heap.pop();

    if (ds.find(e.src) != ds.find(e.dst)){
      mst.add_edge(e);
      ds.union_sets(e.src, e.dst);
    }
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
