#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
using State = vector<string>;

string generate_key(State s){
	string key = "";
	for (auto t : s){
		key += t;
		key += ".";
	}
	
	return key;
}

bool correct(State state){
	size_t found = state[0].find_first_not_of("A");
	
	if (found == string::npos){
		found = state[1].find_first_not_of("B");
		
		if (found == string::npos){
			found = state[2].find_first_not_of("C");
			
			if (found == string::npos)
				return true;
		}
	}
	
	return false;
}

int bfs(State start_state){
	queue<State> q;
	map<string, int> cnt;
	
	q.emplace(start_state);
	cnt[generate_key(start_state)] = 0;
	
	while (!q.empty()){
		State cur = q.front();
		q.pop();
	
		if (correct(cur))
			return cnt[generate_key(cur)];
		
		for (int i = 0; i < 3; i++){
			vector<int> newT = {0, 1, 2};
			newT.erase(find(newT.begin(), newT.end(), i));
			for (auto next_tower : newT){
				State newState(cur);
				// skip empty tower
				if (newState[i].empty())
					continue;
				// move plate
				char plate_to_move = newState[i].back();
				newState[i].pop_back();
				newState[next_tower] += plate_to_move;
				// visit check
				if (cnt.find(generate_key(newState)) == cnt.end()){
					cnt[generate_key(newState)] = cnt[generate_key(cur)] + 1;
					q.emplace(newState);
				}
			}
		}
	}
}

int main(){
	State start_state(3);
	for (int i = 0; i < 3; i++){
		int n;
		string s;
		cin >> n;
		
		if (n != 0)
			cin >> start_state[i];
	}
	
	cout << bfs(start_state) << endl;
	
	return 0;
}