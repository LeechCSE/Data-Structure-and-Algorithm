#include "graph_final.cpp"
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

template <typename T>
struct Vertex{
  int id;
  T distance;
  Vertex(int i, T d) : id(i), distance(d){}
  bool operator>(Vertex<T> v) const{ return this->distance > v.distance; }
};

template <typename T>
Graph<T> init_graph(){
  Graph<T> g(9);
  
  map<int, vector<pair<int, T> > > edge_map;
  edge_map[1] = { {2, 2}, {5, 3} };
  edge_map[2] = { {1, 2}, {5, 5}, {4, 1} };
  edge_map[3] = { {4, 2}, {7, 3} };
  edge_map[4] = { {2, 1}, {3, 2}, {5, 2}, {6, 4}, {8, 5} };
  edge_map[5] = { {1, 3}, {2, 5}, {4, 2}, {8, 3} };
  edge_map[6] = { {4, 4}, {7, 4}, {8, 1} };
  edge_map[7] = { {3, 3}, {6, 4} };
  edge_map[8] = { {4, 5}, {5, 3}, {6, 1} };

  for (auto m : edge_map)
    for (auto p : m.second)
      g.add_edge(Edge<T>(m.first, p.first, p.second));

  return g;
}

template <typename T>
pair<vector<int>, int> dijkstra(Graph<T> g, int start, int target){
  priority_queue<Vertex<T>, vector<Vertex<T> >, greater<Vertex<T> > > min_heap;
  set<int> visited;
  
  vector<int> parent(g.vertices());
  vector<T> dist(g.vertices(), numeric_limits<T>::max());
  dist[start] = 0;
  min_heap.emplace(Vertex(start, dist[start]));

  while (!min_heap.empty()){
    Vertex<T> cur = min_heap.top();
    min_heap.pop();
    
    if (visited.find(cur.id) == visited.end()){
      visited.insert(cur.id);
      
      for (auto e : g.get_edges_of(cur.id)){
	if (visited.find(e.dst) == visited.end()){
	  if (dist[e.dst] > dist[cur.id] + e.weight){
	    dist[e.dst] = dist[cur.id] + e.weight;
	    parent[e.dst] = cur.id;
	    min_heap.emplace(Vertex(e.dst, dist[e.dst]));
	  }
	}
      }
    }
  }

  vector<int> path;
  int cur = target;
  while (cur != start){
    path.emplace_back(cur);
    cur = parent[cur];
  }
  path.emplace_back(start);
  reverse(path.begin(), path.end());
  
  return pair<vector<int>, int>(path, dist[target]);;
}

int main(){
  Graph<int> g = init_graph<int>();
  int start = 1;
  int target = 6;

  pair<vector<int>, int> p = dijkstra<int>(g, start, target);
  cout << "Shortest path of distance " << p.second << ": ";
  for (auto v : p.first)
    cout << v << " ";
  cout << endl;
  
  return 0;
}
