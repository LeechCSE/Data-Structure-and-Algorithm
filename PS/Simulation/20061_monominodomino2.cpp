#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int RED_ROW = 4;
const int RED_COL = 4;
const int BLUE_ROW = 4;
const int BLUE_COL = 6;
const int GREEN_ROW = 6;
const int GREEN_COL = 4;

vector<vector<bool>> red(RED_ROW, vector<bool>(RED_COL, false));
vector<vector<bool>> blue(BLUE_ROW, vector<bool>(BLUE_COL, false));
vector<vector<bool>> green(GREEN_ROW, vector<bool>(GREEN_COL, false));

void print(){
	for (int i = 0; i < RED_ROW; i++){
		for (int j = 0; j < RED_COL + BLUE_COL; j++){
			if (0 <= j && j < RED_COL)
				cout << red[i][j] << " ";
			else
				cout << blue[i][j - 4] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < GREEN_ROW; i++){
		for (int j = 0; j < GREEN_COL; j++){
			cout << green[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void place1(int x, int y){
	// blue
	auto room = find(blue[x].begin(), blue[x].end(), true);
	*prev(room, 1) = true;
	// green
	int index;
	for (index = 0; index < GREEN_ROW; index++){
		if (green[index][y])
			break;
	}
	green[index - 1][y] = true;
}

void place2(int x, int y){
	// blue
	auto room = find(blue[x].begin(), blue[x].end(), true);
	*prev(room, 1) = true;
	*prev(room, 2) = true;
	// green
	int index1;
	for (index1 = 0; index1 < GREEN_ROW; index1++){
		if (green[index1][y])
			break;
	}
	int index2;
	for (index2 = 0; index2 < GREEN_ROW; index2++){
		if (green[index2][y + 1])
			break;
	}
	index1--; index2--;
	
	int less = min(index1, index2);
	green[less][y] = true;
	green[less][y + 1] = true;
}

void place3(int x, int y){
	// blue
	int index1 = distance(blue[x].begin(), 
		find(blue[x].begin(), blue[x].end(), true));
	int index2 = distance(blue[x + 1].begin(), 
		find(blue[x + 1].begin(), blue[x + 1].end(), true));
	int less = min(index1, index2);
	blue[x][less - 1] = true;
	blue[x + 1][less - 1] = true;
	// green
	int index;
	for (index = 0; index < GREEN_ROW; index++){
		if (green[index][y])
			break;
	}
	green[index - 1][y] = true;
	green[index - 2][y] = true;
}

void place(int t, int x, int y){
	if (t == 1)			place1(x, y);
	else if (t == 2)	place2(x, y);
	else 					place3(x, y);
}

bool filled(vector<bool> v){
	for (auto el: v)
		if (!el) return false;
	return true;
}

void shift_right(int target_col){
	for (int i = 0; i < BLUE_ROW; i++)
		blue[i][target_col] = false;
	for (int j = target_col; j > 0; j--){
		for (int i = 0; i < BLUE_ROW; i++){
			blue[i][j] = blue[i][j - 1];
		}
	}
	for (int i = 0; i < BLUE_ROW; i++)
		blue[i][0] = false;
}

void shift_down(int target_row){
	green[target_row].flip();
	for (int j = target_row; j > 0; j--)
		green[j] = green[j - 1];
	fill(green[0].begin(), green[0].end(), false);
}

int score(){
	int rtn = 0;
	// blue
	for (int col_index = 0; col_index < BLUE_COL; col_index++){
		bool filled = true;
		for (int i = 0; i < BLUE_ROW; i++)
			if (!blue[i][col_index]) filled = false;
		
		if (filled){
			rtn++;
			shift_right(col_index);
		}
	}
	// green
	for (int i = 0; i < GREEN_ROW; i++){
		if (filled(green[i])){
			rtn++;
			shift_down(i);
		}
	}
	
	return rtn;
}

void special_check(){
	int cnt = 0;
	// blue
	for (int j = 0; j < 2; j++){
		for (int i = 0; i < BLUE_ROW; i++){
			if (blue[i][j]){
				cnt++;
				break;
			}
		}
	}
	while (cnt--)
		shift_right(BLUE_COL - 1);
	// green
	cnt = 0;
	for (int i = 0; i < 2; i++){
		for (auto el: green[i]){
			if (el){
				cnt++;
				break;
			}
		}
	}
	while (cnt--)
		shift_down(GREEN_ROW - 1);
}

int count_blocks(){
	int rtn = 0;
	
	for (int i = 0; i < BLUE_ROW; i++){
		for (int j = 0; j < BLUE_COL; j++){
			if (blue[i][j])
				rtn++;
		}
	}
	for (int i = 0; i < GREEN_ROW; i++){
		for (int j = 0; j < GREEN_COL; j++){
			if (green[i][j])
				rtn++;
		}
	}
	
	return rtn;
}

int main(){
	freopen("tc.txt", "r", stdin);
	
	int n;
	cin >> n;
	
	int scr = 0;
	while (n--){
		int t, x, y;
		cin >> t >> x >> y;
		
		place(t, x, y);
		scr += score();
		special_check();
	}
	
	cout << scr << endl << count_blocks() << endl;
	
	return 0;
}