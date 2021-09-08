#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Node{
	int y, x, num_broken;
};

int bfs(vector<vector<int> > map, int limit){
	int n = map.size();
	int m = map[0].size();
	vector<pair<int, int> > moves = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
	
	queue<Node> q;
	vector<vector<vector<int> > > cnt(n, 
		vector<vector<int> > (m, vector<int>(limit + 1, -1)));
	
	q.emplace(Node{0, 0, 0});
	cnt[0][0][0] = 1;
	
	while (!q.empty()){
		Node cur = q.front();
		q.pop();

		for (auto move : moves){
			int newY = cur.y + move.first;
			int newX = cur.x + move.second;
			
			if (!(0 <= newY && newY < n && 0 <= newX && newX < m))
				continue;
			
			if (map[newY][newX] == 0){ // path
				if (cnt[newY][newX][cur.num_broken] == -1){
					q.emplace(Node{newY, newX, cur.num_broken});
					cnt[newY][newX][cur.num_broken] = 
						cnt[cur.y][cur.x][cur.num_broken] + 1;
				}
			}
			else{ // wall
				if (cur.num_broken + 1 <= limit){
					if (cnt[newY][newX][cur.num_broken + 1] == -1){
						q.emplace(Node{newY, newX, cur.num_broken + 1});
						cnt[newY][newX][cur.num_broken + 1] = 
							cnt[cur.y][cur.x][cur.num_broken] + 1;
					}
				}
			}
		}
	}

	int rtn = -1;
	for (int i = 0; i <= limit; i++){
		if (cnt[n - 1][m - 1][i] == -1)
			continue;
		if (rtn == -1)
			rtn = cnt[n - 1][m - 1][i];
		else if (rtn > cnt[n - 1][m - 1][i])
			rtn = cnt[n - 1][m - 1][i];
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