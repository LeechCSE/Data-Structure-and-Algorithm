#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_diff(vector<vector<int>> s, vector<int> t1, vector<int> t2){
   int rtn = 0;
   // Team 1
   for (int i = 0; i < (int)t1.size() - 1; i++){
      for (int j = i + 1; j < (int)t1.size(); j++){
         rtn += s[t1[i]][t1[j]];
         rtn += s[t1[j]][t1[i]];
      }
   }
   // Team 2
   for (int i = 0; i < (int)t2.size() - 1; i++){
      for (int j = i + 1; j < (int)t2.size(); j++){
         rtn -= s[t2[i]][t2[j]];
         rtn -= s[t2[j]][t2[i]];
      }
   }
   
   return abs(rtn);
}

int main(){
   int answer = 100;
   
   int n;
   cin >> n;
   vector<vector<int>> s(n, vector<int>(n));
   for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
         cin >> s[i][j];
      }
   }
   // n Choose n/2
   vector<int> pool;
   for (int i = 0; i < n; i++)
      pool.emplace_back(i);
   vector<bool> mask(n, false);
   for (int i = 0; i < n / 2; i++)
      mask[i] = true;
   do{
      vector<int> star, link;
      for (int i = 0; i < n; i++){
         if (mask[i])
            star.emplace_back(pool[i]);
         else
            link.emplace_back(pool[i]);
      }
      
      int diff = get_diff(s, star, link);
      if (answer > diff)
         answer = diff;
   } while (prev_permutation(mask.begin(), mask.end()));
   
   cout << answer << endl;
   
   return 0;
}