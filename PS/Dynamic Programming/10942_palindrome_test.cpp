#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int m;
	cin >> m;
	
	vector<vector<int> > d(n, vector<int>(n));
	for (int i = 0; i < n - 1; i++)
		d[i][i + 1] = (a[i] ==  a[i + 1]);
	for (int i = 0; i < n; i++)
		d[i][i] = 1;
	// diagonal direction
	for (int k = 3; k <= n; k++){
		for (int i = 0; i <= n - k; i++){
			int j = i + k - 1;
			d[i][j] = d[i + 1][j - 1] && (a[i] == a[j]);
		}
	}
	
	while (m--){
		int s, e;
		cin >> s >> e;
		cout << d[s - 1][e - 1] << endl;
	}
	
	return 0;
}