#include<iostream>
#include<vector>

// recursive

struct Node {
  int16_t value{0};
  Node* left{nullptr};
  Node* right{nullptr};

  Node(int v, Node* l, Node* r)
    :value(v),left(l),right(r){};
};

bool traverse(const int16_t& ref, Node *& root){
  if(root != nullptr && root->value != ref) return false;
  if(root == nullptr) return true;
  return traverse(ref, root->right) && traverse(ref, root->left);
}

bool isUnivalTree(Node* root){
  if(root != nullptr) return traverse(root->value, root);
  return false;
}



int main(){
  Node n1a{1, nullptr, nullptr};
  Node n2a{1, nullptr, nullptr};
  Node n3a{1, nullptr, nullptr};
  Node n4a{2, nullptr, nullptr};
  Node n5a{1, nullptr, nullptr};
  n1a.left = &n2a;
  n1a.right = &n3a;
  n3a.right = &n4a;
  n4a.left = &n5a;

  Node n1b{1, nullptr, nullptr};
  Node n2b{1, nullptr, nullptr};
  Node n3b{1, nullptr, nullptr};
  Node n4b{1, nullptr, nullptr};
  Node n5b{1, nullptr, nullptr};
  n1b.left = &n2b;
  n1b.right = &n3b;
  n3b.right = &n4b;
  n4b.left = &n5b;

  bool valid{isUnivalTree(&n1b)};
  bool notValid{isUnivalTree(&n1a)};

  std::cout<<valid<<'\n';
  std::cout<<notValid<<'\n';
}

