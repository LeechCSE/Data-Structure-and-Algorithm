#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Pos = pair<int, int>;

struct Node{
	int y, x, map_id;
};

vector<vector<int> > move_wall(vector<vector<int> > map){
	vector<vector<int> > rtn = map;
	
	for (int j = 0; j < 8; j++)
		rtn[0][j] = 0;
	for (int i = 1; i < 8; i++){
		for (int j = 0; j < 8; j++){
			rtn[i][j] = map[i - 1][j];
		}
	}
	
	return rtn;
}

int bfs(vector<vector<vector<int> > > map_v){
	vector<Pos> moves = {
		{-1, 0}, {1, 0}, {0, 1}, {0, -1},
		{-1, -1}, {-1, 1}, {1, -1}, {1, 1}
	};
	
	Pos start = Pos(7, 0);
	Pos end = Pos(0, 7);
	vector<vector<vector<bool> > > visited(8,
		vector<vector<bool> >(8, 
			vector<bool>(8, false)));
	queue<Node> q;
	
	q.emplace(Node{start.first, start.second, 0});
	visited[start.first][start.second][0];
	
	while (!q.empty()){
		Node cur = q.front();
		q.pop();
		
		if (cur.y == end.first && cur.x == end.second)
			return 1;
		
		if (map_v[cur.map_id][cur.y][cur.x] == 1)
			continue;
		
		int newMapId = cur.map_id + 1 > 7 ? 7 : cur.map_id + 1;
		for (auto move : moves){
			int newY = cur.y + move.first;
			int newX = cur.x+ move.second;
			
			if (!(0 <= newY && newY < 8 && 0 <= newX && newX < 8))
				continue;
			
			if (map_v[cur.map_id][newY][newX] == 0){
				if (!visited[newMapId][newY][newX]){
					visited[newMapId][newY][newX] = true; 
					q.emplace(Node{newY, newX, newMapId});
				}
			}
		}
		q.emplace(Node{cur.y, cur.x, newMapId});
	}
	
	return 0;
}

int main(){
	vector<vector<vector<int> > > map_v(8,
		vector<vector<int> >(8, 
			vector<int>(8)));
	for (int i = 0; i < 8; i++){
		string s;
		cin >> s;
		for (int j = 0; j < 8; j++){
			if (s[j] == '#')
				map_v[0][i][j] = 1;
		}
	}
	// generate 8 possible maps
	for (int i = 1; i < 8; i++)
		map_v[i] = move_wall(map_v[i - 1]);
	
	cout << bfs(map_v) << endl;
	
	return 0;
}