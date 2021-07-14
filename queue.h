#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

template <typename T>
struct Node{
  T data;
  Node<T>* next;
  Node<T>* prev;
  Node(): prev(nullptr), next(nullptr){}
  Node(T data) : next(nullptr), prev(nullptr), data(data){}
};

template <typename T>
class Queue{
private:
  Node<T>* front;
  Node<T>* back;
  int size;
public:
  // Constructor
  Queue();
  // Deconstructor
  ~Queue();
  // Return whether queue is empty or not
  bool isEmpty();
  // Return size of queue
  int get_size();
  // Return the first element of queue
  T get_front();
  // Return the last element of queue
  T get_back();
  // Add data in Queue
  void enqueue(T data);
  // Remove data from Queue
  void dequeue();
  // Print all data in queue
  void print_data();
};
// Constructor
template <typename T>
Queue<T>::Queue(){
  front = nullptr;
  back = nullptr;
  size = 0;
}
// Decontructor
template <typename T>
Queue<T>::~Queue(){
  while (!isEmpty())
    dequeue();
}
// Return whether queue is empty or not
template <typename T>
bool Queue<T>::isEmpty(){ return !size; }
// Return size of queue
template <typename T>
int Queue<T>::get_size(){ return size; }
// Return the first element of queue
template <typename T>
T Queue<T>::get_front(){ return front->data; }
// Return the last element of queue
template <typename T>
T Queue<T>::get_back(){ return back->data; }
// Add data in Queue
template <typename T>
void Queue<T>::enqueue(T data){  
  Node<T> *newNode = new Node<T>(data);
  if (isEmpty()){
    front = newNode;
    back = newNode;
  }
  else{
    newNode->next = back;
    back->prev = newNode;
    back = newNode;
  }
  size++;
}
// Remove and return data from Queue
template <typename T>
void Queue<T>::dequeue(){
  if (isEmpty()){
    //    cout << "[Err] dequeue: no data to dequeue!" << endl;
    return;
  }

  if (size == 1){
    Node<T> *cur = front;
    
    front = nullptr;
    back = nullptr;
    delete cur;
    size--;
  }
  else {
    Node<T> *cur = front->prev;
    
    cur->next->prev = nullptr;
    front = cur;
    cur = cur->next;
    front->next = nullptr;
    delete cur;
    size--;
  }
}
// Print all data in queue
template <typename T>
void Queue<T>::print_data(){
  Node<T> *cur = front;
  while(cur != nullptr){
    cout << cur->data << " ";
    cur = cur->prev;
  }
}

/*
int main(){
  Queue<int> q;

  for (int i = 0; i < 10; i++)
    q.enqueue(i + 1);

  cout << "[Front] "; q.print_data(); cout << "[Back]" << endl;
   
  return 0;
}
*/
#endif
