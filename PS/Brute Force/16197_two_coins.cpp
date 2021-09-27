#include <iostream>
#include <vector>

using namespace std;
using Pos = pair<int, int>;

int n, m;
vector<vector<char> > mat(20, vector<char>(20));
vector<Pos> moves = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };

bool dropped(Pos c){
	if (!(0 <= c.first && c.first < n && 0 <= c.second && c.second < m))
		return true;
	else
		return false;
}

int proc(int num_clicks, Pos c1, Pos c2){
	// base case 1: (num_clicks > 10) invalid
	if (num_clicks > 10)
		return -1;
	// base case 2: (two coins are dropped) invalid
	if (dropped(c1) && dropped(c2))
		return -1;
	// base case 3: (one coin is dropped) target
	if ((dropped(c1) && !dropped(c2)) || (!dropped(c1) && dropped(c2)))
		return num_clicks;
	
	int min = 11;
	for (auto move : moves){
		int newY1 = c1.first + move.first;
		int newX1 = c1.second + move.second;
		int newY2 = c2.first + move.first;
		int newX2 = c2.second + move.second;
		Pos nc1 = {newY1, newX1};
		Pos nc2 = {newY2, newX2};
			
		if ((0 <= newY1 && newY1 < n && 0 <= newX1 && newX1 < m) &&
			mat[newY1][newX1] == '#') // coin1 hits a wall
			nc1 = c1;
		if ((0 <= newY2 && newY2 < n && 0 <= newX2 && newX2 < m) &&
			mat[newY2][newX2] == '#') // coin2 hits a wall
			nc2 = c2;
		
		int out = proc(num_clicks + 1, nc1, nc2);
		
		if (out == -1)
			continue;
		
		if (min > out)
			min = out;
	}
	
	if (min == 11)
		return -1;
	else 
		return min;
}

int main(){
	cin >> n >> m;
	
	Pos coin1 = {-1, -1};
	Pos coin2 = {-1, -1};
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> mat[i][j];
			
			if (mat[i][j] == 'o'){
				mat[i][j] = '.';
				if (coin1 == Pos(-1, -1))
					coin1 = Pos(i, j);
				else
					coin2 = Pos(i, j);
			}
		}
	}
	
	cout << proc(0, coin1, coin2) << endl;
	
	return 0;
}