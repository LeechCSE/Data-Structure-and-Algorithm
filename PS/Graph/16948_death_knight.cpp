#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Pos = pair<int, int>;

int bfs(int n, Pos start, Pos end){
	vector<Pos> moves = {
		{-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1}
	};
	
	queue<Pos> q;
	vector<vector<int> > cnt(n, vector<int>(n, -1));
	bool is_valid = false;
	
	q.emplace(start);
	cnt[start.second][start.first] = 0;
	
	while (!q.empty()){
		Pos cur = q.front();
		q.pop();
		
		if (cur == end){
			is_valid = true;
			break;
		}
		
		for (auto move : moves){
			int newX = cur.first + move.first;
			int newY = cur.second + move.second;
			
			if (0 <= newX && newX < n && 0 <= newY && newY < n){
				if (cnt[newY][newX] == -1){
					q.emplace(Pos(newX, newY));
					cnt[newY][newX] = cnt[cur.second][cur.first] + 1;
				}
			}
		}
	}
	
	if (is_valid)
		return cnt[end.second][end.first];
	else
		return -1;
}

int main(){
	int n, r1, c1, r2, c2;
	cin >> n >> r1 >> c1 >> r2 >> c2;
	
	cout << bfs(n, Pos(r1, c1), Pos(r2, c2)) << endl;
	
	return 0;
}