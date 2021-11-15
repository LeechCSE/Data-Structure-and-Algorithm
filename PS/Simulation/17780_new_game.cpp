#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

#define WHITE 0
#define RED 1
#define BLUE 2

#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4

using namespace std;
using Pos = pair<int, int>;

struct Piece{
	Pos pos;
	int dir;
};

pair<Pos, int> get_next(vector<vector<int>> board, Piece p){
	int n = board.size();
	
	Pos next_pos = p.pos; 
	if (p.dir == RIGHT)		next_pos.second++;
	else if (p.dir == LEFT)	next_pos.second--;
	else if (p.dir == UP)	next_pos.first--;
	else if (p.dir == DOWN)	next_pos.first++;
	
	if (!(0 <= next_pos.first && next_pos.first < n &&
			0 <= next_pos.second && next_pos.second < n))
		return make_pair(next_pos, BLUE);
	else
		return make_pair(next_pos, board[next_pos.first][next_pos.second]);
}

bool move(int id, vector<Piece> &pieces, vector<vector<deque<int>>> &arr, 
		Pos np, bool flip = false){
	if (flip)
		reverse(arr[pieces[id].pos.first][pieces[id].pos.second].begin(), 
			arr[pieces[id].pos.first][pieces[id].pos.second].end());
	
	Pos op = pieces[id].pos;
	while (!arr[op.first][op.second].empty()){
		int cur_id = arr[op.first][op.second].back();
		arr[op.first][op.second].pop_back();
		arr[np.first][np.second].emplace_front(cur_id);
		pieces[cur_id].pos = np;
	}
	
	return arr[np.first][np.second].size() >= 4;
}

bool play(vector<vector<int>> board, 
		vector<vector<deque<int>>> &arrangement, vector<Piece> &pieces){
	for (int id = 0; id < (int)pieces.size(); id++){
		Piece cur_piece = pieces[id];
		
		if (arrangement[cur_piece.pos.first][cur_piece.pos.second].back() != id)
			continue;
		
		pair<Pos, int> next_info = get_next(board, cur_piece);
		Pos next_pos = next_info.first;
		int next_color = next_info.second;
		
		if (next_color == WHITE){
			if (move(id, pieces, arrangement, next_pos))
				return true;
		}
		else if (next_color == RED){
			if (move(id, pieces, arrangement, next_pos, true))
				return true;
		}
		else if (next_color == BLUE){
			if (cur_piece.dir == RIGHT)		pieces[id].dir = LEFT;
			else if (cur_piece.dir == LEFT) 	pieces[id].dir = RIGHT;
			else if (cur_piece.dir == UP) 	pieces[id].dir = DOWN;
			else if (cur_piece.dir == DOWN) 	pieces[id].dir = UP;
			
			pair<Pos, int> next_info = get_next(board, pieces[id]);
			Pos next_pos = next_info.first;
			int next_color = next_info.second;
			
			if (next_color == WHITE){
				if (move(id, pieces, arrangement, next_pos))
					return true;
			}
			else if (next_color == RED){
				if (move(id, pieces, arrangement, next_pos, true))
					return true;
			}
		}
	}
	
	return false;
}

int main(){
	int n, k;
	cin >> n >> k;
	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> board[i][j];
		}
	}
	vector<vector<deque<int>>> arrangement(n, vector<deque<int>>(n));
	vector<Piece> pieces;
	for (int id = 0; id < k; id++){
		int y, x, dir;
		cin >> y >> x >> dir;
		
		pieces.emplace_back(Piece{Pos(y - 1, x - 1), dir});
		arrangement[y - 1][x - 1].emplace_back(id);
	}
	
	bool done = false;
	int turn;
	for (turn = 1; turn <= 1000; turn++){
		if (play(board, arrangement, pieces)){
			done = true;
			break;
		}
	}
	
	if (done)
		cout << turn << endl;
	else
		cout << -1 << endl;
	
	return 0;
}