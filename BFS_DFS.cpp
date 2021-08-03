#include "graph_final.cpp"
#include <map>
#include <queue>
#include <stack>
#include <set>

using namespace std;

template <typename T>
Graph<T> init_graph(){
  Graph<T> g(9);

  map<int, vector<pair<int, T> > > edge_map;
  edge_map[1] = { {2, 0}, {5, 0} };
  edge_map[2] = { {1, 0}, {4, 0}, {5, 0} };
  edge_map[3] = { {4, 0}, {7, 0} };
  edge_map[4] = { {2, 0}, {3, 0}, {5, 0}, {6, 0}, {8, 0} };
  edge_map[5] = { {1, 0}, {2, 0}, {4, 0}, {8, 0} };
  edge_map[6] = { {4, 0}, {7, 0}, {8, 0} };
  edge_map[7] = { {3, 0}, {6, 0} };
  edge_map[8] = { {4, 0}, {5, 0}, {6, 0} };

  for (auto el_map : edge_map){
    for (auto p : el_map.second){
      g.add_edge(Edge<T>(el_map.first, p.first, p.second));
    }
  }

  return g;
}

template <typename T>
vector<int> BFS(Graph<T> g, int start){
  queue<int> q;
  set<int> visited;
  vector<int> path;
  q.push(start);

  while (!q.empty()){
    int cur = q.front();
    q.pop();

    if (visited.find(cur) == visited.end()){
      visited.insert(cur);
      path.emplace_back(cur);

      for (auto edge : g.get_edges_of(cur))
	if (visited.find(edge.dst) == visited.end())
	  q.push(edge.dst);
    }
  }

  return path;
}

template <typename T>
vector<int> DFS(Graph<T> g, int start){
  stack<int> s;
  set<int> visited;
  vector<int> path;
  s.push(start);

  while (!s.empty()){
    int cur = s.top();
    s.pop();
    if (visited.find(cur) == visited.end()){
      visited.insert(cur);
      path.emplace_back(cur);
      
      for (auto edge : g.get_edges_of(cur))
	if (visited.find(edge.dst) == visited.end())
	  s.push(edge.dst);
    }
  }

  return path;
}

int main(){
  Graph<int> g = init_graph<int>();
  for (auto v : BFS(g, 1))
    cout << v << " ";
  cout << endl;

  for (auto v : DFS(g, 1))
    cout << v << " ";
  cout << endl;
  
  return 0;
}
