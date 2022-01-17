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
Graph traversal algorithm. O(V + E) where V is the number of vertices, and E is
the number of edges. Starting from the given vertex, it traverses all vertices
visiting adjacent child nodes first and then grand child nodes. It is more
useful when finding close vertices from the starting vertex. In addition, it
guarantees the path taken to the arriving node to be the shortest path.
#### DFS
Graph traversal algorithm. It also traverses all vertices visiting grand
children earlier than its children nodes. Therefore, the node to be found would
better be far from the starting node. It works at O(V + E) where V is the
number of vertices, and E is the number of edges.
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
Dijkstra algorithm is a single-source shortest-path-problem. Given a
positive-weighted graph, start node, and target node, it gives the
shortest(least weighted) path from the start node to the target node. From the
start node, in BFS manner, it updates the distance from start node to vertex u.
After all iterations, each node has the total distance from the start node.
Using back-tracing technique, it returns the shortest path and the total
distance. Example in dijkstra_NY.cpp
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