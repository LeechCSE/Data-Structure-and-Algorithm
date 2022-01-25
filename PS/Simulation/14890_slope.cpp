#include <iostream>
#include <vector>

using namespace std;

bool is_valid(vector<int> row, int l){
   int n = row.size();
   vector<bool> used(n, false);
   int i = 0; int j = 1;
    
   while (j < n){
      // height difference > 1
      if (abs(row[i] - row[j]) > 1)
         return false;
      
      if (row[i] < row[j]){ // increasing: check backwards
         int back_i = i;
         
         while (true){
            // out-of-bound
            if (back_i < 0)
               return false;
            // another wall before L blocks
            if (row[i] != row[back_i])
               return false;
            // re-used
            if (used[back_i])
               return false;
            
            if (j - back_i == l){
               for (int x = back_i; x < j; x++)
                  used[x] = true;
               i++; j++;
               break;
            }
            
            back_i--;
         }
      }
      else if (row[i] > row[j]){ // decreasing: check forwards
         int forward_j = j;
         
         while (true){
            // out-of-bound
            if (forward_j > n - 1)
               return false;
            // another wall before L blocks
            if (row[j] != row[forward_j])
               return false;
            // re-used
            if (used[forward_j])
               return false;
            
            if (forward_j - i == l){
               for (int x = forward_j; x > i; x--)
                  used[x] = true;
               i = j; j = i + 1;
               break;
            }
            
            forward_j++;
         }
      }
      else{
         i++; 
         j++;
      }
   }
   
   return true;
}

void transpose(vector<vector<int>> &mat){
   int n = mat.size();
   vector<vector<int>> transposed(n, vector<int>(n));
   
   for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
         transposed[i][j] = mat[j][i];
      }
   }
   
   mat = transposed;
}

int main(){
   int answer = 0;
   
   int n, l;
   cin >> n >> l;
   vector<vector<int>> mat(n, vector<int>(n));
   for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
         cin >> mat[i][j];
      }
   }
   
   
   for (auto row: mat){
      if (is_valid(row, l)) 
         answer++;
   }
   transpose(mat);
   for (auto row: mat){
      if (is_valid(row, l)) 
         answer++;
   }
   
   cout << answer << endl;
  
   return 0;
}