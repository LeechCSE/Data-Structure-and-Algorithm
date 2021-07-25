#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

struct Job{
  int id, start, end;
  int len;
  Job(int i, int s, int e) : id(i), start(s), end(e), len(end - start){}
  bool operator<(const Job& j) const{
    if (this->end == j.end)
      return this->len < j.len;
    return this->end < j.end;
  }
};

void schedule(vector<Job>& list){
  sort(list.begin(), list.end());
  
  for (auto cur = list.begin(); cur != list.end(); cur++){
    bool erased = false;
    for (auto it = cur + 1; it != list.end(); erased ? it : it++){
      if (it->start < cur->end){
	list.erase(it);
	erased = true;
      }
      else
	erased = false;
    }
  }
}

void print(vector<Job> list){
  for (auto el: list)
    cout << "["  << el.id << "] " << el.start << " -> " << el.end << endl;
  cout << endl;
}

int main(){
  //  list<Job> list;
  vector<Job> list;
  list.push_back(Job(1, 5, 9));
  list.push_back(Job(2, 6, 20));
  list.push_back(Job(3, 16, 19));
  list.push_back(Job(4, 7, 10));
  list.push_back(Job(5, 9, 19));
  list.push_back(Job(6, 10, 19));
  list.push_back(Job(7, 6, 12));
  list.push_back(Job(8, 2, 17));
  list.push_back(Job(9, 10, 13));
  list.push_back(Job(10, 4, 7));

  cout << "Jobs" << endl;
  print(list);
  
  cout << "Scheduled Jobs" << endl;
  schedule(list);
  print(list);
  
  return 0;
}
