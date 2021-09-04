#include <vector>
#include <queue>

using namespace std;
using Pos = pair<int, int>;

int bfs(vector<vector<int> > &picture, Pos start){
    int m = picture.size();
    int n = picture[0].size();
    vector<Pos> moves = {
        {-1, 0}, {1, 0}, {0, 1}, {0, -1}
    };
    
    int cnt = 0;
    int area_code = picture[start.second][start.first];
    queue<Pos> q;
    vector<vector<bool> > visited(m, vector<bool>(n, false));
    
    q.emplace(start);
    visited[start.second][start.first] = true;
    picture[start.second][start.first] = 0;
    
    while (!q.empty()){
        Pos cur = q.front();
        q.pop();
        cnt++;
        
        for (auto move : moves){
            int adjX = cur.first + move.first;
            int adjY = cur.second + move.second;
            
            if (0 <= adjX && adjX < n && 0 <= adjY && adjY < m){
                if (picture[adjY][adjX] == area_code){
                    if (!visited[adjY][adjX]){
                        picture[adjY][adjX] = 0;
                        visited[adjY][adjX] = true;
                        q.emplace(Pos(adjX, adjY));
                    }
                }
            }
        }
    }
    
    return cnt;
}

vector<int> solution(int m, int n, vector<vector<int> > picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
   
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (picture[i][j] != 0){
                int size = bfs(picture, Pos(j, i));
                
                if (max_size_of_one_area < size)
                    max_size_of_one_area = size;
                
                number_of_area++;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}