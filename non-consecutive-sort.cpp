#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <set>

using namespace std;

// For debugging (verbose mode)
bool DEBUG = false;
// Check if element of input is exhausted
bool remaining(pair<int, bool> p){ return (p.second != 0); }
// Print target element for the remaining times
void print_left(map<int, int> m, int target){
  for (int i = 0; i < m[target]; i++)
    cout << target << " ";
}

int main(){
  int N;
  cin >> N;
  
  vector<int> input;
  input.reserve(N);
  for (int i = 0; i < N; i++){
    int in;
    cin >> in;
    input.emplace_back(in);
  }
  sort(input.begin(), input.end());
  // Mapping <element : #elements>
  set<int> unique;
  for (auto el : input)
    unique.insert(el);
  map<int, int> cnt_map;
  for (auto el : unique)
    cnt_map.insert(pair<int, int>(el, count(input.begin(), input.end(), el)));

  while (true){
    auto it = find_if(cnt_map.begin(), cnt_map.end(), remaining);
    if (it == cnt_map.end()) // base case: all elements are checked
      break;
    
    int cur = it->first;
    if (DEBUG){
      cout << "\n**<STAT>**" << endl;
      for (auto el : cnt_map)
	cout << el.first << ": " << el.second << endl;
      cout << "********" << endl;
      cout << "Current element: " << cur << endl;
    }
    if (binary_search(input.begin(), input.end(), cur + 1)
	&& cnt_map[cur + 1] != 0){ // cur + 1 Exists

      auto beyond = find_if(input.begin(), input.end(),
			 [cur](int x){ return x >= cur + 2; });
      if (beyond != input.end() && cnt_map[*beyond] != 0){
	if (DEBUG) cout << "Cur + 1 and beyond exists: "
			<< cur + 1 << " & " << *beyond << endl;
	print_left(cnt_map, cur); cnt_map[cur] = 0;
	cout << *beyond << " "; cnt_map[*beyond]--;
      }
      else{ // cur + 2 Not exists
	if (DEBUG) cout << "Cur + 1 exists: " << cur + 1 << endl;
	print_left(cnt_map, cur + 1); cnt_map[cur + 1] = 0;
      }
    }
    else{ // cur + 1 Not exists
      if (DEBUG) cout << "Only me: " << cur << endl;
      print_left(cnt_map, cur); cnt_map[cur] = 0;
    }
    if (DEBUG) cout << endl;
  }
  cout << endl;
  
  return 0;
}
