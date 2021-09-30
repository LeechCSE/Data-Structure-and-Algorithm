#include <iostream>
#include <vector>

using namespace std;
using Pos = pair<int, int>;

int lcs(vector<char> v){
	int max = 0;
	int acc = 0;
	char cur = v[0];
	
	for (auto el : v){
		if (el == cur)
			acc++;
		else{
			if (max < acc)
				max = acc;
			
			acc = 1;
			cur = el;
		}
	}
	
	if (max < acc)
		max = acc;
	
	return max;
}

vector<vector<char> > rotate(vector<vector<char> > mat){
	int n = mat.size();
	vector<vector<char> > out(n, vector<char>(n));
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			out[i][j] = mat[n - 1 - j][i];
		}
	}
	
	return out;
}

int sol(vector<vector<char> > mat){
	int rtn = 0;
	
	for (auto row : mat){
		int out = lcs(row);
		if (rtn < out)
			rtn = out;	
	}
	for (auto col : rotate(mat)){
		int out = lcs(col);
		if (rtn < out)
			rtn = out;	
	}
	
	return rtn;
}

int main(){
	int n;
	cin >> n;
	vector<vector<char> > mat(n, vector<char>(n));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> mat[i][j];
		}
	}
	
	int ans = sol(mat);
	vector<Pos> adjacents = { {1, 0}, {0, 1} };
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			for (auto adj : adjacents){
				int newI = i + adj.first;
				int newJ = j + adj.second;
				
				if (!(0 <= newI && newI < n && 0 <= newJ && newJ < n))
					continue;
				// swap
				swap(mat[i][j], mat[newI][newJ]);
				int temp = sol(mat);
				if (ans < temp)
					ans = temp;
				// restore for the next iteration
				swap(mat[i][j], mat[newI][newJ]);
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}