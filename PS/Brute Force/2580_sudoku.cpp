#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<vector<int> > mat(9, vector<int>(9));
vector<vector<bool> > row_check(9, vector<bool>(9, false));
vector<vector<bool> > col_check(9, vector<bool>(9, false));
vector<vector<bool> > sqr_check(9, vector<bool>(9, false));

int sqr_hash(int y, int x){ return y / 3 * 3 + x / 3; }
void print(){
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

void solve(int id = 0){
	if (id == 81){
		print();
		exit(EXIT_SUCCESS);
	}
	
	int y = id / 9;
	int x = id % 9;
	
	if (mat[y][x] != 0)
		solve(id + 1);
	else{
		for (int k = 1; k <= 9; k++){
			if (!row_check[y][k] && 
				 !col_check[x][k] && 
				 !sqr_check[sqr_hash(y, x)][k]){
				row_check[y][k] = true;
				col_check[x][k] = true;
				sqr_check[sqr_hash(y, x)][k] = true;
				mat[y][x] = k;
				
				solve(id + 1);
				
				row_check[y][k] = false;
				col_check[x][k] = false;
				sqr_check[sqr_hash(y, x)][k] = false;
				mat[y][x] = 0;
			}	
		}
	}
}

int main(){
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			cin >> mat[i][j];
			
			if (mat[i][j] != 0){
				row_check[i][mat[i][j]] = true;
				col_check[j][mat[i][j]] = true;
				sqr_check[sqr_hash(i, j)][mat[i][j]] = true;
			}
		}
	}
	
	solve();
	
	return 0;
}