#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

using namespace std;

template <typename T>
struct Node{
  T data;
  Node<T> *prev;
  Node<T> *next;
  Node() : prev(nullptr), next(nullptr){};
  Node(T data) : data(data), prev(nullptr), next(nullptr){};
};

template <typename T>
class DoublyLinkedList{
private:
  Node<T> *head;
  Node<T> *tail;
  int size;

public:
  // Constructor
  DoublyLinkedList();
  // Destructor
  ~DoublyLinkedList();
  // Return size
  int get_size();
  // Return whether list is empty
  bool isEmpty();
  // Return head data
  T get_head();
  // Return tail data
  T get_tail();
  // Return nth node's data
  T get_data_at(int n);
  // Return index of node containing target data
  int find(T data);
  // Print all data
  void print_data();
  // Add a new node at the end
  void push_back(T data);
  // Add a new node in front
  void push_head(T data);
  // Add a new node at nth place
  void insert(T data, int n);
  // Delete the last node
  void pop_back();
  // Delete the first node
  void pop_head();
  // Delete nth node
  void erase(int n);
  // Delete all nodes
  void clear();
};

// Constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(){
  head = nullptr;
  tail = nullptr;
  size = 0;
}
// Destructor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
  while (!isEmpty())
    pop_head();
}
// Return size
template <typename T>
int DoublyLinkedList<T>::get_size(){ return size; }
// Return whether list is empty
template <typename T>
bool DoublyLinkedList<T>::isEmpty(){ return !size; }
// Return head data
template <typename T>
T DoublyLinkedList<T>::get_head(){ return head->data; }
// Return tail data
template <typename T>
T DoublyLinkedList<T>::get_tail(){ return tail->data; }
// Return nth node's data
template <typename T>
T DoublyLinkedList<T>::get_data_at(int n){
  // arg sanity check
  if (n < 1 || n > size){
    cout << "[Err] get_dat_at: indext out of range!" << endl;
    return -1;
  }
  
  Node<T> *cur = head;

  for (int i = 0; i < n - 1; i++)
    cur = cur->next;

  return cur->data;
}
// Return index of node containing target data
template <typename T>
int DoublyLinkedList<T>::find(T data){
  Node<T> *cur = head;
  int index = 1;

  while(cur != nullptr){
    if (cur->data == data)
      return index;
    cur = cur->next;
    index++;
  }
  
  //cerr << "[Err] find: data not found!" << endl;
  return -1;
}
// Print all data
template <typename T>
void DoublyLinkedList<T>::print_data(){
  Node<T> *cur = head;

  while(cur != nullptr){
    cout << cur->data << " ";
    cur = cur->next;
  }
  cout << endl;
}
// Add a new node at the end
template <typename T>
void DoublyLinkedList<T>::push_back(T data){
  Node<T> *newNode = new Node<T>;
  newNode->data = data;

  if (!isEmpty()){
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
  }
  else{
    head = newNode;
    tail = newNode;
  }
  size++;
}
// Add a new node in front
template <typename T>
void DoublyLinkedList<T>::push_head(T data){
  Node<T> *newNode = new Node<T>;
  newNode->data = data;

  if (!isEmpty()){
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
  else{
    head = newNode;
    tail = newNode;
  }
  size++;
}
// Add a new node at nth place
template <typename T>
void DoublyLinkedList<T>::insert(T data, int n){
  // arg sanity check
  if (n < 1 || n > size){
    cout << "[Err] insert: index out of range!" << endl;
    return;
  }

  if (n == 1){
    push_front(data);
    return;
  }
  else if (n == size){
    push_back(data);
    return;
  }
  
  if (size > 1){
    Node<T> *cur = head;
    Node<T> *newNode = new Node<T>;
    newNode->data = data;
    
    for (int i = 0; i < n - 1; i++)
      cur = cur->next;

    newNode->prev = cur->prev;
    newNode->next = cur;
    cur->prev->next = newNode;
    cur->prev = newNode;
  }
  else{ //empty list or single-node list
    push_back(data);
  }
  size++;
}
// Delete the last node
template <typename T>
void DoublyLinkedList<T>::pop_back(){
  if (isEmpty()){
    cout << "[Err] pop_back: no data to pop-back!" << endl;
    return;
  }
  else{
    if (size > 1){
      Node<T> *cur = tail;
      cur->prev->next = nullptr;
      tail = cur->prev;
      cur->prev = nullptr;
      cur->next = nullptr;
      delete cur;
    }
    else{
      Node<T> *cur = head;
      head = nullptr;
      tail = nullptr;
      delete cur;
    }
  }
  size--;
}
// Delete the first node
template <typename T>
void DoublyLinkedList<T>::pop_head(){
  if (isEmpty()){
    cout << "[Err] pop_head: no data to pop-head!" << endl;
    return;
  }
  else{
    if (size > 1){
      Node<T> *cur = head;
      head = cur->next;
      cur->next->prev = nullptr;
      cur->next = nullptr;
      delete cur;
    }
    else{
      Node<T> *cur = head;
      head = nullptr;
      tail = nullptr;
      delete cur;
    }
  }
  size--;
}
// Delete nth node
template <typename T>
void DoublyLinkedList<T>::erase(int n){
  // arg sanity check
  if (n < 1 || n > size){
    cout << "[Err] erase: index out of range!" << endl;
    return;
  }

  if (n == 1){
    pop_head();
  }
  else if (n == size)
    pop_back();
  else{
    Node<T> *cur = head;
    
    for (int i = 0; i < n - 1; i++)
      cur = cur->next;
    
    cur->prev->next = cur->next;
    cur->prev = nullptr;
    cur->next->prev = cur->prev;
    cur->next = nullptr;
    delete cur;
    size--;
  }
}
// Delete all nodes
template <typename T>
void DoublyLinkedList<T>::clear(){
  while (size != 0){
    pop_head();
  }
}
/*
int main(){
  DoublyLinkedList<int> list;

  for (int i = 0; i < 5; i++)
    list.push_back(i);

  for (int i = 0; i < 5; i++){
    list.print_data();
    cout << "size: " << list.get_size() << endl;
    cout << "HT: " << list.get_head() << " " << list.get_tail() << endl;
    cout << "Target: " << i <<  " & Target index: " << list.find(i) << endl;
    list.erase(list.find(i));
    cout << "OK" << endl;
    list.print_data();
    cout << endl;
  }

  list.push_back(22);
  
  return 0;
}
*/
#endif
