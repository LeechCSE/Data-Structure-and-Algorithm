#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int get_distance(string pool, char from, char to){
	int from_pos, to_pos;

	for (int i = 0; i < pool.length(); i++){
		if (pool[i] == from)
			from_pos = i;
		if (pool[i] == to)
			to_pos = i;
	}

	return abs(from_pos - to_pos) - 1;
}

int solution(int n, vector<string> data) {
	int answer = 0;
	string pool = "ACFJMNRT";

	do{
		bool valid = true;

		for (auto d : data){
			char from = d[0];
			char to = d[2];
			char sym = d[3];
			int offset = d[4] - '0';

			int dist = get_distance(pool, from, to);

			if (sym == '='){
				if (!(dist == offset))
					valid = false;
			}
			else if (sym  == '<'){
				if (!(dist < offset))
					valid = false;
			}
			else if (sym == '>'){
				if (!(dist > offset))
					valid = false;
			}
		}

		if (valid)
			answer++;
	} while (next_permutation(pool.begin(), pool.end()));

	cout << answer << endl;

	return answer;
}