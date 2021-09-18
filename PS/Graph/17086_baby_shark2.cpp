#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Pos = pair<int, int>;

int bfs(vector<vector<int> > mat, Pos start){
   vector<Pos> moves = {
		{-1, 0}, {1, 0}, {0, 1}, {0, -1},
		{1, 1}, {1, -1}, {-1, -1}, {-1, 1}
   };
   int n = mat.size();
   int m = mat[0].size();
   
   queue<Pos> q;
   vector<vector<int> > cnt(n, vector<int>(m, -1));
   Pos end;
	
   q.emplace(start);
   cnt[start.first][start.second] = 0;
   
   while (!q.empty()){
      Pos cur = q.front();
      q.pop();
		
		if (mat[cur.first][cur.second]){
			end = cur;
			break;
		}
		
		for (auto move : moves){
			int newY = cur.first + move.first;
			int newX = cur.second + move.second;
			
			if (!(0 <= newY && newY < n && 0 <= newX && newX < m))
				continue;
			
			if (cnt[newY][newX] == -1){
				cnt[newY][newX] = cnt[cur.first][cur.second] + 1;
				q.emplace(Pos(newY, newX));
			}
		}
   }
	
	return cnt[end.first][end.second];
}

int main(){
   int n, m;
   cin >> n >> m;
   
   vector<vector<int> > mat(n, vector<int>(m));
   for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
         cin >> mat[i][j];
      }
   }
	
   int ans = 0;
   for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
         int out = bfs(mat, Pos(i, j));
         if (ans < out)
            ans = out;
      }
   }
   
   cout << ans << endl;
   
   return 0;
}