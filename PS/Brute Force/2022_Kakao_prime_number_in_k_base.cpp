#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string to_k_base(int n, int k){
    string rtn = "";
    
    while (n != 0){
        rtn += to_string(n % k);
        n /= k;
    }
    
    reverse(rtn.begin(), rtn.end());
    
    return rtn;
}

vector<long long> parse(string num){
    vector<long long> rtn;
    
    size_t before = 0;
    while (true){
        size_t zero_pos = num.find("0", before);
        string ss = num.substr(before, zero_pos - before);
        if (!ss.empty()){
            rtn.emplace_back(stoll(ss));
        }
        
        if (zero_pos == string::npos)
            break;
        
        before = zero_pos + 1;
    }
    
    return rtn;
}

bool is_prime(long long n){
    if (n <= 1)
        return false;
    
    for (long long i = 2; i <= (long long)sqrt(n); i++){
        if (n % i == 0)
            return false;
    }
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    string n_in_k = to_k_base(n, k);
    vector<long long> cand = parse(n_in_k);
    for (auto el: cand){
        if (is_prime(el))
            answer++;
    }
    
    return answer;
}