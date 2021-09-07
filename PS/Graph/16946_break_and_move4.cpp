#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
using Pos = pair<int, int>;

int bfs(vector<vector<int> > &map, 
		vector<vector<bool> > &visited, Pos start, int group_num){
	vector<Pos> moves = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
	int n = map.size();
	int m = map[0].size();
	
	queue<Pos> q;
	int cnt = 0;
	
	q.emplace(start);
	visited[start.first][start.second] = true;
	map[start.first][start.second] = group_num;
	
	while (!q.empty()){
		Pos cur = q.front();
		q.pop();
		cnt++;
		
		for (auto move : moves){
			int newY = cur.first + move.first;
			int newX = cur.second + move.second;
			
			if (0 <= newY && newY < n && 0 <= newX && newX < m){
				if (map[newY][newX] == 0){
					if (!visited[newY][newX]){
						map[newY][newX] = group_num;
						q.emplace(Pos(newY, newX));
						visited[newY][newX] = true;
					}
				}
			}
		}
	}
	
	return cnt;
}

int main(){
	int n, m;
	cin >> n >> m;
	
	vector<vector<int> > map(n, vector<int>(m));
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		for (int j = 0; j < m; j++){
			map[i][j] = s[j] - '0';
		}
	}
	
	vector<vector<bool> > visited(n, vector<bool>(m, false));
	vector<vector<int> > group_map = map;
	std::map<int, int> cc_map;
	int group_num = 2;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (group_map[i][j] == 0 && !visited[i][j]){
				cc_map[group_num] = bfs(group_map, visited, 
										Pos{i, j}, group_num);
				group_num++;
			}
		}
	}
	
	vector<Pos> moves = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
	vector<vector<int> > ans(n, vector<int>(m));
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (map[i][j] == 0)
				cout << 0;
			if (group_map[i][j] == 1){
				ans[i][j] = 1;
				set<int> buf;
				for (auto move : moves){
					int newY = i + move.first;
					int newX = j + move.second;
					
					if (0 <= newY && newY < n && 0 <= newX && newX < m){
						if (group_map[newY][newX] != 1)
							buf.insert(group_map[newY][newX]);
					}
				}
				
				for (auto g : buf)
					ans[i][j] += cc_map[g];
				cout << ans[i][j] % 10;
			}
		}
		cout << endl;
	}
	
	return 0;
}