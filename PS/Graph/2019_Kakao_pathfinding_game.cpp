#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> rtn;

struct Label{
    int index, x, y;
};

struct Node{
    int data;
    int key;
    Node* left;
    Node* right;
    
    Node(int _data, int _key){
        data = _data;
        key = _key;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert_node(Node* root, int data, int key){
    if (root == nullptr)
        return new Node(data, key);
    
    if (key < root->key)
        root->left = insert_node(root->left, data, key);
    else
        root->right = insert_node(root->right, data, key);
    
    return root;
}

Node* create_tree(vector<Label> nodelabel){
    Node* root = nullptr;
    for (auto l: nodelabel)
        root = insert_node(root, l.index, l.x);
    
    return root;
}

vector<int> preorder(Node* root){    
    if (root == nullptr)
        return rtn;
    
    rtn.emplace_back(root->data);
    preorder(root->left);
    preorder(root->right);
    
    return rtn;
}

vector<int> postorder(Node* root){
    if (root == nullptr)
        return {};
    
    postorder(root->left);
    postorder(root->right);
    rtn.emplace_back(root->data);
    
    return rtn;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    vector<Label> nodelabel;
    for (int i = 0; i < nodeinfo.size(); i++)
        nodelabel.emplace_back(Label{i + 1, nodeinfo[i][0], nodeinfo[i][1]});
    sort(nodelabel.begin(), nodelabel.end(), [](Label l1, Label l2){
        return l1.y > l2.y;
    });
    
    Node* root = create_tree(nodelabel);
    answer.emplace_back(preorder(root));
    rtn.clear();
    answer.emplace_back(postorder(root));
    
    return answer;
}