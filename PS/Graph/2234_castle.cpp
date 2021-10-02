#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

map<int, int> connected_component;
vector<vector<bool> > visited(50, vector<bool>(50, false));
vector<vector<int> > cc_mat(50, vector<int>(50));

struct Pos{
	int y, x;
};

void label_cc(vector<vector<int> > mat, int label, int y, int x){
	int n = mat.size();
	int m  = mat[0].size();
	
	vector<Pos> moves = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
	queue<Pos> q;
	Pos last;
	int cc_cnt = 0;
	
	q.emplace(Pos{y, x});
	visited[y][x] = true;
	
	while (!q.empty()){
		Pos cur = q.front();
		q.pop();
		cc_cnt++;
		last = cur;
		cc_mat[cur.y][cur.x] = label;
		
		bitset<4> wall(mat[cur.y][cur.x]);
		// order: W N E S
		for (int i = 0; i < moves.size(); i++){
			Pos move = moves[i];
			int newY = cur.y + move.y;
			int newX = cur.x + move.x;
			// out-of-bound check
			if (!(0 <= newY && newY < n && 0 <= newX && newX < m))
				continue;
			// wall check
			if (wall[i])
				continue;
			// visit check
			if (visited[newY][newX])
				continue;
			
			visited[newY][newX] = true;
			q.emplace(Pos{newY, newX});
		}
	}
	
	connected_component[label] = cc_cnt;
}

void find_adj(int n, int m, vector<vector<int> > cc_mat, vector<set<int> > &adj, 
				int y, int x){
	vector<Pos> moves = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
	queue<Pos> q;
	
	q.emplace(Pos{y, x});
	visited[y][x] = true;
	
	while (!q.empty()){
		Pos cur = q.front();
		q.pop();
		
		for (auto move : moves){
			int newY = cur.y + move.y;
			int newX = cur.x + move.x;
			
			if (!(0 <= newY && newY < n && 0 <= newX && newX < m))
				continue;
			if (visited[newY][newX])
				continue;
			
			if (cc_mat[newY][newX] != cc_mat[cur.y][cur.x]){
				adj[cc_mat[cur.y][cur.x]].insert(cc_mat[newY][newX]);
				adj[cc_mat[newY][newX]].insert(cc_mat[cur.y][cur.x]);
			}
			else{
				visited[newY][newX] = true;
				q.emplace(Pos{newY, newX});
			}
		}
	}
}

int main(){
	int n, m;
	cin >> m >> n;
	
	vector<vector<int> > mat(n, vector<int>(m));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> mat[i][j];
		}
	}
	
	int label = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (!visited[i][j]){
				label_cc(mat, label++, i, j);
			}
		}
	}
	
	for (auto &v : visited)
		fill(v.begin(), v.end(), false);
	
	vector<set<int> > adj(connected_component.size());
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (!visited[i][j]){
				find_adj(n, m, cc_mat, adj, i, j);
			}
		}
	}
	
	int ans1 = connected_component.size();
	int ans2 = 0;
	int ans3 = 0;
	for (int cur = 0; cur < adj.size(); cur++){
		if (ans2 < connected_component[cur])
			ans2 = connected_component[cur];
		
		int sum = 0;
		sum += connected_component[cur];
		
		vector<int> cand;
		for (auto a : adj[cur])
			cand.emplace_back(connected_component[a]);
		
		sum += *max_element(cand.begin(), cand.end());
		
		if (ans3 < sum)
			ans3 = sum;
	}
	
	cout << ans1 << endl << ans2 << endl << ans3 << endl;
	
	return 0;
}