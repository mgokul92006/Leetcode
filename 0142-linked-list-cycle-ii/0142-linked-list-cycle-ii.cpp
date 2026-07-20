/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* s=head;
        ListNode* f=head;
        while(f!=NULL && f->next!=NULL){
            s=s->next;
            f=f->next->next;
            if(s==f){
                while(head!=s){
                    s=s->next;
                    head=head->next;
                }
                return head;
            }
        }
        return NULL;
    }
};