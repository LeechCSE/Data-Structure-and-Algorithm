#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Pos = pair<int, int>;

struct Info{
	Pos coor;
	int fish_size, time;
};

int closest_path(vector<vector<int> > map, Pos start, Pos end, int size){
	int n = map.size();
	vector<Pos> moves = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
	
	queue<Pos> q;
	vector<vector<int> > cnt(n, vector<int>(n, -1));
	
	q.emplace(start);
	cnt[start.first][start.second] = 0;
	
	while (!q.empty()){
		Pos cur = q.front();
		q.pop();
		
		if (cur == end)
			break;
		
		for (auto move : moves){
			int newY = cur.first + move.first;
			int newX = cur.second + move.second;
			
			if (!(0 <= newY && newY < n && 0 <= newX && newX < n))
				continue;
			if (map[newY][newX] > size)
				continue;
			
			if (cnt[newY][newX] == -1){
				q.emplace(Pos{newY, newX});
				cnt[newY][newX] = cnt[cur.first][cur.second] + 1;
			}
		}
	}
	
	return cnt[end.first][end.second];
}

Info find_fish(vector<vector<int> > map, Pos cur, int size){
	int path = -1;
	Info rtn = {Pos(-1, -1), -1, -1};
	
	int n = map.size();
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (0 < map[i][j] && map[i][j] < size){
				if (path == -1){
					path = closest_path(map, cur, Pos(i, j), size);
					rtn = {Pos(i, j), map[i][j], path};
				}
				else{
					int p = closest_path(map, cur, Pos(i, j), size);
					if (p != -1){
						if (path > p){
							path = p;
							rtn = {Pos(i, j), map[i][j], p};
						}
					}
				}
			}
		}
	}
	
	return rtn;
}

int sol(vector<vector<int> > &map, Pos start){
	int tot_time = 0;
	int size = 2;
	int size_buf = size;
	
	while (true){
		Info fish_info = find_fish(map, start, size);
		
		if (fish_info.time == -1)
			break;
		
		start = fish_info.coor;
		map[fish_info.coor.first][fish_info.coor.second] = 0;
		tot_time += fish_info.time;
		
		size_buf--;
		if (size_buf == 0){
			size++;
			size_buf = size;
		}
	}
	
	return tot_time;
}

int main(){
	int n;
	cin >> n;
	
	vector<vector<int> > map(n, vector<int>(n));
	Pos start;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int in;
			cin >> in;
			
			if (in == 9){
				start = Pos(i, j);
				map[i][j] = 0;
			}
			else
				map[i][j] = in;
		}
	}
	
	cout << sol(map, start) << endl;
	
	return 0;
}