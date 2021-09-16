#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using Pos = pair<int, int>;

struct Node{
	int y, x, num_knights;
};

int bfs(vector<vector<int> > board, int k){
	int n = board.size();
	int m = board[0].size();
	vector<Pos> monkey_moves = {
		{-1, 0}, {1, 0}, {0, 1}, {0, -1}
	};
	vector<Pos> knight_moves = {
		{-2, 1}, {-1, 2}, {1, 2}, {2, 1},
		{2, -1}, {1, -2}, {-1, -2}, {-2, -1}
	};
	vector<vector<Pos> > moves = { monkey_moves, knight_moves };
	
	queue<Node> q;
	vector<vector<vector<int> > > cnt(n, 
								vector<vector<int> >(m, 
												vector<int>(k + 1, -1)));
	
	q.emplace(Node{0, 0, 0});
	for (int i = 0; i <= k; i++)
		cnt[0][0][i] = 0;
	
	while (!q.empty()){
		Node cur = q.front();
		q.pop();
		
		if (cur.y == n - 1 && cur.x == m - 1)
			break;
		
		for (int i = 0; i < 2; i++){
			for (auto move : moves[i]){
				int newY = cur.y + move.first;
				int newX = cur.x + move.second;
				
				if (!(0 <= newY && newY < n && 0 <= newX && newX < m))
					continue;
				if (board[newY][newX] == 1)
					continue;
				
				if (i == 1){ // knight_move
					if (cur.num_knights > k)
						continue;

					if (cnt[newY][newX][cur.num_knights + 1] == -1){
						cnt[newY][newX][cur.num_knights + 1] = 
							cnt[cur.y][cur.x][cur.num_knights] + 1;
						q.emplace(Node{newY, newX, cur.num_knights + 1});
					}
				}
				else{ // monkey_move
					if (cnt[newY][newX][cur.num_knights] == -1){
						cnt[newY][newX][cur.num_knights] = 
							cnt[cur.y][cur.x][cur.num_knights] + 1;
						q.emplace(Node{newY, newX, cur.num_knights});
					}
				}
			}
		}
	}
	
	int rtn = -1;
	for (int i = 0; i <= k; i++){
		if (cnt[n - 1][m - 1][i] == -1)
			continue;
		if (rtn == -1)
			rtn = cnt[n - 1][m - 1][i];
		else if (rtn > cnt[n - 1][m - 1][i])
			rtn = cnt[n - 1][m - 1][i];
	}
	
	return rtn;
}

int main(){
	int k, m, n;
	cin >> k >> m >> n;
	
	vector<vector<int> > board(n, vector<int>(m));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> board[i][j];
		}
	}
	
	cout << bfs(board, k) << endl;
	
	return 0;
}