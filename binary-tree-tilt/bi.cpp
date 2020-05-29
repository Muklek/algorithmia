#include<iostream>

// recursive solution

struct Node{
   int value{0};
   Node* left{nullptr};
   Node* right{nullptr};

   Node(int data, Node* lt, Node* rt)
      :value(data),left(lt), right(rt){};
};


void getTilt(int& acc, Node* root){
  int localValue{0};

  if(root != nullptr && root->left != nullptr)
    localValue = root->left->value;
  if(root != nullptr && root->right != nullptr)
    localValue = std::abs(localValue - root->right->value);

  acc += localValue;

  if(root == nullptr) return;

  getTilt(acc, root->left);
  getTilt(acc, root->right);
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

  int tilt{0};
  getTilt(tilt, &n1);

  std::cout<<tilt<<'\n';
}

