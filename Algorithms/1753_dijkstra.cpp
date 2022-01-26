#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

using Info = pair<int, int>; // <dest. vertex, edge weight>

struct Node{
   int vertex, distance;
   bool operator>(Node n) const{ return this->distance > n.distance; }
};

vector<int> dikstra(vector<vector<Info>> adj_list, int src, int dst){
   int num_v = adj_list.size();
   
   priority_queue<Node, vector<Node>, greater<Node>> min_heap;
   vector<int> distance(num_v, numeric_limits<int>::max());
   vector<bool> visited(num_v, false);
   vector<int> parent(num_v);
   
   distance[src] = 0;
   min_heap.emplace(Node{src, distance[src]});
   
   while (!min_heap.empty()){
      Node cur = min_heap.top();
      min_heap.pop();
      // reach the target
      if (cur.vertex == dst)
         break;
      // visit check
      if (visited[cur.vertex]) 
         continue;
      
      visited[cur.vertex] = true;
      // update neighbors' distance from src
      for (auto adj_node: adj_list[cur.vertex]){
         int dest = adj_node.first;
         int weight = adj_node.second;
         
         if (distance[dest] > cur.distance + weight){
            distance[dest] = cur.distance + weight;
            min_heap.emplace(Node{dest, distance[dest]});
            parent[dest] = cur.vertex;
         }
      }
   }
   // shortest path: src -> dst
   vector<int> path;
   int cur = dst;
   while (cur != src){
      path.emplace_back(cur);
      cur = parent[cur];
   }
   path.emplace_back(src);
   reverse(path.begin(), path.end());
   
   return path;
}

int main(){
   int num_v, num_e, src;
   cin >> num_v >> num_e >> src;
   vector<vector<Info>> adj_list(num_v + 1);
   for (int i = 0; i < num_e; i++){
      int u, v, w;
      cin >> u >> v >> w;
      
      adj_list[u].emplace_back(Info(v, w));
   }
   
   int dst = 4;
   vector<int> path = dikstra(adj_list, src, dst);
   for (auto el: path)
      cout << el << " ";
   cout << endl;
  
   return 0;
}