#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while (true){
        // check 4-blocks
        set<pair<int, int>> hits;
        for (int i = 0; i < m - 1; i++){
            for (int j = 0; j < n - 1; j++){
                if (board[i][j] == 'X') continue;
                
                char cur = board[i][j];
                if (cur == board[i][j + 1] &&
                    cur == board[i + 1][j] &&
                    cur == board[i + 1][j + 1]){
                    
                    hits.insert(make_pair(i, j));
                    hits.insert(make_pair(i, j + 1));
                    hits.insert(make_pair(i + 1, j));
                    hits.insert(make_pair(i + 1, j + 1));
                }
            }
        }
        // base case
        if (hits.size() == 0) break;
        // erase 4-blocks
        for (auto cur: hits){
            int i = cur.first; 
            int j = cur.second;
            
            for (int k = 1; k <= i; k++) 
					board[i - k + 1][j] = board[i - k][j];
            board[0][j] = 'X';
        }
        
        answer += hits.size();
        hits.clear();
    }
    
    return answer;
}