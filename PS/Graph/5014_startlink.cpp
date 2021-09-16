#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int tot, int start, int end, int up, int down){
	vector<int> moves = {up, -down};
	queue<int> q;
	vector<int> cnt(tot + 1, -1);
	
	q.emplace(start);
	cnt[start] = 0;
	
	while (!q.empty()){
		int cur = q.front();
		q.pop();
		
		if (cur == end)
			break;
		
		for (auto move : moves){
			int next = cur + move;
			
			if (!(1 <= next && next <= tot))
				continue;
			
			if (cnt[next] == -1){
				cnt[next] = cnt[cur] + 1;
				q.emplace(next);
			}
		}
	}
	
	return cnt[end];
}

int main(){
	int tot, start, end, up, down;
	cin >> tot >> start >> end >> up >> down;
	
	int out = bfs(tot, start, end, up, down);
	if (out == -1)
		cout << "use the stairs" << endl;
	else
		cout << out << endl;
	
	return 0;
}