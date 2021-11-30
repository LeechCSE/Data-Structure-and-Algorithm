#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string to_time(int t){
	int hour = t / 60;
	int min = t % 60;

	string time = "0";
	if (hour < 10)  time += to_string(hour);
	else            time = to_string(hour);
	time += ":";
	if (min < 10)   time += "0";
	time += to_string(min);

	return time;
};

int to_min(string time){
	return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));
}

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	map<int, vector<string>> buses;
	int cur = 540;
	for (int i = 0; i < n; i++){
		buses.emplace(cur, vector<string>());
		cur += t;
	}

	sort(timetable.begin(), timetable.end());
	// populate buses
	for (auto x: timetable){
		if (buses.rbegin()->second.size() == m)
			break;

		auto it = find_if(buses.begin(), buses.end(),
			[x](pair<int, vector<string>> p){ return to_min(x) <= p.first; });
		if (it == buses.end())
			continue;

		int target_bus = it->first;

		while (true){
			if (buses[target_bus].size() < m){
				buses[target_bus].emplace_back(x);
				break;
			}
			else target_bus += t;
		}
	}
	// calculate spot
	if (buses.rbegin()->second.size() < m) // seat available
		answer = to_time(buses.rbegin()->first);
	else // all filled
		answer = to_time(to_min(*(buses.rbegin()->second.rbegin())) - 1);

	return answer;
}