Algorithms
===
## Greedy Algorithm
#### Job Scheduling
scheduling.cpp is an example of greedy algorithm that schedules given jobs to
maximize the number of jobs done without overlapped with each other. The jobs
are selected in order of earliest end time, and the overlapped jobs are cut
off greadily. This greedy approach gives the optimized outcome.
#### Minimum Spanning Tree(Kruskal Algorithm)
The minimum spanning tree(MST) algorithm is an algorihtm that makes an
undirected-weighted graph be a completely connected tree with minimum total
weight of used edges. It uses greedy algorithm adding edges with the lowest
weight as long as they don't make cyclic path in the minimum spanning tree. In
order to check the cyclicity, the disjoint-set is used. Disjoint-set is a set
of trees. Union_sets() method combines two trees if input nodes are not in the
same tree. In other words, this method checks if the new edge creates a cyclic
path in the minimum spanning tree.
#### Graph Coloring + Welsh-Powell algorithm
Graph coloring is an algorithm that decides color of vertices of given graph
with adjacent vertices not having the same color. This algorithm greedily picks
a color of a vertex based on its adjacent vertices' color; it simply picks
colors that are not used by adjacent vetices yet until all vertices' color is
decided. With Welsh-Powell algorithm, which starts coloring the vertex with
the highest degree, gives less chromatic number.
#### Non consecutive sorting
Non-consecutive sorting, given list of numbers, sorts numbers in a way that
no consecutive number lines next to each other. In addition, among many
possible cases, it gives lexicographically smallest sorting. It is implemented
using greedy algorithm. It maps elements with its counts in the list. Then, in
the sorted list in ascending order, for each elements that has remaining
counts, it greedily checks the existence of numbers that are greater than
current number. This problem is from BOJ#1071.

## Graph Algorithm
#### BFS 
###### for finding shortest path in evenly weighted graph
Graph traversal algorithm. O(V + E) with adjacency list where V is the number of 
vertices, and E is the number of edges. Starting from the given vertex, it 
traverses all vertices visiting adjacent child nodes first and then grand child 
nodes. It is more useful when finding close vertices from the starting vertex. 
In addition, it guarantees the path taken to the arriving node to be the shortest 
path.

**Source code**
```
void bfs(vector<vector<int>> adj_list,  int src){
   queue<int> q;
   q.emplace(src);
   visited[src] = true; // declared globally
   
   while (!q.empty()){
      int cur = q.front();
      q.pop();
      
      cout << cur << " ";
      
      for (auto v: adj_list[cur]){
         // visit check
         if (visited[v])
            continue;
         
         visited[v] = true;
         q.emplace(v);
      }
   }
}
```
#### DFS
###### for exhausted search and back-tracking with search criteria
Graph traversal algorithm. It also traverses all vertices visiting grand
children earlier than its children nodes. Therefore, the node to be found would
better be far from the starting node. It works at O(V + E) with adjacency list 
where V is the number of vertices, and E is the number of edges.

**Source code**
```
void dfs(vector<vector<int>> adj_list, int src){
   // visit check
   if (visited[src])
      return;
   
   cout << src << " ";
   visited[src] = true;
   for (auto v: adj_list[src])
      dfs(adj_list, v);
}
```
#### Bipartite
A graph is bipartite if nodes can be divided into two group perfectly, and
nodes in the same group must be connected with edges. In other words, the
graph is bipartite if it can be colored by two colors. As this algorithm has to
traverse all nodes, both DFS and BFS can be used. While traversing nodes, it
alternately colors nodes with two colors. If adjacent nodes have the same
color, the graph is not bipartite.
#### MST(Prim Algorithm)
MST algorithm. It works like BFS algorithm but with minimum heap, implemented
with priority_queue. Given graph with vertices having infinite distance, it
compares adjacent vertex v's distance and edge's weight of which destination
is v. The v's distance is replaced with the smaller one, and the vertex v is
added into minimum heap. It continues until the heap is empty.

#### Dijkstra Algorithm
###### for shortest path in positively weighted graph
Dijkstra algorithm is a single-source shortest-path-problem. Given a
positive-weighted graph, source node, and destination node, it gives the
shortest(least weighted) path from the source node to the destination node. 
From the source node, in BFS manner, it updates the distance from start node to 
vertex u. After all iterations, each node has the total distance from the start 
node. Using back-tracing technique, it returns the shortest path and the total
distance. E.g. dijkstra_NY.cpp

**Source code**
```
using Info = pair<int, int> // <v, w> in edge (u)--w-->(v)

vector<int> dikstra(vector<vector<Info>> adj_list, int src, int dst){
   int num_v = adj_list.size();
   // init
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
```
#### Bellman-Ford Algorithm
Bellman-ford algorithm is a graph algorithm that gives the shortest distance 
from the start node to all nodes. While Dijkstra algorithm cannot deal with the 
negative edge weight, Bellman-ford algorithm can. With priority queue, Dijkstra 
runs as O(|V|+|E|log|V|). However, as Bellman-ford algorithm iterates updating 
algorithm for |V| - 1 times and one checking algorithm, it runs at O(|V||E|).
Example in bellman_ford_example.cpp

## Dynamic Programming
### Pre-requisites
* Optimal sub-structure: whether the final optimal solution can be constructed
from its sub-optimal solutions
* Overlapping sub-problem: whether the problem can be broken down into
subproblems that are reused serveral times