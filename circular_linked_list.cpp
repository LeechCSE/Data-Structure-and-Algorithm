#include <iostream>

using namespace std;

/*********************************************************
 * Circular_ll_node
 *   Node data type used for Circular linked list
 * It contains 'data'(int) and 'next'(NodePtr) that points 
 * to the next node.  
 *********************************************************/
struct Circular_ll_node{
  int data;
  Circular_ll_node *next;
  Circular_ll_node(int val) : data(val), next(nullptr){}
};

class Circular_ll{
public:
  using Node = Circular_ll_node;
  using NodePtr = Node*;
private:
  NodePtr head;
  NodePtr tail;
public:
  // Constructor
  Circular_ll();
  // Copy Constructor
  Circular_ll(const Circular_ll &list);
  // Destructor
  ~Circular_ll();
  // Add a new element at the front of the list
  void push_front(int val);
  // Remove the first element from the list
  void pop_front();
  // Return the number of list
  int size();
  
  /*********************************************************
   * Circular_ll_iterator
   *   An iterator data type used for Circular linked list
   * It contains 'ptr'(NodePtr) that points to a circular
   * linked list node.
   *********************************************************/
  struct Circular_ll_iterator{
  private:
    NodePtr ptr;
  public:
    // Constructor
    Circular_ll_iterator(NodePtr p) : ptr(p){}
    // Operator * overloading: return data of node that iterator is pointing to
    int& operator*(){ return ptr->data; }
    // Return iterator itself
    NodePtr get(){ return ptr; }
    // Advance iterator to the next node by one(pre-increment)
    Circular_ll_iterator& operator++(){
      ptr = ptr->next;
      return *this;
    }
    // Operator == overloading:
    //   return true if both iterator points to the same node
    friend bool operator==(Circular_ll_iterator lhs, Circular_ll_iterator rhs){
      return (lhs.ptr == rhs.ptr);
    }
    // Operator == overloading:
    //   return false if both iterator points to the same node
    friend bool operator!=(Circular_ll_iterator lhs, Circular_ll_iterator rhs){
      return (lhs.ptr != rhs.ptr);
    }
  };
  // Return an iterator pointing to the head
  Circular_ll_iterator begin();
  Circular_ll_iterator begin() const;
  // Return an iterator pointing to the past-the-end element(head in this case)
  Circular_ll_iterator end();
  Circular_ll_iterator end() const;
  // Return an iterator pointing to the tail
  Circular_ll_iterator back_it();
  Circular_ll_iterator back_it() const;
};
// Constructor
Circular_ll::Circular_ll() : head(nullptr), tail(nullptr){}
// Copy constructor
Circular_ll::Circular_ll(const Circular_ll &list){
  if (list.head != nullptr){
    head = new Node(-1);
    NodePtr cur = head;
    Circular_ll_iterator it = list.begin();
    while (it == list.back_it()){
      cur->data = *it;
      cur->next = it.get()->next;
      cout << "COPIED: " << cur->data << endl;
      cur = cur->next;
      ++it;
    }
    tail = it.get();
    tail->next = head;
  }
  else{
    head = nullptr;
    tail = nullptr;
  }
}
// Destructor
Circular_ll::~Circular_ll(){};
// Add a new element at the front of the list
void Circular_ll::push_front(int val){
  Node *newNode = new Node(val);
  if (head != nullptr){ // not empty
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
  }
  else{ // empty
    newNode->next = newNode;
    head = newNode;
    tail = newNode;
  }
}
// Remove the first element from the list
void Circular_ll::pop_front(){
  if (head != nullptr){
    NodePtr cur = head;
    tail->next = head->next;
    head = head->next;
    cur->next = nullptr;
    delete cur;
  }
}
// Return the number of list
int Circular_ll::size(){
  int cnt = 0;
  NodePtr cur = head;
  while (cur != tail){
    cnt++;
    cur = cur->next;
  }
  return cnt;
}
// Return an iterator pointing to the head
Circular_ll::Circular_ll_iterator Circular_ll::begin(){
  return Circular_ll_iterator(head);
}
Circular_ll::Circular_ll_iterator Circular_ll::begin() const{
  return Circular_ll_iterator(head);
}
// Return an iterator pointing to the past-the-end element(head in this case)
Circular_ll::Circular_ll_iterator Circular_ll::end(){
  return Circular_ll_iterator(head);
}
Circular_ll::Circular_ll_iterator Circular_ll::end() const{
  return Circular_ll_iterator(head);
}
// Return an iterator pointing to the tail
Circular_ll::Circular_ll_iterator Circular_ll::back_it(){
  return Circular_ll_iterator(tail);
}
Circular_ll::Circular_ll_iterator Circular_ll::back_it() const{
  return Circular_ll_iterator(tail);
}
int main(){
  Circular_ll list;

  for (int i = 0; i < 10; i++){
    list.push_front(i);
  }

  int cycle = 1;
  int index = 0;
  for (auto it = list.begin(); cycle != 6; ++it){
    index++;
    cout << *it << " ";
    if (index % (list.size() + 1) == 0){
      cout << "(Cycle " << cycle << ")" << endl;
      cycle++;
    }
  }
  cout << endl;
  cycle = 1;
  index = 0;
  
  Circular_ll list2(list);
  list2.push_front(99);
  cout << "LIST1\n";
  for (auto it = list.begin(); cycle != 6; ++it){
    index++;
    cout << *it << " ";
    if (index % (list.size() + 1) == 0){
      cout << "(Cycle " << cycle << ")" << endl;
      cycle++;
    }
  }
  cout << endl;
  cycle = 1;
  index = 0;
  cout << "LIST2\n";
  for (auto it = list2.begin(); cycle != 6; ++it){
    index++;
    cout << *it << " ";
    if (index % (list.size() + 1) == 0){
      cout << "(Cycle " << cycle << ")" << endl;
      cycle++;
    }
  }
  cout << endl;
  cycle = 1;
  index = 0;
  return 0;
}
