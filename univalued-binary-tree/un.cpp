#include<iostream>
#include<vector>

// non-recursive

struct Node {
  int16_t value{0};
  Node* left{nullptr};
  Node* right{nullptr};

  Node(int v, Node* l, Node* r)
    :value(v),left(l),right(r){};
};


__attribute__((always_inline))
inline bool isUnivalTree(Node* root){
  int16_t refValue{root->value};
  std::vector<Node*> nodes{root};

  for(size_t i{0}; i < nodes.size(); i++){
    if(nodes[i] != nullptr) {

      if(nodes[i]->value != refValue)
        return false;

      nodes.emplace_back(nodes[i]->left);
      nodes.emplace_back(nodes[i]->right);
    }
  }
  return true;
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

