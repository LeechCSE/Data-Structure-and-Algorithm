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
  vector<Edge> edges_of(int u) const;
  // Return degree of vertex u
  int degree(int u) const;
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
vector<Edge> Graph::edges_of(int u) const{
  vector<Edge> rtn;
  for (auto e: edgeList){
    if (e.src == u)
      rtn.emplace_back(e);
  }

  return rtn;
}
// Return degree of vertex u
int Graph::degree(int u) const{
  return edges_of(u).size();
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
// Welsh-Powell coloring
vector<int> wp_color(Graph g){
  vector<int> colored(g.vertices(), -1);
  vector<int> v_by_degree;
  for (int i = 1; i <= g.vertices(); i++)
    v_by_degree.emplace_back(i);
  sort(v_by_degree.begin(), v_by_degree.end(),
       [g](int x, int y){ return g.degree(x) > g.degree(y); });
  
  for (auto cur : v_by_degree){
    if (colored[cur - 1] == -1){
      vector<Edge> adjs = g.edges_of(cur);
      vector<int> adj_colors(adjs.size()); 
      for (auto e: adjs)
	adj_colors.emplace_back(colored[e.dst - 1]);
      
      int unused; // Red at start
      for (unused = 1; unused <= color_map.size(); unused++){
	auto it = find(adj_colors.begin(), adj_colors.end(), unused);
	if (it == adj_colors.end())
	  break;
      }
      colored[cur - 1] = unused;
      
      for (auto cur2 : v_by_degree){
	if (colored[cur2 - 1] == -1){
	  vector<Edge> adjs2 = g.edges_of(cur2);
	  vector<int> adj_colors2(adjs2.size()); 
	  for (auto e: adjs2)
	    adj_colors2.emplace_back(colored[e.dst - 1]);
	  
	  auto it2 = find(adj_colors2.begin(), adj_colors2.end(), unused);
	  if (it2 == adj_colors2.end()){
	    colored[cur2 - 1] = unused;
	  }
	}
      }
    }
  }
  return colored;
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

  cout << "Normal coloring" << endl;
  vector<int> vertex_color = color(g);
  for (int i = 0; i < g.vertices(); i++)
    cout << "Vertex " << i + 1 << ": " << color_map[vertex_color[i]] << endl;
  cout << endl;
  
  cout << "Welsh-Powell coloring" << endl;
  vector<int> colored = wp_color(g);
  for (int i = 0; i < g.vertices(); i++)
    cout << "Vertex " << i + 1 << ": " << color_map[colored[i]] << endl;
  
  return 0;
}
