#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int NUM_WALLS = 3;

struct Position{
   int y, x;
};

int get_safe(vector<vector<int>> mat, 
      vector<Position> viruses, vector<Position> walls){
   int n = mat.size();
   int m = mat[0].size();
   vector<Position> moves = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
   // set new walls
   for (auto w_pos: walls)
      mat[w_pos.y][w_pos.x] = 1;
   // simulate virus diffusion w/ BFS
   queue<Position> q;
   vector<vector<bool>> visited(n, vector<bool>(m, false));
   for (auto v_pos: viruses){
      q.emplace(v_pos);
      visited[v_pos.y][v_pos.x] = true;
   }
   
   while (!q.empty()){
      Position cur = q.front();
      q.pop();
      
      for (auto move: moves){
         int ny = cur.y + move.y;
         int nx = cur.x + move.x;
         // out-of-bound check
         if (!(0 <= ny && ny < n && 0 <= nx && nx < m))
            continue;
         // wall check
         if (mat[ny][nx] == 1)
            continue;
         // another virus
         else if (mat[ny][nx] == 2)
            continue;
         // visit check
         if (visited[ny][nx])
            continue;
         
         visited[ny][nx] = true;
         mat[ny][nx] = 2;
         q.emplace(Position{ny, nx});
      }
   }
   
   int num_safe = 0;
   for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
         if (mat[i][j] == 0)
            num_safe++;
      }
   }
   
   return num_safe;
}

int main(){
   freopen("tc.txt", "r", stdin);
   
   int answer = 0;
   
   int n, m;
   cin >> n >> m;
   vector<vector<int>> mat(n, vector<int>(m, 0));
   vector<Position> viruses;
   vector<Position> rooms;
   for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
         cin >> mat[i][j];
         
         if (mat[i][j] == 0)
            rooms.emplace_back(Position{i, j});
         else if (mat[i][j] == 2)
            viruses.emplace_back(Position{i, j});
      }
   }
   // #rooms Choose 3
   vector<bool> mask(rooms.size(), false);
   for (int i = 0; i < NUM_WALLS; i++)
      mask[i] = true;
   do{
      vector<Position> walls;
      for (int i = 0; i < (int)rooms.size(); i++){
         if (mask[i])
            walls.emplace_back(rooms[i]);
      }
      
      int num_safe = get_safe(mat, viruses, walls);
      if (answer < num_safe)
         answer = num_safe;
   } while (prev_permutation(mask.begin(), mask.end()));
   
   cout << answer << endl;
   
   return 0;
}