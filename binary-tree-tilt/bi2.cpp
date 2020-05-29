#include<iostream>
#include<vector>
#include<memory>

// non-recursive solution

struct Node{
   int value{0};
   Node* left{nullptr};
   Node* right{nullptr};

   Node(int data, Node* lt, Node* rt)
      :value(data),left(lt), right(rt){};
};

__attribute__((always_inline))
int getTilt(Node* root){
  int tilt{0}, localTilt{0};
  std::vector<Node*> nodes{root};

  for(int i{0}, lookup{0}; i<nodes.size(); i++){
    if(nodes[i] != nullptr) {

      if(nodes[i]->left != nullptr)
        localTilt = nodes[i]->left->value;
      if(nodes[i]->right != nullptr)
        localTilt = std::abs(localTilt - nodes[i]->right->value);

      tilt += localTilt;
      localTilt = 0;

      nodes.emplace_back(nodes[i]->left);
      nodes.emplace_back(nodes[i]->right);
    }
  }
  return tilt;
}


int main(){
  Node n1{1, nullptr, nullptr};
  Node n2{2, nullptr, nullptr};
  Node n3{3, nullptr, nullptr};
  Node n4{30, nullptr, nullptr};
  Node n5{29, nullptr, nullptr};

  n1.left = &n2;
  n1.right = &n3;
  n3.right = &n4;
  n3.left = &n5;

  std::cout<<getTilt(&n1)<<'\n';
}

