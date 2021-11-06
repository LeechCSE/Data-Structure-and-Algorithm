#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
using Pos = pair<int, int>;
using Tree = pair<int, bool>; // (age, is_dead)

void sort_all(vector<vector<deque<Tree>>> &tree){
	int n = tree.size();
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			sort(tree[i][j].begin(), tree[i][j].end());
		}
	}
}

void spring(vector<vector<deque<Tree>>> &tree, vector<vector<int>> &soil){
	int n = tree.size();
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (tree[i][j].empty())
				continue;
			
			deque<Tree> new_trees;
			while (!tree[i][j].empty()){
				Tree youngest = tree[i][j].front();
				tree[i][j].pop_front();
				
				if (soil[i][j] - youngest.first < 0){ // out-of-soil: dead
					youngest.second = true;
					new_trees.emplace_back(Tree(youngest));
				}
				else{ // grow
					soil[i][j] -= youngest.first++;
					new_trees.emplace_back(Tree(youngest));
				}
			}
			tree[i][j] = new_trees;
		}
	}
}

void summer(vector<vector<deque<Tree>>> &tree, vector<vector<int>> &soil){
	int n = tree.size();
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int og_size = tree[i][j].size();
			for (int k = 0; k < og_size; k++){
				Tree youngest = tree[i][j].front();
				tree[i][j].pop_front();
				
				if (youngest.second)
					soil[i][j] += youngest.first / 2;
				else
					tree[i][j].emplace_back(youngest);
			}
		}
	}
}

void fall(vector<vector<deque<Tree>>> &tree){
	int n = tree.size();
	vector<Pos> adjacents = { 
		{-1, 0}, {1, 0}, {0, 1}, {0, -1},
		{1, 1}, {1, -1}, {-1, 1}, {-1, -1}
	};
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			for (auto youngest : tree[i][j]){
				if (youngest.first % 5 == 0){
					for (auto adj : adjacents){
						int newY = i + adj.first;
						int newX = j + adj.second;
						
						if (0 <= newY && newY < n && 0 <= newX && newX < n)
							tree[newY][newX].emplace_front(Tree(1, false));
					}
				}
			}
		}
	}
}

void winter(vector<vector<int>> &soil, vector<vector<int>> a){
	int n = soil.size();
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			soil[i][j] += a[i][j];
		}
	}
}

int count_trees(vector<vector<deque<Tree>>> tree){
	int rtn = 0;
	int n = tree.size();
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			while (!tree[i][j].empty()){
				rtn++;
				tree[i][j].pop_front();
			}
		}
	}
	
	return rtn;
}

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	
	vector<vector<int>> soil(n, vector<int>(n, 5));
	vector<vector<deque<Tree>>> tree(n, vector<deque<Tree>>(n));
	for (int i = 0; i < m; i++){
		int y, x, z;
		cin >> y >> x >> z;
		tree[y - 1][x - 1].emplace_back(Tree(z, false));
	}
	
	sort_all(tree);
	while (k--){
		spring(tree, soil);
		summer(tree, soil);
		fall(tree);
		winter(soil, a);
	}
	cout << count_trees(tree) << endl;
	
	return 0;
}