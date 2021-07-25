#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

struct Job{
  int id, start, end;
  Job(int i, int s, int e) : id(i), start(s), end(e){}
  bool operator<(const Job& j) const{ return this->end < j.end; }
};

void schedule(list<Job>& list){
  list.sort();
  
  for (auto cur = list.begin(); cur != list.end(); cur++)
    for (auto it = next(cur); it != list.end(); it++)
      if (it->start < cur->end)
	list.erase(it);
}

void print(list<Job> list){
  for (auto el: list)
    cout << "["  << el.id << "] " << el.start << " -> " << el.end << endl;
  cout << endl;
}

int main(){
  list<Job> list;
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
