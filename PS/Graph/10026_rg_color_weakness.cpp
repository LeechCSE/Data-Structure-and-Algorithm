#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Pos{
	int y, x;
};

int bfs(vector<vector<char> > map, bool rg_blind){
	int num_components = 0;
	vector<Pos> moves = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
	int n = map.size();
	vector<vector<bool> > visited(100, vector<bool>(100, false));
	
	if (rg_blind){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (map[i][j] == 'G')
					map[i][j] = 'R';
			}
		}
	}
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (visited[i][j])
				continue;
			
			queue<Pos> q;
			char start_color = map[i][j];
			
			q.emplace(Pos{i, j});
			visited[i][j] = true;
			
			while (!q.empty()){
				Pos cur = q.front();
				q.pop();
				
				for (auto move : moves){
					int newY = cur.y + move.y;
					int newX = cur.x + move.x;
					
					if (!(0 <= newY && newY < n && 
							0 <= newX && newX < n))
						continue;
					
					if (map[newY][newX] == start_color){
						if (!visited[newY][newX]){
							q.emplace(Pos{newY, newX});
							visited[newY][newX] = true;
						}
					}
				}
			}
			
			num_components++;
		}
	}
	
	return num_components;
}

int main(){
	int n;
	cin >> n;
	
	vector<vector<char> > map(n, vector<char>(n));
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		
		for (int j = 0; j < n; j++){
			map[i][j] = s[j];
		}
	}
	
	cout << bfs(map, false) << " " << bfs(map, true) << endl;

	return 0;
}