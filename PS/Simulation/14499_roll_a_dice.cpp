#include <iostream>
#include <vector>

using namespace std;

struct Dice{
	int bot, up, north, south, east, west;
	Dice(): bot(0), up(0), north(0), south(0), east(0), west(0){}
	
	void roll_north(){
		int b_temp = bot;
		int u_temp = up;
		
		bot = north;
		up = south;
		north = u_temp;
		south = b_temp;
	}
	void roll_south(){
		int b_temp = bot;
		int u_temp = up;
		
		bot = south;
		up = north;
		north = b_temp;
		south = u_temp;
	}
	void roll_east(){
		int b_temp = bot;
		int u_temp = up;
		
		bot = east;
		up = west;
		east = u_temp;
		west = b_temp;
	}
	void roll_west(){
		int b_temp = bot;
		int u_temp = up;
		
		bot = west;
		up = east;
		east = b_temp;
		west = u_temp;
	}
};

int main(){
	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;
	
	vector<vector<int> > mat(n, vector<int>(m));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> mat[i][j];
		}
	}
	
	Dice d;
	while (k--){
		int op;
		cin >> op;
		
		if (op == 1){ // E
			if (!(y + 1 < m))
				continue;
			y++;
			d.roll_east();
		}
		else if (op == 2){ // W
			if (!(y - 1 >= 0))
				continue;
			y--;
			d.roll_west();
		}
		else if (op == 3){ // N
			if (!(x - 1 >= 0))
				continue;
			x--;
			d.roll_north();
		}
		else{ // S
			if (!(x + 1 < n))
				continue;
			x++;
			d.roll_south();
		}
		
		if (mat[x][y] == 0)
			mat[x][y] = d.bot;
		else{
			d.bot = mat[x][y];
			mat[x][y] = 0;
		}
		
		cout << d.up << endl;
	}

	return 0;
}