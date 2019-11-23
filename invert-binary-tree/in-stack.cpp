#include<iostream>
#include<stack>



struct Node {
   int data;
   Node* right;
   Node* left;

   Node(Node* rt, Node* lt, int item)
      :right(rt),left(lt),data(item){};
};


void invert(Node *& t){
   std::stack<Node*> nodes;

   nodes.push(t);
   while(nodes.size() != 0){
      Node* node = nodes.top();
      if(node != nullptr){
         Node* temp = node->left;
         node->left = node->right;
         node->right = temp;
      }
      
      nodes.pop();
      
      if(node != nullptr){
         nodes.push(node->left);
         nodes.push(node->right);
      }
   }
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
