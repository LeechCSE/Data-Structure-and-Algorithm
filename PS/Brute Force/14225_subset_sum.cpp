#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	
	vector<int> in(n);
	for (int i = 0; i < n; i++)
		cin >> in[i];
	
	vector<bool> mask(n, false);
	set<int> sums;
	
	for (int size = 1; size <= n; size++){
		for (int j = 0; j < size; j++)
			mask[j] = true;
		
		do{
			int sum = 0;
			
			for (int j = 0; j < n; j++){
				if (mask[j])
					sum += in[j];
			}
			
			sums.insert(sum);
		} while (prev_permutation(mask.begin(), mask.end()));
	}
	
	int max = 0;
	for (auto el : in)
		max += el;
	
	bool done = false;
	auto it = sums.begin();
	for (int i = 1; i <= max; i++){
		if (*it != i){
			cout << i << endl;
			done = true;
			break;
		}
		advance(it, 1);
	}
	
	if (!done)
		cout << max + 1 << endl;
	
	return 0;
}