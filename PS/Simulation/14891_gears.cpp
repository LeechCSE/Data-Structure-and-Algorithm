#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

void rotate(bitset<8> &g, int dir){
	if (dir == 1){
		int lsb = g[0];
		g >>= 1;
		g[7] = lsb;
	}
	else{
		int msb = g[7];
		g <<= 1;
		g[0] = msb;
	}
}

void propagate(vector<bitset<8>> &gears, int which, int dir){
	vector<bitset<8>> gears_temp = gears;
	
	rotate(gears_temp[which], dir);
	if (which == 0){
		if (gears[0][5] != gears[1][1]){
			rotate(gears_temp[1], dir == 1 ? -1 : 1);
			
			if (gears[1][5] != gears[2][1]){
				rotate(gears_temp[2], dir);
				
				if (gears[2][5] != gears[3][1]){
					rotate(gears_temp[3], dir == 1 ? -1 : 1);
				}
			}
		}
	}
	else if (which == 1){
		if (gears[0][5] != gears[1][1])
			rotate(gears_temp[0], dir == 1 ? -1 : 1);
		if (gears[1][5] != gears[2][1]){
			rotate(gears_temp[2], dir == 1 ? -1 : 1);
			
			if (gears[2][5] != gears[3][1])
				rotate(gears_temp[3], dir);
		}
	}
	else if (which == 2){
		if (gears[1][5] != gears[2][1]){
			rotate(gears_temp[1], dir == 1 ? -1 : 1);
			
			if (gears[0][5] != gears[1][1]){
				rotate(gears_temp[0], dir);
			}
		}
		if (gears[2][5] != gears[3][1])
			rotate(gears_temp[3], dir == 1 ? -1 : 1);
	}
	else{
		if (gears[3][1] != gears[2][5]){
			rotate(gears_temp[2], dir == 1 ? -1 : 1);
			
			if (gears[2][1] != gears[1][5]){
				rotate(gears_temp[1], dir);
				
				if (gears[1][1] != gears[0][5])
					rotate(gears_temp[0], dir == 1 ? -1 : 1);
			}
		}
	}
	
	gears = gears_temp;
}

int score(vector<bitset<8>> gears){
	int rtn = 0;
	
	for (int i = 0; i < 4; i++)
		rtn += pow(2, i) * gears[i][7];
	
	return rtn;
}

int main(){
	vector<bitset<8>> gears(4);
	for (int i = 0; i < 4; i++)
		cin >> gears[i];
	
	int t;
	cin >> t;
	while (t--){
		int which, dir;
		cin >> which >> dir;
		which--;
		
		propagate(gears, which, dir);
	}
	cout << score(gears) << endl;

	return 0;
}