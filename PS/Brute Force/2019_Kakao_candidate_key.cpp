#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <bitset>

using namespace std;

string v_to_s(vector<bool> v){
    string s = "";
    
    for (auto el: v){
        if (el) s += "1";
        else    s += "0";
    }
    
    return s;
}

bool is_unique(vector<string> v){
    map<string, bool> exist;
    
    for (auto el: v){
        if (exist[el])  return false;
        else            exist[el] = true;
    }
    
    return true;
}

bool is_minimal(string superkey, vector<string> candidate_key){
    bitset<8> superkey_bs(superkey);
    for (auto ck: candidate_key){
        bitset<8> candidate_key_bs(ck);
        
        if (candidate_key_bs == (superkey_bs & candidate_key_bs))
            return false;
    }
    
    return true;
}

int solution(vector<vector<string>> relation){
    int n = relation.size();
    int m = relation[0].size();
    // uniqueness: get superkeys with combination of all attributes
    vector<string> superkey;
    for (int attr_size = 1; attr_size <= m; attr_size++){
        vector<bool> mask(m, false);
        for (int i = 0; i < attr_size; i++) mask[i] = true;
        
        do{
            vector<string> values;
            for (int i = 0; i < n; i++){
                string value = "";
                
                for (int j = 0; j < m; j++)
                    if (mask[j]) value += relation[i][j];
                
                values.emplace_back(value);
            }
            
            if (is_unique(values)) superkey.emplace_back(v_to_s(mask));
        } while (prev_permutation(mask.begin(), mask.end()));
    }
    // minimality: filter candidate keys out of superkeys
    vector<string> candidate_key;
    candidate_key.emplace_back(superkey[0]);
    
    for (int i = 1; i < superkey.size(); i++){
        if (is_minimal(superkey[i], candidate_key))
            candidate_key.emplace_back(superkey[i]);
    }
    
    return candidate_key.size();
}