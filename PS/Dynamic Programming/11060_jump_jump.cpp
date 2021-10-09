#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	vector<int> d(n, -1);
	d[0] = 0;
	
	for (int i = 1; i < n; i++){
		bool moved = false;
		int min = 1000;
		for (int x = 0; x < i; x++){
			if (x + a[x] >= i){
				if (d[x] == -1)
					continue;
				
				if (min > d[x]){
					moved = true;
					min = d[x];
				}
			}
		}
		
		if (moved)
			d[i] = min + 1;
	}
	
	cout << d[n - 1] << endl;
	
	return 0;
}