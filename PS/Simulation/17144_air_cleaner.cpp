#include <iostream>
#include <vector>

using namespace std;
using Pos = pair<int, int>;

void diffuse(vector<vector<int>> &dust){
	int r = dust.size();
	int c = dust[0].size();
	vector<Pos> adjacents = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
	
	vector<vector<int>> dust_og = dust;
	
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (!dust_og[i][j])
				continue;
			
			int diffuse_amount = dust_og[i][j] / 5;
			for (auto adj : adjacents){
				int newR = i + adj.first;
				int newC = j + adj.second;
				
				if (!(0 <= newR && newR < r && 0 <= newC && newC < c))
					continue;
				if (dust_og[newR][newC] == -1)
					continue;
				
				dust[newR][newC] += diffuse_amount;
				dust[i][j] -= diffuse_amount;
			}
		}
	}
}

void clean(vector<vector<int>> &dust, Pos cleaner){
	int r = dust.size();
	int c = dust[0].size();
	
	int cclk_start = cleaner.first;
	for (int i = cclk_start - 1; i > 0; i--)
		dust[i][0] = dust[i - 1][0];
	for (int j = 0; j < c - 1; j++)
		dust[0][j] = dust[0][j + 1];
	for (int i = 0; i < cclk_start; i++)
		dust[i][c - 1] = dust[i + 1][c - 1];
	for (int j = c - 1; j >= 2; j--)
		dust[cclk_start][j] = dust[cclk_start][j - 1];
	dust[cclk_start][1] = 0;
	
	int clk_start = cleaner.second;
	for (int i = clk_start + 1; i < r - 1; i++)
		dust[i][0] = dust[i + 1][0];
	for (int j = 0; j < c - 1; j++)
		dust[r - 1][j] = dust[r - 1][j + 1];
	for (int i = r - 1; i > clk_start; i--)
		dust[i][c - 1] = dust[i - 1][c - 1];
	for (int j = c - 1; j >= 2; j--)
		dust[clk_start][j] = dust[clk_start][j - 1];
	dust[clk_start][1] = 0;
}

int count(vector<vector<int>> dust){
	int rtn = 0;
	int r = dust.size();
	int c = dust[0].size();
	
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (dust[i][j] == -1)
				continue;
			
			rtn += dust[i][j];
		}
	}
	
	return rtn;
}

int main(){
	int r, c, t;
	cin >> r >> c >> t;
	vector<vector<int>> dust(r, vector<int>(c));
	Pos cleaner = {-1, -1};
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			cin >> dust[i][j];
			
			if (dust[i][j] == -1){
				if (cleaner.first == -1)
					cleaner.first = i;
				else
					cleaner.second = i;
			}
				
		}
	}
	
	while (t--){
		diffuse(dust);
		clean(dust, cleaner);
	}
	
	cout << count(dust) << endl;
	
	return 0;
}