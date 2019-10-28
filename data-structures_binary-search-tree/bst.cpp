#include<iostream>

using namespace std;

template <typename Object>
class BinarySearchTree{
   public:
      BinarySearchTree():root(nullptr){};
      ~BinarySearchTree(){emptyTree();};

      void insert(Object item){
         insert(item, root);
      }
      void remove(Object item){
         remove(item, root, root);
      }
      void emptyTree(){
         deleteNodes(root);
      }
      void print(){
         std::cout<<std::endl;
         printNodes(root);
      }
      void printLeft(){
         std::cout<<std::endl;
         std::cout<<std::endl;
         printLeft(root);
      }
      void printRight(){
         std::cout<<std::endl;
         std::cout<<std::endl;
         printRight(root);
      }

   private:
      
      struct Node{
         Object data;
         Node* right;
         Node* left;

         Node(Object value, Node* rt, Node* lt)
            : data(value), right(rt), left(lt){};
      };

      Node* root;
      
      void insert(Object x, Node *& t){
         if(t == nullptr){
            t = new Node(x, nullptr, nullptr);
         }
         else if(x < t->data) insert(x, t->left);
         else if(x > t->data) insert(x, t->right);
      }

      Node* findMin(Node *& t){
         if(t->right == nullptr) return t;
         else findMin(t->right);
      }
      void remove(Object x, Node *& p, Node *& c){
         if(c->data == x){
            if(c->right != nullptr && c->left != nullptr){
               c->data = findMin(c->right)->data;
               remove(c->data, c, c->right);
            }
            else if(c->right != nullptr || c->left != nullptr){
               Node* temp = c;
               c = c->right != nullptr ? c->right : c->left;
               delete temp;
            }
            else{
               if(x<p->data) p->left = nullptr;
               else p->right = nullptr;
               delete c;
            }
         }
         else if(x < c->data) remove(x, c, c->left);
         else if(x > c->data) remove(x, c, c->right);
      }

      void deleteNodes(Node *& t){
         if(t->right != nullptr) deleteNodes(t->right);
         if(t->left != nullptr) deleteNodes(t->left);
         delete t;
      }

      Node* clone(Node *& t){
         if(t == nullptr) return nullptr;
         else return new Node(t->data, clone(t->left), clone(t->right));
      }

      void printNodes(Node *& t){
         std::cout<<t->data<<std::endl;
         if(t->right != nullptr) printNodes(t->right);
         if(t->left != nullptr) printNodes(t->left);
      }
      void printLeft(Node *& t){
         std::cout<<t->data<<std::endl;
         if(t->left != nullptr) printLeft(t->left);
      }
      void printRight(Node *& t){
         std::cout<<t->data<<std::endl;
         if(t->right != nullptr) printRight(t->right);
      }
};


int main(){
   BinarySearchTree<int> b;
   b.insert(6);
   b.insert(2);
   b.insert(22);
   b.insert(3);
   b.insert(5);
   b.print();
   
   b.remove(6);
   b.print();
   
   b.remove(5);
   b.print();
   
   b.remove(22);
   b.print();
   
   b.remove(3);
   b.print();
   
}
