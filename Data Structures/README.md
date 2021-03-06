Data Strunctures
===
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
Simple templated queue data structure using the same container with the one
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
+ `remove_vertex(int u)`: remove vertex u and the edges connected to it 
accordingly
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
+ `reserve()`: set the number of vertices and edges


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
##### Source code
```
struct Node{
   int data;
   Node* left;
   Node* right;
   
   Node(int d): data(d), left(nullptr), right(nullptr){}
};

Node* insert(Node* root, int data){
   if (root == nullptr) // base case
      return new Node(data);
   
   if (data < root->data)
      root->left = insert(root->left, data);
   else
      root->right = insert(root->right, data);
   
   return root;
}

Node* create(vector<int> data_set){
   Node* root = nullptr;
   for (auto data: data_set)
      root = insert(root, data);
   
   return root;
}

void pre_order(Node* root){
   if (root == nullptr)
      return;
   
   cout << root->data << " ";
   pre_order(root->left);
   pre_order(root->right);
}

void in_order(Node* root){
   if (root == nullptr)
      return;
   
   in_order(root->left);
   cout << root->data << " ";
   in_order(root->right);
}

void post_order(Node* root){
   if (root == nullptr)
      return;
   
   post_order(root->left);
   post_order(root->right);
   cout << root->data << " ";
}

int main(){
    ...
    Node* root = create(dataset);
    
    return 0;
}
```
##### Example
```
Data = [4, 2, 6, 1, 3, 5, 9]
Tree:
         4
      2     6
     1 3   5 9
Pre-order:  4 2 1 3 6 5 9 (ROOT->LEFT->RIGHT)
In-order:   1 2 3 4 5 6 9 (LEFT->ROOT->RIGHT)
Post-order: 1 3 2 5 9 6 4 (LEFT->RIGHT->ROOT)
```
##### Methods
+ `find`: find and return a node that has the target value
+ `insert`: add a new node keeping the BST rule
+ `pre_order`: prints all nodes in pre-order manner (parent->left->right)
+ `in_order`: prints all nodes in in-order manner (left->parent->right)
+ `post_order`: prints all nodes in post-order manner (left->right->parent)
##### TODO
- [ ] implement `level_order` method
- [ ] implement `remove` method