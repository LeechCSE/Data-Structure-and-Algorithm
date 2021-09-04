#include <vector>
#include <iostream>

using namespace std;
using ll = long long;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    
    vector<vector<ll> > d(m, vector<ll>(n));
    // initialization
    d[0][1] = city_map[0][1] == 1 ? 0 : 1;
    d[1][0] = city_map[1][0] == 1 ? 0 : 1;
    for (int i = 2; i < n; i++){
        if (city_map[0][i] == 1)
            continue;
        
        d[0][i] = d[0][i - 1];
    }
    for (int i = 2; i < m; i++){
        if (city_map[i][0] == 1)
            continue;
        
        d[i][0] = d[i - 1][0];
    }
    
    for (int i = 1; i < m; i++){
        for (int j = 1; j < n; j++){
            if (city_map[i][j] == 1)
                continue;
            
            ll up = 0;
            ll left = 0;
            // set `up`
            if (city_map[i - 1][j] == 0 || city_map[i - 1][j] == 1)
                up = d[i - 1][j];
            else{
                for (int x = i - 2; x >= 0; x--){
                    if (city_map[x][j] != 2){
                        up = d[x][j];
                        break;
                    }
                }
            }
            // set `left`
            if (city_map[i][j - 1] == 0 || city_map[i][j - 1] == 1)
                left = d[i][j - 1];
            else{
                for (int x = j - 2; x >= 0; x--){
                    if (city_map[i][x] != 2){
                        left = d[i][x];
                        break;
                    }
                }
            }
            
            d[i][j] = up + left;
            d[i][j] %= MOD;
        }
    }
    
    answer = d[m - 1][n - 1];
    return answer;
}