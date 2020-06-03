#include<iostream>

// recursive

struct Node {
  int16_t val;
  Node* left;
  Node* right;

  Node(int16_t v, Node* l, Node* r)
    :val(v), left(l), right(r){};
};

bool isSymmetric(Node* childA, Node* childB){
  if(childA != nullptr && childB != nullptr &&
     childA->val != childB->val) return false;

  if(childA == nullptr && childB == nullptr) return true;
  if(childA == nullptr || childB == nullptr) return false;

  return isSymmetric(childA->right, childB->left) &&
         isSymmetric(childA->left, childB->right);
}


int main(){
  Node n1a{1, nullptr, nullptr};
  Node n2a{2, nullptr, nullptr};
  Node n3a{2, nullptr, nullptr};
  Node n4a{3, nullptr, nullptr};
  Node n5a{4, nullptr, nullptr};
  Node n6a{3, nullptr, nullptr};
  Node n7a{4, nullptr, nullptr};

  n1a.left = &n3a;
  n1a.right = &n2a;
  n2a.left = &n4a;
  n2a.right = &n5a;
  n3a.left = &n7a;
  n3a.right = &n6a;

  Node n1b{1, nullptr, nullptr};
  Node n2b{2, nullptr, nullptr};
  Node n3b{2, nullptr, nullptr};
  Node n4b{3, nullptr, nullptr};
  Node n5b{3, nullptr, nullptr};

  n1b.right = &n2b;
  n1b.left = &n3b;
  n2b.right = &n4b;
  n3b.right = &n5b;

  bool valid{isSymmetric(n1a.left, n1a.right)};
  bool notValid{isSymmetric(n1b.left, n1b.right)};

  std::cout<<valid<<'\n';
  std::cout<<notValid<<'\n';
}
