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
+ destructor: need to free Nodes
+ operator overloading  
+ implement erase/2 method
+ bug fix
+ more intuitive naming

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
+ destructor: need to free Nodes
+ operator overloading
+ implement copy constructor
+ implemet erase/2 method

### Queue
Simple templatedqueue data structure using the same container with the one
used in doubly_linked_list.cpp. Initially, queue is implemented with
singly-linked container. However, the code became less readable. Besides some
general getters, such as get_size(), get_front(), get_back(), two critical
methods are implemented: enqueue() & dequeue(). Basically, enqueue() is much
like push_back() in linked-list, and dequeue() works like pop_front() but
returns front node's data. Since queue.cpp uses increases its size by one at each time of enqueuing data, overflow is not a concern.
##### Methods
+ `isEmpty()`: return whether queue is empty
+ `get_size()`: return the size of queue
+ `get_front()`: return the first element of queue
+ `get_back()`: return the last element of queue
+ `enqueue(T data)`: add new data into queue in FIFO(First In First Out) manner
+ `dequeue()`: remove and return front element of queue in FIFO manner
+ `print_data()`: print all data in queue
##### TODO
+ operator overloading
+ destructor: need to manually free Nodes