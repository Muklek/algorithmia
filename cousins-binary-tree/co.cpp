#include<iostream>
#include<vector>

struct Node {
  int8_t val{0};
  Node* left{nullptr};
  Node* right{nullptr};

  Node(int8_t v, Node* l, Node* r)
    :val(v), left(l), right(r){};
};

inline bool isCousin(const int8_t valA,
                     const int8_t valB,
                     Node* root) {

  std::vector<Node*> nodes{root};

  for(size_t i{0}, localMax{0}, max{0}, verify{0};
      i<nodes.size(); i++){

    if(nodes[i] != nullptr){

      nodes.emplace_back(nodes[i]->left);
      nodes.emplace_back(nodes[i]->right);
      localMax += 2;

      if(nodes[i]->val == valA || nodes[i]->val == valB) ++verify;

      if(verify == 1){

        if(i > 1 && i % 2 == 0 && nodes[i-1] != nullptr &&
          (nodes[i-1]->val != valA || nodes[i-1]->val != valB)) return false;

        if(i < nodes.size()-1 && i % 2 != 0 && nodes[i+1] != nullptr &&
          (nodes[i+1]->val != valA || nodes[i+1]->val != valA)) return false;
      }
    }
    if(i == max) {
      if(verify > 1) return true;
      if(verify == 1) return false;

      max = i + localMax;
      localMax = 0;
    }
  }
  return false;
}


int main(){

  Node n1a{1, nullptr, nullptr};
  Node n2a{2, nullptr, nullptr};
  Node n3a{3, nullptr, nullptr};
  Node n4a{4, nullptr, nullptr};
  Node n5a{5, nullptr, nullptr};

  n1a.left = &n2a;
  n1a.right = &n3a;
  n2a.left = &n4a;
  n3a.right = &n5a;

  Node n1b{1, nullptr, nullptr};
  Node n2b{2, nullptr, nullptr};
  Node n3b{3, nullptr, nullptr};
  Node n4b{4, nullptr, nullptr};
  Node n5b{5, nullptr, nullptr};

  n1b.left = &n2b;
  n1b.right = &n3b;
  n2b.left = &n4b;
  n2b.right = &n5b;

  bool cousin{isCousin(4, 5, &n1a)};
  bool notCousin{isCousin(4, 5, &n1b)};

  std::cout<<cousin<<'\n';
  std::cout<<notCousin<<'\n';
}

