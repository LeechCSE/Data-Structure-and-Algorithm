#include <iostream>
#include <vector>

using namespace std;

int ans = 0;

void compress_left(vector<int> &row){
   int n = row.size();
   
   vector<int> tmp(n, 0);
   int cur = 0;
   
   for (int j = 0; j < n; j++)
      if (row[j] != 0) tmp[cur++] = row[j];
   
   row = tmp;
}

void compress_right(vector<int> &row){
   int n = row.size();
   
   vector<int> tmp(n, 0);
   int cur = n - 1;
   
   for (int j = n - 1; j >= 0; j--)
      if (row[j] != 0) tmp[cur--] = row[j];
   
   row = tmp;
}

void combine_left(vector<int> &row){
   auto it = row.begin();
   
   while (it != row.end()){
      if (*it == 0){ 
         advance(it, 1);
         continue;
      }
      
      if (*it == *next(it)){
         *it *= 2;
         *next(it) = 0;
         advance(it, 2);
      }
      else
         advance(it, 1);
   }
   compress_left(row);
}

void combine_right(vector<int> &row){
   auto it = row.rbegin();
   
   while (it != row.rend()){
      if (*it == 0){ 
         advance(it, 1);
         continue;
      }
      
      if (*it == *next(it)){
         *it *= 2;
         *next(it) = 0;
         advance(it, 2);
      }
      else
         advance(it, 1);
   }
   compress_right(row);
}

vector<vector<int>> transpose(vector<vector<int>> mat){
   int n = mat.size();
   vector<vector<int>> transposed(n, vector<int>(n));
   
   for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
         transposed[j][i] = mat[i][j];
      }
   }
   
   return transposed;
}

vector<vector<int>> move_left(vector<vector<int>> mat){
   int n = mat.size();
   
   for (int i = 0; i < n; i++){
      compress_left(mat[i]);
      combine_left(mat[i]);
   }
   
   return mat;
}

vector<vector<int>> move_right(vector<vector<int>> mat){
   int n = mat.size();
   
   for (int i = 0; i < n; i++){
      compress_right(mat[i]);
      combine_right(mat[i]);
   }
   
   return mat;
}

vector<vector<int>> move_up(vector<vector<int>> mat){
   mat = transpose(mat);
   mat = move_left(mat);
   return transpose(mat);
}

vector<vector<int>> move_down(vector<vector<int>> mat){
   mat = transpose(mat);
   mat = move_right(mat);
   return transpose(mat);
}

int get_max(vector<vector<int>> mat){
   int n = mat.size();
   int rtn = 0;
   
   for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
         if (rtn < mat[i][j])
            rtn = mat[i][j];
      }
   }
   
   return rtn;
}

void solve(vector<vector<int>> mat, int depth = 0){
   if (depth == 5){
      int local_max = get_max(mat);
      
      if (ans < local_max)
         ans = local_max;
      
      return;
   }
   
   solve(move_left(mat), depth + 1);
   solve(move_right(mat), depth + 1);
   solve(move_up(mat), depth + 1);
   solve(move_down(mat), depth + 1);
}

int main(){
   int n;
   cin >> n;
   vector<vector<int>> mat(n, vector<int>(n));
   for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
         cin >> mat[i][j];
      }
   }
   
   solve(mat);
   cout << ans << endl;
   
   return 0;
}