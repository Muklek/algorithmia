#include<iostream>
#include<vector>

// non-recursive

struct Node {
  int16_t val;
  Node* left;
  Node* right;

  Node(int16_t v, Node* l, Node* r)
    :val(v), left(l), right(r){};
};


__attribute__((always_inline))
inline bool isSymmetric(Node* root){

  if(root == nullptr) return true;

  std::vector<Node*> nodes{root, root->left, root->right};
  for(int i{1}; i<nodes.size() - 1; i++){
    if(i % 2 != 0){
      if(nodes[i] == nullptr && nodes[i+1] == nullptr) continue;
      if(nodes[i] == nullptr || nodes[i+1] == nullptr) return false;
      if(nodes[i]->val != nodes[i+1]->val) return false;

      nodes.emplace_back(nodes[i]->left);
      nodes.emplace_back(nodes[i+1]->right);
      nodes.emplace_back(nodes[i]->right);
      nodes.emplace_back(nodes[i+1]->left);
    }
  }
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

  bool valid{isSymmetric(&n1a)};
  bool notValid{isSymmetric(&n1b)};

  std::cout<<valid<<'\n';
  std::cout<<notValid<<'\n';
}
