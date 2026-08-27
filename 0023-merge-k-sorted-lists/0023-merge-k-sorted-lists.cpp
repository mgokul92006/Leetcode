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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*>a;
        for(int i=0;i<lists.size();i++){
            while(lists[i]){
                a.push_back(lists[i]);
                lists[i]=lists[i]->next;
            }
        }
        ListNode* k=new ListNode();
        ListNode* h=k;
        int c=0;
        vector<int>b;
        for(int i=0;i<a.size();i++)
        b.push_back(a[i]->val);
        sort(b.begin(),b.end());
        for(int i=0;i<b.size();i++){
           h->next=new ListNode(b[i]);
           h=h->next;
        }
        return k->next;
    }
};