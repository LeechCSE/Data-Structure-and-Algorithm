#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > a(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	
	vector<vector<int> > d(n + 1, vector<int>(m + 1));
	d[1][1] = a[1][1];
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			vector<int> cand = {d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]};
			d[i][j] = *max_element(cand.begin(), cand.end()) + a[i][j];
		}
	}
	
	cout << d[n][m] << endl;
	
	return 0;
}