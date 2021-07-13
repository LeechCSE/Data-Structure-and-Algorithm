#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
struct Node{
  T data;
  Node<T> *next = nullptr;
};

template <typename T>
class SinglyLinkedList{
private:
  Node<T> *head;
  Node<T> *tail;
  int size;

public:
  // Constructor
  SinglyLinkedList();
  // Destructor
  ~SinglyLinkedList();

  /*************/
  /** Methods **/
  /*************/
  // return size
  int get_size();
  // return head data
  const T get_head();
  // return tail data
  const T get_tail();
  // print all nodes' data
  void print_data();
  // return index of the first node containing target data
  int find_by_data(T data);
  // return data of nth node
  const T find_by_index(int n);
  // return whether the list is empty or not
  bool isEmpty();
  // add a new node at the end of the list
  void push_back(T data);
  // add a new node at the start of the list
  void push_front(T data);
  // add a new node at nth index; the new node will be nth node
  void insert(T data, int n);
  // delete the last node
  void pop_back();
  // delete head
  void pop_front();
  // delete nth node
  void erase(int n);
  // TODO(not working at all)
  // delete range of nodes
  void erase(int start, int end);
};

// Constructor
template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
  }
// Destructor
template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList(){
  while (!isEmpty())
    pop_front();
}
// return size
template<typename T>
int SinglyLinkedList<T>::get_size(){ return size; }
// return head data
template<typename T>
const T SinglyLinkedList<T>::get_head(){ return head->data; }
// return tail data
template<typename T>
const T SinglyLinkedList<T>::get_tail(){ return tail->data; }
// print all nodes' data
template<typename T>
void SinglyLinkedList<T>::print_data(){
  Node<T> *cur = head;
  while (cur != nullptr){
    cout << cur->data << " ";
    cur = cur->next;
  }
  cout << endl;
}
// return index of the first node containing target data
template<typename T>
int SinglyLinkedList<T>::find_by_data(T data){
  Node<T> *cur = head;
  int index = 1;
  
  while(cur != nullptr){
    if (cur->data == data)
      return index;
    cur = cur->next;
    index++;
  }

  cout << "[Err] find_by_data: data not found!" << endl;
  return -1; // not found
}
// return data of nth node
template<typename T>
const T SinglyLinkedList<T>::find_by_index(int n){
  if (n < 1 || n > size){
    cout << "[err] find_by_index: out of range!" << endl;
    return -1;
  }
  
  Node<T> *cur = head;
  for (int i = 0; i < n - 1; i++){
    cur = cur->next;
  }

  return cur->data;
}
// return whether the list is empty or not
template<typename T>
bool SinglyLinkedList<T>::isEmpty(){
  return !size;
}
// TODO(not implemented): assignment operator overloading (deep copy)

// TODO(not implemted): stream extraction overloading
/*
ostream &operator<<(ostream &os, SinglyLinkedList<T><T> &list){
  print_data();
}
*/
// add a new node at the end of the list
template<typename T>
void SinglyLinkedList<T>::push_back(T data){
  Node<T> *newNode = new Node<T>;
  newNode->data = data;
  newNode->next = nullptr;

  if (head == nullptr){ // empty list
    head = newNode;
    tail = newNode;
  }
  else{
    tail->next = newNode;
    tail = newNode;
  }
  
  size++;
}
// add a new node at the start of the list
template<typename T>
void SinglyLinkedList<T>::push_front(T data){
  Node<T> *newNode = new Node<T>;
  
  newNode->data = data;
  newNode->next = head;
  head = newNode;
  size++;
}
// add a new node at nth index; the new node will be nth node
template<typename T>
void SinglyLinkedList<T>::insert(T data, int n){
  Node<T> *cur = head;
  Node<T> *cur2 = head;

  //    assert(n <= size);
  if (n > size){ // target index is out of range/size
    cout << "append: out of range!" << endl;
    return;
  }
  
  for (int i = 0; i < n - 2; i++){ // if n <= 2, n will be head
    cur = cur->next;
    cur2 = cur->next;
  }
  
  Node<T> *newNode = new Node<T>;
  newNode->data = data;
  cur->next = newNode;
  newNode->next = cur2;
  size++;
}
// delete the last node
template<typename T>
void SinglyLinkedList<T>::pop_back(){
  if (size >= 2){
    Node<T> *cur = head;
    
    while (cur->next != tail)
cur = cur->next;

    tail = cur;
    cur->next = nullptr;
    delete cur->next;
    size--;
  }
  else if (size == 1){
    head = nullptr;
    tail = nullptr;
    size--;
  }
  else if (size == 0){
    cout << "[err]pop_back: empty list!" << endl;
  }
}
// delete head
template<typename T>
void SinglyLinkedList<T>::pop_front(){
  if (isEmpty())
    cout << "[err]pop_front: empty list!" << endl;
  else{
    Node<T> *cur = head;
    head = head->next;
    delete cur;
    size--;
  }
}
// delete nth node
template<typename T>
void SinglyLinkedList<T>::erase(int n){
  if (n <= 0 || n > size){
    cout << "[err]erase/1: out of range!" << endl;
    return;
  }
  else if (n == 1){
    pop_front();
    return;
  }
  else if (n == size){
    pop_back();
    return;
  }
  
  Node<T> *cur = head;
  Node<T> *cur2 = head;
  
  for (int i = 0; i < n - 2; i++){
    cur = cur->next;
    cur2 = cur->next;
  }

  cur->next = cur2->next;
  delete cur2;
  size--;
}
// TODO(not working at all)
// delete range of nodes
template<typename T>
void SinglyLinkedList<T>::erase(int start, int end){
  if (start < 0 || end > size)
    cout << "invalid arg" << endl;
  else{
    Node<T> *scur = head;
    Node<T> *scur2 = head;
    Node<T> *scur3 = head;
    Node<T> *ecur = head;
    
    for (int i = 0; i < start - 2; i++){
scur = scur->next;
scur2 = scur->next;
scur3 = scur2->next;
    }
    for (int i = 0; i < end - 2; i++){
ecur = ecur->next;
    }
    scur->next = ecur->next;

    //while(scur2 != ecur){
//  delete scur2;
    //}
    
    size -= (end - start + 1);
  }
}

int main(){
  SinglyLinkedList<int> list;

  for (int i = 0; i < 8; i++){
    list.push_back(i+1);
  }

  cout << "insert: " << endl;
  list.insert(99, 5);
  list.print_data();

  cout << "erase at 4: " << endl;
  list.erase(13);
  list.print_data();
  cout << "size " << list.get_size() << endl;

  cout << "pop_back: " << endl;
  list.pop_back();
  list.print_data();
  cout << "size " << list.get_size() << endl;

  cout << "erase last: " << endl;
  list.erase(list.get_size());
  list.print_data();
  cout << "size " << list.get_size() << endl;

  cout << "erase head: " << endl;
  list.erase(1);
  list.print_data();
  cout << "size " << list.get_size() << endl;

  cout << endl;
  list.print_data();
  cout << "find by data 5:" << endl;
  cout << "At " << list.find_by_data(77) << endl;

  cout << "find by index last:" << endl;
  cout << "Data " << list.find_by_index(list.get_size()) << endl;

  SinglyLinkedList<int> list2;
  list2.print_data();
  list2.push_front(99);
  list2.print_data();

  return 0;
}
