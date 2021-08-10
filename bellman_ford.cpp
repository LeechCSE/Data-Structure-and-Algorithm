#include "graph_final.cpp"
#include <iostream>
#include <limits>
#include <set>

using namespace std;

template <typename T>
Graph<T> init_graph(){
	Graph<T> g(5);
	
	/*
	vector<Edge<T> > edge_map{
		Edge<T>(0, 1, 3), Edge<T>(1, 2, 5), 
		Edge<T>(1, 3, 10), Edge<T>(3, 2, -7), 
		Edge<T>(2, 4, 2)
	};
	*/
	vector<Edge<T> > edge_map{
		Edge<T>(0, 1, 3),
		Edge<T>(1, 3, -8),
		Edge<T>(2, 1, 3),
		Edge<T>(2, 5, 5),
		Edge<T>(3, 2, 3), 
		Edge<T>(2, 4, 2), 
		Edge<T>(4, 5, -1),
		Edge<T>(5, 1, 8)
	};
	for (auto e : edge_map)
		g.add_edge(e);
	
	return g;
}

template <typename T>
vector<int> bellman_ford(Graph<T> g, int start){
	set<int> visited;
	vector<int> distance(g.vertices(), numeric_limits<int>::max());
	visited.insert(start);
	distance[start] = 0;
	
	for (int i = 0; i < g.vertices() - 1; i++){
		for (auto e : g.get_edges()){
			if (visited.find(e.src) == visited.end())
				continue;
			
			if (distance[e.dst] > distance[e.src] + e.weight){
				visited.insert(e.dst);
				distance[e.dst] = distance[e.src] + e.weight;
			}
		}
	}
	// check if g has a negative cycle
	for (auto e : g.get_edges()){
		if (visited.find(e.src) == visited.end())
			continue;
		
		if (distance[e.dst] > distance[e.src] + e.weight)
			return {};
	}
	
	return distance;
}

int main(){
	Graph<int> g = init_graph<int>();
	int start = 0;
	
	vector<int> distance = bellman_ford<int>(g, start);
	if (!distance.size())
		cout << "Negative cycle!" << endl;
	else{
		for (auto d : bellman_ford<int>(g, start))
			cout << d << " ";
		cout << endl;
	}
	
	return 0;	
}