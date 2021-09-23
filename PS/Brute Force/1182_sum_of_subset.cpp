#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n, target;
	cin >> n >> target;
	
	vector<int> in(n);
	for (int i = 0; i < n; i++)
		cin >> in[i];
	
	int ans = 0;
	vector<int> mask(n, false);
	
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < i; j++)
			mask[j] = true;
		
		do{
			int sum = 0;
			
			for (int j = 0; j < n; j++){
				if (mask[j])
					sum += in[j];
			}
			
			if (sum == target)
				ans++;
			
		} while (prev_permutation(mask.begin(), mask.end()));
	}
	
	cout << ans << endl;
	
	return 0;
}