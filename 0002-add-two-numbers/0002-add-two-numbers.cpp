/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* n=new ListNode(0);
        ListNode* temp=n;
        int c=0;
        while(l1!=NULL && l2!=NULL){
            c=c+l1->val+l2->val;
            n->next=new ListNode(c%10);
            n=n->next;
            l1=l1->next;
            l2=l2->next;
            c=c/10;
        }
        while(l1!=NULL){
            c=c+l1->val;
            n->next=new ListNode(c%10);
            n=n->next;
            l1=l1->next;
            c=c/10;
        }
        while(l2!=NULL){
            c=c+l2->val;
            n->next=new ListNode(c%10);
            n=n->next;
            l2=l2->next;
            c=c/10;
        }
        if(c!=0)
        n->next=new ListNode(c);
        return temp->next;
    }
};