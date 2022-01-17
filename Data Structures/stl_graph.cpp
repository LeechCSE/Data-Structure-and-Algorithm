#include "stl_graph.h"
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

// Constructor: initialize graph with n vertices
Graph::Graph(int n){
  num_vertex = n;
  num_edge = 0;
  for (int i = 0; i < n; i++){
    adjList.push_back(list<int>());
    visited.push_back(false);
  }
}
// Destructor
Graph::~Graph(){}
// Print adjacency list
void Graph::print(){
  for (int i = 0; i < num_vertex; i++){
    cout << "Node " << i << ": ";
    for (list<int>::iterator it = adjList[i].begin(); it != adjList[i].end(); it++){
      cout << *it << " ";
    }
    cout << endl;
  }
  cout << num_vertex << " vertices + " << num_edge << " edges\n";
}
// Check if vertex u is graph
bool Graph::is_vertex(int u){
  if (u < 0 || u > (num_vertex - 1))
    return false;
  else
    return true;
}
// Check if edge between vertex u and v is in graph
bool Graph::is_edge(int u, int v){
  if (!is_vertex(u) || !is_vertex(v))
    return false;
  
  list<int>::iterator it = find(adjList[u].begin(), adjList[u].end(), v);
  if (it != adjList[u].end())
    return true;
  else
    return false;
}
// Add a new edge between vertex u and v
void Graph::add_edge(int u, int v){
  if (!is_vertex(u) || !is_vertex(v))
    return;
  if (is_edge(u, v))
    return;
  
  adjList[u].push_back(v);
  adjList[v].push_back(u);
  num_edge++;
}
// Add a new vertex
void Graph::add_vertex(int u){
  if (is_vertex(u))
    return;

  adjList.push_back(list<int>());
  num_vertex++;
}
// Remove edge between vertex u and v
void Graph::remove_edge(int u, int v){
  if (!is_edge(u, v))
    return;

  adjList[u].remove(v);
  adjList[v].remove(u);
  num_edge--;
}
// Breath-First-Search(BFS)
void Graph::bfs(int u){
  // arg sanity check
  if (!is_vertex(u))
    return;
  
  queue<int> q;
  q.push(u);
  visited[u] = true;
  
  while (!q.empty()){
    int turn = q.front();
    q.pop();

    list<int> neighbors = adjList[turn];
    while (!neighbors.empty()){
      if (!visited[neighbors.front()]){
	visited[neighbors.front()] = true;
	q.push(neighbors.front());
      }
      neighbors.pop_front();
    }
  }
  // reset visited vector
  visited.assign(num_vertex, false);
}
// Depth-First-Search(DFS) recursive version
void Graph::dfs_rec(int u){
  // arg sanity check
  if (!is_vertex(u))
    return;
  
  visited[u] = true;
  list<int> neighbors = adjList[u];
  while (!neighbors.empty()){
    if (!visited[neighbors.front()]){
      visited[neighbors.front()] = true;
      dfs_rec(neighbors.front());
    }
    neighbors.pop_front();
  }
}
// Depth-First-Search(DFS) iterattive version
void Graph::dfs_itr(int u){
  if (!is_vertex(u))
    return;
  
  stack<int> s;
  s.push(u);
  visited[u] = true;

  while (!s.empty()){
    int turn = s.top();
    s.pop();

    cout << "Turn: " << turn << endl;

    list<int> neighbors = adjList[turn];
    while (!neighbors.empty()){
      if (!visited[neighbors.front()]){
	visited[neighbors.front()] = true;
	s.push(neighbors.front());
	cout << neighbors.front() << " ";
      }
      neighbors.pop_front();
    }
    cout << endl;
  }
  visited.assign(num_vertex, false);
}

int main(){
  Graph g(5);
  g.add_edge(0, 2);
  g.add_edge(0, 3);
  g.add_edge(3, 1);
  g.add_vertex(5);
  g.remove_edge(1, 3);
  g.add_edge(5, 1);
  g.add_edge(5, 4);
  g.add_edge(3, 5);
  g.print();

  g.bfs(0);
  
  Graph g2(9);
  g2.add_edge(0, 1);
  g2.add_edge(1, 2);
  g2.add_edge(1, 3);
  g2.add_edge(3, 4);
  g2.add_edge(0, 5);
  g2.add_edge(5, 7);
  g2.add_edge(7, 8);
  g2.add_edge(0, 6);
  g2.print();
  //g2.dfs_rec(0);
  g2.dfs_itr(10);
  
  return 0;
}
B
