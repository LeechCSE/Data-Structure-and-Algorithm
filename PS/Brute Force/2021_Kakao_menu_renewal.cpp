#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	for (auto &o : orders)
		sort(o.begin(), o.end(), [](char c1, char c2){ return c1 < c2; });

	for (auto c : course){
		map<string, int> dict;

		for (auto order : orders){
			if (order.length() < c)
				continue;

			vector<bool> mask(order.length(), false);
			for (int i = 0; i < c; i++)
				mask[i] = true;

			do{
				string order_to_check = "";

				for (int i = 0; i < order.length(); i++){
					if (mask[i])
						order_to_check += order[i];
				}

				dict[order_to_check]++;
			} while (prev_permutation(mask.begin(), mask.end()));
		}

		if (dict.empty())
			continue;

		vector<pair<string, int>> dict_v(dict.begin(), dict.end());
		sort(dict_v.begin(), dict_v.end(), 
			[](pair<string, int> p1, pair<string, int> p2){
				return p1.second > p2.second; // sort map by value
			}
		);

		int max_freq = dict_v[0].second;
		if (max_freq < 2)
			continue;

		for (auto d : dict_v){
			if (d.second == max_freq)
				answer.emplace_back(d.first);
			else
				break;
		}
	}

	sort(answer.begin(), answer.end());

	return answer;
}