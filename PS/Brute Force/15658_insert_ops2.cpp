#include <iostream>
#include <vector>

using namespace std;

pair<int, int> accumulate(vector<int> a, int add, int sub, int mul, int div, 
								int acc, int pos = 1){
	if (pos == a.size())
		return pair<int, int>(acc, acc);
	
	vector<pair<int, int> > res;
	if (add) res.emplace_back(accumulate(a, add - 1, sub, mul, div, 
										acc + a[pos], pos + 1));
	if (sub) res.emplace_back(accumulate(a, add, sub - 1, mul, div, 
										acc - a[pos], pos + 1));
	if (mul) res.emplace_back(accumulate(a, add, sub, mul - 1, div, 
										acc * a[pos], pos + 1));
	if (div) res.emplace_back(accumulate(a, add, sub, mul, div - 1, 
										acc / a[pos], pos + 1));
										
	int max = res[0].first;
	int min = res[0].second;
	for (auto p : res){
		if (max < p.first)
			max = p.first;
		if (min >  p.second)
			min = p.second;
	}
	
	return pair<int, int>(max, min);
}

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<int> ops(4);
	for (int i = 0; i < 4; i++)
		cin >> ops[i];
	
	pair<int, int> ans = accumulate(a, ops[0], ops[1], ops[2], ops[3], a[0]);
	
	cout << ans.first << endl << ans.second << endl;
	
	return 0;
}