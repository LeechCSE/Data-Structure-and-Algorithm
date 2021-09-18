#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using Pos = pair<int, int>;

vector<vector<int> > bfs(vector<vector<char> > mat, Pos start){
   vector<Pos> moves = {
		{-1, 0}, {1, 0}, {0, 1}, {0, -1}
   };
   int n = mat.size();
   int m = mat[0].size();
   
   queue<Pos> q;
   vector<vector<int> > cnt(n, vector<int>(m, -1));
	
   q.emplace(start);
   cnt[start.first][start.second] = 0;
   
   while (!q.empty()){
      Pos cur = q.front();
      q.pop();
		
		for (auto move : moves){
			int newY = cur.first + move.first;
			int newX = cur.second + move.second;
			
			if (!(0 <= newY && newY < n && 0 <= newX && newX < m))
				continue;
			if (mat[newY][newX] == 'x')
				continue;
			
			if (cnt[newY][newX] == -1){
				cnt[newY][newX] = cnt[cur.first][cur.second] + 1;
				q.emplace(Pos(newY, newX));
			}
		}
   }
	
	return cnt;
}

int main(){
   int n, m;
   
	while (cin >> m >> n){
		if (n == 0 && m == 0)
			break;
		
		// Input
		vector<vector<char> > mat(n, vector<char>(m));
		vector<Pos> dusts;
		Pos start;
		
		for (int i = 0; i < n; i++){
			string s;
			cin >> s;
			
			for (int j = 0; j < m; j++){
				if (s[j] == '*')
					dusts.emplace_back(Pos(i, j));
				
				if (s[j] == 'o'){
					start = Pos(i, j);
					mat[i][j] = s[j];
				}
				else
					mat[i][j] = s[j];
			}
		}
		
		// Solve
		int min = 0;
		bool invalid = false;
		vector<vector<vector<vector<int> > > > distances(20,
											vector<vector<vector<int> > >(20));
		distances[start.first][start.second] = bfs(mat, start);
		for (auto dust : dusts)
			distances[dust.first][dust.second] = bfs(mat, dust);
		
		do{
			int ans = 0;
			Pos tmp_start = start;
			
			for (int i = 0; i < dusts.size(); i++){
				int start_y = tmp_start.first;
				int start_x = tmp_start.second;
				int end_y = dusts[i].first;
				int end_x = dusts[i].second;
				
				int out = distances[start_y][start_x][end_y][end_x];
				
				if (out == -1){
					invalid = true;
					break;
				}
				
				ans += out;
				tmp_start = dusts[i];
			}
			
			if (min == 0)
				min = ans;
			
			if (min > ans)
				min = ans;
		} while (next_permutation(dusts.begin(), dusts.end()));
		
		if (invalid)
			cout << -1 << endl;
		else
			cout << min << endl;
	}
	
   return 0;
}