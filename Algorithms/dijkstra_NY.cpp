#include "graph_final.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <set>
#include <limits>
#include <algorithm>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

Graph<unsigned> init_graph(){
	ifstream ifs("dijkstra_NY_ata.txt");
	if (!ifs.is_open()){
		cout << "Error: cannot open file" << endl;
		exit(EXIT_FAILURE);
	}
	
	
	Graph<unsigned> NYC_graph;
	string line;
	
	while (getline(ifs, line)){
		char label = line[0];
	
		if (label == 'p'){
			istringstream iss(line);
			char p;
			string sp;
			unsigned N, M; // N: #vertices, M: #edges
			iss >> p >> sp >> N >> M;
			NYC_graph.reserve(N + 1, M);
			
		}
		if (label == 'a'){
			istringstream iss(line);
			char a;
			unsigned u, v, w;
			iss >> a >> u >> v >> w;
			NYC_graph.add_edge(Edge<unsigned>(u, v, w));
		}
		
	}
	ifs.close();
	
	return NYC_graph;
}

struct Vertex{
	unsigned id, dist;
	Vertex(unsigned i, unsigned d) : id(i), dist(d){}
	bool operator>(Vertex v) const { return this->dist > v.dist; }
};

vector<unsigned> dijkstra(Graph<unsigned> g, unsigned start, unsigned target){
	priority_queue<Vertex, vector<Vertex>, greater<Vertex> > min_heap;
	set<unsigned> visited;
	
	vector<unsigned> parent(g.vertices());
	vector<unsigned> distance(g.vertices(), numeric_limits<unsigned>::max());
	distance[start] = 0;
	min_heap.emplace(Vertex(start, distance[start]));
	
	while (!min_heap.empty()){
		Vertex cur = min_heap.top();
		min_heap.pop();
		
		if (cur.id == target)
			break;
		
		if (visited.find(cur.id) == visited.end()){
			visited.insert(cur.id);
			
			for (auto e : g.get_edges_of(cur.id)){
				if (visited.find(e.dst) == visited.end()){
					if (distance[e.dst] > cur.dist + e.weight){
						distance[e.dst] = cur.dist + e.weight;
						parent[e.dst] = cur.id;
						min_heap.emplace(Vertex(e.dst, distance[e.dst]));
					}
				}
			}	
		}
	}
	
	vector<unsigned> sp;
	unsigned cur = target;
	while (cur != start){
		sp.emplace_back(cur);
		cur = parent[cur];
	}
	sp.emplace_back(start);
	reverse(sp.begin(), sp.end());
	
	return sp;
}

int main(){
	Graph<unsigned> NYC_graph = init_graph();
	
	unsigned start = 913;
	unsigned target = 542;
	cout << "Shortest path: ";
	for (auto v : dijkstra(NYC_graph, start, target))
		cout << v << " ";
	cout << endl;
	
	return 0;
}