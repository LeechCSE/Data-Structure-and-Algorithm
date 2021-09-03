#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<pair<int, int> > moves = {
	{0, -1}, {1, -1},
	{-1, 0}, {1, 0},
	{-1, 1}, {0, 1}
};
vector<vector<int> > board;
vector<vector<bool> > visited;
vector<vector<int> > color;

void dfs(int x, int y, int cur_color){
	int n = board.size();
	
	visited[y][x] = true;
	color[y][x] = cur_color;
	
	for (auto m : moves){
		int adjX = x + m.first;
		int adjY = y + m.second;
		
		if (0 <= adjX && adjX < n && 0 <= adjY && adjY < n){
			if (board[adjY][adjX]){
				if (!visited[adjY][adjX]){
					dfs(adjX, adjY, 3 - cur_color);
				}
			}				
		}
	}
}

int sol(){
	int n = board.size();
	int num_color = 0;
	
	for (int y = 0; y < n; y++){
		for (int x = 0; x < n; x++){
			if (board[y][x]){
				
				if (num_color < 1)
					num_color++;
				
				for (auto m : moves){
					int adjX = x + m.first;
					int adjY = y + m.second;
					
					if (0 <= adjX && adjX < n && 0 <= adjY && adjY < n){
						if (board[adjY][adjX]){
							
							if (num_color < 2)
								num_color++;
							
							if (color[y][x] == color[adjY][adjX])
								num_color = 3;
						}				
					}
				}
			}
		}
	}
	
	return num_color;
}

int main(){
	int n;
	cin >> n;
	
	board.resize(n);
	visited.resize(n);
	color.resize(n);
	for (int i = 0; i < n; i++){
		board[i].resize(n);
		visited[i].resize(n);
		color[i].resize(n);
	}
	
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		for (int j = 0; j < n; j++){
			if (s[j] == 'X')
				board[i][j] = 1;
		}
	}
	// 2-color coloring
	for (int y = 0; y < n; y++){
		for (int x = 0; x < n; x++){
			if (!color[y][x] && board[y][x]){
				dfs(x, y, 1);
			}
		}
	}
	// checking if bipartite & return ans
	cout << sol() << endl;
	
	return 0;
}