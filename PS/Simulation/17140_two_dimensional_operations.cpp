#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

void count_sort(vector<int> &v){
	set<int> s(v.begin(), v.end());
	map<int, int> m;
	for (auto el : s){
		if (el == 0)
			continue;
		
		m[el] = count(v.begin(), v.end(), el);
	}
	
	vector<pair<int, int>> vm(m.begin(), m.end());
	sort(vm.begin(), vm.end(), [](pair<int, int> p1, pair<int, int> p2){
		return p1.second < p2.second;
	});
	
	vector<int> rtn;
	for (auto el : vm){
		rtn.emplace_back(el.first);
		rtn.emplace_back(el.second);
	}
	
	v = rtn;
}

void r_operation(vector<vector<int>> &mat){
	int max_size = 0;
	
	for (auto &row : mat){
		count_sort(row);
		if (max_size < row.size())
			max_size = row.size();
	}
	
	for (auto &row : mat){
		if (row.size() < max_size)
			row.resize(max_size, 0);
	}
}

void transpose(vector<vector<int>> &mat){
	int r = mat.size();
	int c = mat[0].size();
	
	vector<vector<int>> transposed(c, vector<int>(r));
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			transposed[j][i] = mat[i][j];
		}
	}
	
	mat.swap(transposed);
}

void c_operation(vector<vector<int>> &mat){
	transpose(mat);
	r_operation(mat);
	transpose(mat);
}

bool check(vector<vector<int>> mat, int r, int c, int k){
	return mat[r - 1][c - 1] == k;
}

void chop(vector<vector<int>> &mat){
	mat.resize(100);
	for (auto row : mat)
		row.resize(100);
}

void print(vector<vector<int>> mat){
	for (auto row : mat){
		for (auto el : row){
			cout << el << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main(){
	int r, c, k;
	cin >> r >> c >> k;
	vector<vector<int>> mat(3, vector<int>(3));
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cin >> mat[i][j];
		}
	}
	
	int time = -1;
	bool done = false;
	
	while (time++ != 101){
		int num_row = mat.size();
		int num_col = mat[0].size();
		
		if (num_row >= r && num_col >= c){
			if (check(mat, r, c, k)){
				done = true;
				break;
			}
		}
		
		if (num_row >= num_col)
			r_operation(mat);
		else
			c_operation(mat);
		
		if (num_row > 100)
			mat.resize(100);
		if (num_col > 100){
			for (auto row : mat)
				row.resize(100);
		}
	}
	
	if (done)
		cout << time << endl;
	else
		cout << -1 << endl;
	
	return 0;
}