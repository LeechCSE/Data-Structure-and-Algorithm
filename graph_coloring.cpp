#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

struct Edge{
  int src, dst;
  Edge(int s, int d) : src(s), dst(d){}
};

class Graph{
public:
  // Constructor
  Graph(int n);
  // Return the number of vertices
  int vertices();
  // Return the edge list
  vector<Edge> edges();
  // Return all edges from vertex u
  vector<Edge> edges_of(int u);
  // Add a new edge
  void add_edge(Edge e);
private:
  int num_vertex;
  vector<Edge> edgeList;
};
// Constructor
Graph::Graph(int n) : num_vertex(n){}
// Return the number of vertices
int Graph::vertices(){ return num_vertex; }
// Return the edge list
vector<Edge> Graph::edges(){ return edgeList; }
// Return all edges from vertex u
vector<Edge> Graph::edges_of(int u){
  vector<Edge> rtn;
  for (auto e: edgeList){
    if (e.src == u)
      rtn.emplace_back(e);
  }

  return rtn;
}
// Add a new edge
void Graph::add_edge(Edge e){
  if (e.src < 1 || e.src > num_vertex || e.dst < 1 || e.dst > num_vertex)
    return;
  
  edgeList.emplace_back(e);
  edgeList.emplace_back(Edge(e.dst, e.src));
}

unordered_map<int, string> color_map = {
  {1, "Red"},
  {2, "Orange"},
  {3, "Yellow"},
  {4, "Green"},
  {5, "Blue"},
  {6, "Navy"}
};

// Color all vertices
vector<int> color(Graph g){
  vector<int> vertex_color(g.vertices(), -1); // -1 as uncolored yet

  for (int i = 1; i <= g.vertices(); i++){ // for all vertices
    vector<int> adj_color; // get adjacent vertices' color
    for (auto e: g.edges_of(i))
      adj_color.emplace_back(vertex_color[e.dst - 1]);

    int cur;
    for (cur = 1; cur <= color_map.size(); cur++){ // get unused color
      if (find(adj_color.begin(), adj_color.end(), cur) == adj_color.end())
	break;
    }
    vertex_color[i - 1] = cur;
  }

  return vertex_color;
}

int main(){
  Graph g(8);
  g.add_edge(Edge(1, 2));
  g.add_edge(Edge(1, 5));
  g.add_edge(Edge(5, 8));
  g.add_edge(Edge(5, 4));
  g.add_edge(Edge(2, 4));
  g.add_edge(Edge(2, 5));
  g.add_edge(Edge(8, 4));
  g.add_edge(Edge(8, 6));
  g.add_edge(Edge(4, 6));
  g.add_edge(Edge(3, 4));
  g.add_edge(Edge(3, 7));
  g.add_edge(Edge(6, 7));

  vector<int> vertex_color = color(g);
  for (int i = 0; i < g.vertices(); i++){
    cout << "Vertex " << i + 1 << ": " << color_map[vertex_color[i]] << endl;
  }
		  
  return 0;
}
