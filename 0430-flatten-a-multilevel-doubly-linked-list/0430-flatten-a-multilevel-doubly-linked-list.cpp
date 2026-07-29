/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    // Node* head=NULL;
    // Node* tail=NULL;
    // void convert(Node* root){
    //     if(root==NULL)
    //     return;
    //     Node* n=new Node(root->val);
    //     if(head==NULL){
    //         head=n;
    //         tail=n;
    //     }
    //     else{
    //         tail->next=n;
    //         n->prev=tail;
    //         tail=n;
    //     }
    //     convert(root->child);
    //     convert(root->next);
    // }
    // Node* flatten(Node* root) {
    //    convert(root);
    //    return head;
    // }
    Node* prev=NULL;
    Node* flatten(Node* root) {
        if(root==NULL)
        return root;
        flatten(root->next);
        flatten(root->child);
        root->next=prev;
        if( prev )
            prev->prev=root;
        root->child = NULL;
        prev=root;
        return root;
    }
};