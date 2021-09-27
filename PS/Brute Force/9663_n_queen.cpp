#include <iostream>
#include <vector>

using namespace std;
using Pos = pair<int, int>;

int n;
vector<bool> row_exist(15, false);
vector<bool> dig_exist(31, false);
vector<bool> dig2_exist(31, false);

bool is_valid(Pos p){
	if (row_exist[p.second])
		return false;
	if (dig_exist[p.first + p.second])
		return false;
	if (dig2_exist[p.second - p.first + n - 1])
		return false;
	
	return true;
}

void bind(Pos p){
	row_exist[p.second] = true;
	dig_exist[p.first + p.second] = true;
	dig2_exist[p.second - p.first + n - 1] = true;
}

void unbind(Pos p){
	row_exist[p.second] = false;
	dig_exist[p.first + p.second] = false;
	dig2_exist[p.second - p.first + n - 1] = false;
}

int fill(int col = 0){
	// base case: reach the end successfully
	if (col == n)
		return 1;
	
	int cnt = 0;
	for (int r = 0; r < n; r++){
		Pos cur = Pos(col, r);
		
		if (!is_valid(cur))
			continue;
		
		bind(cur);
		cnt += fill(col + 1);
		unbind(cur);
	}
	
	return cnt;
}

int main(){
	cin >> n;
	cout << fill() << endl;
	
	return 0;
}