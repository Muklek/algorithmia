#include<iostream>

struct Node{
   int value;
   Node* left;
   Node* right;

   Node(int data): value(data), left(nullptr), right(nullptr){};

   Node(int data, Node* lt, Node* rt)
      :value(data),left(lt), right(rt){};
};


void traverse(int& commulative, Node *& t){
   commulative += t->value;

   if(t->right != nullptr)
      traverse(commulative, t->right);
   if(t->left != nullptr)
      traverse(commulative, t->left);
}

int getTilt(Node *& root){
   int rightWeight{0}, leftWeight{0};
   
   traverse(rightWeight, root->right);
   traverse(leftWeight, root->left);

   return root->value + std::abs(rightWeight - leftWeight);
}


int main(){
   Node* n1 = new Node(1);
   Node* n2 = new Node(2);
   Node* n3 = new Node(3);
   Node* n4 = new Node(4);
   Node* n5 = new Node(5);
   Node* n6 = new Node(6);
   Node* n7 = new Node(7);

   Node* root = new Node(8, n4, n7);
   root->left->left = n3;
   root->left->right = n7;
   root->right->left = n1;
   root->right->right = n2;

   std::cout<<getTilt(root)<<std::endl;
}


