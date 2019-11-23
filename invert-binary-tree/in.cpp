#include<iostream>
#include<vector>

struct Node {
   int data;
   Node* right;
   Node* left;

   Node(Node* rt, Node* lt, int item)
      :right(rt),left(lt),data(item){};
};

void invert(Node *& t){
   if(t != nullptr){
      Node* temp{t->right};
      t->right = t->left;
      t->left = temp;
   }
   if(t->right != nullptr) invert(t->right);
   if(t->left != nullptr) invert(t->left);
}


int main(){
   Node* node_1 = new Node(nullptr, nullptr, 1);
   Node* node_2 = new Node(nullptr, nullptr, 2);
   Node* node_3 = new Node(nullptr, nullptr, 3);
   Node* node_4 = new Node(nullptr, nullptr, 4);
   Node* node_5 = new Node(nullptr, nullptr, 5);
   Node* node_6 = new Node(nullptr, nullptr, 6);

   node_1->left = node_2;
   node_1->right = node_3;
   node_2->left = node_4;
   node_2->right = node_5;
   node_3->left = node_6;

   invert(node_1);

   std::cout<<node_1->right->data<<std::endl;
   std::cout<<node_2->right->data<<std::endl;
   std::cout<<node_3->right->data<<std::endl;
}
