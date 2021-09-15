#include <iostream>
#include <map>
#include <queue>

using namespace std;
using ull = unsigned long long;

void bfs(int s, int t){
	queue<ull> q;
	map<ull, bool> visited;
	map<ull, int> cnt;
	map<ull, string> parent;
	
	q.emplace(s);
	visited[s] = true;
	cnt[s] = 0;
	
	while (!q.empty()){
		ull cur = q.front();
		q.pop();
		
		if (cur == t)
			break;
		
		vector<ull> nexts = {cur * cur, cur + cur, cur - cur};
		vector<string> symbols = {"*", "+", "-"};
		if (cur != 0){
			nexts.emplace_back(cur / cur);
			symbols.emplace_back("/");
		}
	
		for (int i = 0; i < nexts.size(); i++){
			ull next = nexts[i];
			
			if (next <= t){
				if (!visited[next]){
					visited[next] = true;
					q.emplace(next);
					cnt[next] = cnt[cur] + 1;
					parent[next] = parent[cur] + symbols[i];
				}
			}
		}
	}
	
	if (!visited[t])
		cout << -1 << endl;
	else{
		if (cnt[t] == 0)
			cout << 0 << endl;
		else{
			cout << parent[t] << endl;
		}
	}
}

int main(){
	int s, t;
	cin >> s >> t;
	
	bfs(s, t);
	
	return 0;
}