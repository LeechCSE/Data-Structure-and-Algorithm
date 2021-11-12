#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Pos = pair<int, int>;

struct Shark{
	int speed, dir, size;
	bool is_updated;
	Shark() : speed(-1), dir(-1), size(-1), is_updated(false){}
	Shark(int spd, int d, int s) : speed(spd), dir(d), 
		size(s), is_updated(false){}
	Shark(int spd, int d, int s, bool iu) : speed(spd), dir(d), 
		size(s), is_updated(iu){}
	bool operator==(Shark shark){
		return (this->speed == shark.speed 
			&& this->dir == shark.dir && this->size == shark.size);
	}
	bool operator!=(Shark shark){ return !(*this == shark); }
};

int catch_sharks(int col, vector<vector<queue<Shark>>> &pool){
	int r = pool.size();
	
	for (int i = 0; i < r; i++){
		if (!pool[i][col].empty()){
			Shark caught = pool[i][col].front();
			pool[i][col].pop();
			
			if (caught == Shark(-1, -1, -1))
				continue;
			
			return caught.size;
		}
	}
	
	return 0;
}

Pos get_next_pos(Shark &cur, Pos cur_pos, int r, int c){
	Pos next = cur_pos;
	int spd = cur.speed;
	int dir = cur.dir;
	
	while (spd != 0){
		if (dir == 1){
			if (next.first - 1 < 0){
				dir = 2;
				next.first++;
			}
			else
				next.first--;
			
			spd--;
		}
		else if (dir == 2){
			if (next.first + 1 >= r){
				dir = 1;
				next.first--;
			}
			else
				next.first++;
			
			spd--;
		}
		else if (dir == 3){
			if (next.second + 1 >= c){
				dir = 4;
				next.second--;
			}
			else
				next.second++;
			
			spd--;
		}
		else if (dir == 4){
			if (next.second - 1 < 0){
				dir = 3;
				next.second++;
			}
			else
				next.second--;
			
			spd--;
		}
	}
	cur.dir = dir;
	
	return next;
}

void move_sharks(vector<vector<queue<Shark>>> &pool){
	int r = pool.size();
	int c = pool[0].size();
	// move sharks
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (!pool[i][j].empty()){
				if (pool[i][j].front().size == Shark(-1, -1, -1))
					continue;
				
				if (!pool[i][j].front().is_updated){
					Shark cur = pool[i][j].front();
					pool[i][j].pop();
					cur.is_updated = true;
					
					Pos next_pos = get_next_pos(cur, {i, j}, r, c);
					pool[next_pos.first][next_pos.second].emplace(cur);
				}
			}
		}
	}
	// leave the biggest shark per grid
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			Shark survived;
			
			while(!pool[i][j].empty()){
				Shark cur = pool[i][j].front();
				pool[i][j].pop();
				
				if (cur.size > survived.size)
					survived = cur;
			}
			
			survived.is_updated = false;
			pool[i][j].emplace(survived);
		}
	}
}

int main(){
	int r, c, m;
	cin >> r >> c >> m;
	
	vector<vector<queue<Shark>>> pool(r, vector<queue<Shark>>(c));
	for (int i = 0; i < m; i++){
		int y, x, spd, dir, size;
		cin >> y >> x >> spd >> dir >> size;
		
		pool[y - 1][x - 1].emplace(Shark(spd, dir, size));
	}
	
	int ans = 0;
	for (int col = 0; col < c; col++){
		ans += catch_sharks(col, pool);
		move_sharks(pool);
	}
	
	cout << ans << endl;
	
	return 0;
}