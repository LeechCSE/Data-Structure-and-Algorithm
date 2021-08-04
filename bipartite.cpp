#include "graph_final.cpp"
#include <iostream>
#include <map>
#include <stack>
#include <set>
#include <queue>

using namespace std;

template <typename T>
Graph<T> init_graph(){
  
  // Example 1: odd cycle (not bipartite)
  Graph<T> g(6);

  map<int, vector<pair<int, T> > > edge_map;
  edge_map[1] = { {2, 0}, {5, 0} };
  edge_map[2] = { {1, 0}, {3, 0} };
  edge_map[3] = { {2, 0}, {4, 0} };
  edge_map[4] = { {3, 0}, {5, 0} };
  edge_map[5] = { {1, 0}, {4, 0} };

  for (auto m : edge_map)
    for (auto p : m.second)
      g.add_edge(Edge<T>(m.first, p.first, p.second));
  
  /*    
  // Example 2: bipartite graph
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
  */
  return g;
}

template <typename T>
bool is_bipartite_dfs(Graph<T> g){
  stack<int> s;
  set<int> visited;
  vector<char> colors(g.vertices() + 1);
  char cur_color = 'B';
  s.push(1);
    
  while (!s.empty()){
    int cur = s.top();
    s.pop();

    if (visited.find(cur) == visited.end()){
      visited.insert(cur);
      colors[cur] = cur_color;
      cur_color = (cur_color == 'B') ? 'R' : 'B';
      
      for (auto e : g.get_edges_of(cur)){
	if (visited.find(e.dst) == visited.end())
	  s.push(e.dst);
      }
    }
    else{
      if (colors[cur] != cur_color)
	return false;
    }
  }
  
  return true;
}

template <typename T>
bool is_bipartite_bfs(Graph<T> g){
  queue<int> q;
  set<int> visited;
  vector<char> colors(g.vertices() + 1);
  char cur_color = 'B';
  q.push(1);
  colors[1] = cur_color;
  
  while (!q.empty()){
    int cur = q.front();
    q.pop();
    
    if (visited.find(cur) == visited.end()){
      visited.insert(cur);
      
      for (auto e : g.get_edges_of(cur)){
	if (visited.find(e.dst) == visited.end()){
	  q.push(e.dst);
	  colors[e.dst] = cur_color;
	}
      }
      cur_color = (cur_color == 'B') ? 'R' : 'B';
    }
    else{
      if (colors[cur] == cur_color)
	return false;
    }
  }
  
  return true;
}

int main(){
  Graph<int> g = init_graph<int>();
  
  cout << "DFS ver: ";
  if (is_bipartite_dfs<int>(g))
    cout << "This graph is bipartite" << endl;
  else
    cout << "This graph is not bipartite" << endl;
  
  cout << "BFS ver: ";
  if (is_bipartite_bfs<int>(g))
    cout << "This graph is bipartite" << endl;
  else
    cout << "This graph is not bipartite" << endl;
  
  return 0;
}
