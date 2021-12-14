#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> stage_rate;
    
    for (int i = 1; i <= N; i++){
        double tot = 0;
        double unclear = 0;
        for (auto s: stages){
            if (s >= i) tot++;
            if (s == i) unclear++;
        }
        
        stage_rate.emplace_back(make_pair(i, tot == 0 ? 0 : unclear / tot));
    }
    
    sort(stage_rate.begin(), stage_rate.end(), 
         [](pair<int, double> p1, pair<int, double> p2){
             if (p1.second == p2.second)
                 return p1.first < p2.first;
             return p1.second > p2.second;
         });
    
    for (auto sr: stage_rate)
        answer.emplace_back(sr.first);
    
    return answer;
}