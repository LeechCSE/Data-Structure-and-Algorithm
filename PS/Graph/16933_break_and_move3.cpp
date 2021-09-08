#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct Node{
	int y, x, num_broken;
	bool time;
};

int cnt[1000][1000][11][2];

int bfs(vector<vector<int> > map, int limit){
    memset(cnt, -1, sizeof(cnt));
	int n = map.size();
	int m = map[0].size();
	vector<pair<int, int> > moves = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
    
	queue<Node> q;
	
	q.emplace(Node{0, 0, 0, true});
	cnt[0][0][0][1] = 1;
	
	while (!q.empty()){
		Node cur = q.front();
		q.pop();
	
		if (cur.y == n - 1 && cur.x == m - 1)
			break;
		
		for (auto move : moves){
			int newY = cur.y + move.first;
			int newX = cur.x + move.second;
			
			if (!(0 <= newY && newY < n && 0 <= newX && newX < m))
				continue;
			
			// path: just go as long as next state is not visited
			if (map[newY][newX] == 0 &&
				cnt[newY][newX][cur.num_broken][!cur.time] == -1){
					
				q.emplace(Node{newY, newX, cur.num_broken, !cur.time});
				cnt[newY][newX][cur.num_broken][!cur.time] = 
					cnt[cur.y][cur.x][cur.num_broken][cur.time] + 1;
			}
			// wall & breakable
			if (map[newY][newX] == 1 && cur.num_broken < limit && 
				cur.time && 
				cnt[newY][newX][cur.num_broken + 1][!cur.time] == -1){
				q.emplace(Node{newY, newX, 
								cur.num_broken + 1, !cur.time});
				cnt[newY][newX][cur.num_broken + 1][!cur.time] = 
					cnt[cur.y][cur.x][cur.num_broken][cur.time] + 1;
			}
		}
		if (!cur.time){
			q.emplace(Node{cur.y, cur.x, cur.num_broken, !cur.time});
			cnt[cur.y][cur.x][cur.num_broken][!cur.time] =
				cnt[cur.y][cur.x][cur.num_broken][cur.time] + 1;
		}
	}
	
	int rtn = -1;
	for (int i = 0; i <= limit; i++){
		for (int j = 0; j <= 1; j++){
			int cand = cnt[n - 1][m - 1][i][j];
			
			if (cand != -1){
				if (rtn == -1)
					rtn = cand;
				else{
					if (cand < rtn)
						rtn = cand;
				}
			}
		}
	}
	
	return rtn;
}

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<vector<int> >  map(n, vector<int>(m));
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		
		for (int j = 0; j < m; j++){
			map[i][j] = s[j] - '0';
		}
	}
	
	cout << bfs(map, k) << endl;
	
	return 0;
}