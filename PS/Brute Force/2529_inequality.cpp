#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int k;
	cin >> k;
	vector<char> a(k);
	for (int i = 0; i < k; i++)
		cin >> a[i];
	vector<int> pool(10);
	for (int i = 0; i < 10; i++)
		pool[i] = i;
	vector<bool> mask(10, false);
	for (int i = 0; i < k + 1; i++)
		mask[i] = true;
	
	vector<string> ans;
	
	// Among 0 - 9, choose k+1 numbers: 10 C k+1
	do{
		vector<int> cand;
		for (int i = 0; i < 10; i++){
			if (mask[i]){
				cand.emplace_back(pool[i]);
			}
		}
		
		// permutation of picked k+1 numbers
		do{
			bool valid = true;
			for (int i = 0; i < cand.size() - 1; i++){
				if (a[i] == '<'){
					if (!(cand[i] < cand[i + 1]))
						valid = false;
				}
				else{
					if (!(cand[i] > cand[i + 1]))
						valid = false;
				}
			}
			
			if (valid){
				string ans_str = "";
				for (auto el : cand)
					ans_str += to_string(el);
				
				ans.emplace_back(ans_str);
			}
		} while (next_permutation(cand.begin(), cand.end()));
		
	} while (prev_permutation(mask.begin(), mask.end()));
	
	sort(ans.begin(), ans.end());
	cout << *ans.rbegin() << endl << *ans.begin() << endl;
	
	return 0;
}