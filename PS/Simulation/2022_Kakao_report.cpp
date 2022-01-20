#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct Report{
    string reporter, reported;
};

Report split(string r){
    size_t pos = r.find(" ");
    return Report{r.substr(0, pos), r.substr(pos + 1)};
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    map<string, set<string>> who_reported; // id: [user who reported this.id, ...]
    map<string, int> num_reported; // id: #reported
    map<string, int> index_map; // id: given index
    for (int i = 0; i < id_list.size(); i++){
        index_map[id_list[i]] = i;
        num_reported[id_list[i]] = 0;
    }
    
    for (auto r: report){ // O(n * log m) where n = #reports and m = #users
        Report cur = split(r);
        
        auto it = who_reported[cur.reported].find(cur.reporter);
        if (it == who_reported[cur.reported].end()){
            num_reported[cur.reported]++;
            who_reported[cur.reported].insert(cur.reporter);
        }
    }
    
    for (auto el: num_reported){ // O(m * log m)
        string reported = el.first;
        
        if (el.second >= k){
            for (auto x: who_reported[reported])
                answer[index_map[x]]++;
        }
    }
    
    return answer;
}