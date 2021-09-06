#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int bfs(int a, int b, int c){
	int tot = a + b + c;
	
	queue<pair<int, int> > q;
	vector<vector<bool> > visited(2000, vector<bool>(2000, false));
	
	q.emplace(make_pair(a, b));
	visited[a][b] = true;
	
	while (!q.empty()){
		pair<int, int> cur = q.front();
		q.pop();
		
		int third = tot - cur.first - cur.second;
		
		if (cur.first == cur.second && cur.second == third)
			return 1;
		
		vector<int> x = {cur.first, cur.second, third};
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				if (x[i] < x[j]){
					vector<int> y = x;
					y[i] += x[i];
					y[j] -= x[i];
					
					pair<int, int> next = make_pair(y[0], y[1]);
					if (!visited[y[0]][y[1]]){
						visited[y[0]][y[1]] = true;
						q.emplace(next);
					}
				}
			}
		}
	}
	
	return 0;
}

int main(){
	freopen("tc.txt", "r", stdin);
	
	int a, b, c;
	cin >> a >> b >> c;
	
	cout << bfs(a, b, c) << endl;
	
	return 0;
}