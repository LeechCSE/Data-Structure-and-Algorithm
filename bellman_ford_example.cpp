#include "graph_final.cpp"
#include <iostream>
#include <set>
#include <limits>
#include <fstream>

using namespace std;

template <typename T>
Graph<T> make_graph(ifstream& ifs){
	int N;
	ifs >> N;
	
	Graph<T> g(N * N);
	
	for (int i = 0; i < N * N - 1; i++){
		string direction;
		int weight;
		ifs >> direction >> weight;
		
		int src = i;
		for (auto d : direction){
			int dst = i;
			if (d == 'E') dst++;
			else if (d == 'W') dst--;
			else if (d == 'S') dst += N;
			else if (d == 'N') dst -= N;
			
			g.add_edge(Edge<T>(src, dst, -weight));
			dst = 0;
		}
	}
	
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
				distance[e.dst] = distance[e.src] + e.weight;
				visited.insert(e.dst);
			}
		}
	}
	
	for (auto e : g.get_edges()){
		if (visited.find(e.src) == visited.end())
			continue;
			
		if (distance[e.dst] > distance[e.src] + e.weight) // infinite cycle
			return {};
	}
	
	return distance;
}

int main(){
	ifstream ifs("bellman_ford_example_data.txt");
	if (!ifs.is_open())
		return false;
	
	int T;
	ifs >> T;
	int i = 1;
	while (T--){
		cout << i++ << ": ";
		Graph<int> g = make_graph<int>(ifs);
		vector<int> distance = bellman_ford<int>(g, 0);
		
		if (!distance.size())
			cout << "Overchared!" << endl;
		else{
			cout << -bellman_ford<int>(g, 0)[g.vertices() - 1] << endl;
		}
	}
	
	return 0;
}