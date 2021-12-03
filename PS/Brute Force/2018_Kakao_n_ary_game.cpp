#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string to_base(int n, int x){
    string rtn = "";
    if (x == 0) return "0";
    
    while (x){
        string remainder;
        switch (x % n){
            case 10: remainder = "A"; break;
            case 11: remainder = "B"; break;
            case 12: remainder = "C"; break;
            case 13: remainder = "D"; break;
            case 14: remainder = "E"; break;
            case 15: remainder = "F"; break;
            default: remainder = to_string(x % n); break;
        }
        rtn += remainder;
        
        x /= n;
    }
    reverse(rtn.begin(), rtn.end());
    
    return rtn;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string cand = "";
    
    for (int i = 0; cand.size() <= m * t; i++)  cand += to_base(n, i);
    for (int i = p - 1; i < t * m; i += m)      answer += cand[i];
    
    return answer;
}