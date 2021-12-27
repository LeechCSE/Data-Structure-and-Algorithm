#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Label{
    int index, time;
    bool operator()(Label l1, Label l2){
        return l1.time > l2.time;
    }
};

vector<int> index_vec(priority_queue<Label, vector<Label>, Label> pq){
    vector<int> rtn;
    
    while (!pq.empty()){
        rtn.emplace_back(pq.top().index);
        pq.pop();
    }
    
    sort(rtn.begin(), rtn.end());
    
    return rtn;
}

int solution(vector<int> food_times, long long k) {
    priority_queue<Label, vector<Label>, Label> pq;
    for (int i = 0; i < food_times.size(); i++)
        pq.emplace(Label{i + 1, food_times[i]});
    
    int past = 0;
    while (!pq.empty()){
        int cur_time = pq.top().time;
        if (k < (cur_time - past) * pq.size()){
            k %= pq.size();
            break;
        }
        
        k -= (cur_time - past) * pq.size();
        past = cur_time;
        pq.pop();
    }
    
    if (pq.empty()) return -1;
    else            return index_vec(pq)[k];
}