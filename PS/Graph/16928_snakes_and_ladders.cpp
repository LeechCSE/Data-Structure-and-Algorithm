#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int bfs(vector<int> board){
	queue<int> q;
	vector<int> cnt(board.size(), -1);
	
	int start = 1;
	int end = 100;
	q.emplace(start);
	cnt[start] = 0;
	
	while (!q.empty()){
		int cur = q.front();
		q.pop();
		
		if (cur == end)
			break;
		
		for (int dice = 1; dice <= 6; dice++){
			int newPos = cur + dice;
			
			if (newPos <= end){
				if (board[newPos] != 0)
					newPos = board[newPos];
				
				if (cnt[newPos] == -1){
					cnt[newPos] = cnt[cur] + 1;
					q.emplace(newPos);
				}
			}
		}
	}
	
	return cnt[100];
}

int main(){
	vector<int> board(101);
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n + m; i++){
		int from, to;
		cin >> from >> to;
		
		board[from] = to;
	}
	
	cout << bfs(board) << endl;
	
	return 0;
}