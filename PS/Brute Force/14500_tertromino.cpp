#include <iostream>
#include <vector>

using namespace std;

struct Pos{
	int y, x;
	Pos(int _y, int _x) : y(_y), x(_x){}
};

vector<vector<int> > mat(500, vector<int>(500));
vector<vector<bool> > visited(500, vector<bool>(500, false));
vector<Pos> moves = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };

int probe(Pos cur, int sum = 0, int cnt = 0){
	int n = mat.size();
	int m = mat[0].size();
	
	if (cnt == 4) // base case: taken 3 steps
		return sum;
		
	vector<int> res;
	
	if (!(0 <= cur.y && cur.y < n && 0 <= cur.x && cur.x < m)) // out of mat
		return -1;
	if (visited[cur.y][cur.x]) // already visited
		return -1;

	visited[cur.y][cur.x] = true;
	for (auto move : moves){
		int newY = cur.y + move.y;
		int newX = cur.x + move.x;
		
		res.emplace_back(probe(Pos(newY, newX), sum + mat[cur.y][cur.x], cnt + 1));
	}
	
	visited[cur.y][cur.x] = false; // unbind visited
	
	int max = res[0];
	for (auto r : res){
		if (max < r)
			max = r;
	}
	
	return max;
}

int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> mat[i][j];
		}
	}
	
	int ans = probe(Pos(0, 0));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			// Typical tetrominoes
			int out = probe(Pos(i, j));
			if (ans < out)
				ans = out;
			// T-shape tetromino
			if (n - i > 2){ // col bot margin
				out = mat[i][j] + mat[i + 1][j] + mat[i + 2][j];
				if (m - j > 1){ // row right margin
					out += mat[i + 1][j + 1];
					
					if (ans < out)
						ans = out;
					out -= mat[i + 1][j + 1];
				}
				if (j > 0){ // row left margin
					out += mat[i + 1][j - 1];
					
					if (ans < out)
						ans = out;
				}
			}
			if (m - j > 2){ // row right margin
				out = mat[i][j] + mat[i][j + 1] + mat[i][j + 2];
				if (n - i > 1){ // col bot margin
					out += mat[i + 1][j + 1];
					
					if (ans < out)
						ans = out;
					out -= mat[i + 1][j + 1];
				}
				if (i > 0){ // col up margin
					out += mat[i - 1][j + 1];
					
					if (ans < out)
						ans = out;
				}
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}