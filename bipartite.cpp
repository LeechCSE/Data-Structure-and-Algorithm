#include "graph_final.cpp"
#include <iostream>
#include <map>
#include <stack>
#include <set>

using namespace std;

template <typename T>
Graph<T> init_graph(){
  Graph<T> g(10);

  map<int, vector<pair<int , T> > > edge_map;
  edge_map[1] = { {2, 0} };
  edge_map[2] = { {1, 0}, {3, 0}, {8, 0} };
  edge_map[3] = { {2, 0}, {4, 0} };
  edge_map[4] = { {3, 0}, {6, 0} };
  edge_map[5] = { {7, 0}, {9, 0} };
  edge_map[6] = { {4, 0} };
  edge_map[7] = { {5, 0} };
  edge_map[8] = { {2, 0}, {9, 0} };
  edge_map[9] = { {5, 0}, {8, 0} };

  for (auto m : edge_map)
    for (auto p : m.second)
      g.add_edge(Edge<T>(m.first, p.first, p.second));

  return g;
}

template <typename T>
bool is_bipartite(Graph<T> g){
  stack<int> s;
  set<int> visited;
  map<int, char> bi_map;
  bi_map[1] = 'B';
  s.push(1);
  
  char parent_color = bi_map[1];
  while (!s.empty()){
    int cur = s.top();
    s.pop();   
    
    if (visited.find(cur) == visited.end()){
      visited.insert(cur);
      
      if (cur != 1){
	bi_map[cur] = (parent_color == 'B') ? 'R' : 'B';
	parent_color = bi_map[cur];
      }
      
      for (auto e : g.get_edges_of(cur))
	if (visited.find(e.dst) == visited.end())
	  s.push(e.dst);
    }
    else
      if (bi_map[cur] != parent_color)
	return false;
  }
  
  return true;
}

int main(){
  Graph<int> g = init_graph<int>();

  if (is_bipartite<int>(g))
    cout << "This graph is bipartite" << endl;
  else
    cout << "This graph is not bipartite" << endl;
  
  return 0;
}
