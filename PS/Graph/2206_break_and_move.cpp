#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

struct Node{
	int y, x;
	bool broken;
};

int bfs(vector<vector<int> > map){
	vector<pair<int, int> > moves = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
	int n  = map.size();
	int m = map[0].size();
	Node start = Node{0, 0, 0};
	
	queue<Node> q;
	vector<vector<vector<int> > > cnt(n, 
		vector<vector<int> >(m, vector<int>(2, -1)));
	
	q.emplace(start);
	cnt[start.y][start.x][0] = 1;
	
	while (!q.empty()){
		Node cur = q.front();
		q.pop();
		
		for (auto move : moves){
			int newX = cur.x + move.first;
			int newY = cur.y + move.second;
			
			if (0 <= newX && newX < m && 0 <= newY && newY < n){
				if (cur.broken){ // already breaked once
					if (map[newY][newX] == 0){
						if (cnt[newY][newX][cur.broken] == -1){
							q.emplace(Node{newY, newX, cur.broken});
							cnt[newY][newX][cur.broken] = 
								cnt[cur.y][cur.x][cur.broken] + 1;
						}
					}
				}
				else{ // not breaked yet
					if (map[newY][newX] == 0){
						if (cnt[newY][newX][cur.broken] == -1){
							q.emplace(Node{newY, newX, cur.broken});
							cnt[newY][newX][cur.broken] = 
								cnt[cur.y][cur.x][cur.broken] + 1;
						}
					}
					else{
						if (cnt[newY][newX][true] == -1){
							q.emplace(Node{newY, newX, true});
							cnt[newY][newX][true] = 
								cnt[cur.y][cur.x][cur.broken] + 1;
						}
					}
				}
			}
		}
	}
	
	int ans0 = cnt[n - 1][m - 1][0];
	int ans1 = cnt[n - 1][m - 1][1];
	
	if (ans0 == -1 && ans1 == -1)
		return ans0;
	else if (ans0 != -1 && ans1 != -1)
		return min(ans0, ans1);
	else
		return max(ans0, ans1);
}

int main(){
	int n, m;
	cin >> n >> m;
	
	vector<vector<int> > map(n);
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		
		for (auto ch : s)
			map[i].emplace_back(ch - '0');
	}
	
	cout << bfs(map) << endl;
	
	return 0;
}