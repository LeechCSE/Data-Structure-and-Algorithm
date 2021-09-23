#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<double> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<int> ops; // 0: +, 1: -, 2: *, 3: /
	for (int i = 0; i < 4; i++){
		int in;
		cin >> in;
		
		for (int j = 0; j < in; j++)
			ops.emplace_back(i);
	}
	
	int max = numeric_limits<int>::min();
	int min = numeric_limits<int>::max();
	
	do{
		auto it = a.begin();
		int out = *it;
		advance(it, 1);
		
		for (auto op : ops){
			switch (op){
				case 0:
					out += *it;
					break;
				case 1:
					out -= *it;
					break;
				case 2:
					out *= *it;
					break;
				case 3:
					out /= *it;
					break;
			}
			advance(it, 1);
		}
		
		if (max < out)
			max = out;
		if (min > out)
			min = out;
	} while (next_permutation(ops.begin(), ops.end()));
	
	cout << max << endl << min << endl;
	
	return 0;
}