#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>

using namespace std;
using Pos = pair<int, int>;

bool operator==(vector<vector<int>> m1, vector<vector<int>> m2){
	int n = m1.size();
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (m1[i][j] != m2[i][j])
				return false;
		}
	}
	
	return true;
}

vector<vector<bool> > visited(50, vector<bool>(50, false));

void bfs(vector<vector<int>> &mat, Pos start, int l, int r){
	int n = mat.size();
	vector<Pos> moves = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
	queue<Pos> q;
	int cnt = 0;
	int sum = mat[start.first][start.second];
	vector<Pos> el = { start };
	
	q.emplace(start);
	visited[start.first][start.second] = true;
	
	while (!q.empty()){
		Pos cur = q.front();
		q.pop();
		
		cnt++;
		
		for (auto move : moves){
			int newY = cur.first + move.first;
			int newX = cur.second + move.second;
			
			if (!(0 <= newY && newY < n && 0 <= newX && newX < n))
				continue;
			if (visited[newY][newX])
				continue;
			
			int diff = abs(mat[cur.first][cur.second] - mat[newY][newX]);
			if (l <= diff && diff <= r){
				q.emplace(Pos(newY, newX));
				visited[newY][newX] = true;
				sum += mat[newY][newX];
				el.emplace_back(Pos(newY, newX));
			}
		}
	}
	
	for (auto e : el)
		mat[e.first][e.second] = sum / cnt;
}

int main(){
	int n, l, r;
	cin >> n >> l >> r;
	
	vector<vector<int>> mat(n, vector<int>(n));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> mat[i][j];
		}
	}
	
	vector<vector<int>> cp_mat = mat;
	int ans = 0;
	while (true){
		for (auto &v : visited)
			fill(v.begin(), v.end(), false);
		
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (!visited[i][j])
					bfs(mat, {i, j}, l, r);
			}
		}
		
		if (mat == cp_mat)
			break;
		
		cp_mat = mat;
		ans++;
	}
	
	cout << ans << endl;
	
	return 0;
}