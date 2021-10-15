#include <iostream>
#include <vector>

using namespace std;
using Pos = pair<int, int>;

struct State{
	int y, x, dir;
};

int run(vector<vector<int>> mat, State init){
	int n = mat.size();
	int m = mat[0].size();
	vector<Pos> moves = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
	vector<int> order = {2, 1, 0, 3, 2, 1, 0};
	vector<vector<bool>> cleaned(n, vector<bool>(m, false));
	
	int rtn = 1;
	cleaned[init.y][init.x] = true;
	State cur = init;
	
	while (true){
		for (int i = 3 - cur.dir; i < 7 - cur.dir; i++){
			int newDir = order[i];
			int newY = cur.y + moves[newDir].first;
			int newX = cur.x + moves[newDir].second;
			
			if (mat[newY][newX] == 0 && !cleaned[newY][newX]){ // #2a
				cleaned[newY][newX] = true;
				cur = State{newY, newX, newDir};
				rtn++;
				break;
			}
			
			if (i == 6 - cur.dir){
				int backDir = abs(2 - i);
				int backY = cur.y + moves[order[backDir]].first;
				int backX = cur.x + moves[order[backDir]].second;
				
				if (mat[backY][backX] == 1)
					return rtn;
				else{
					cur = State{backY, backX, cur.dir};
					break;
				}
			}
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	int r, c, d;
	cin >> r >> c >> d;
	vector<vector<int>> mat(n, vector<int>(m));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> mat[i][j];
		}
	}

	cout << run(mat, {r, c, d}) << endl;

	return 0;
}