#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for (int i = 0; i < n; i++){
        bitset<16> bs(arr1[i]);
        bitset<16> bs2(arr2[i]);
        
        for (int j = n - 1; j >= 0; j--)
            bs[j] = bs[j] | bs2[j];
        
        string ans = "";
        for (int j = n - 1; j >= 0; j--){
            if (bs[j])  ans += "#";
            else        ans += " ";
        }
        
        answer.emplace_back(ans);
    }
    
    return answer;
}