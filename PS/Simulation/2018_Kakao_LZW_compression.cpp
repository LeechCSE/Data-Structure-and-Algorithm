#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    map<string, int> dict;
    for (char ch = 'A'; ch <= 'Z'; ch++)
        dict[string(1, ch)] = ch - 64;
    
    int len = 1;
    int pos = 0;
    string w = "";
    while (true){
        string wc = msg.substr(pos, len);
        auto it = dict.find(wc);     
        if (it != dict.end()){ // found: check the next string
            if (pos + wc.length() >= msg.length()){ // exception: the last chunk
                answer.emplace_back(it->second);
                break;
            }
            
            w = wc;
            len++;
        }
        else{ // not found: add mapping
            dict[wc] = dict.size() + 1;
            answer.emplace_back(dict[msg.substr(pos, len - 1)]);
            len = 1;
            pos += w.length();
        }
    }
    
    return answer;
}