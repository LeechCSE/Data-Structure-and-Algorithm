Data Struncture & Algorithm
===
This repo is for practicing the fundamentals of Computer Science.  
### Singly Linked List
Templated singly-linked list. As the name indicates, each node only points to
'next' forward.
##### Methods
+ `get_size()`: return size of list
+ `get_head()`: return head data
+ `get_tail()`: return tail data
+ `print_data()`: print all nodes' data
+ `find_by_data(T data)`: return index of the first node containing target data
+ `find_by_index(int n)`: return data of target node
+ `isEmpty()`: return whether list is empty or not
+ `push_back(T data)`: add a new node at the end of list
+ `push_front(T data)`: add a new node at the start of list
+ `insert(T data, int n)`: add a new node at given nth node; new node becomes
nth node
+ `pop_back()`: remove the last node
+ `pop_front()`: remove the first node
+ `erase(int n)`: remove nth node
##### TODO
- [x] destructor: need to free Nodes
- [ ] operator overloading  
- [ ] implement erase/2 method
- [ ] bug fix
- [ ] more intuitive naming

### Doubly Linked List
Like singly-linked list, doubly-linked list is templated with nodes pointing
their previous and next node. This feature allows the cursor to traverse nodes
much easier; therefore, bit conciser codes are made than singly-linked list.
In addition, it is easier for api users to identify methods' purpose by
their method name, which becomes bit more intuitive.
##### Methods
+ `get_size()`: return size of list
+ `isEmpty()`: return whether list is empty or not
+ `get_head()`: return head data
+ `get_tail()`: return tail data
+ `get_data_at(int n)`: return data of target node
+ `find(T data)`: return index of the first node containing target data
+ `print_data()`: print all nodes' data
+ `push_back(T data)`: add a new node at the end of list
+ `push_front(T data)`: add a new node at the start of list
+ `insert(T data, int n)`: add a new node at given nth node; new node becomes
nth node
+ `pop_back()`: remove the last node
+ `pop_front()`: remove the first node
+ `erase(int n)`: remove nth node
##### TODO
- [x] destructor: need to free Nodes
- [ ] operator overloading
- [ ] implement copy constructor
- [ ] implemet erase/2 method

### Queue
Simple templatedqueue data structure using the same container with the one
used in doubly_linked_list.cpp. Initially, queue is implemented with
singly-linked container. However, the code became less readable. Besides some
general getters, such as `get_size()`, `get_front()`, `get_back()`, two
critical methods are implemented: `enqueue()` & `dequeue()`. Basically,
`enqueue()` is much like `push_back()` in linked-list, and `dequeue()` works
like `pop_front()` but returns front node's data. Since queue.cpp uses
increases its size by one at each time of enqueuing data, overflow is not a
concern.
##### Methods
+ `isEmpty()`: return whether queue is empty
+ `get_size()`: return the size of queue
+ `get_front()`: return the first element of queue
+ `get_back()`: return the last element of queue
+ `enqueue(T data)`: add new data into queue in FIFO(First In First Out) manner
+ `dequeue()`: remove and return front element of queue in FIFO manner
+ `print_data()`: print all data in queue
##### TODO
- [ ] operator overloading
- [x] destructor: need to manually free Nodes
- [x] change return type of `dequeue()` from T to void

### Stack
Templated stack data structure using singly-pointing nodes. Initially, 'next'
pointer is pointing up, meaning that nodes are toward top node, and the top
node is pointing nowhere. It is troublesome in method `pop()`. As top node
must be removed and freed in memory, something should be pointing to adjacent
node of top. However, in current setting, top is the dead end. Therefore,
the direction of pointer is reversed; everything is good now.
##### Methods
+ `isEmpty()`: return whether stack is empty or not
+ `get_size()`: return the size of stack
+ `get_top()`: return top data
+ `push(T data)`: add a new data element into the top of stack in LIFO(Last
In First Out) manner
+ `pop()`: remove top node
+ `print()`: print all data
##### TODO
- [ ] operator overloading
- [x] destructor

### Graph
This is a non-directed and unweighted graph implemented with
Doubly-linked-list in the adjacency list format. The name of vertex goes by
its index in order of creation. Each vertex has a list indicating its adjacent
vertices, and the lists are wrapped in a vector.
##### Methods
+ `is_member(int u)`: check if vertex u is in the graph
+ `is_edge(int u, int v)`: check if vertex u is adjacent to vertex v
+ `print()`: print all vertices with their adjacent vertices and the number of
edges and vertices
+ `add_edge(int u, int v)`: add a new edge between vertex u and v
+ `remove_edge(int u, int v)`: remove the edge between vertex u and v
+ `add_vertex()`: add a new vertex
+ `remove_vertex(int u)`: remove vertex u and the edges connected to it accordingly
##### TODO
- [ ] Implement destructor
- [ ] `remove_vertex(int u)`

### STL_Graph
This stl_graph is another graph data structure implemented with STL vector,
list, and queue. It's more of practicing DFS and BFS itself without stressing
out from debugging my own data structure of list and queue.
##### Methods
+ `print()`: print adjacency list
+ `is_vertex(int u)`: check if vertex u is in graph
+ `is_edge(int u, int v)`: check if edge between u and v is in graph
+ `add_edge(int u, int v)`: add a new edge between vertex u and v
+ `add_vertex(int u)`: add a new vertex u
+ `remove_edge(int u, int v)`: remove edge between vertex u and v
+ `bfs(int u)`: Breath-First-Search staring from vertex u
+ `dfs_rec(int u)`: Depth-First-Search staring from vertex u in recursive
manner
+ `dfs_itr(int u)`: Depth-First-Search staring from vertex u in iterative
manner
##### TODO
- [x] BFS
- [x] DFS

### Graph_Final
Instead of using adjacent list, this graph library is using a list of edge.
Since it stores edges themselves, the complexity of implementation is way less
than one of using adjacency list.
##### Methods
+ `vertices()`: return the number of vertices
+ `add_edge()`: add a new edge
+ `get_edges_of()`: return edges of which source vertex is given


### Array
Array is a dynamically-allocated array. It is an advanced array of C-style
array, supporting garbage collecting; don't worry about memory leak nor
annoying `delete`.
##### Methods
+ `operator []`: access data by index
+ `at(int index)`: access data by index(out-of-range exception checking)
+ `size()`: return size of array
+ `begin()`: return an iterator pointing to the first element of array
+ `end()`: return an iterator pointing to the past-the-end element of array
##### TODO

### Circular Linked List
Circular linked list is a list of which the last node points to the first
node; therefore, the list never ends. This implementation mimic C++ STL list,
having iterator and iterator methods.
##### Methods
+ `push_front(int val)`: add a new element at the front of the list
+ `pop_front()`: remove the first element from the list
+ `size()`: return the number of nodes in the list
+ `Circular_ll_iterator`: an iterator data type for circular_linked_list
containing node pointer that points to a node
  + `operator *()`: return data of node that the iterator is pointing to
  + `get()`: return node pointer that the iterator
  + `operator ++()`: advance iterator to the next node by one(pre-increment)
  + `operator ==(...)`: return true if both iterator points to the same node
  + `operator !=(...)`:	return false if both iterator points to the same node
+ `begin()`: return an iterator pointing to the head
+ `end()`: return an iterator pointing to the past-the-end element(head)
+ `back_it()`: return an iterator pointing to the tail
##### TODO
- [x] finalize copy constructor

### Binary Treee
Binary tree is a simple binary tree structure that supports minimum features:
create, add, find, and traversals. Specifically, it's more about practicing
tree traversal: pre-, in-, post-, and level-order traversals.
##### Methods
+ `create`: initialize a new tree
+ `add`: find and return a node that contains the target value
+ `pre_order`: prints all nodes in pre-order manner (parent->left->right)
+ `in_order`: prints all nodes in in-order manner (left->parent->right)
+ `post_order`: prints all nodes in post-order manner (left->right->parent)
+ `level_order`: prints all nodes by level (Root->Level 1->Level 2-> ...)

### Binary Search Tree
The binary search tree, a.k.a. BST, is a binary tree with a special
relationship between a parent node and its child nodes. In fact,  all left
child nodes have smaller or equal keys than the ones of their parents, and
all right child nodes have bigger key.
##### Methods
+ `find`: find and return a node that has the target value
+ `insert`: add a new node keeping the BST rule
+ `pre_order`: prints all nodes in pre-order manner (parent->left->right)
+ `in_order`: prints all nodes in in-order manner (left->parent->right)
+ `post_order`: prints all nodes in post-order manner (left->right->parent)
##### TODO
- [ ] implement `level_order` method
- [ ] implement `remove` method

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
distance.