#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

bool is_prime(string s){
	int x = stoi(s);
	if (x < 2)
		return false;
	
	for (int i = 2; i * i <= x; i++){
		if (x % i == 0)
			return false;
	}
	
	return true;
}

int bfs(string start, string end){
	queue<string> q;
	map<string, bool> visited;
	map<string, int> cnt;
	
	q.emplace(start);
	visited[start] = true;
	cnt[start] = 0;
	
	while (!q.empty()){
		string cur = q.front();
		q.pop();
		
		if (cur == end)
			return cnt[end];
			
		for (int i = 0; i <= 3; i++){
			for (int j = 0; j <= 9; j++){
				if (i == 0 && j == 0)
					continue;
				
				string next = cur;
				next[i] = j + 48;
				
				if (is_prime(next)){
					if (!visited[next]){
						q.emplace(next);
						visited[next] = true;
						cnt[next] = cnt[cur] + 1;
					}
				}
			}
		}
	}
	
	return -1;
}

int main(){
	int t;
	cin >> t;
	
	while (t--){
		string start, end;
		cin >> start >> end;
		
		int out = bfs(start, end);
		
		if (out == -1)
			cout << "Impossible" << endl;
		else
			cout << out << endl;
	}
	
	return 0;
}