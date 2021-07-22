#include <iostream>

using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;
  Node(int d) : data(d), left(nullptr), right(nullptr){}
};

struct BST{
  Node* root;
  BST() : root(nullptr){}
  // Wrapper for find_helper
  Node* find(int val){ return find_helper(root, val); }
  // Wrapper for insert_helper
  void insert(int val){
    if (root == nullptr)
      root = new Node(val);
    else
      insert_helper(root, val);
  }
  // Wrapper for pre_order_helper
  void pre_order() { pre_order_helper(root); }
  // Wrapper for in_order_helper
  void in_order() { in_order_helper(root); }
    // Wrapper for post_order_helper
  void post_order() { post_order_helper(root); }
private:
  // Return a node that has target value
  Node* find_helper(Node* root, int val){
    if (root == nullptr) // base case: empty tree
      return nullptr;
    if (root->data == val) // base case: target found
      return root;
    
    if (val <= root->data)
      return find_helper(root->left, val);
    else
      return find_helper(root->right, val); 
  }
  // Add a new node
  void insert_helper(Node* root, int val){
    if (val <= root->data){
      if (root->left != nullptr)
	insert_helper(root->left, val);
      else
	root->left = new Node(val);
    }
    else{
      if (root->right != nullptr)
	insert_helper(root->right, val);
      else
	root->right = new Node(val);
    }
  }
  // Print all nodes in pre-order manner(parent->left->right)
  void pre_order_helper(Node* root){
    if (root == nullptr)
      return;

    cout << root->data << " ";
    pre_order_helper(root->left);
    pre_order_helper(root->right);
  }
  // Print all nodes in in-order manner(left->parent->right)
  void in_order_helper(Node* root){
    if (root == nullptr)
      return;

    pre_order_helper(root->left);
    cout << root->data << " ";
    pre_order_helper(root->right);
  }
  // Print all nodes in post-order manner(left->right->parent)
  void post_order_helper(Node* root){
    if (root == nullptr)
      return;

    pre_order_helper(root->left);
    pre_order_helper(root->right);
    cout << root->data << " ";
  }
};

int main(){
  BST tree;
  
  tree.insert(3);
  tree.insert(12);
  tree.insert(7);
  tree.insert(14);
  tree.insert(21);
  tree.insert(1);
  tree.insert(9);
  tree.insert(17);

  tree.pre_order(); cout << endl;
  tree.in_order(); cout << endl;
  tree.post_order(); cout << endl;
  
  return 0;
}
