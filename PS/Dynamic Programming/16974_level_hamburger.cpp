#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<ll> all(51), patty(51);

ll sol(int n, ll x){
	if (n == 0) // Level-0: "P" always patty
		return x;
	else if (x == 1) // P...
		return 0;
	else if (x <= 1 + all[n - 1]) // B(N-1)...
		return sol(n - 1, x - 1);
	else if (x == 1 + all[n - 1] + 1) // B(N-1)P...
		return patty[n - 1] + 1;
	else if (x <= 1 + all[n - 1] + 1 + all[n - 1]) // B(N-1)P(N-1)...
		return patty[n - 1] + 1 + sol(n - 1, x - 1 - all[n - 1] - 1);
	else // B(N-1)P(N-1)B
		return patty[n - 1] + 1 + patty[n - 1];
}

int main(){
	int n;
	ll x;
	cin >> n >> x;
	
	all[0] = 1;
	patty[0] = 1;
	for (int i = 1; i <= n; i++){
		all[i] = 2 * all[i - 1] + 3;
		patty[i] = 2 * patty[i - 1] + 1;
	}
	
	cout << sol(n, x) << endl;
	
	return 0;
}