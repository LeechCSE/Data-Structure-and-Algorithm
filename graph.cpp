#include "doubly_linked_list.h"
#include "graph.h"
#include <iostream>
#include <vector>

using namespace std;

// Constructor: initialize an empty graph with n vertices
Graph::Graph(int n){
  num_vertex = n;
  num_edge = 0;
  
  for (int i = 0; i < n; i++)
    adjList.push_back(DoublyLinkedList<int>());
}
// Destructor
Graph::~Graph(){
  if (num_vertex > 1){
    for (int i = 0; i < num_vertex; i++){
      for (int j = 1; j < num_vertex; j++){
	remove_edge(i, j);
      }
    }    
    adjList.clear();
    num_vertex = 0;
  }
}
// Check whether vertex u is in graph
bool Graph::is_member(int u){
  if (u > (num_vertex - 1) || u < 0)
    return false;
  else
    return true;
}
// Check if edge between vertex u and v is valid
bool Graph::is_edge(int u, int v){
  if (adjList[u].find(v) == -1)
    return false;
  else
    return true;
}
// Print graph
void Graph::print(){
  for (int i = 0; i < adjList.size(); i++){
    cout << "Node " << i << ": ";
    adjList[i].print_data();
  }
  cout << num_vertex << " vertices with "  << num_edge << " edges" << endl;
}
// Add a new edge(undirected)
void Graph::add_edge(int u, int v){ // TODO: maybe sorting?
  if (!is_member(u) || !is_member(v))
    return;
  if (is_edge(u, v))
    return;

  adjList[u].push_back(v);
  adjList[v].push_back(u);

  num_edge++;
}
// Remove edge between vertex u and v
void Graph::remove_edge(int u, int v){
  // arg sanity check
  if (!is_edge(u, v))
    return;
  if (!is_member(u) || !is_member(v))
    return;

  adjList[u].erase(adjList[u].find(v));
  adjList[v].erase(adjList[v].find(u));
  num_edge--;
}
// Add a new vertex
void Graph::add_vertex(){
  adjList.push_back(DoublyLinkedList<int>());
  num_vertex++;
}
// Remove vertex u
void Graph::remove_vertex(int u){
  // arg sanity check
  if (!is_member(u))
    return;
  // trace u in adj list and remove all
  for (int i = 0; i < adjList[u].get_size(); i++){
    remove_edge(u, adjList[u].get_head());
    adjList[u].pop_head();
  }
  // remove vertex u
  adjList.erase(adjList.begin() + u - 1);
  num_vertex--;
}


int main(){
  Graph g(5);
  g.add_edge(0, 2);
  g.add_edge(3, 0);
  g.add_edge(1, 3);
  cout << "##########Initial state:\n";
  g.print();

  cout << "##########Remove edge 1 3\n";
  g.remove_edge(1, 3);
  g.print();

  cout << "##########Add vertex:\n";
  g.add_vertex();
  g.print();

  cout << "##########Add edges:\n";
  g.add_edge(5, 1);
  g.add_edge(5, 3);
  g.add_edge(4, 5);
  g.print();

  /*
  g.remove_vertex(3);
  cout << "\nAfter rm vertex 5 ..." << endl;
  g.print();
  */
  return 0;
}
