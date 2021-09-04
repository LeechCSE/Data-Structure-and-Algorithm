#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool operator==(vector<int> v1, vector<int> v2){
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	for (int i = 0; i < v1.size(); i++){
		if (v1[i] != v2[i])
			return false;
	}
	
	return true;
}

int main(){
	freopen("tc.txt", "r", stdin);
	
	int n;
	cin >> n;
	
	vector<vector<int> > adjList(n + 1);
	vector<int> order(n);
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		adjList[u].emplace_back(v);
	}
	for (int i = 0; i < n; i++)
		cin >> order[i];
	
	for (auto el : order)
		cout << el << " ";
	cout << endl << endl;
	for (int i = 1; i <= n; i++){
		cout << i << ": ";
		for (auto adj : adjList[i])
			cout << adj << " ";
		cout << endl;
	}
	cout << endl;
	
	auto it = next(order.begin());
	for (auto el : order){
		
		cout << el << endl;
		
		vector<int> tmp;
		for (; it != next(it, adjList[el].size()); it++){
			
			
			
			cout << "  " << *it << endl;
			
			tmp.emplace_back(*it);
		}
		
		if (adjList[el] != tmp)
			cout << "HIT!" << endl;
	}
	
	return 0;
}