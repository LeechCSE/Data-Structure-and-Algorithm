#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int k;
	while (cin >> k){
		if (k == 0)
			break;
		
		vector<int> s(k);
		for (int i = 0; i < k; i++)
			cin >> s[i];
		
		vector<bool> helper(k, true);
		for (int i = 1; i <= k - 6; i++)
			helper[k - i] = false;
		
		do{
			for (int i = 0; i < k; i++){
				if (helper[i])
					cout << s[i] << " ";
			}
			
			cout << endl;
		} while (prev_permutation(helper.begin(), helper.end()));
		
		cout << endl;
	}
	
	return 0;
}