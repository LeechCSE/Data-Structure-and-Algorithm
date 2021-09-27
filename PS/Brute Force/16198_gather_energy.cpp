#include <iostream>
#include <vector>

using namespace std;

int gather_max(vector<int> w){
	// base case: size == 2
	if (w.size() == 2)
		return 0;
	
	int max = -1;
	for (int x = 1; x < w.size() - 1; x++){
		int energy = w[x - 1] * w[x + 1];

		vector<int> temp(w);
		temp.erase(next(temp.begin(), x));
		
		energy += gather_max(temp);
		
		if (max < energy)
			max = energy;
	}
	
	return max;
}

int main(){
	int n;
	cin >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++)
		cin >> w[i];
	
	
	cout << gather_max(w) << endl;
	
	return 0;
}