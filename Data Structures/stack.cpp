#include <iostream>

using namespace std;

template <typename T>
struct Node{
  T data;
  Node<T> *next;
  Node() : next(nullptr){}
  Node(T data) : next(nullptr), data(data){}
};

template <typename T>
class Stack{
private:
  Node<T> *top;
  int size;
public:
  // Constructor
  Stack();
  // Destructor
  ~Stack();
  // Return whether stack is empty or not
  bool isEmpty();
  // Return size of stack
  int get_size();
  // Return top data
  T get_top();
  // Add a new element into the top of stack
  void push(T data);
  // Remove top data
  void pop();
  // Print all data in LIFO manner
  void print();
};

// Constructor
template <typename T>
Stack<T>::Stack() : top(nullptr), size(0){}
// Destructor
template <typename T>
Stack<T>::~Stack(){
  while (!isEmpty())
    pop();
}
// Return whether stack is empty or not
template <typename T>
bool Stack<T>::isEmpty(){ return !size; }
// Return size of stack
template <typename T>
int Stack<T>::get_size(){ return size; }
// Return top data
template <typename T>
T Stack<T>::get_top(){ return top->data; }
// Add a new element into the top of stack
template <typename T>
void Stack<T>::push(T data){
  Node<T> *newNode = new Node<T>(data);

  if (isEmpty()){
    top = newNode;
  }
  else{
    newNode->next = top;
    top = newNode;
  }
  size++;
}
// Remove top data
template <typename T>
void Stack<T>::pop(){
  Node<T> *cur = top;

  if (isEmpty()){
    cout << "[Err] pop: no data to pop!" << endl;
    return;
  }
  else{
    Node<T> *cur = top;
    
    if (size == 1){
      delete top;
    }
    else{
      top = cur->next;
      cur->next = nullptr;
      delete cur;
    }
    size--;
  }
}
// Print all data in LIFO manner
template <typename T>
void Stack<T>::print(){
  Node<T> *cur = top;

  while (cur != nullptr){
    cout << cur->data << " ";
    cur = cur->next;
  }
}

int main(){
  Stack<int> s;

  for (int i = 0; i < 10; i++)
    s.push(i + 1);

  s.print();
  cout << endl;

  while(!s.isEmpty()){
    cout << s.get_top() << endl;
    s.pop();
  }
}
