#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
using Pos = pair<int, int>;

int bfs(vector<vector<int> > map, Pos start, Pos end){
	vector<Pos> moves = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	int n = map.size();
	int m = map[0].size();
	
	queue<Pos> q;
	vector<vector<int> > cnt(n, vector<int>(m, 9));
	
	q.emplace(start);
	cnt[start.first][start.second] = 0;
	
	while (!q.empty()){
		Pos cur = q.front();
		q.pop();
				
		for (int i = 0; i < moves.size(); i++){
			Pos move = moves[i];
			int newY = cur.first + move.first;
			int newX = cur.second + move.second;
			
			while (true){
				if (!(0 <= newY && newY < n && 0 <= newX && newX < m))
					break;
				if (map[newY][newX] == 1)
					break;
				
				if (cnt[newY][newX] == 9){
					q.emplace(Pos(newY, newX));
					cnt[newY][newX] = cnt[cur.first][cur.second] + 1;
				}
				
				newY += move.first;
				newX += move.second;
			}
		}
	}
	
	return cnt[end.first][end.second] - 1;
}

int main(){
	freopen("tc.txt", "r", stdin);
	
	int n, m;
	cin >> m >> n;
	
	vector<vector<int> > map(n, vector<int>(m));
	Pos start = {-1, -1};
	Pos end;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		for (int j = 0; j < m; j++){
			char in = s[j];
			
			if (in == 'C'){
				if (start == Pos(-1, -1))
					start = Pos(i, j);
				else
					end = Pos(i, j);
			}
			else if (in == '*')
				map[i][j] = 1;
		}
	}
	
	// cout << start.first << " " << start.second << endl;
	// cout << end.first << " " << end.second << endl;
	// for (int i = 0; i < n; i++){
		// for (int j = 0; j < m; j++){
			// cout << map[i][j] << " ";
		// }
		// cout << endl;
	// }
	
	cout << bfs(map, start, end) << endl;
	
	
	return 0;
}