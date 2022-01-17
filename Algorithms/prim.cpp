#include "graph_final.cpp"
#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <set>

using namespace std;

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
struct Vertex{
  int id, parent;
  T distance;
  Vertex(int i, int p, T d) : id(i), parent(p), distance(d){}
  bool operator>(const Vertex v) const{ return this->distance > v.distance; }
};

template <typename T>
pair<vector<int>, Graph<T> > prim(Graph<T> g, int start){
  priority_queue<Vertex<T>, vector<Vertex<T> >, greater<Vertex<T> > > min_heap;
  vector<T> dist(g.vertices(), numeric_limits<T>::max());
  set<int> visited;
  vector<int> path;
  Graph<T> mst(g.vertices());
  
  min_heap.emplace(Vertex(start, 0, 0));
  
  while (!min_heap.empty()){
    Vertex<T> cur = min_heap.top();
    min_heap.pop();

    if (visited.find(cur.id) == visited.end()){
      visited.insert(cur.id);
      path.emplace_back(cur.id);
      mst.add_edge(Edge<T>(cur.parent, cur.id, dist[cur.id]));
      mst.add_edge(Edge<T>(cur.id, cur.parent, dist[cur.id]));
      
      for (auto e : g.get_edges_of(cur.id)){
	if (e.weight < dist[e.dst]){
	  if (visited.find(e.dst) == visited.end()){
	    dist[e.dst] = e.weight;
	    min_heap.emplace(Vertex<T>(e.dst, cur.id, dist[e.dst]));
	  }
	}
      }
    }
  }

  return pair<vector<int>, Graph<T> >(path, mst);
}

int main(){
  Graph<int> g = init_graph<int>();
  cout << "INPUT" << endl;
  for (int i = 1; i < g.vertices(); i++){
    cout << i << ": ";
    for (auto e : g.get_edges_of(i))
      cout << "{" << e.dst << ", " << e.weight << "} ";
    cout << endl;
  }

  vector<int> path = prim<int>(g, 1).first;
  Graph<int> mst = prim<int>(g, 1).second;
  cout << "\nOUTPUT" << endl;
  cout << "MST PATH: ";
  for (auto p : path)
    cout << p << " ";
  cout << endl;
  for (int i = 1; i < mst.vertices(); i++){
    cout << i << ": ";
    for (auto e : mst.get_edges_of(i)){
      cout << "{" << e.dst << ", " << e.weight << "} ";
    }
    cout << endl;
  }
  
  return 0;
}
