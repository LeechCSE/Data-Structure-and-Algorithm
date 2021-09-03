#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > adjList;
vector<bool> visited;
vector<int> color;

void dfs(int cur, int cur_color){
	
	// cout << "CUR " << cur << ": " << cur_color << endl;
	
	visited[cur] = true;
	color[cur] = cur_color;
	
	for (auto adj : adjList[cur]){
		if (!visited[adj]){
			
			// cout << "   ADJ " << adj << endl;

			dfs(adj, 3 - cur_color);
		}
	}
}

int main(){
	freopen ("test.txt", "r", stdin);
	
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		
		adjList.clear();
		adjList.resize(n + 1);
		visited.clear();
		visited.resize(n + 1, false);
		color.clear();
		color.resize(n + 1, 0);
		
		for (int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			adjList[u].emplace_back(v);
			adjList[v].emplace_back(u);
		}
		// color
		for (int i = 1; i < adjList.size(); i++){
			if (!color[i])
				dfs(i, 1);
		}
		// check if bipartite
		bool is_bipartite = true;
		for (int u = 1; u < adjList.size(); u++){
			for (auto v : adjList[u]){
				if (color[u] == color[v])
					is_bipartite = false;
			}
		}
		
		if (is_bipartite)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
	return 0;
}