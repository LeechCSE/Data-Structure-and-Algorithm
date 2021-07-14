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
##### TODO
- [ ] BFS
- [ ] DFS