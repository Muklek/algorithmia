#include<iostream>
#include<vector>

struct ListNode{
    int data;
    Node* next;
    Node(int x):data(x),next(NULL){}
}

class Solution{
    public:
        ListNode* appendNode(int number, ListNode* root){
            ListNode* new_node(nullptr);
            new_node = new ListNode(number);
            new_node->next=*root;
            return new_node;
        }
        ListNode* mergeSum(ListNode* l1, ListNode* l2){
            ListNode* outcome_list(nullptr);
            while(l1 || l2){
                appendNode(l1->data >= l2->data ?
                        l1->data : l2->data, 
            }
        }
}
