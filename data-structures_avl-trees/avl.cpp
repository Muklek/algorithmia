#include<iostream>

using namespace std;

template<typename Object>
class AvlTree{
   public:
      AvlTree():root(nullptr){};
      ~AvlTree(){deleteTree();};

      void insert(Object x){
         insert(x, root);
      }

      void remove(Object x){
         remove(x, root, root);
      }

      void deleteTree(){
         eraseNodes(root);
      }

      void printTree(){
         std::cout<<std::endl;
         print(root);
      }

      void printRight(){
         std::cout<<std::endl;
         std::cout<<std::endl;
         printRight(root);
      }

      void printLeft(){
         std::cout<<std::endl;
         std::cout<<std::endl;
         printLeft(root);
      }

   private:

      struct Node{
         Object data;
         Node* right;
         Node* left;
         int height;

         Node(Object element, Node* rt, Node* lt, int h=0)
            : data(element),right(rt),left(lt), height(h){};
      };

      Node* root;

      int height(Node *& t){
         return t == nullptr ? -1 : t->height;
      }

      void insert(Object x, Node *& t){
         if(t == nullptr) t = new Node(x, nullptr, nullptr);
         else if(x < t->data) insert(x, t->left);
         else if(x > t->data) insert(x, t->right);

         balance(t);
      }

      void balance(Node *& t){
         if(t == nullptr) return;

         if(height(t->left) - height(t->right) > 1){
            if(height(t->left->left) >=  height(t->left->right)){
               singleLeftRotation(t);
            }
            else doubleLeftRotation(t);
         }
         else if(height(t->right) - height(t->left) > 1){
            if(height(t->right->right) >= height(t->right->left)){
               singleRightRotation(t);
            }
            else doubleRightRotation(t);
         }
         t->height = max(height(t->right), height(t->left)) + 1;
      }

      void singleLeftRotation(Node *& k2){
         Node* k1 = k2->left;
         k2->left = k1->right;
         k1->right = k2;

         // height recompute
         k2->height = max(height(k2->right), height(k2->left)) + 1;
         k1->height = max(height(k1->left), k2->height) + 1;

         k2 = k1;
      }

      void singleRightRotation(Node *& k1){
         Node* k2 = k1->right;
         k1->right = k2->left;
         k2->left = k1;

         // height recompute
         k1->height = max(height(k1->right), height(k1->left)) + 1;
         k2->height = max(height(k2->left), k1->height) + 1;

         k1 = k2;
      }

      void doubleLeftRotation(Node *& k3){
         singleRightRotation(k3->left);
         singleLeftRotation(k3);
      }

      void doubleRightRotation(Node *& k1){
         singleLeftRotation(k1->right);
         singleRightRotation(k1);
      }

      Node* findMin(Node *& t){
         if(t->left != nullptr) findMin(t->right);
         else if(t->left == nullptr) return t;
      }

      void remove(Object x, Node *& p, Node *& c){
         if(c == nullptr) return;
         if(c->data == x){
            if(c->left != nullptr && c->right != nullptr){
               c->data = findMin(c->right)->data;
               remove(c->data, c, c->right);
            }
            else if(c->left == nullptr || c->right == nullptr){
               Node* temp = c;
               c = (c->left != nullptr) ? c->left : c->right;
               delete temp;
            }
            else{

               Node* temp = c;
               if(c->data < p->data) p->left = nullptr;
               else p->right = nullptr;
               delete temp;
            }
         }
         else if(x > c->data) remove(x, c, c->right);
         else if(x < c->data) remove(x, c, c->left);

         balance(p);
      }

      void print(Node *& t){
         std::cout<<t->data<<"   ";
         std::cout<<"height: "<<t->height<<std::endl;
         if(t->right != nullptr) print(t->right);
         if(t->left != nullptr) print(t->left);
      }

      void printRight(Node *& t){
         std::cout<<t->data<<std::endl;
         if(t->right != nullptr) printRight(t->right);
      }

      void printLeft(Node *& t){
         std::cout<<t->data<<std::endl;
         if(t->left != nullptr) printLeft(t->left);
      }

      void eraseNodes(Node *& t){
         if(t->right != nullptr) eraseNodes(t->right);
         if(t->left != nullptr) eraseNodes(t->left);
         delete t;
      }

};


int main(){
   AvlTree<int> t;
   t.insert(20);
   t.insert(15);
   t.printTree();

   t.insert(7);
   t.printTree();

   t.insert(5);
   t.printTree();

   t.insert(3);
   t.printTree();

   t.insert(6);
   t.printTree();

   t.remove(15);
   t.printTree();

   t.remove(7);
   t.printTree();

}
