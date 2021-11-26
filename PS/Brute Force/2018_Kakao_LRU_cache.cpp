#include <string>
#include <deque>
#include <cctype>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> cache;
    
    if (cacheSize == 0)
        return 5 * cities.size();
    
    for (auto city: cities){
        for (auto &ch: city)
            ch = toupper(ch);
        auto it = find(cache.begin(), cache.end(), city);
        
        if (it == cache.end()){ // cache miss
            answer += 5;
            
            if (!cache.empty() && cache.size() >= cacheSize)
                cache.pop_front();
                
            cache.emplace_back(city);
        }
        else{ // cache hit
            answer++;
            
            cache.erase(it);
            cache.emplace_back(city);
        }
    }
    
    return answer;
}