#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Tree_node{
  string data;
  Tree_node *left;
  Tree_node *right;
  Tree_node(string d) : data(d), left(nullptr), right(nullptr){}
};

struct Tree{
  Tree_node *root;
  // Initialize a new tree
  static Tree create(const string &data){
    Tree tree;
    tree.root = new Tree_node(data);
    return tree;
  }
  // Find and return a node that has target value
  Tree_node *find(Tree_node *root, const string &val){
    if (root == nullptr){ // empty tree
      return nullptr;
    }
    if (root->data == val) // base case
      return root;

    Tree_node *target = find(root->left, val); // recursion w/ left sub-tree
    if (target != nullptr)
      return target;
    
    return find(root->right, val); // recursion w/ right sub-tree
  }
  // Add a new node under the parent node
  bool add(const string &parent, const string &data){
    Tree_node *parent_node = find(root, parent);
    if (parent_node == nullptr) // not found
      return false;
    if (parent_node->left && parent_node->right) // full parent sub-tree
      return false;

    if (!parent_node->left){
      parent_node->left = new Tree_node(data);
      return true;
    }
    else{
      parent_node->right = new Tree_node(data);
      return true;
    }
  }
  // Print all nodes in pre-order manner(parent->left->right)
  void pre_order(Tree_node *root){
    if (root == nullptr) // base case
      return;

    cout << root->data << " ";
    pre_order(root->left);
    pre_order(root->right);
  }
  // Print all nodes in in-order manner(left->parent->right)
  void in_order(Tree_node *root){
    if (root == nullptr) // base case
      return; 

    in_order(root->left);
    cout << root->data << " ";
    in_order(root->right);
  }
  // Print all nodes in post-order manner(left->right->parent)
  void post_order(Tree_node *root){
    if (root == nullptr) // base case
      return;

    post_order(root->left);
    post_order(root->right);
    cout << root->data << " ";
  }
  // Print all nodes by level(Root->level 1->level 2-> ...)
  void level_order(Tree_node *root){
    queue<Tree_node *> q;
    q.push(root);

    while (!q.empty()){
      Tree_node *cur = q.front();
      q.pop();
      
      cout << cur->data << " ";
      
      if (cur->left != nullptr)
	q.push(cur->left);
      if (cur->right != nullptr)
	q.push(cur->right);
    }
  }
};

int main(){
  Tree t = Tree::create("ROOT");
  
  t.add("ROOT", "AA");
  t.add("AA", "AA-l");
  t.add("AA", "AA-r");
  t.add("AA-l", "AA-l-l");
  t.add("AA-l", "AA-l-r");

  cout << "PRE: ";
  t.pre_order(t.root);
  cout << endl;

  cout << "IN: ";
  t.in_order(t.root);
  cout << endl;

  cout << "POST: ";
  t.post_order(t.root);
  cout << endl;

  cout << "LEVEL: ";
  t.level_order(t.root);
  cout << endl;

  return 0;
}
