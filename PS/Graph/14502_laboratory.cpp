#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using Pos = pair<int, int>;

int bfs(vector<vector<int> > map, vector<Pos> virus){
	int n = map.size();
	int m = map[0].size();
	vector<Pos> moves = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	int num_blocks = 0;
	for (auto v : map)
		num_blocks += count(v.begin(), v.end(), 1);
	
	queue<Pos> q;
	vector<vector<bool> > visited(n, vector<bool>(m, false));
	vector<vector<int> > cnt(n, vector<int>(m, -1));
	
	for (auto v : virus){
		q.emplace(v);
		visited[v.second][v.first] = true;
		cnt[v.second][v.first] = 0;
	}
	
	while (!q.empty()){
		Pos cur = q.front();
		q.pop();
		
		for (auto move : moves){
			int newX = cur.first + move.first;
			int newY = cur.second + move.second;
			
			if (0 <= newX && newX < m && 0 <= newY && newY < n){
				if (map[newY][newX] == 0){
					if (!visited[newY][newX]){
						visited[newY][newX] = true;
						q.emplace(Pos(newX, newY));
						cnt[newY][newX] = cnt[cur.second][cur.first] + 1;
					}
				}
			}
		}
	}
	
	int unvisiteds = 0;
	for (int i = 0; i < n; i++)
		unvisiteds += count(visited[i].begin(), visited[i].end(), false);
		
	return unvisiteds - num_blocks;
}

int main(){
	int n, m;
	cin >> n >> m;
	
	vector<vector<int> > map(n, vector<int>(m));
	vector<Pos> virus;
	vector<Pos> room;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> map[i][j];
			if (map[i][j] == 2)
				virus.emplace_back(Pos(j, i));
			else if(map[i][j] == 0)
				room.emplace_back(Pos(j, i));
		}
	}
	
	int ans = 0;
	for (int i = 0; i < room.size() - 2; i++){
		map[room[i].second][room[i].first] = 1;
		
		for (int j = i + 1; j < room.size() - 1; j++){
			map[room[j].second][room[j].first] = 1;
			
			for (int k = j + 1; k < room.size(); k++){
				map[room[k].second][room[k].first] = 1;
				
				int num_safe = bfs(map, virus);
				if (ans < num_safe)
					ans = num_safe;
				
				map[room[k].second][room[k].first] = 0;
			}
			map[room[j].second][room[j].first] = 0;
		}
		map[room[i].second][room[i].first] = 0;
	}
	
	cout << ans << endl;
	
	return 0;
}