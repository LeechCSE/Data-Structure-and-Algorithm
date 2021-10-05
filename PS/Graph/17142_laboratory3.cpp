#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using Pos = pair<int, int>;

int bfs(vector<vector<int> > mat, vector<Pos> starting_pts){
	int n = mat.size();
	vector<Pos> moves = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
	queue<Pos> q;
	vector<vector<int> > cnt(n, vector<int>(n, -1));
	
	for (auto sp : starting_pts){
		q.emplace(sp);
		cnt[sp.first][sp.second] = 0;
	}
	
	while (!q.empty()){
		Pos cur = q.front();
		q.pop();
		
		for (auto move : moves){
			int newY = cur.first + move.first;
			int newX = cur.second + move.second;
			// out-of-bound check
			if (!(0 <= newY && newY < n && 0 <= newX && newX < n))
				continue;
			// wall check
			if (mat[newY][newX] == 1)
				continue;
			// visit check
			if (cnt[newY][newX] != -1)
				continue;
			
			q.emplace(Pos(newY, newX));
			cnt[newY][newX] = cnt[cur.first][cur.second] + 1;
		}
	}
	
	int rtn = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (mat[i][j] == 0){
				if (cnt[i][j] == -1)
					return -1;
				
				if (rtn < cnt[i][j])
					rtn = cnt[i][j];
			}
		}
	}
	
	return rtn;
}

int main(){
	int n, m;
	cin >> n >> m;
	
	vector<vector<int> > mat(n, vector<int>(n));
	vector<Pos> starting_pts;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> mat[i][j];
			
			if (mat[i][j] == 2)
				starting_pts.emplace_back(Pos(i, j));
		}
	}
	
	vector<bool> mask(starting_pts.size(), false);
	for (int i = 0; i < m; i++)
		mask[i] = true;
	
	int ans = n * n;
	do{ // k Choose m where k is #starting points
		vector<Pos> cand;
		for (int i = 0; i < starting_pts.size(); i++){
			if (mask[i])
				cand.emplace_back(starting_pts[i]);
		}
		
		int out = bfs(mat, cand);
		if (out != -1){
			if (ans > out)
				ans = out;
		}
		
	} while (prev_permutation(mask.begin(), mask.end()));
	
	if (ans  == n * n)
		cout << -1 << endl;
	else
		cout << ans << endl;
	
	return 0;
}