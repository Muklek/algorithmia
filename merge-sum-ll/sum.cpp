#include<iostream>
#include<vector>
#include<string>

class Node{
    public:
        int data;
        Node* next;
};

class LinkedList{
    public:
        Node* root;
        LinkedList();
        ~LinkedList();
        void insert(int item);
        void traverse();
};

LinkedList::LinkedList(){
    this->root=nullptr;
};

LinkedList::~LinkedList(){
    std::cout<<"end"<<std::endl;
}

void LinkedList::insert(int item){
    Node* node = new Node();
    node->data=item;
    node->next=this->root;
    this->root=node;
};

void LinkedList::traverse(){
    while(this->root->next != nullptr){
        std::cout<<root->data<<std::endl;
        this->root=this->root->next;
    }
};

int main(){
    LinkedList myList;
    myList.insert(1);
    myList.insert(2);
    myList.insert(3);
    myList.insert(4);
    myList.traverse();
    
}
