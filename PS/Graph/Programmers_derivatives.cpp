#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

vector<set<char>> pool;

void init_char_pool(vector<string> words){
    pool.resize(words[0].length());
    for (auto w: words){
        for (int i = 0; i < w.length(); i++){
            pool[i].insert(w[i]);
        }
    }
}

vector<string> get_derivatives(string str, vector<string> words){
    vector<string> dws;
    
    for (int i = 0; i < (int)pool.size(); i++){
        string dw = str;
        for (auto ch: pool[i]){
            if (ch == dw[i])
                continue;
            
            dw[i] = ch;
            
            if (find(words.begin(), words.end(), dw) != words.end()){
                dws.emplace_back(dw);
            }
        }
    }
    
    return dws;
}

int bfs(vector<string> words, string src, string dst){
    map<string, int> cnt;
    for (auto w: words)
        cnt[w] = -1;
    
    queue<string> q;
    q.emplace(src);
    cnt[src] = 0;
    
    while (!q.empty()){
        string cur = q.front();
        q.pop();
        
        if (cur == dst)
            return cnt[dst];
        
        vector<string> derivatives = get_derivatives(cur, words);
        for (auto derivative: derivatives){
            if (cnt[derivative] != -1)
                continue;
            
            cnt[derivative] = cnt[cur] + 1;
            q.emplace(derivative);
        }
    }
    
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    if (find(words.begin(), words.end(), target) == words.end())
        return 0;
    
    init_char_pool(words);
    return bfs(words, begin, target);
}