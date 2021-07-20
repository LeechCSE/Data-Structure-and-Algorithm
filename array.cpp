#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Array{
private:
  T *data;
  size_t n;
public:
  // Constructor
  Array(size_t n);
  // Copy constructor
  Array(Array<T> &arr);
  // Destructor
  ~Array();
  // Operator [] overloading for accessing data by index
  T& operator[](int index);
  // Access data by index (out-of-range exception checking)
  T& at(int index);
  // Return size of array
  size_t size();
  // Return iterator pointing to the first element of array 
  T* begin();
  // Return iterator pointing to the past-the-end element of array
  T* end();
};
// Constructor
template <typename T>
Array<T>::Array(size_t n){
  this->n = n;
  data = new T[n];
}
// Copy constructor
template <typename T>
Array<T>::Array(Array<T> &arr){
  this->n = arr.n;
  data = new T[n];

  for (int i = 0; i < arr.n; i++)
    data[i] = arr.data[i];
}
// Destructor
template <typename T>
Array<T>::~Array(){ delete[] data; }
// Access data by index
template <typename T>
T& Array<T>::operator[](int index){ return data[index]; }
// Access data by index (out-of-range exception checking)
template <typename T>
T& Array<T>::at(int index){
  if (index < n)
    return data[index];
  throw out_of_range("Index out-of-range");
}
// Return size of array
template <typename T>
size_t Array<T>::size(){ return n; }
// Return iterator pointing to the first element of array
template <typename T>
T* Array<T>::begin(){ return data; }
// Return iterator pointing to the past-the-end element of array
template <typename T>
T* Array<T>::end(){ return (data + n); }

int main(){

  Array<int> arr(10);
  for (int i = 0; i < arr.size(); i++)
    arr[i] = 2 * (i + 1);

  for (auto el: arr){
    cout << el << " ";
  }
  cout << endl;

  try{
    arr.at(99) = -1;
  }
  catch(out_of_range oor){
    cout << "Err: " << oor.what() << endl;
  }
  
  return 0;
}
